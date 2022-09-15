/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_TIMESTAMP_V1 3
#define PD_CALL_BALANCES_V1 4
#define PD_CALL_SESSION_V1 10
#define PD_CALL_ELECTIONS_V1 12
#define PD_CALL_VESTING_V1 14
#define PD_CALL_UTILITY_V1 15
#define PD_CALL_MULTISIG_V1 16
#define PD_CALL_SUDO_V1 17

#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ALL_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_ELECTIONS_CHANGE_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_V1_t members;
} pd_elections_change_members_V1_t;

#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

#define PD_CALL_VESTING_VEST_OTHER_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
} pd_vesting_vest_other_V1_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_vested_transfer_V1_t;

#define PD_CALL_VESTING_FORCE_VESTED_TRANSFER_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_force_vested_transfer_V1_t;

#define PD_CALL_VESTING_MERGE_SCHEDULES_V1 4
typedef struct {
    pd_u32_t schedule1_index;
    pd_u32_t schedule2_index;
} pd_vesting_merge_schedules_V1_t;

#define PD_CALL_SUDO_SUDO_V1 0
typedef struct {
    pd_Call_t call;
} pd_sudo_sudo_V1_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT_V1 1
typedef struct {
    pd_Call_t call;
    pd_Weight_V1_t weight;
} pd_sudo_sudo_unchecked_weight_V1_t;

#define PD_CALL_SUDO_SET_KEY_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t new_;
} pd_sudo_set_key_V1_t;

#define PD_CALL_SUDO_SUDO_AS_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V1_t;

#endif

typedef union {
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_elections_change_members_V1_t elections_change_members_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_vesting_vest_other_V1_t vesting_vest_other_V1;
    pd_vesting_vested_transfer_V1_t vesting_vested_transfer_V1;
    pd_vesting_force_vested_transfer_V1_t vesting_force_vested_transfer_V1;
    pd_vesting_merge_schedules_V1_t vesting_merge_schedules_V1;
    pd_sudo_sudo_V1_t sudo_sudo_V1;
    pd_sudo_sudo_unchecked_weight_V1_t sudo_sudo_unchecked_weight_V1;
    pd_sudo_set_key_V1_t sudo_set_key_V1;
    pd_sudo_sudo_as_V1_t sudo_sudo_as_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t source;
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V1 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
