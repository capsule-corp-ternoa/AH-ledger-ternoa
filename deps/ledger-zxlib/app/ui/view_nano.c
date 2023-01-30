/*******************************************************************************
*   (c) 2018 - 2022 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#include "bolos_target.h"

#if defined(TARGET_NANOS) || defined(TARGET_NANOS2) || defined(TARGET_NANOX)

#include "view_internal.h"
#include "view_nano.h"

#include "view.h"
#include "coin.h"
#include "view_internal.h"
#include "crypto.h"

#include "actions.h"
#include "apdu_codes.h"
#include "ux.h"
#include "bagl.h"
#include "zxmacros.h"
#include "view_templates.h"
#include "tx.h"
#include "addr.h"
#include "app_mode.h"
#include "zxerror.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

extern unsigned int review_type;

uint8_t getIntroPages() {
#if defined(SHORTCUT_MODE_ENABLED) && defined(TARGET_NANOS)
    if (review_type == REVIEW_ADDRESS || !app_mode_shortcut()) {
        return INTRO_PAGES ? INTRO_PAGES - 1 : 0;
    }
#endif
    return INTRO_PAGES;
}

bool h_paging_intro_screen() {
    return viewdata.itemIdx < getIntroPages();
}

void h_initialize(__Z_UNUSED unsigned int _) {
    view_idle_show(0, NULL);
    UX_WAIT();
}

void view_error_show() {
    snprintf(viewdata.key, MAX_CHARS_PER_KEY_LINE, "ERROR");
    snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "SHOWING DATA");
    view_error_show_impl();
}

///////////////////////////////////
// Paging related
bool h_paging_can_increase() {
    if (viewdata.pageIdx + 1 < viewdata.pageCount) {
        zemu_log_stack("h_paging_can_increase");
        return true;
    }

    // passed page count, go to next index
    if (viewdata.itemCount > 0 && viewdata.itemIdx < (viewdata.itemCount - 1 + INCLUDE_ACTIONS_COUNT)) {
        zemu_log_stack("h_paging_can_increase");
        return true;
    }

    zemu_log_stack("h_paging_can_increase NO");
    return false;
}

void h_paging_increase() {
    zemu_log_stack("h_paging_increase");

    if (viewdata.pageIdx + 1 < viewdata.pageCount) {
        // increase page
        viewdata.pageIdx++;
        return;
    }

    // passed page count, go to next index
    if (viewdata.itemCount > 0 && viewdata.itemIdx < (viewdata.itemCount - 1 + INCLUDE_ACTIONS_COUNT)) {
        viewdata.itemIdx++;
        viewdata.pageIdx = 0;
    }
}

bool h_paging_can_decrease() {
    if (viewdata.pageIdx != 0) {
        zemu_log_stack("h_paging_can_decrease");
        return true;
    }

    if (viewdata.itemIdx > 0) {
        zemu_log_stack("h_paging_can_decrease");
        return true;
    }

    zemu_log_stack("h_paging_can_decrease NO");
    return false;
}

void h_paging_decrease() {
    ZEMU_LOGF(50, "h_paging_decrease Idx %d\n", viewdata.itemIdx)

    if (viewdata.pageIdx != 0) {
        viewdata.pageIdx--;
        zemu_log_stack("page--");
        return;
    }

    if (viewdata.itemIdx > 0) {
        viewdata.itemIdx--;
        zemu_log_stack("item--");
        // jump to last page. update will cap this value
        viewdata.pageIdx = 255;
    }
}

#ifdef INCLUDE_ACTIONS_AS_ITEMS
bool is_accept_item(){
    return viewdata.itemIdx == viewdata.itemCount - 1;
}

void set_accept_item(){
    viewdata.itemIdx = viewdata.itemCount - 1;
    viewdata.pageIdx = 0;
}

bool is_reject_item(){
    return viewdata.itemIdx == viewdata.itemCount;
}
#endif

void h_review_action(unsigned int requireReply) {
#ifdef INCLUDE_ACTIONS_AS_ITEMS
    if( is_accept_item() ){
        zemu_log_stack("action_accept");
        h_approve(1);
        return;
    }

    if( is_reject_item() ){
        zemu_log_stack("action_reject");
        h_reject(requireReply);
        return;
    }

    zemu_log_stack("quick accept");
    if (app_mode_expert() || app_mode_shortcut()) {
        set_accept_item();
        h_review_update();
        return;
    }
#endif
}

zxerr_t h_review_update_data() {
    if (viewdata.viewfuncGetNumItems == NULL) {
        zemu_log_stack("h_review_update_data - GetNumItems==NULL");
        return zxerr_no_data;
    }
    if (viewdata.viewfuncGetItem == NULL) {
        zemu_log_stack("h_review_update_data - GetItem==NULL");
        return zxerr_no_data;
    }

    if (viewdata.viewfuncGetItem == NULL) {
        zemu_log_stack("h_review_update_data - GetItem==NULL");
        return zxerr_no_data;
    }

    if (viewdata.viewfuncGetItem == NULL) {
        zemu_log_stack("h_review_update_data - GetItem==NULL");
        return zxerr_no_data;
    }

    char buffer[20];
    snprintf(buffer, sizeof(buffer), "update Idx %d/%d", viewdata.itemIdx, viewdata.pageIdx);
    zemu_log_stack(buffer);

#ifdef INCLUDE_ACTIONS_AS_ITEMS
    viewdata.pageCount = 1;

    if( is_accept_item() ){
        snprintf(viewdata.key, MAX_CHARS_PER_KEY_LINE, "%s","");
        snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "%s", APPROVE_LABEL);
        splitValueField();
        zemu_log_stack("show_accept_action - accept item");
        viewdata.pageIdx = 0;
        return zxerr_ok;
    }

    if( is_reject_item() ){
        snprintf(viewdata.key, MAX_CHARS_PER_KEY_LINE, "%s", "");
        snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "%s", REJECT_LABEL);
        splitValueField();
        zemu_log_stack("show_reject_action - reject item");
        viewdata.pageIdx = 0;
        return zxerr_ok;
    }

    if (h_paging_intro_screen()) {
        char* intro_key = NULL;
        char* intro_value = NULL;

#if defined(REVIEW_SCREEN_ENABLED)
        switch (viewdata.itemIdx) {
            case 0:
                intro_key = PIC(review_key);
                switch (review_type)
                {
                case REVIEW_UI:
                    intro_key = PIC(review_keyconfig);
                    intro_value = PIC(review_configvalue);
                    break;

                case REVIEW_ADDRESS:
                    intro_value = PIC(review_addrvalue);
                    break;

                case REVIEW_TXN:
                default:
                    intro_value = PIC(review_txvalue);
                    break;
                }
                break;
        #if defined(SHORTCUT_MODE_ENABLED)
            case 1:
                intro_key = PIC(shortcut_key);
                intro_value = PIC(shortcut_value);
                break;
        #endif
            default:
                return zxerr_no_data;
        }
#elif defined(SHORTCUT_MODE_ENABLED)
        intro_key = PIC(shortcut_key);
        intro_value = PIC(shortcut_value);
#else
        return zxerr_no_data;
#endif

        snprintf(viewdata.key, MAX_CHARS_PER_KEY_LINE, "%s", intro_key);
        snprintf(viewdata.value, MAX_CHARS_PER_VALUE1_LINE, "%s", intro_value);
        splitValueField();
        viewdata.pageIdx = 0;
        return zxerr_ok;
    }
#endif

    do {
        CHECK_ZXERR(viewdata.viewfuncGetNumItems(&viewdata.itemCount))
        viewdata.itemCount += getIntroPages();

        if (viewdata.itemIdx - getIntroPages() < 0) {
          return zxerr_out_of_bounds;
        }
        const uint8_t realItemIdx = viewdata.itemIdx - getIntroPages();

        //Verify how many chars fit in display (nanos)
        CHECK_ZXERR(viewdata.viewfuncGetItem(
                realItemIdx,
                viewdata.key, MAX_CHARS_PER_KEY_LINE,
                viewdata.value, MAX_CHARS_PER_VALUE1_LINE,
                0, &viewdata.pageCount))
        viewdata.pageCount = 1;
        const max_char_display dyn_max_char_per_line1 = get_max_char_per_line();

        // be sure we are not out of bounds
        CHECK_ZXERR(viewdata.viewfuncGetItem(
                realItemIdx,
                viewdata.key, MAX_CHARS_PER_KEY_LINE,
                viewdata.value, dyn_max_char_per_line1,
                0, &viewdata.pageCount))
        if (viewdata.pageCount != 0 && viewdata.pageIdx > viewdata.pageCount) {
            // try again and get last page
            viewdata.pageIdx = viewdata.pageCount - 1;
        }
        CHECK_ZXERR(viewdata.viewfuncGetItem(
                realItemIdx,
                viewdata.key, MAX_CHARS_PER_KEY_LINE,
                viewdata.value, dyn_max_char_per_line1,
                viewdata.pageIdx, &viewdata.pageCount))

        viewdata.itemCount++;

        if (viewdata.pageCount > 1) {
            uint8_t keyLen = strnlen(viewdata.key, MAX_CHARS_PER_KEY_LINE);
            if (keyLen < MAX_CHARS_PER_KEY_LINE) {
                snprintf(viewdata.key + keyLen,
                         MAX_CHARS_PER_KEY_LINE - keyLen,
                         " [%d/%d]",
                         viewdata.pageIdx + 1,
                         viewdata.pageCount);
            }
        }

        if (viewdata.pageCount == 0) {
            h_paging_increase();
        }
    } while (viewdata.pageCount == 0);

    splitValueAddress();
    return zxerr_ok;
}

///////////////////////////////////
// General
void io_seproxyhal_display(const bagl_element_t *element) {
    io_seproxyhal_display_default(element);
}

#endif
