/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(
    parser_context_t* c, pd_balances_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
    parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V1(
    parser_context_t* c, pd_balances_transfer_all_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
    parser_context_t* c, pd_staking_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(
    parser_context_t* c, pd_staking_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(
    parser_context_t* c, pd_staking_unbond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(
    parser_context_t* c, pd_staking_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(
    parser_context_t* c, pd_staking_validate_V1_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V1(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
    parser_context_t* c, pd_staking_nominate_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(
    parser_context_t* c, pd_staking_chill_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V1(
    parser_context_t* c, pd_staking_set_payee_V1_t* m)
{
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
    parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
    parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(
    parser_context_t* c, pd_staking_rebond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(
    parser_context_t* c, pd_session_set_keys_V1_t* m)
{
    CHECK_ERROR(_readKeys_V1(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(
    parser_context_t* c, pd_session_purge_keys_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(
    parser_context_t* c, pd_utility_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V1(
    parser_context_t* c, pd_utility_batch_all_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V1(
    parser_context_t* c, pd_utility_force_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_create_V1(
    parser_context_t* c, pd_crowdloan_create_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    CHECK_ERROR(_readCompactu32(c, &m->first_period))
    CHECK_ERROR(_readCompactu32(c, &m->last_period))
    CHECK_ERROR(_readCompactu32(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner_V1(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_V1(
    parser_context_t* c, pd_crowdloan_contribute_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readOptionMultiSignature_V1(c, &m->signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_withdraw_V1(
    parser_context_t* c, pd_crowdloan_withdraw_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_refund_V1(
    parser_context_t* c, pd_crowdloan_refund_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_dissolve_V1(
    parser_context_t* c, pd_crowdloan_dissolve_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_edit_V1(
    parser_context_t* c, pd_crowdloan_edit_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->cap))
    CHECK_ERROR(_readCompactu32(c, &m->first_period))
    CHECK_ERROR(_readCompactu32(c, &m->last_period))
    CHECK_ERROR(_readCompactu32(c, &m->end))
    CHECK_ERROR(_readOptionMultiSigner_V1(c, &m->verifier))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_add_memo_V1(
    parser_context_t* c, pd_crowdloan_add_memo_V1_t* m)
{
    CHECK_ERROR(_readParaId_V1(c, &m->index))
    CHECK_ERROR(_readVecu8(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_poke_V1(
    parser_context_t* c, pd_crowdloan_poke_V1_t* m)
{
    CHECK_ERROR(_readParaId_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_crowdloan_contribute_all_V1(
    parser_context_t* c, pd_crowdloan_contribute_all_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readOptionMultiSignature_V1(c, &m->signature))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V1(
    parser_context_t* c, pd_system_fill_block_V1_t* m)
{
    CHECK_ERROR(_readPerbill_V1(c, &m->ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V1(
    parser_context_t* c, pd_system_remark_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V1(
    parser_context_t* c, pd_system_set_heap_pages_V1_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V1(
    parser_context_t* c, pd_system_set_code_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V1(
    parser_context_t* c, pd_system_set_code_without_checks_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V1(
    parser_context_t* c, pd_system_remark_with_event_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V1(
    parser_context_t* c, pd_timestamp_set_V1_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V1(
    parser_context_t* c, pd_indices_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V1(
    parser_context_t* c, pd_indices_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V1(
    parser_context_t* c, pd_indices_free_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V1(
    parser_context_t* c, pd_indices_force_transfer_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V1(
    parser_context_t* c, pd_indices_freeze_V1_t* m)
{
    CHECK_ERROR(_readAccountIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V1(
    parser_context_t* c, pd_balances_set_balance_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V1(
    parser_context_t* c, pd_balances_force_unreserve_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V1(
    parser_context_t* c, pd_staking_set_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V1(
    parser_context_t* c, pd_staking_increase_validator_count_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V1(
    parser_context_t* c, pd_staking_force_no_eras_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V1(
    parser_context_t* c, pd_staking_force_new_era_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V1(
    parser_context_t* c, pd_staking_set_invulnerables_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(
    parser_context_t* c, pd_staking_force_unstake_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(
    parser_context_t* c, pd_staking_force_new_era_always_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V1(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V1_t* m)
{
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V1(
    parser_context_t* c, pd_staking_set_history_depth_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(
    parser_context_t* c, pd_staking_reap_stash_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V1(
    parser_context_t* c, pd_staking_kick_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V1(
    parser_context_t* c, pd_staking_chill_other_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V1(
    parser_context_t* c, pd_staking_force_apply_min_commission_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V1(
    parser_context_t* c, pd_grandpa_note_stalled_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V1(
    parser_context_t* c, pd_democracy_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V1(
    parser_context_t* c, pd_democracy_second_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V1(
    parser_context_t* c, pd_democracy_vote_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V1(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V1(
    parser_context_t* c, pd_democracy_emergency_cancel_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V1(
    parser_context_t* c, pd_democracy_external_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V1(
    parser_context_t* c, pd_democracy_external_propose_majority_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V1(
    parser_context_t* c, pd_democracy_external_propose_default_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V1(
    parser_context_t* c, pd_democracy_fast_track_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V1(
    parser_context_t* c, pd_democracy_veto_external_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_referendum_V1(
    parser_context_t* c, pd_democracy_cancel_referendum_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_queued_V1(
    parser_context_t* c, pd_democracy_cancel_queued_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->which))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V1(
    parser_context_t* c, pd_democracy_delegate_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readConviction_V1(c, &m->conviction))
    CHECK_ERROR(_readBalance(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V1(
    parser_context_t* c, pd_democracy_undelegate_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_clear_public_proposals_V1(
    parser_context_t* c, pd_democracy_clear_public_proposals_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V1(
    parser_context_t* c, pd_democracy_note_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V1(
    parser_context_t* c, pd_democracy_reap_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V1(
    parser_context_t* c, pd_democracy_unlock_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V1(
    parser_context_t* c, pd_democracy_remove_vote_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V1(
    parser_context_t* c, pd_democracy_remove_other_vote_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_enact_proposal_V1(
    parser_context_t* c, pd_democracy_enact_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_cancel_proposal_V1(
    parser_context_t* c, pd_democracy_cancel_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->prop_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V1(
    parser_context_t* c, pd_council_set_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V1(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V1(
    parser_context_t* c, pd_council_execute_V1_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V1(
    parser_context_t* c, pd_council_propose_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V1(
    parser_context_t* c, pd_council_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V1(
    parser_context_t* c, pd_council_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V1(
    parser_context_t* c, pd_council_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V1(
    parser_context_t* c, pd_technicalcommittee_set_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V1(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V1(
    parser_context_t* c, pd_technicalcommittee_execute_V1_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V1(
    parser_context_t* c, pd_technicalcommittee_propose_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V1(
    parser_context_t* c, pd_technicalcommittee_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V1(
    parser_context_t* c, pd_technicalcommittee_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V1(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_vote_V1(
    parser_context_t* c, pd_phragmenelection_vote_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->votes))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_remove_voter_V1(
    parser_context_t* c, pd_phragmenelection_remove_voter_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_submit_candidacy_V1(
    parser_context_t* c, pd_phragmenelection_submit_candidacy_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_remove_member_V1(
    parser_context_t* c, pd_phragmenelection_remove_member_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->slash_bond))
    CHECK_ERROR(_readbool(c, &m->rerun_election))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_clean_defunct_voters_V1(
    parser_context_t* c, pd_phragmenelection_clean_defunct_voters_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_voters))
    CHECK_ERROR(_readu32(c, &m->num_defunct))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_add_member_V1(
    parser_context_t* c, pd_technicalmembership_add_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V1(
    parser_context_t* c, pd_technicalmembership_remove_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V1(
    parser_context_t* c, pd_technicalmembership_swap_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->remove))
    CHECK_ERROR(_readAccountId_V1(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V1(
    parser_context_t* c, pd_technicalmembership_reset_members_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V1(
    parser_context_t* c, pd_technicalmembership_change_key_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V1(
    parser_context_t* c, pd_technicalmembership_set_prime_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V1(
    parser_context_t* c, pd_technicalmembership_clear_prime_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V1(
    parser_context_t* c, pd_treasury_propose_spend_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V1(
    parser_context_t* c, pd_treasury_reject_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V1(
    parser_context_t* c, pd_treasury_approve_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_spend_V1(
    parser_context_t* c, pd_treasury_spend_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_remove_approval_V1(
    parser_context_t* c, pd_treasury_remove_approval_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_V1(
    parser_context_t* c, pd_claims_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V1(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_claim_attest_V1(
    parser_context_t* c, pd_claims_claim_attest_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    CHECK_ERROR(_readEcdsaSignature_V1(c, &m->ethereum_signature))
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_attest_V1(
    parser_context_t* c, pd_claims_attest_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->statement))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_claims_move_claim_V1(
    parser_context_t* c, pd_claims_move_claim_V1_t* m)
{
    CHECK_ERROR(_readEthereumAddress_V1(c, &m->old))
    CHECK_ERROR(_readEthereumAddress_V1(c, &m->new_))
    CHECK_ERROR(_readOptionAccountId_V1(c, &m->maybe_preclaim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V1(
    parser_context_t* c, pd_identity_add_registrar_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V1(
    parser_context_t* c, pd_identity_clear_identity_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V1(
    parser_context_t* c, pd_identity_request_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V1(
    parser_context_t* c, pd_identity_cancel_request_V1_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V1(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V1(
    parser_context_t* c, pd_identity_set_fee_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V1(
    parser_context_t* c, pd_identity_set_account_id_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
    parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V1(
    parser_context_t* c, pd_identity_remove_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V1(
    parser_context_t* c, pd_identity_quit_sub_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_bid_V1(
    parser_context_t* c, pd_society_bid_V1_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unbid_V1(
    parser_context_t* c, pd_society_unbid_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vouch_V1(
    parser_context_t* c, pd_society_vouch_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBalanceOf(c, &m->tip))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unvouch_V1(
    parser_context_t* c, pd_society_unvouch_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->pos))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_vote_V1(
    parser_context_t* c, pd_society_vote_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->candidate))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_defender_vote_V1(
    parser_context_t* c, pd_society_defender_vote_V1_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_payout_V1(
    parser_context_t* c, pd_society_payout_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_found_V1(
    parser_context_t* c, pd_society_found_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->founder))
    CHECK_ERROR(_readu32(c, &m->max_members))
    CHECK_ERROR(_readBytes(c, &m->rules))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_unfound_V1(
    parser_context_t* c, pd_society_unfound_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_judge_suspended_member_V1(
    parser_context_t* c, pd_society_judge_suspended_member_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readbool(c, &m->forgive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_society_set_max_members_V1(
    parser_context_t* c, pd_society_set_max_members_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_set_recovered_V1(
    parser_context_t* c, pd_recovery_set_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V1(
    parser_context_t* c, pd_recovery_initiate_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V1(
    parser_context_t* c, pd_recovery_vouch_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V1(
    parser_context_t* c, pd_recovery_claim_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V1(
    parser_context_t* c, pd_recovery_close_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V1(
    parser_context_t* c, pd_recovery_remove_recovery_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V1(
    parser_context_t* c, pd_recovery_cancel_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V1(
    parser_context_t* c, pd_vesting_vest_other_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V1(
    parser_context_t* c, pd_vesting_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_force_vested_transfer_V1(
    parser_context_t* c, pd_vesting_force_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_merge_schedules_V1(
    parser_context_t* c, pd_vesting_merge_schedules_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->schedule1_index))
    CHECK_ERROR(_readu32(c, &m->schedule2_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V1(
    parser_context_t* c, pd_proxy_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V1(
    parser_context_t* c, pd_proxy_add_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V1(
    parser_context_t* c, pd_proxy_remove_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V1(
    parser_context_t* c, pd_proxy_remove_proxies_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V1(
    parser_context_t* c, pd_proxy_anonymous_V1_t* m)
{
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V1(
    parser_context_t* c, pd_proxy_kill_anonymous_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V1(
    parser_context_t* c, pd_proxy_proxy_announced_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V1(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(
    parser_context_t* c, pd_multisig_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V1(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(
    parser_context_t* c, pd_multisig_approve_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
    parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V1(
    parser_context_t* c, pd_preimage_note_preimage_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V1(
    parser_context_t* c, pd_preimage_unnote_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V1(
    parser_context_t* c, pd_preimage_request_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V1(
    parser_context_t* c, pd_preimage_unrequest_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_bounty_V1(
    parser_context_t* c, pd_bounties_propose_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_approve_bounty_V1(
    parser_context_t* c, pd_bounties_approve_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_propose_curator_V1(
    parser_context_t* c, pd_bounties_propose_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_unassign_curator_V1(
    parser_context_t* c, pd_bounties_unassign_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_accept_curator_V1(
    parser_context_t* c, pd_bounties_accept_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_award_bounty_V1(
    parser_context_t* c, pd_bounties_award_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_claim_bounty_V1(
    parser_context_t* c, pd_bounties_claim_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_close_bounty_V1(
    parser_context_t* c, pd_bounties_close_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bounties_extend_bounty_expiry_V1(
    parser_context_t* c, pd_bounties_extend_bounty_expiry_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->bounty_id))
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_add_child_bounty_V1(
    parser_context_t* c, pd_childbounties_add_child_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readVecu8(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_propose_curator_V1(
    parser_context_t* c, pd_childbounties_propose_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->curator))
    CHECK_ERROR(_readCompactBalance(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_accept_curator_V1(
    parser_context_t* c, pd_childbounties_accept_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_unassign_curator_V1(
    parser_context_t* c, pd_childbounties_unassign_curator_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_award_child_bounty_V1(
    parser_context_t* c, pd_childbounties_award_child_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_claim_child_bounty_V1(
    parser_context_t* c, pd_childbounties_claim_child_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_childbounties_close_child_bounty_V1(
    parser_context_t* c, pd_childbounties_close_child_bounty_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->parent_bounty_id))
    CHECK_ERROR(_readCompactu32(c, &m->child_bounty_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_report_awesome_V1(
    parser_context_t* c, pd_tips_report_awesome_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_retract_tip_V1(
    parser_context_t* c, pd_tips_retract_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_new_V1(
    parser_context_t* c, pd_tips_tip_new_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->reason))
    CHECK_ERROR(_readAccountId_V1(c, &m->who))
    CHECK_ERROR(_readCompactu128(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_tip_V1(
    parser_context_t* c, pd_tips_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    CHECK_ERROR(_readCompactu128(c, &m->tip_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_close_tip_V1(
    parser_context_t* c, pd_tips_close_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_tips_slash_tip_V1(
    parser_context_t* c, pd_tips_slash_tip_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_governance_fallback_V1(
    parser_context_t* c, pd_electionprovidermultiphase_governance_fallback_V1_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->maybe_max_voters))
    CHECK_ERROR(_readOptionu32(c, &m->maybe_max_targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_place_bid_V1(
    parser_context_t* c, pd_gilt_place_bid_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readu32(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_retract_bid_V1(
    parser_context_t* c, pd_gilt_retract_bid_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readu32(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_set_target_V1(
    parser_context_t* c, pd_gilt_set_target_V1_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_gilt_thaw_V1(
    parser_context_t* c, pd_gilt_thaw_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_rebag_V1(
    parser_context_t* c, pd_voterlist_rebag_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dislocated))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voterlist_put_in_front_of_V1(
    parser_context_t* c, pd_voterlist_put_in_front_of_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lighter))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_join_V1(
    parser_context_t* c, pd_nominationpools_join_V1_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_bond_extra_V1(
    parser_context_t* c, pd_nominationpools_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readBondExtraBalanceOfT_V1(c, &m->extra))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_claim_payout_V1(
    parser_context_t* c, pd_nominationpools_claim_payout_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_unbond_V1(
    parser_context_t* c, pd_nominationpools_unbond_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->member_account))
    CHECK_ERROR(_readCompactu128(c, &m->unbonding_points))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_pool_withdraw_unbonded_V1(
    parser_context_t* c, pd_nominationpools_pool_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_withdraw_unbonded_V1(
    parser_context_t* c, pd_nominationpools_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->member_account))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_create_V1(
    parser_context_t* c, pd_nominationpools_create_V1_t* m)
{
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    CHECK_ERROR(_readAccountId_V1(c, &m->root))
    CHECK_ERROR(_readAccountId_V1(c, &m->nominator))
    CHECK_ERROR(_readAccountId_V1(c, &m->state_toggler))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_nominate_V1(
    parser_context_t* c, pd_nominationpools_nominate_V1_t* m)
{
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_state_V1(
    parser_context_t* c, pd_nominationpools_set_state_V1_t* m)
{
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    CHECK_ERROR(_readPoolState_V1(c, &m->state))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_metadata_V1(
    parser_context_t* c, pd_nominationpools_set_metadata_V1_t* m)
{
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    CHECK_ERROR(_readVecu8(c, &m->metadata))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_set_configs_V1(
    parser_context_t* c, pd_nominationpools_set_configs_V1_t* m)
{
    CHECK_ERROR(_readConfigOpBalanceOfT_V1(c, &m->min_join_bond))
    CHECK_ERROR(_readConfigOpBalanceOfT_V1(c, &m->min_create_bond))
    CHECK_ERROR(_readConfigOpu32_V1(c, &m->max_pools))
    CHECK_ERROR(_readConfigOpu32_V1(c, &m->max_members))
    CHECK_ERROR(_readConfigOpu32_V1(c, &m->max_members_per_pool))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_update_roles_V1(
    parser_context_t* c, pd_nominationpools_update_roles_V1_t* m)
{
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    CHECK_ERROR(_readConfigOpAccountId_V1(c, &m->new_root))
    CHECK_ERROR(_readConfigOpAccountId_V1(c, &m->new_nominator))
    CHECK_ERROR(_readConfigOpAccountId_V1(c, &m->new_state_toggler))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nominationpools_chill_V1(
    parser_context_t* c, pd_nominationpools_chill_V1_t* m)
{
    CHECK_ERROR(_readPoolId_V1(c, &m->pool_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_cooldown_V1(
    parser_context_t* c, pd_configuration_set_validation_upgrade_cooldown_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_validation_upgrade_delay_V1(
    parser_context_t* c, pd_configuration_set_validation_upgrade_delay_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_code_retention_period_V1(
    parser_context_t* c, pd_configuration_set_code_retention_period_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_code_size_V1(
    parser_context_t* c, pd_configuration_set_max_code_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_pov_size_V1(
    parser_context_t* c, pd_configuration_set_max_pov_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_head_data_size_V1(
    parser_context_t* c, pd_configuration_set_max_head_data_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_parathread_cores_V1(
    parser_context_t* c, pd_configuration_set_parathread_cores_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_parathread_retries_V1(
    parser_context_t* c, pd_configuration_set_parathread_retries_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_group_rotation_frequency_V1(
    parser_context_t* c, pd_configuration_set_group_rotation_frequency_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_chain_availability_period_V1(
    parser_context_t* c, pd_configuration_set_chain_availability_period_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_thread_availability_period_V1(
    parser_context_t* c, pd_configuration_set_thread_availability_period_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_scheduling_lookahead_V1(
    parser_context_t* c, pd_configuration_set_scheduling_lookahead_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_per_core_V1(
    parser_context_t* c, pd_configuration_set_max_validators_per_core_V1_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_validators_V1(
    parser_context_t* c, pd_configuration_set_max_validators_V1_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_period_V1(
    parser_context_t* c, pd_configuration_set_dispute_period_V1_t* m)
{
    CHECK_ERROR(_readSessionIndex_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V1(
    parser_context_t* c, pd_configuration_set_dispute_post_conclusion_acceptance_period_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_max_spam_slots_V1(
    parser_context_t* c, pd_configuration_set_dispute_max_spam_slots_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_dispute_conclusion_by_time_out_period_V1(
    parser_context_t* c, pd_configuration_set_dispute_conclusion_by_time_out_period_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_no_show_slots_V1(
    parser_context_t* c, pd_configuration_set_no_show_slots_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_n_delay_tranches_V1(
    parser_context_t* c, pd_configuration_set_n_delay_tranches_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_zeroth_delay_tranche_width_V1(
    parser_context_t* c, pd_configuration_set_zeroth_delay_tranche_width_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_needed_approvals_V1(
    parser_context_t* c, pd_configuration_set_needed_approvals_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_relay_vrf_modulo_samples_V1(
    parser_context_t* c, pd_configuration_set_relay_vrf_modulo_samples_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_count_V1(
    parser_context_t* c, pd_configuration_set_max_upward_queue_count_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_queue_size_V1(
    parser_context_t* c, pd_configuration_set_max_upward_queue_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_downward_message_size_V1(
    parser_context_t* c, pd_configuration_set_max_downward_message_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_ump_service_total_weight_V1(
    parser_context_t* c, pd_configuration_set_ump_service_total_weight_V1_t* m)
{
    CHECK_ERROR(_readWeight_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_size_V1(
    parser_context_t* c, pd_configuration_set_max_upward_message_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_max_upward_message_num_per_candidate_V1(
    parser_context_t* c, pd_configuration_set_max_upward_message_num_per_candidate_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_open_request_ttl_V1(
    parser_context_t* c, pd_configuration_set_hrmp_open_request_ttl_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_sender_deposit_V1(
    parser_context_t* c, pd_configuration_set_hrmp_sender_deposit_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_recipient_deposit_V1(
    parser_context_t* c, pd_configuration_set_hrmp_recipient_deposit_V1_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_capacity_V1(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_capacity_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_total_size_V1(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_total_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V1(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_inbound_channels_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parathread_inbound_channels_V1(
    parser_context_t* c, pd_configuration_set_hrmp_max_parathread_inbound_channels_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_channel_max_message_size_V1(
    parser_context_t* c, pd_configuration_set_hrmp_channel_max_message_size_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V1(
    parser_context_t* c, pd_configuration_set_hrmp_max_parachain_outbound_channels_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_parathread_outbound_channels_V1(
    parser_context_t* c, pd_configuration_set_hrmp_max_parathread_outbound_channels_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_hrmp_max_message_num_per_candidate_V1(
    parser_context_t* c, pd_configuration_set_hrmp_max_message_num_per_candidate_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_ump_max_individual_weight_V1(
    parser_context_t* c, pd_configuration_set_ump_max_individual_weight_V1_t* m)
{
    CHECK_ERROR(_readWeight_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_pvf_checking_enabled_V1(
    parser_context_t* c, pd_configuration_set_pvf_checking_enabled_V1_t* m)
{
    CHECK_ERROR(_readbool(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_pvf_voting_ttl_V1(
    parser_context_t* c, pd_configuration_set_pvf_voting_ttl_V1_t* m)
{
    CHECK_ERROR(_readSessionIndex_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_minimum_validation_upgrade_delay_V1(
    parser_context_t* c, pd_configuration_set_minimum_validation_upgrade_delay_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_configuration_set_bypass_consistency_check_V1(
    parser_context_t* c, pd_configuration_set_bypass_consistency_check_V1_t* m)
{
    CHECK_ERROR(_readbool(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_initializer_force_approve_V1(
    parser_context_t* c, pd_initializer_force_approve_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->up_to))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_force_process_hrmp_open_V1(
    parser_context_t* c, pd_hrmp_force_process_hrmp_open_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->channels))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_hrmp_force_process_hrmp_close_V1(
    parser_context_t* c, pd_hrmp_force_process_hrmp_close_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->channels))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_parasdisputes_force_unfreeze_V1(
    parser_context_t* c, pd_parasdisputes_force_unfreeze_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_registrar_reserve_V1(
    parser_context_t* c, pd_registrar_reserve_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_new_auction_V1(
    parser_context_t* c, pd_auctions_new_auction_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->duration))
    CHECK_ERROR(_readCompactu32(c, &m->lease_period_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_bid_V1(
    parser_context_t* c, pd_auctions_bid_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->para))
    CHECK_ERROR(_readCompactu32(c, &m->auction_index))
    CHECK_ERROR(_readCompactu32(c, &m->first_slot))
    CHECK_ERROR(_readCompactu32(c, &m->last_slot))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_auctions_cancel_auction_V1(
    parser_context_t* c, pd_auctions_cancel_auction_V1_t* m)
{
    return parser_ok;
}

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_transfer_all_V1(c, &method->basic.balances_transfer_all_V1))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V1(c, &method->basic.utility_batch_all_V1))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V1(c, &method->basic.utility_force_batch_V1))
        break;
    case 18688: /* module 73 call 0 */
        CHECK_ERROR(_readMethod_crowdloan_create_V1(c, &method->basic.crowdloan_create_V1))
        break;
    case 18689: /* module 73 call 1 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_V1(c, &method->basic.crowdloan_contribute_V1))
        break;
    case 18690: /* module 73 call 2 */
        CHECK_ERROR(_readMethod_crowdloan_withdraw_V1(c, &method->basic.crowdloan_withdraw_V1))
        break;
    case 18691: /* module 73 call 3 */
        CHECK_ERROR(_readMethod_crowdloan_refund_V1(c, &method->basic.crowdloan_refund_V1))
        break;
    case 18692: /* module 73 call 4 */
        CHECK_ERROR(_readMethod_crowdloan_dissolve_V1(c, &method->basic.crowdloan_dissolve_V1))
        break;
    case 18693: /* module 73 call 5 */
        CHECK_ERROR(_readMethod_crowdloan_edit_V1(c, &method->basic.crowdloan_edit_V1))
        break;
    case 18694: /* module 73 call 6 */
        CHECK_ERROR(_readMethod_crowdloan_add_memo_V1(c, &method->basic.crowdloan_add_memo_V1))
        break;
    case 18695: /* module 73 call 7 */
        CHECK_ERROR(_readMethod_crowdloan_poke_V1(c, &method->basic.crowdloan_poke_V1))
        break;
    case 18696: /* module 73 call 8 */
        CHECK_ERROR(_readMethod_crowdloan_contribute_all_V1(c, &method->basic.crowdloan_contribute_all_V1))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->nested.system_fill_block_V1))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->nested.system_set_heap_pages_V1))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->nested.system_set_code_V1))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->nested.system_set_code_without_checks_V1))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V1(c, &method->nested.system_remark_with_event_V1))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V1(c, &method->basic.indices_claim_V1))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V1(c, &method->basic.indices_transfer_V1))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V1(c, &method->basic.indices_free_V1))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V1(c, &method->basic.indices_force_transfer_V1))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V1(c, &method->basic.indices_freeze_V1))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->nested.balances_set_balance_V1))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_force_unreserve_V1(c, &method->basic.balances_force_unreserve_V1))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V1(c, &method->basic.staking_set_history_depth_V1))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_staking_kick_V1(c, &method->basic.staking_kick_V1))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_staking_chill_other_V1(c, &method->basic.staking_chill_other_V1))
        break;
    case 1561: /* module 6 call 25 */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V1(c, &method->basic.staking_force_apply_min_commission_V1))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V1(c, &method->nested.democracy_propose_V1))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V1(c, &method->nested.democracy_second_V1))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V1(c, &method->nested.democracy_vote_V1))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V1(c, &method->nested.democracy_emergency_cancel_V1))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V1(c, &method->nested.democracy_external_propose_V1))
        break;
    case 3333: /* module 13 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V1(c, &method->nested.democracy_external_propose_majority_V1))
        break;
    case 3334: /* module 13 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V1(c, &method->nested.democracy_external_propose_default_V1))
        break;
    case 3335: /* module 13 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V1(c, &method->nested.democracy_fast_track_V1))
        break;
    case 3336: /* module 13 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V1(c, &method->nested.democracy_veto_external_V1))
        break;
    case 3337: /* module 13 call 9 */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V1(c, &method->nested.democracy_cancel_referendum_V1))
        break;
    case 3338: /* module 13 call 10 */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V1(c, &method->nested.democracy_cancel_queued_V1))
        break;
    case 3339: /* module 13 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V1(c, &method->nested.democracy_delegate_V1))
        break;
    case 3340: /* module 13 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V1(c, &method->nested.democracy_undelegate_V1))
        break;
    case 3341: /* module 13 call 13 */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V1(c, &method->nested.democracy_clear_public_proposals_V1))
        break;
    case 3342: /* module 13 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V1(c, &method->basic.democracy_note_preimage_V1))
        break;
    case 3343: /* module 13 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V1(c, &method->basic.democracy_note_preimage_operational_V1))
        break;
    case 3344: /* module 13 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V1(c, &method->basic.democracy_note_imminent_preimage_V1))
        break;
    case 3345: /* module 13 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V1(c, &method->basic.democracy_note_imminent_preimage_operational_V1))
        break;
    case 3346: /* module 13 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V1(c, &method->nested.democracy_reap_preimage_V1))
        break;
    case 3347: /* module 13 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V1(c, &method->nested.democracy_unlock_V1))
        break;
    case 3348: /* module 13 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V1(c, &method->nested.democracy_remove_vote_V1))
        break;
    case 3349: /* module 13 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V1(c, &method->nested.democracy_remove_other_vote_V1))
        break;
    case 3350: /* module 13 call 22 */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V1(c, &method->nested.democracy_enact_proposal_V1))
        break;
    case 3352: /* module 13 call 24 */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V1(c, &method->nested.democracy_cancel_proposal_V1))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_council_set_members_V1(c, &method->basic.council_set_members_V1))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V1(c, &method->basic.council_execute_V1))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V1(c, &method->basic.council_propose_V1))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V1(c, &method->basic.council_vote_V1))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V1(c, &method->basic.technicalcommittee_set_members_V1))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V1(c, &method->basic.technicalcommittee_execute_V1))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V1(c, &method->basic.technicalcommittee_propose_V1))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V1(c, &method->basic.technicalcommittee_vote_V1))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V1(c, &method->basic.technicalcommittee_close_V1))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V1(c, &method->basic.technicalcommittee_disapprove_proposal_V1))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_phragmenelection_vote_V1(c, &method->basic.phragmenelection_vote_V1))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_phragmenelection_remove_voter_V1(c, &method->basic.phragmenelection_remove_voter_V1))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_phragmenelection_submit_candidacy_V1(c, &method->basic.phragmenelection_submit_candidacy_V1))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_phragmenelection_remove_member_V1(c, &method->basic.phragmenelection_remove_member_V1))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_phragmenelection_clean_defunct_voters_V1(c, &method->basic.phragmenelection_clean_defunct_voters_V1))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V1(c, &method->basic.technicalmembership_add_member_V1))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V1(c, &method->basic.technicalmembership_remove_member_V1))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V1(c, &method->basic.technicalmembership_swap_member_V1))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V1(c, &method->basic.technicalmembership_reset_members_V1))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V1(c, &method->basic.technicalmembership_change_key_V1))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V1(c, &method->basic.technicalmembership_set_prime_V1))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V1(c, &method->basic.technicalmembership_clear_prime_V1))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V1(c, &method->basic.treasury_propose_spend_V1))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V1(c, &method->basic.treasury_reject_proposal_V1))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V1(c, &method->basic.treasury_approve_proposal_V1))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_treasury_spend_V1(c, &method->basic.treasury_spend_V1))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_treasury_remove_approval_V1(c, &method->basic.treasury_remove_approval_V1))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_claims_claim_V1(c, &method->basic.claims_claim_V1))
        break;
    case 4866: /* module 19 call 2 */
        CHECK_ERROR(_readMethod_claims_claim_attest_V1(c, &method->basic.claims_claim_attest_V1))
        break;
    case 4867: /* module 19 call 3 */
        CHECK_ERROR(_readMethod_claims_attest_V1(c, &method->basic.claims_attest_V1))
        break;
    case 4868: /* module 19 call 4 */
        CHECK_ERROR(_readMethod_claims_move_claim_V1(c, &method->basic.claims_move_claim_V1))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V1(c, &method->basic.identity_request_judgement_V1))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V1(c, &method->basic.identity_cancel_request_V1))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V1(c, &method->basic.identity_set_fee_V1))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V1(c, &method->basic.identity_set_account_id_V1))
        break;
    case 6410: /* module 25 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
    case 6413: /* module 25 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
    case 6414: /* module 25 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_society_bid_V1(c, &method->basic.society_bid_V1))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_society_unbid_V1(c, &method->basic.society_unbid_V1))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_society_vouch_V1(c, &method->basic.society_vouch_V1))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_society_unvouch_V1(c, &method->basic.society_unvouch_V1))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_society_vote_V1(c, &method->basic.society_vote_V1))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_society_defender_vote_V1(c, &method->basic.society_defender_vote_V1))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_society_payout_V1(c, &method->basic.society_payout_V1))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_society_found_V1(c, &method->basic.society_found_V1))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_society_unfound_V1(c, &method->basic.society_unfound_V1))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_society_judge_suspended_member_V1(c, &method->basic.society_judge_suspended_member_V1))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_society_set_max_members_V1(c, &method->basic.society_set_max_members_V1))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_recovery_set_recovered_V1(c, &method->basic.recovery_set_recovered_V1))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V1(c, &method->basic.recovery_initiate_recovery_V1))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V1(c, &method->basic.recovery_vouch_recovery_V1))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V1(c, &method->basic.recovery_claim_recovery_V1))
        break;
    case 6918: /* module 27 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V1(c, &method->basic.recovery_close_recovery_V1))
        break;
    case 6919: /* module 27 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V1(c, &method->basic.recovery_remove_recovery_V1))
        break;
    case 6920: /* module 27 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V1(c, &method->basic.recovery_cancel_recovered_V1))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V1(c, &method->basic.vesting_vest_other_V1))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V1(c, &method->basic.vesting_vested_transfer_V1))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_vesting_force_vested_transfer_V1(c, &method->basic.vesting_force_vested_transfer_V1))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_vesting_merge_schedules_V1(c, &method->basic.vesting_merge_schedules_V1))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->nested.proxy_proxy_V1))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V1(c, &method->basic.proxy_add_proxy_V1))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V1(c, &method->basic.proxy_remove_proxy_V1))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V1(c, &method->basic.proxy_remove_proxies_V1))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V1(c, &method->basic.proxy_anonymous_V1))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V1(c, &method->basic.proxy_kill_anonymous_V1))
        break;
    case 7689: /* module 30 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V1(c, &method->basic.proxy_proxy_announced_V1))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->nested.multisig_as_multi_threshold_1_V1))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->nested.multisig_as_multi_V1))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->nested.multisig_approve_as_multi_V1))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->nested.multisig_cancel_as_multi_V1))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V1(c, &method->basic.preimage_note_preimage_V1))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V1(c, &method->basic.preimage_unnote_preimage_V1))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V1(c, &method->basic.preimage_request_preimage_V1))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V1(c, &method->basic.preimage_unrequest_preimage_V1))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_bounties_propose_bounty_V1(c, &method->basic.bounties_propose_bounty_V1))
        break;
    case 8961: /* module 35 call 1 */
        CHECK_ERROR(_readMethod_bounties_approve_bounty_V1(c, &method->basic.bounties_approve_bounty_V1))
        break;
    case 8962: /* module 35 call 2 */
        CHECK_ERROR(_readMethod_bounties_propose_curator_V1(c, &method->basic.bounties_propose_curator_V1))
        break;
    case 8963: /* module 35 call 3 */
        CHECK_ERROR(_readMethod_bounties_unassign_curator_V1(c, &method->basic.bounties_unassign_curator_V1))
        break;
    case 8964: /* module 35 call 4 */
        CHECK_ERROR(_readMethod_bounties_accept_curator_V1(c, &method->basic.bounties_accept_curator_V1))
        break;
    case 8965: /* module 35 call 5 */
        CHECK_ERROR(_readMethod_bounties_award_bounty_V1(c, &method->basic.bounties_award_bounty_V1))
        break;
    case 8966: /* module 35 call 6 */
        CHECK_ERROR(_readMethod_bounties_claim_bounty_V1(c, &method->basic.bounties_claim_bounty_V1))
        break;
    case 8967: /* module 35 call 7 */
        CHECK_ERROR(_readMethod_bounties_close_bounty_V1(c, &method->basic.bounties_close_bounty_V1))
        break;
    case 8968: /* module 35 call 8 */
        CHECK_ERROR(_readMethod_bounties_extend_bounty_expiry_V1(c, &method->basic.bounties_extend_bounty_expiry_V1))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_childbounties_add_child_bounty_V1(c, &method->basic.childbounties_add_child_bounty_V1))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_childbounties_propose_curator_V1(c, &method->basic.childbounties_propose_curator_V1))
        break;
    case 10242: /* module 40 call 2 */
        CHECK_ERROR(_readMethod_childbounties_accept_curator_V1(c, &method->basic.childbounties_accept_curator_V1))
        break;
    case 10243: /* module 40 call 3 */
        CHECK_ERROR(_readMethod_childbounties_unassign_curator_V1(c, &method->basic.childbounties_unassign_curator_V1))
        break;
    case 10244: /* module 40 call 4 */
        CHECK_ERROR(_readMethod_childbounties_award_child_bounty_V1(c, &method->basic.childbounties_award_child_bounty_V1))
        break;
    case 10245: /* module 40 call 5 */
        CHECK_ERROR(_readMethod_childbounties_claim_child_bounty_V1(c, &method->basic.childbounties_claim_child_bounty_V1))
        break;
    case 10246: /* module 40 call 6 */
        CHECK_ERROR(_readMethod_childbounties_close_child_bounty_V1(c, &method->basic.childbounties_close_child_bounty_V1))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_tips_report_awesome_V1(c, &method->basic.tips_report_awesome_V1))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_tips_retract_tip_V1(c, &method->basic.tips_retract_tip_V1))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_tips_tip_new_V1(c, &method->basic.tips_tip_new_V1))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_tips_tip_V1(c, &method->basic.tips_tip_V1))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_tips_close_tip_V1(c, &method->basic.tips_close_tip_V1))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_tips_slash_tip_V1(c, &method->basic.tips_slash_tip_V1))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_governance_fallback_V1(c, &method->basic.electionprovidermultiphase_governance_fallback_V1))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_gilt_place_bid_V1(c, &method->basic.gilt_place_bid_V1))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_gilt_retract_bid_V1(c, &method->basic.gilt_retract_bid_V1))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_gilt_set_target_V1(c, &method->basic.gilt_set_target_V1))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_gilt_thaw_V1(c, &method->basic.gilt_thaw_V1))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_voterlist_rebag_V1(c, &method->basic.voterlist_rebag_V1))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_voterlist_put_in_front_of_V1(c, &method->basic.voterlist_put_in_front_of_V1))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_nominationpools_join_V1(c, &method->basic.nominationpools_join_V1))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_nominationpools_bond_extra_V1(c, &method->basic.nominationpools_bond_extra_V1))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_nominationpools_claim_payout_V1(c, &method->basic.nominationpools_claim_payout_V1))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_nominationpools_unbond_V1(c, &method->basic.nominationpools_unbond_V1))
        break;
    case 10500: /* module 41 call 4 */
        CHECK_ERROR(_readMethod_nominationpools_pool_withdraw_unbonded_V1(c, &method->basic.nominationpools_pool_withdraw_unbonded_V1))
        break;
    case 10501: /* module 41 call 5 */
        CHECK_ERROR(_readMethod_nominationpools_withdraw_unbonded_V1(c, &method->basic.nominationpools_withdraw_unbonded_V1))
        break;
    case 10502: /* module 41 call 6 */
        CHECK_ERROR(_readMethod_nominationpools_create_V1(c, &method->basic.nominationpools_create_V1))
        break;
    case 10503: /* module 41 call 7 */
        CHECK_ERROR(_readMethod_nominationpools_nominate_V1(c, &method->basic.nominationpools_nominate_V1))
        break;
    case 10504: /* module 41 call 8 */
        CHECK_ERROR(_readMethod_nominationpools_set_state_V1(c, &method->basic.nominationpools_set_state_V1))
        break;
    case 10505: /* module 41 call 9 */
        CHECK_ERROR(_readMethod_nominationpools_set_metadata_V1(c, &method->basic.nominationpools_set_metadata_V1))
        break;
    case 10506: /* module 41 call 10 */
        CHECK_ERROR(_readMethod_nominationpools_set_configs_V1(c, &method->basic.nominationpools_set_configs_V1))
        break;
    case 10507: /* module 41 call 11 */
        CHECK_ERROR(_readMethod_nominationpools_update_roles_V1(c, &method->basic.nominationpools_update_roles_V1))
        break;
    case 10508: /* module 41 call 12 */
        CHECK_ERROR(_readMethod_nominationpools_chill_V1(c, &method->basic.nominationpools_chill_V1))
        break;
    case 13056: /* module 51 call 0 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_cooldown_V1(c, &method->basic.configuration_set_validation_upgrade_cooldown_V1))
        break;
    case 13057: /* module 51 call 1 */
        CHECK_ERROR(_readMethod_configuration_set_validation_upgrade_delay_V1(c, &method->basic.configuration_set_validation_upgrade_delay_V1))
        break;
    case 13058: /* module 51 call 2 */
        CHECK_ERROR(_readMethod_configuration_set_code_retention_period_V1(c, &method->basic.configuration_set_code_retention_period_V1))
        break;
    case 13059: /* module 51 call 3 */
        CHECK_ERROR(_readMethod_configuration_set_max_code_size_V1(c, &method->basic.configuration_set_max_code_size_V1))
        break;
    case 13060: /* module 51 call 4 */
        CHECK_ERROR(_readMethod_configuration_set_max_pov_size_V1(c, &method->basic.configuration_set_max_pov_size_V1))
        break;
    case 13061: /* module 51 call 5 */
        CHECK_ERROR(_readMethod_configuration_set_max_head_data_size_V1(c, &method->basic.configuration_set_max_head_data_size_V1))
        break;
    case 13062: /* module 51 call 6 */
        CHECK_ERROR(_readMethod_configuration_set_parathread_cores_V1(c, &method->basic.configuration_set_parathread_cores_V1))
        break;
    case 13063: /* module 51 call 7 */
        CHECK_ERROR(_readMethod_configuration_set_parathread_retries_V1(c, &method->basic.configuration_set_parathread_retries_V1))
        break;
    case 13064: /* module 51 call 8 */
        CHECK_ERROR(_readMethod_configuration_set_group_rotation_frequency_V1(c, &method->basic.configuration_set_group_rotation_frequency_V1))
        break;
    case 13065: /* module 51 call 9 */
        CHECK_ERROR(_readMethod_configuration_set_chain_availability_period_V1(c, &method->basic.configuration_set_chain_availability_period_V1))
        break;
    case 13066: /* module 51 call 10 */
        CHECK_ERROR(_readMethod_configuration_set_thread_availability_period_V1(c, &method->basic.configuration_set_thread_availability_period_V1))
        break;
    case 13067: /* module 51 call 11 */
        CHECK_ERROR(_readMethod_configuration_set_scheduling_lookahead_V1(c, &method->basic.configuration_set_scheduling_lookahead_V1))
        break;
    case 13068: /* module 51 call 12 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_per_core_V1(c, &method->basic.configuration_set_max_validators_per_core_V1))
        break;
    case 13069: /* module 51 call 13 */
        CHECK_ERROR(_readMethod_configuration_set_max_validators_V1(c, &method->basic.configuration_set_max_validators_V1))
        break;
    case 13070: /* module 51 call 14 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_period_V1(c, &method->basic.configuration_set_dispute_period_V1))
        break;
    case 13071: /* module 51 call 15 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_post_conclusion_acceptance_period_V1(c, &method->basic.configuration_set_dispute_post_conclusion_acceptance_period_V1))
        break;
    case 13072: /* module 51 call 16 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_max_spam_slots_V1(c, &method->basic.configuration_set_dispute_max_spam_slots_V1))
        break;
    case 13073: /* module 51 call 17 */
        CHECK_ERROR(_readMethod_configuration_set_dispute_conclusion_by_time_out_period_V1(c, &method->basic.configuration_set_dispute_conclusion_by_time_out_period_V1))
        break;
    case 13074: /* module 51 call 18 */
        CHECK_ERROR(_readMethod_configuration_set_no_show_slots_V1(c, &method->basic.configuration_set_no_show_slots_V1))
        break;
    case 13075: /* module 51 call 19 */
        CHECK_ERROR(_readMethod_configuration_set_n_delay_tranches_V1(c, &method->basic.configuration_set_n_delay_tranches_V1))
        break;
    case 13076: /* module 51 call 20 */
        CHECK_ERROR(_readMethod_configuration_set_zeroth_delay_tranche_width_V1(c, &method->basic.configuration_set_zeroth_delay_tranche_width_V1))
        break;
    case 13077: /* module 51 call 21 */
        CHECK_ERROR(_readMethod_configuration_set_needed_approvals_V1(c, &method->basic.configuration_set_needed_approvals_V1))
        break;
    case 13078: /* module 51 call 22 */
        CHECK_ERROR(_readMethod_configuration_set_relay_vrf_modulo_samples_V1(c, &method->basic.configuration_set_relay_vrf_modulo_samples_V1))
        break;
    case 13079: /* module 51 call 23 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_count_V1(c, &method->basic.configuration_set_max_upward_queue_count_V1))
        break;
    case 13080: /* module 51 call 24 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_queue_size_V1(c, &method->basic.configuration_set_max_upward_queue_size_V1))
        break;
    case 13081: /* module 51 call 25 */
        CHECK_ERROR(_readMethod_configuration_set_max_downward_message_size_V1(c, &method->basic.configuration_set_max_downward_message_size_V1))
        break;
    case 13082: /* module 51 call 26 */
        CHECK_ERROR(_readMethod_configuration_set_ump_service_total_weight_V1(c, &method->basic.configuration_set_ump_service_total_weight_V1))
        break;
    case 13083: /* module 51 call 27 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_size_V1(c, &method->basic.configuration_set_max_upward_message_size_V1))
        break;
    case 13084: /* module 51 call 28 */
        CHECK_ERROR(_readMethod_configuration_set_max_upward_message_num_per_candidate_V1(c, &method->basic.configuration_set_max_upward_message_num_per_candidate_V1))
        break;
    case 13085: /* module 51 call 29 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_open_request_ttl_V1(c, &method->basic.configuration_set_hrmp_open_request_ttl_V1))
        break;
    case 13086: /* module 51 call 30 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_sender_deposit_V1(c, &method->basic.configuration_set_hrmp_sender_deposit_V1))
        break;
    case 13087: /* module 51 call 31 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_recipient_deposit_V1(c, &method->basic.configuration_set_hrmp_recipient_deposit_V1))
        break;
    case 13088: /* module 51 call 32 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_capacity_V1(c, &method->basic.configuration_set_hrmp_channel_max_capacity_V1))
        break;
    case 13089: /* module 51 call 33 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_total_size_V1(c, &method->basic.configuration_set_hrmp_channel_max_total_size_V1))
        break;
    case 13090: /* module 51 call 34 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_inbound_channels_V1(c, &method->basic.configuration_set_hrmp_max_parachain_inbound_channels_V1))
        break;
    case 13091: /* module 51 call 35 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parathread_inbound_channels_V1(c, &method->basic.configuration_set_hrmp_max_parathread_inbound_channels_V1))
        break;
    case 13092: /* module 51 call 36 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_channel_max_message_size_V1(c, &method->basic.configuration_set_hrmp_channel_max_message_size_V1))
        break;
    case 13093: /* module 51 call 37 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parachain_outbound_channels_V1(c, &method->basic.configuration_set_hrmp_max_parachain_outbound_channels_V1))
        break;
    case 13094: /* module 51 call 38 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_parathread_outbound_channels_V1(c, &method->basic.configuration_set_hrmp_max_parathread_outbound_channels_V1))
        break;
    case 13095: /* module 51 call 39 */
        CHECK_ERROR(_readMethod_configuration_set_hrmp_max_message_num_per_candidate_V1(c, &method->basic.configuration_set_hrmp_max_message_num_per_candidate_V1))
        break;
    case 13096: /* module 51 call 40 */
        CHECK_ERROR(_readMethod_configuration_set_ump_max_individual_weight_V1(c, &method->basic.configuration_set_ump_max_individual_weight_V1))
        break;
    case 13097: /* module 51 call 41 */
        CHECK_ERROR(_readMethod_configuration_set_pvf_checking_enabled_V1(c, &method->basic.configuration_set_pvf_checking_enabled_V1))
        break;
    case 13098: /* module 51 call 42 */
        CHECK_ERROR(_readMethod_configuration_set_pvf_voting_ttl_V1(c, &method->basic.configuration_set_pvf_voting_ttl_V1))
        break;
    case 13099: /* module 51 call 43 */
        CHECK_ERROR(_readMethod_configuration_set_minimum_validation_upgrade_delay_V1(c, &method->basic.configuration_set_minimum_validation_upgrade_delay_V1))
        break;
    case 13100: /* module 51 call 44 */
        CHECK_ERROR(_readMethod_configuration_set_bypass_consistency_check_V1(c, &method->basic.configuration_set_bypass_consistency_check_V1))
        break;
    case 14592: /* module 57 call 0 */
        CHECK_ERROR(_readMethod_initializer_force_approve_V1(c, &method->basic.initializer_force_approve_V1))
        break;
    case 15364: /* module 60 call 4 */
        CHECK_ERROR(_readMethod_hrmp_force_process_hrmp_open_V1(c, &method->basic.hrmp_force_process_hrmp_open_V1))
        break;
    case 15365: /* module 60 call 5 */
        CHECK_ERROR(_readMethod_hrmp_force_process_hrmp_close_V1(c, &method->basic.hrmp_force_process_hrmp_close_V1))
        break;
    case 15872: /* module 62 call 0 */
        CHECK_ERROR(_readMethod_parasdisputes_force_unfreeze_V1(c, &method->basic.parasdisputes_force_unfreeze_V1))
        break;
    case 17925: /* module 70 call 5 */
        CHECK_ERROR(_readMethod_registrar_reserve_V1(c, &method->basic.registrar_reserve_V1))
        break;
    case 18432: /* module 72 call 0 */
        CHECK_ERROR(_readMethod_auctions_new_auction_V1(c, &method->basic.auctions_new_auction_V1))
        break;
    case 18433: /* module 72 call 1 */
        CHECK_ERROR(_readMethod_auctions_bid_V1(c, &method->basic.auctions_bid_V1))
        break;
    case 18434: /* module 72 call 2 */
        CHECK_ERROR(_readMethod_auctions_cancel_auction_V1(c, &method->basic.auctions_cancel_auction_V1))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 4:
        return STR_MO_BALANCES;
    case 6:
        return STR_MO_STAKING;
    case 8:
        return STR_MO_SESSION;
    case 24:
        return STR_MO_UTILITY;
    case 73:
        return STR_MO_CROWDLOAN;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_INDICES;
    case 10:
        return STR_MO_GRANDPA;
    case 13:
        return STR_MO_DEMOCRACY;
    case 14:
        return STR_MO_COUNCIL;
    case 15:
        return STR_MO_TECHNICALCOMMITTEE;
    case 16:
        return STR_MO_PHRAGMENELECTION;
    case 17:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 18:
        return STR_MO_TREASURY;
    case 19:
        return STR_MO_CLAIMS;
    case 25:
        return STR_MO_IDENTITY;
    case 26:
        return STR_MO_SOCIETY;
    case 27:
        return STR_MO_RECOVERY;
    case 28:
        return STR_MO_VESTING;
    case 30:
        return STR_MO_PROXY;
    case 31:
        return STR_MO_MULTISIG;
    case 32:
        return STR_MO_PREIMAGE;
    case 35:
        return STR_MO_BOUNTIES;
    case 40:
        return STR_MO_CHILDBOUNTIES;
    case 36:
        return STR_MO_TIPS;
    case 37:
        return STR_MO_ELECTIONPROVIDERMULTIPHASE;
    case 38:
        return STR_MO_GILT;
    case 39:
        return STR_MO_VOTERLIST;
    case 41:
        return STR_MO_NOMINATIONPOOLS;
    case 51:
        return STR_MO_CONFIGURATION;
    case 57:
        return STR_MO_INITIALIZER;
    case 60:
        return STR_MO_HRMP;
    case 62:
        return STR_MO_PARASDISPUTES;
    case 70:
        return STR_MO_REGISTRAR;
    case 72:
        return STR_MO_AUCTIONS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER;
    case 1026: /* module 4 call 2 */
        return STR_ME_FORCE_TRANSFER;
    case 1027: /* module 4 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 1028: /* module 4 call 4 */
        return STR_ME_TRANSFER_ALL;
    case 1536: /* module 6 call 0 */
        return STR_ME_BOND;
    case 1537: /* module 6 call 1 */
        return STR_ME_BOND_EXTRA;
    case 1538: /* module 6 call 2 */
        return STR_ME_UNBOND;
    case 1539: /* module 6 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 1540: /* module 6 call 4 */
        return STR_ME_VALIDATE;
    case 1541: /* module 6 call 5 */
        return STR_ME_NOMINATE;
    case 1542: /* module 6 call 6 */
        return STR_ME_CHILL;
    case 1543: /* module 6 call 7 */
        return STR_ME_SET_PAYEE;
    case 1544: /* module 6 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 1554: /* module 6 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 1555: /* module 6 call 19 */
        return STR_ME_REBOND;
    case 2048: /* module 8 call 0 */
        return STR_ME_SET_KEYS;
    case 2049: /* module 8 call 1 */
        return STR_ME_PURGE_KEYS;
    case 6144: /* module 24 call 0 */
        return STR_ME_BATCH;
    case 6146: /* module 24 call 2 */
        return STR_ME_BATCH_ALL;
    case 6148: /* module 24 call 4 */
        return STR_ME_FORCE_BATCH;
    case 18688: /* module 73 call 0 */
        return STR_ME_CREATE;
    case 18689: /* module 73 call 1 */
        return STR_ME_CONTRIBUTE;
    case 18690: /* module 73 call 2 */
        return STR_ME_WITHDRAW;
    case 18691: /* module 73 call 3 */
        return STR_ME_REFUND;
    case 18692: /* module 73 call 4 */
        return STR_ME_DISSOLVE;
    case 18693: /* module 73 call 5 */
        return STR_ME_EDIT;
    case 18694: /* module 73 call 6 */
        return STR_ME_ADD_MEMO;
    case 18695: /* module 73 call 7 */
        return STR_ME_POKE;
    case 18696: /* module 73 call 8 */
        return STR_ME_CONTRIBUTE_ALL;
    default:
        return _getMethod_Name_V1_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V1_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 8: /* module 0 call 8 */
        return STR_ME_REMARK_WITH_EVENT;
    case 512: /* module 2 call 0 */
        return STR_ME_SET;
    case 768: /* module 3 call 0 */
        return STR_ME_CLAIM;
    case 769: /* module 3 call 1 */
        return STR_ME_TRANSFER;
    case 770: /* module 3 call 2 */
        return STR_ME_FREE;
    case 771: /* module 3 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 772: /* module 3 call 4 */
        return STR_ME_FREEZE;
    case 1025: /* module 4 call 1 */
        return STR_ME_SET_BALANCE;
    case 1029: /* module 4 call 5 */
        return STR_ME_FORCE_UNRESERVE;
    case 1545: /* module 6 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 1546: /* module 6 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 1548: /* module 6 call 12 */
        return STR_ME_FORCE_NO_ERAS;
    case 1549: /* module 6 call 13 */
        return STR_ME_FORCE_NEW_ERA;
    case 1550: /* module 6 call 14 */
        return STR_ME_SET_INVULNERABLES;
    case 1551: /* module 6 call 15 */
        return STR_ME_FORCE_UNSTAKE;
    case 1552: /* module 6 call 16 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 1553: /* module 6 call 17 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 1556: /* module 6 call 20 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 1557: /* module 6 call 21 */
        return STR_ME_REAP_STASH;
    case 1558: /* module 6 call 22 */
        return STR_ME_KICK;
    case 1560: /* module 6 call 24 */
        return STR_ME_CHILL_OTHER;
    case 1561: /* module 6 call 25 */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
    case 2562: /* module 10 call 2 */
        return STR_ME_NOTE_STALLED;
    case 3328: /* module 13 call 0 */
        return STR_ME_PROPOSE;
    case 3329: /* module 13 call 1 */
        return STR_ME_SECOND;
    case 3330: /* module 13 call 2 */
        return STR_ME_VOTE;
    case 3331: /* module 13 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 3332: /* module 13 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 3333: /* module 13 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 3334: /* module 13 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 3335: /* module 13 call 7 */
        return STR_ME_FAST_TRACK;
    case 3336: /* module 13 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 3337: /* module 13 call 9 */
        return STR_ME_CANCEL_REFERENDUM;
    case 3338: /* module 13 call 10 */
        return STR_ME_CANCEL_QUEUED;
    case 3339: /* module 13 call 11 */
        return STR_ME_DELEGATE;
    case 3340: /* module 13 call 12 */
        return STR_ME_UNDELEGATE;
    case 3341: /* module 13 call 13 */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
    case 3342: /* module 13 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 3343: /* module 13 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 3344: /* module 13 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 3345: /* module 13 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 3346: /* module 13 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 3347: /* module 13 call 19 */
        return STR_ME_UNLOCK;
    case 3348: /* module 13 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 3349: /* module 13 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 3350: /* module 13 call 22 */
        return STR_ME_ENACT_PROPOSAL;
    case 3352: /* module 13 call 24 */
        return STR_ME_CANCEL_PROPOSAL;
    case 3584: /* module 14 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3585: /* module 14 call 1 */
        return STR_ME_EXECUTE;
    case 3586: /* module 14 call 2 */
        return STR_ME_PROPOSE;
    case 3587: /* module 14 call 3 */
        return STR_ME_VOTE;
    case 3588: /* module 14 call 4 */
        return STR_ME_CLOSE;
    case 3589: /* module 14 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3840: /* module 15 call 0 */
        return STR_ME_SET_MEMBERS;
    case 3841: /* module 15 call 1 */
        return STR_ME_EXECUTE;
    case 3842: /* module 15 call 2 */
        return STR_ME_PROPOSE;
    case 3843: /* module 15 call 3 */
        return STR_ME_VOTE;
    case 3844: /* module 15 call 4 */
        return STR_ME_CLOSE;
    case 3845: /* module 15 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 4096: /* module 16 call 0 */
        return STR_ME_VOTE;
    case 4097: /* module 16 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 4098: /* module 16 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 4100: /* module 16 call 4 */
        return STR_ME_REMOVE_MEMBER;
    case 4101: /* module 16 call 5 */
        return STR_ME_CLEAN_DEFUNCT_VOTERS;
    case 4352: /* module 17 call 0 */
        return STR_ME_ADD_MEMBER;
    case 4353: /* module 17 call 1 */
        return STR_ME_REMOVE_MEMBER;
    case 4354: /* module 17 call 2 */
        return STR_ME_SWAP_MEMBER;
    case 4355: /* module 17 call 3 */
        return STR_ME_RESET_MEMBERS;
    case 4356: /* module 17 call 4 */
        return STR_ME_CHANGE_KEY;
    case 4357: /* module 17 call 5 */
        return STR_ME_SET_PRIME;
    case 4358: /* module 17 call 6 */
        return STR_ME_CLEAR_PRIME;
    case 4608: /* module 18 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4609: /* module 18 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4610: /* module 18 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 4611: /* module 18 call 3 */
        return STR_ME_SPEND;
    case 4612: /* module 18 call 4 */
        return STR_ME_REMOVE_APPROVAL;
    case 4864: /* module 19 call 0 */
        return STR_ME_CLAIM;
    case 4866: /* module 19 call 2 */
        return STR_ME_CLAIM_ATTEST;
    case 4867: /* module 19 call 3 */
        return STR_ME_ATTEST;
    case 4868: /* module 19 call 4 */
        return STR_ME_MOVE_CLAIM;
    case 6400: /* module 25 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 6403: /* module 25 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 6404: /* module 25 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 6405: /* module 25 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 6406: /* module 25 call 6 */
        return STR_ME_SET_FEE;
    case 6407: /* module 25 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 6410: /* module 25 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 6413: /* module 25 call 13 */
        return STR_ME_REMOVE_SUB;
    case 6414: /* module 25 call 14 */
        return STR_ME_QUIT_SUB;
    case 6656: /* module 26 call 0 */
        return STR_ME_BID;
    case 6657: /* module 26 call 1 */
        return STR_ME_UNBID;
    case 6658: /* module 26 call 2 */
        return STR_ME_VOUCH;
    case 6659: /* module 26 call 3 */
        return STR_ME_UNVOUCH;
    case 6660: /* module 26 call 4 */
        return STR_ME_VOTE;
    case 6661: /* module 26 call 5 */
        return STR_ME_DEFENDER_VOTE;
    case 6662: /* module 26 call 6 */
        return STR_ME_PAYOUT;
    case 6663: /* module 26 call 7 */
        return STR_ME_FOUND;
    case 6664: /* module 26 call 8 */
        return STR_ME_UNFOUND;
    case 6665: /* module 26 call 9 */
        return STR_ME_JUDGE_SUSPENDED_MEMBER;
    case 6667: /* module 26 call 11 */
        return STR_ME_SET_MAX_MEMBERS;
    case 6913: /* module 27 call 1 */
        return STR_ME_SET_RECOVERED;
    case 6915: /* module 27 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6916: /* module 27 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6917: /* module 27 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6918: /* module 27 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6919: /* module 27 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6920: /* module 27 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 7168: /* module 28 call 0 */
        return STR_ME_VEST;
    case 7169: /* module 28 call 1 */
        return STR_ME_VEST_OTHER;
    case 7170: /* module 28 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 7171: /* module 28 call 3 */
        return STR_ME_FORCE_VESTED_TRANSFER;
    case 7172: /* module 28 call 4 */
        return STR_ME_MERGE_SCHEDULES;
    case 7680: /* module 30 call 0 */
        return STR_ME_PROXY;
    case 7681: /* module 30 call 1 */
        return STR_ME_ADD_PROXY;
    case 7682: /* module 30 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7683: /* module 30 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7684: /* module 30 call 4 */
        return STR_ME_ANONYMOUS;
    case 7685: /* module 30 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 7689: /* module 30 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7936: /* module 31 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7937: /* module 31 call 1 */
        return STR_ME_AS_MULTI;
    case 7938: /* module 31 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7939: /* module 31 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
    case 8192: /* module 32 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 8193: /* module 32 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 8194: /* module 32 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 8195: /* module 32 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 8960: /* module 35 call 0 */
        return STR_ME_PROPOSE_BOUNTY;
    case 8961: /* module 35 call 1 */
        return STR_ME_APPROVE_BOUNTY;
    case 8962: /* module 35 call 2 */
        return STR_ME_PROPOSE_CURATOR;
    case 8963: /* module 35 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 8964: /* module 35 call 4 */
        return STR_ME_ACCEPT_CURATOR;
    case 8965: /* module 35 call 5 */
        return STR_ME_AWARD_BOUNTY;
    case 8966: /* module 35 call 6 */
        return STR_ME_CLAIM_BOUNTY;
    case 8967: /* module 35 call 7 */
        return STR_ME_CLOSE_BOUNTY;
    case 8968: /* module 35 call 8 */
        return STR_ME_EXTEND_BOUNTY_EXPIRY;
    case 10240: /* module 40 call 0 */
        return STR_ME_ADD_CHILD_BOUNTY;
    case 10241: /* module 40 call 1 */
        return STR_ME_PROPOSE_CURATOR;
    case 10242: /* module 40 call 2 */
        return STR_ME_ACCEPT_CURATOR;
    case 10243: /* module 40 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 10244: /* module 40 call 4 */
        return STR_ME_AWARD_CHILD_BOUNTY;
    case 10245: /* module 40 call 5 */
        return STR_ME_CLAIM_CHILD_BOUNTY;
    case 10246: /* module 40 call 6 */
        return STR_ME_CLOSE_CHILD_BOUNTY;
    case 9216: /* module 36 call 0 */
        return STR_ME_REPORT_AWESOME;
    case 9217: /* module 36 call 1 */
        return STR_ME_RETRACT_TIP;
    case 9218: /* module 36 call 2 */
        return STR_ME_TIP_NEW;
    case 9219: /* module 36 call 3 */
        return STR_ME_TIP;
    case 9220: /* module 36 call 4 */
        return STR_ME_CLOSE_TIP;
    case 9221: /* module 36 call 5 */
        return STR_ME_SLASH_TIP;
    case 9476: /* module 37 call 4 */
        return STR_ME_GOVERNANCE_FALLBACK;
    case 9728: /* module 38 call 0 */
        return STR_ME_PLACE_BID;
    case 9729: /* module 38 call 1 */
        return STR_ME_RETRACT_BID;
    case 9730: /* module 38 call 2 */
        return STR_ME_SET_TARGET;
    case 9731: /* module 38 call 3 */
        return STR_ME_THAW;
    case 9984: /* module 39 call 0 */
        return STR_ME_REBAG;
    case 9985: /* module 39 call 1 */
        return STR_ME_PUT_IN_FRONT_OF;
    case 10496: /* module 41 call 0 */
        return STR_ME_JOIN;
    case 10497: /* module 41 call 1 */
        return STR_ME_BOND_EXTRA;
    case 10498: /* module 41 call 2 */
        return STR_ME_CLAIM_PAYOUT;
    case 10499: /* module 41 call 3 */
        return STR_ME_UNBOND;
    case 10500: /* module 41 call 4 */
        return STR_ME_POOL_WITHDRAW_UNBONDED;
    case 10501: /* module 41 call 5 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 10502: /* module 41 call 6 */
        return STR_ME_CREATE;
    case 10503: /* module 41 call 7 */
        return STR_ME_NOMINATE;
    case 10504: /* module 41 call 8 */
        return STR_ME_SET_STATE;
    case 10505: /* module 41 call 9 */
        return STR_ME_SET_METADATA;
    case 10506: /* module 41 call 10 */
        return STR_ME_SET_CONFIGS;
    case 10507: /* module 41 call 11 */
        return STR_ME_UPDATE_ROLES;
    case 10508: /* module 41 call 12 */
        return STR_ME_CHILL;
    case 13056: /* module 51 call 0 */
        return STR_ME_SET_VALIDATION_UPGRADE_COOLDOWN;
    case 13057: /* module 51 call 1 */
        return STR_ME_SET_VALIDATION_UPGRADE_DELAY;
    case 13058: /* module 51 call 2 */
        return STR_ME_SET_CODE_RETENTION_PERIOD;
    case 13059: /* module 51 call 3 */
        return STR_ME_SET_MAX_CODE_SIZE;
    case 13060: /* module 51 call 4 */
        return STR_ME_SET_MAX_POV_SIZE;
    case 13061: /* module 51 call 5 */
        return STR_ME_SET_MAX_HEAD_DATA_SIZE;
    case 13062: /* module 51 call 6 */
        return STR_ME_SET_PARATHREAD_CORES;
    case 13063: /* module 51 call 7 */
        return STR_ME_SET_PARATHREAD_RETRIES;
    case 13064: /* module 51 call 8 */
        return STR_ME_SET_GROUP_ROTATION_FREQUENCY;
    case 13065: /* module 51 call 9 */
        return STR_ME_SET_CHAIN_AVAILABILITY_PERIOD;
    case 13066: /* module 51 call 10 */
        return STR_ME_SET_THREAD_AVAILABILITY_PERIOD;
    case 13067: /* module 51 call 11 */
        return STR_ME_SET_SCHEDULING_LOOKAHEAD;
    case 13068: /* module 51 call 12 */
        return STR_ME_SET_MAX_VALIDATORS_PER_CORE;
    case 13069: /* module 51 call 13 */
        return STR_ME_SET_MAX_VALIDATORS;
    case 13070: /* module 51 call 14 */
        return STR_ME_SET_DISPUTE_PERIOD;
    case 13071: /* module 51 call 15 */
        return STR_ME_SET_DISPUTE_POST_CONCLUSION_ACCEPTANCE_PERIOD;
    case 13072: /* module 51 call 16 */
        return STR_ME_SET_DISPUTE_MAX_SPAM_SLOTS;
    case 13073: /* module 51 call 17 */
        return STR_ME_SET_DISPUTE_CONCLUSION_BY_TIME_OUT_PERIOD;
    case 13074: /* module 51 call 18 */
        return STR_ME_SET_NO_SHOW_SLOTS;
    case 13075: /* module 51 call 19 */
        return STR_ME_SET_N_DELAY_TRANCHES;
    case 13076: /* module 51 call 20 */
        return STR_ME_SET_ZEROTH_DELAY_TRANCHE_WIDTH;
    case 13077: /* module 51 call 21 */
        return STR_ME_SET_NEEDED_APPROVALS;
    case 13078: /* module 51 call 22 */
        return STR_ME_SET_RELAY_VRF_MODULO_SAMPLES;
    case 13079: /* module 51 call 23 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_COUNT;
    case 13080: /* module 51 call 24 */
        return STR_ME_SET_MAX_UPWARD_QUEUE_SIZE;
    case 13081: /* module 51 call 25 */
        return STR_ME_SET_MAX_DOWNWARD_MESSAGE_SIZE;
    case 13082: /* module 51 call 26 */
        return STR_ME_SET_UMP_SERVICE_TOTAL_WEIGHT;
    case 13083: /* module 51 call 27 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_SIZE;
    case 13084: /* module 51 call 28 */
        return STR_ME_SET_MAX_UPWARD_MESSAGE_NUM_PER_CANDIDATE;
    case 13085: /* module 51 call 29 */
        return STR_ME_SET_HRMP_OPEN_REQUEST_TTL;
    case 13086: /* module 51 call 30 */
        return STR_ME_SET_HRMP_SENDER_DEPOSIT;
    case 13087: /* module 51 call 31 */
        return STR_ME_SET_HRMP_RECIPIENT_DEPOSIT;
    case 13088: /* module 51 call 32 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_CAPACITY;
    case 13089: /* module 51 call 33 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_TOTAL_SIZE;
    case 13090: /* module 51 call 34 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_INBOUND_CHANNELS;
    case 13091: /* module 51 call 35 */
        return STR_ME_SET_HRMP_MAX_PARATHREAD_INBOUND_CHANNELS;
    case 13092: /* module 51 call 36 */
        return STR_ME_SET_HRMP_CHANNEL_MAX_MESSAGE_SIZE;
    case 13093: /* module 51 call 37 */
        return STR_ME_SET_HRMP_MAX_PARACHAIN_OUTBOUND_CHANNELS;
    case 13094: /* module 51 call 38 */
        return STR_ME_SET_HRMP_MAX_PARATHREAD_OUTBOUND_CHANNELS;
    case 13095: /* module 51 call 39 */
        return STR_ME_SET_HRMP_MAX_MESSAGE_NUM_PER_CANDIDATE;
    case 13096: /* module 51 call 40 */
        return STR_ME_SET_UMP_MAX_INDIVIDUAL_WEIGHT;
    case 13097: /* module 51 call 41 */
        return STR_ME_SET_PVF_CHECKING_ENABLED;
    case 13098: /* module 51 call 42 */
        return STR_ME_SET_PVF_VOTING_TTL;
    case 13099: /* module 51 call 43 */
        return STR_ME_SET_MINIMUM_VALIDATION_UPGRADE_DELAY;
    case 13100: /* module 51 call 44 */
        return STR_ME_SET_BYPASS_CONSISTENCY_CHECK;
    case 14592: /* module 57 call 0 */
        return STR_ME_FORCE_APPROVE;
    case 15364: /* module 60 call 4 */
        return STR_ME_FORCE_PROCESS_HRMP_OPEN;
    case 15365: /* module 60 call 5 */
        return STR_ME_FORCE_PROCESS_HRMP_CLOSE;
    case 15872: /* module 62 call 0 */
        return STR_ME_FORCE_UNFREEZE;
    case 17925: /* module 70 call 5 */
        return STR_ME_RESERVE;
    case 18432: /* module 72 call 0 */
        return STR_ME_NEW_AUCTION;
    case 18433: /* module 72 call 1 */
        return STR_ME_BID;
    case 18434: /* module 72 call 2 */
        return STR_ME_CANCEL_AUCTION;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1026: /* module 4 call 2 */
        return 3;
    case 1027: /* module 4 call 3 */
        return 2;
    case 1028: /* module 4 call 4 */
        return 2;
    case 1536: /* module 6 call 0 */
        return 3;
    case 1537: /* module 6 call 1 */
        return 1;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 1;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1541: /* module 6 call 5 */
        return 1;
    case 1542: /* module 6 call 6 */
        return 0;
    case 1543: /* module 6 call 7 */
        return 1;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1554: /* module 6 call 18 */
        return 2;
    case 1555: /* module 6 call 19 */
        return 1;
    case 2048: /* module 8 call 0 */
        return 2;
    case 2049: /* module 8 call 1 */
        return 0;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 1;
    case 18688: /* module 73 call 0 */
        return 6;
    case 18689: /* module 73 call 1 */
        return 3;
    case 18690: /* module 73 call 2 */
        return 2;
    case 18691: /* module 73 call 3 */
        return 1;
    case 18692: /* module 73 call 4 */
        return 1;
    case 18693: /* module 73 call 5 */
        return 6;
    case 18694: /* module 73 call 6 */
        return 2;
    case 18695: /* module 73 call 7 */
        return 1;
    case 18696: /* module 73 call 8 */
        return 2;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
        return 1;
    case 8: /* module 0 call 8 */
        return 1;
    case 512: /* module 2 call 0 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 769: /* module 3 call 1 */
        return 2;
    case 770: /* module 3 call 2 */
        return 1;
    case 771: /* module 3 call 3 */
        return 3;
    case 772: /* module 3 call 4 */
        return 1;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 2;
    case 1545: /* module 6 call 9 */
        return 1;
    case 1546: /* module 6 call 10 */
        return 1;
    case 1548: /* module 6 call 12 */
        return 0;
    case 1549: /* module 6 call 13 */
        return 0;
    case 1550: /* module 6 call 14 */
        return 1;
    case 1551: /* module 6 call 15 */
        return 2;
    case 1552: /* module 6 call 16 */
        return 0;
    case 1553: /* module 6 call 17 */
        return 2;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 2;
    case 1558: /* module 6 call 22 */
        return 1;
    case 1560: /* module 6 call 24 */
        return 1;
    case 1561: /* module 6 call 25 */
        return 1;
    case 2562: /* module 10 call 2 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 2;
    case 3330: /* module 13 call 2 */
        return 2;
    case 3331: /* module 13 call 3 */
        return 1;
    case 3332: /* module 13 call 4 */
        return 1;
    case 3333: /* module 13 call 5 */
        return 1;
    case 3334: /* module 13 call 6 */
        return 1;
    case 3335: /* module 13 call 7 */
        return 3;
    case 3336: /* module 13 call 8 */
        return 1;
    case 3337: /* module 13 call 9 */
        return 1;
    case 3338: /* module 13 call 10 */
        return 1;
    case 3339: /* module 13 call 11 */
        return 3;
    case 3340: /* module 13 call 12 */
        return 0;
    case 3341: /* module 13 call 13 */
        return 0;
    case 3342: /* module 13 call 14 */
        return 1;
    case 3343: /* module 13 call 15 */
        return 1;
    case 3344: /* module 13 call 16 */
        return 1;
    case 3345: /* module 13 call 17 */
        return 1;
    case 3346: /* module 13 call 18 */
        return 2;
    case 3347: /* module 13 call 19 */
        return 1;
    case 3348: /* module 13 call 20 */
        return 1;
    case 3349: /* module 13 call 21 */
        return 2;
    case 3350: /* module 13 call 22 */
        return 2;
    case 3352: /* module 13 call 24 */
        return 1;
    case 3584: /* module 14 call 0 */
        return 3;
    case 3585: /* module 14 call 1 */
        return 2;
    case 3586: /* module 14 call 2 */
        return 3;
    case 3587: /* module 14 call 3 */
        return 3;
    case 3588: /* module 14 call 4 */
        return 4;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 3;
    case 3841: /* module 15 call 1 */
        return 2;
    case 3842: /* module 15 call 2 */
        return 3;
    case 3843: /* module 15 call 3 */
        return 3;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 2;
    case 4097: /* module 16 call 1 */
        return 0;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4100: /* module 16 call 4 */
        return 3;
    case 4101: /* module 16 call 5 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 2;
    case 4355: /* module 17 call 3 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 1;
    case 4357: /* module 17 call 5 */
        return 1;
    case 4358: /* module 17 call 6 */
        return 0;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4609: /* module 18 call 1 */
        return 1;
    case 4610: /* module 18 call 2 */
        return 1;
    case 4611: /* module 18 call 3 */
        return 2;
    case 4612: /* module 18 call 4 */
        return 1;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4866: /* module 19 call 2 */
        return 3;
    case 4867: /* module 19 call 3 */
        return 1;
    case 4868: /* module 19 call 4 */
        return 3;
    case 6400: /* module 25 call 0 */
        return 1;
    case 6403: /* module 25 call 3 */
        return 0;
    case 6404: /* module 25 call 4 */
        return 2;
    case 6405: /* module 25 call 5 */
        return 1;
    case 6406: /* module 25 call 6 */
        return 2;
    case 6407: /* module 25 call 7 */
        return 2;
    case 6410: /* module 25 call 10 */
        return 1;
    case 6413: /* module 25 call 13 */
        return 1;
    case 6414: /* module 25 call 14 */
        return 0;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 3;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 2;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 0;
    case 6663: /* module 26 call 7 */
        return 3;
    case 6664: /* module 26 call 8 */
        return 0;
    case 6665: /* module 26 call 9 */
        return 2;
    case 6667: /* module 26 call 11 */
        return 1;
    case 6913: /* module 27 call 1 */
        return 2;
    case 6915: /* module 27 call 3 */
        return 1;
    case 6916: /* module 27 call 4 */
        return 2;
    case 6917: /* module 27 call 5 */
        return 1;
    case 6918: /* module 27 call 6 */
        return 1;
    case 6919: /* module 27 call 7 */
        return 0;
    case 6920: /* module 27 call 8 */
        return 1;
    case 7168: /* module 28 call 0 */
        return 0;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 2;
    case 7171: /* module 28 call 3 */
        return 3;
    case 7172: /* module 28 call 4 */
        return 2;
    case 7680: /* module 30 call 0 */
        return 3;
    case 7681: /* module 30 call 1 */
        return 3;
    case 7682: /* module 30 call 2 */
        return 3;
    case 7683: /* module 30 call 3 */
        return 0;
    case 7684: /* module 30 call 4 */
        return 3;
    case 7685: /* module 30 call 5 */
        return 5;
    case 7689: /* module 30 call 9 */
        return 4;
    case 7936: /* module 31 call 0 */
        return 2;
    case 7937: /* module 31 call 1 */
        return 6;
    case 7938: /* module 31 call 2 */
        return 5;
    case 7939: /* module 31 call 3 */
        return 4;
    case 8192: /* module 32 call 0 */
        return 1;
    case 8193: /* module 32 call 1 */
        return 1;
    case 8194: /* module 32 call 2 */
        return 1;
    case 8195: /* module 32 call 3 */
        return 1;
    case 8960: /* module 35 call 0 */
        return 2;
    case 8961: /* module 35 call 1 */
        return 1;
    case 8962: /* module 35 call 2 */
        return 3;
    case 8963: /* module 35 call 3 */
        return 1;
    case 8964: /* module 35 call 4 */
        return 1;
    case 8965: /* module 35 call 5 */
        return 2;
    case 8966: /* module 35 call 6 */
        return 1;
    case 8967: /* module 35 call 7 */
        return 1;
    case 8968: /* module 35 call 8 */
        return 2;
    case 10240: /* module 40 call 0 */
        return 3;
    case 10241: /* module 40 call 1 */
        return 4;
    case 10242: /* module 40 call 2 */
        return 2;
    case 10243: /* module 40 call 3 */
        return 2;
    case 10244: /* module 40 call 4 */
        return 3;
    case 10245: /* module 40 call 5 */
        return 2;
    case 10246: /* module 40 call 6 */
        return 2;
    case 9216: /* module 36 call 0 */
        return 2;
    case 9217: /* module 36 call 1 */
        return 1;
    case 9218: /* module 36 call 2 */
        return 3;
    case 9219: /* module 36 call 3 */
        return 2;
    case 9220: /* module 36 call 4 */
        return 1;
    case 9221: /* module 36 call 5 */
        return 1;
    case 9476: /* module 37 call 4 */
        return 2;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 2;
    case 9730: /* module 38 call 2 */
        return 1;
    case 9731: /* module 38 call 3 */
        return 1;
    case 9984: /* module 39 call 0 */
        return 1;
    case 9985: /* module 39 call 1 */
        return 1;
    case 10496: /* module 41 call 0 */
        return 2;
    case 10497: /* module 41 call 1 */
        return 1;
    case 10498: /* module 41 call 2 */
        return 0;
    case 10499: /* module 41 call 3 */
        return 2;
    case 10500: /* module 41 call 4 */
        return 2;
    case 10501: /* module 41 call 5 */
        return 2;
    case 10502: /* module 41 call 6 */
        return 4;
    case 10503: /* module 41 call 7 */
        return 2;
    case 10504: /* module 41 call 8 */
        return 2;
    case 10505: /* module 41 call 9 */
        return 2;
    case 10506: /* module 41 call 10 */
        return 5;
    case 10507: /* module 41 call 11 */
        return 4;
    case 10508: /* module 41 call 12 */
        return 1;
    case 13056: /* module 51 call 0 */
        return 1;
    case 13057: /* module 51 call 1 */
        return 1;
    case 13058: /* module 51 call 2 */
        return 1;
    case 13059: /* module 51 call 3 */
        return 1;
    case 13060: /* module 51 call 4 */
        return 1;
    case 13061: /* module 51 call 5 */
        return 1;
    case 13062: /* module 51 call 6 */
        return 1;
    case 13063: /* module 51 call 7 */
        return 1;
    case 13064: /* module 51 call 8 */
        return 1;
    case 13065: /* module 51 call 9 */
        return 1;
    case 13066: /* module 51 call 10 */
        return 1;
    case 13067: /* module 51 call 11 */
        return 1;
    case 13068: /* module 51 call 12 */
        return 1;
    case 13069: /* module 51 call 13 */
        return 1;
    case 13070: /* module 51 call 14 */
        return 1;
    case 13071: /* module 51 call 15 */
        return 1;
    case 13072: /* module 51 call 16 */
        return 1;
    case 13073: /* module 51 call 17 */
        return 1;
    case 13074: /* module 51 call 18 */
        return 1;
    case 13075: /* module 51 call 19 */
        return 1;
    case 13076: /* module 51 call 20 */
        return 1;
    case 13077: /* module 51 call 21 */
        return 1;
    case 13078: /* module 51 call 22 */
        return 1;
    case 13079: /* module 51 call 23 */
        return 1;
    case 13080: /* module 51 call 24 */
        return 1;
    case 13081: /* module 51 call 25 */
        return 1;
    case 13082: /* module 51 call 26 */
        return 1;
    case 13083: /* module 51 call 27 */
        return 1;
    case 13084: /* module 51 call 28 */
        return 1;
    case 13085: /* module 51 call 29 */
        return 1;
    case 13086: /* module 51 call 30 */
        return 1;
    case 13087: /* module 51 call 31 */
        return 1;
    case 13088: /* module 51 call 32 */
        return 1;
    case 13089: /* module 51 call 33 */
        return 1;
    case 13090: /* module 51 call 34 */
        return 1;
    case 13091: /* module 51 call 35 */
        return 1;
    case 13092: /* module 51 call 36 */
        return 1;
    case 13093: /* module 51 call 37 */
        return 1;
    case 13094: /* module 51 call 38 */
        return 1;
    case 13095: /* module 51 call 39 */
        return 1;
    case 13096: /* module 51 call 40 */
        return 1;
    case 13097: /* module 51 call 41 */
        return 1;
    case 13098: /* module 51 call 42 */
        return 1;
    case 13099: /* module 51 call 43 */
        return 1;
    case 13100: /* module 51 call 44 */
        return 1;
    case 14592: /* module 57 call 0 */
        return 1;
    case 15364: /* module 60 call 4 */
        return 1;
    case 15365: /* module 60 call 5 */
        return 1;
    case 15872: /* module 62 call 0 */
        return 0;
    case 17925: /* module 70 call 5 */
        return 0;
    case 18432: /* module 72 call 0 */
        return 2;
    case 18433: /* module 72 call 1 */
        return 5;
    case 18434: /* module 72 call 2 */
        return 0;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_signature;
        default:
            return NULL;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_cap;
        case 2:
            return STR_IT_first_period;
        case 3:
            return STR_IT_last_period;
        case 4:
            return STR_IT_end;
        case 5:
            return STR_IT_verifier;
        default:
            return NULL;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18696: /* module 73 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_signature;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3334: /* module 13 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3335: /* module 13 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 3336: /* module 13 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3337: /* module 13 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 3338: /* module 13 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
    case 3339: /* module 13 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 3340: /* module 13 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3341: /* module 13 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3342: /* module 13 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3343: /* module 13 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3344: /* module 13 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3345: /* module 13 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 3346: /* module 13 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 3347: /* module 13 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 3348: /* module 13 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3349: /* module 13 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3350: /* module 13 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 3352: /* module 13 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_members;
        case 1:
            return STR_IT_prime;
        case 2:
            return STR_IT_old_count;
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_slash_bond;
        case 2:
            return STR_IT_rerun_election;
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_voters;
        case 1:
            return STR_IT_num_defunct;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_ethereum_signature;
        case 2:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_statement;
        default:
            return NULL;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_old;
        case 1:
            return STR_IT_new_;
        case 2:
            return STR_IT_maybe_preclaim;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 6414: /* module 25 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pos;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_tip;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pos;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate;
        case 1:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_founder;
        case 1:
            return STR_IT_max_members;
        case 2:
            return STR_IT_rules;
        default:
            return NULL;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_forgive;
        default:
            return NULL;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_target;
        case 2:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule1_index;
        case 1:
            return STR_IT_schedule2_index;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_curator;
        case 2:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        default:
            return NULL;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bounty_id;
        case 1:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        case 2:
            return STR_IT_curator;
        case 3:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        case 2:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reason;
        case 1:
            return STR_IT_who;
        case 2:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        case 1:
            return STR_IT_tip_value;
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_max_voters;
        case 1:
            return STR_IT_maybe_max_targets;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dislocated;
        default:
            return NULL;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lighter;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_extra;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member_account;
        case 1:
            return STR_IT_unbonding_points;
        default:
            return NULL;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_member_account;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_root;
        case 2:
            return STR_IT_nominator;
        case 3:
            return STR_IT_state_toggler;
        default:
            return NULL;
        }
    case 10503: /* module 41 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 10504: /* module 41 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_state;
        default:
            return NULL;
        }
    case 10505: /* module 41 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_metadata;
        default:
            return NULL;
        }
    case 10506: /* module 41 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_min_join_bond;
        case 1:
            return STR_IT_min_create_bond;
        case 2:
            return STR_IT_max_pools;
        case 3:
            return STR_IT_max_members;
        case 4:
            return STR_IT_max_members_per_pool;
        default:
            return NULL;
        }
    case 10507: /* module 41 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        case 1:
            return STR_IT_new_root;
        case 2:
            return STR_IT_new_nominator;
        case 3:
            return STR_IT_new_state_toggler;
        default:
            return NULL;
        }
    case 10508: /* module 41 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool_id;
        default:
            return NULL;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13082: /* module 51 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13091: /* module 51 call 35 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13094: /* module 51 call 38 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13096: /* module 51 call 40 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13097: /* module 51 call 41 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_up_to;
        default:
            return NULL;
        }
    case 15364: /* module 60 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_channels;
        default:
            return NULL;
        }
    case 15365: /* module 60 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_channels;
        default:
            return NULL;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_duration;
        case 1:
            return STR_IT_lease_period_index;
        default:
            return NULL;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_para;
        case 1:
            return STR_IT_auction_index;
        case 2:
            return STR_IT_first_slot;
        case 3:
            return STR_IT_last_slot;
        case 4:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V1 - source */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_force_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_force_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_transfer_all_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.balances_transfer_all_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_all_V1 - keep_alive */;
            return _toStringbool(
                &m->basic.balances_transfer_all_V1.keep_alive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_bond_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_payout_stakers_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_payout_stakers_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V1 - keys */;
            return _toStringKeys_V1(
                &m->basic.session_set_keys_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V1 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18688: /* module 73 call 0 */
        switch (itemIdx) {
        case 0: /* crowdloan_create_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_create_V1 - cap */;
            return _toStringCompactu128(
                &m->basic.crowdloan_create_V1.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_create_V1 - first_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V1.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_create_V1 - last_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V1.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_create_V1 - end */;
            return _toStringCompactu32(
                &m->basic.crowdloan_create_V1.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_create_V1 - verifier */;
            return _toStringOptionMultiSigner_V1(
                &m->basic.crowdloan_create_V1.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18689: /* module 73 call 1 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_contribute_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.crowdloan_contribute_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_contribute_V1 - signature */;
            return _toStringOptionMultiSignature_V1(
                &m->basic.crowdloan_contribute_V1.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18690: /* module 73 call 2 */
        switch (itemIdx) {
        case 0: /* crowdloan_withdraw_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.crowdloan_withdraw_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_withdraw_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_withdraw_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18691: /* module 73 call 3 */
        switch (itemIdx) {
        case 0: /* crowdloan_refund_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_refund_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18692: /* module 73 call 4 */
        switch (itemIdx) {
        case 0: /* crowdloan_dissolve_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_dissolve_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18693: /* module 73 call 5 */
        switch (itemIdx) {
        case 0: /* crowdloan_edit_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_edit_V1 - cap */;
            return _toStringCompactu128(
                &m->basic.crowdloan_edit_V1.cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* crowdloan_edit_V1 - first_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V1.first_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* crowdloan_edit_V1 - last_period */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V1.last_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* crowdloan_edit_V1 - end */;
            return _toStringCompactu32(
                &m->basic.crowdloan_edit_V1.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* crowdloan_edit_V1 - verifier */;
            return _toStringOptionMultiSigner_V1(
                &m->basic.crowdloan_edit_V1.verifier,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18694: /* module 73 call 6 */
        switch (itemIdx) {
        case 0: /* crowdloan_add_memo_V1 - index */;
            return _toStringParaId_V1(
                &m->basic.crowdloan_add_memo_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_add_memo_V1 - memo */;
            return _toStringVecu8(
                &m->basic.crowdloan_add_memo_V1.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18695: /* module 73 call 7 */
        switch (itemIdx) {
        case 0: /* crowdloan_poke_V1 - index */;
            return _toStringParaId_V1(
                &m->basic.crowdloan_poke_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18696: /* module 73 call 8 */
        switch (itemIdx) {
        case 0: /* crowdloan_contribute_all_V1 - index */;
            return _toStringCompactu32(
                &m->basic.crowdloan_contribute_all_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* crowdloan_contribute_all_V1 - signature */;
            return _toStringOptionMultiSignature_V1(
                &m->basic.crowdloan_contribute_all_V1.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - ratio */;
            return _toStringPerbill_V1(
                &m->nested.system_fill_block_V1.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V1 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V1.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_claim_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.indices_transfer_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_transfer_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_free_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.indices_force_transfer_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_force_transfer_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V1 - freeze */;
            return _toStringbool(
                &m->basic.indices_force_transfer_V1.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V1 - index */;
            return _toStringAccountIndex_V1(
                &m->basic.indices_freeze_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_set_balance_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V1 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V1 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V1.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_force_unreserve_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.balances_force_unreserve_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_unreserve_V1 - amount */;
            return _toStringBalance(
                &m->basic.balances_force_unreserve_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V1 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V1 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V1.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V1 - invulnerables */;
            return _toStringVecAccountId_V1(
                &m->basic.staking_set_invulnerables_V1.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_unstake_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_force_unstake_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_cancel_deferred_slash_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V1 - slash_indices */;
            return _toStringVecu32(
                &m->basic.staking_cancel_deferred_slash_V1.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V1 - new_history_depth */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V1 - era_items_deleted */;
            return _toStringCompactu32(
                &m->basic.staking_set_history_depth_V1.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V1 - stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_reap_stash_V1.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_reap_stash_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* staking_kick_V1 - who */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_kick_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V1 - controller */;
            return _toStringAccountId_V1(
                &m->basic.staking_chill_other_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1561: /* module 6 call 25 */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_apply_min_commission_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V1 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->basic.grandpa_note_stalled_V1.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.democracy_propose_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V1 - proposal */;
            return _toStringCompactu32(
                &m->nested.democracy_second_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V1 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->nested.democracy_second_V1.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V1 - ref_index */;
            return _toStringCompactu32(
                &m->nested.democracy_vote_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V1 - vote */;
            return _toStringAccountVote_V1(
                &m->nested.democracy_vote_V1.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V1 - ref_index */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_emergency_cancel_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_external_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3333: /* module 13 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_external_propose_majority_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3334: /* module 13 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_external_propose_default_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3335: /* module 13 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_fast_track_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V1 - voting_period */;
            return _toStringBlockNumber(
                &m->nested.democracy_fast_track_V1.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V1 - delay */;
            return _toStringBlockNumber(
                &m->nested.democracy_fast_track_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3336: /* module 13 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_veto_external_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3337: /* module 13 call 9 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V1 - ref_index */;
            return _toStringCompactu32(
                &m->nested.democracy_cancel_referendum_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3338: /* module 13 call 10 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V1 - which */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_cancel_queued_V1.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3339: /* module 13 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V1 - to */;
            return _toStringAccountId_V1(
                &m->nested.democracy_delegate_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V1 - conviction */;
            return _toStringConviction_V1(
                &m->nested.democracy_delegate_V1.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V1 - balance */;
            return _toStringBalance(
                &m->nested.democracy_delegate_V1.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3340: /* module 13 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3341: /* module 13 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3342: /* module 13 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3343: /* module 13 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3344: /* module 13 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3345: /* module 13 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3346: /* module 13 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_reap_preimage_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V1 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->nested.democracy_reap_preimage_V1.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3347: /* module 13 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V1 - target */;
            return _toStringAccountId_V1(
                &m->nested.democracy_unlock_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3348: /* module 13 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_remove_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3349: /* module 13 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V1 - target */;
            return _toStringAccountId_V1(
                &m->nested.democracy_remove_other_vote_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_remove_other_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3350: /* module 13 call 22 */
        switch (itemIdx) {
        case 0: /* democracy_enact_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_enact_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_enact_proposal_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_enact_proposal_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3352: /* module 13 call 24 */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V1 - prop_index */;
            return _toStringCompactu32(
                &m->nested.democracy_cancel_proposal_V1.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* council_set_members_V1 - new_members */;
            return _toStringVecAccountId_V1(
                &m->basic.council_set_members_V1.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_set_members_V1 - prime */;
            return _toStringOptionAccountId_V1(
                &m->basic.council_set_members_V1.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_set_members_V1 - old_count */;
            return _toStringMemberCount_V1(
                &m->basic.council_set_members_V1.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V1 - threshold */;
            return _toStringCompactu32(
                &m->basic.council_propose_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V1 - index */;
            return _toStringCompactu32(
                &m->basic.council_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V1 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V1 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.council_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_members_V1 - new_members */;
            return _toStringVecAccountId_V1(
                &m->basic.technicalcommittee_set_members_V1.new_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_members_V1 - prime */;
            return _toStringOptionAccountId_V1(
                &m->basic.technicalcommittee_set_members_V1.prime,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_set_members_V1 - old_count */;
            return _toStringMemberCount_V1(
                &m->basic.technicalcommittee_set_members_V1.old_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V1 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V1 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V1 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V1 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V1 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V1 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.technicalcommittee_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* phragmenelection_vote_V1 - votes */;
            return _toStringVecAccountId_V1(
                &m->basic.phragmenelection_vote_V1.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* phragmenelection_vote_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.phragmenelection_vote_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* phragmenelection_submit_candidacy_V1 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.phragmenelection_submit_candidacy_V1.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* phragmenelection_remove_member_V1 - who */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.phragmenelection_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* phragmenelection_remove_member_V1 - slash_bond */;
            return _toStringbool(
                &m->basic.phragmenelection_remove_member_V1.slash_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* phragmenelection_remove_member_V1 - rerun_election */;
            return _toStringbool(
                &m->basic.phragmenelection_remove_member_V1.rerun_election,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* phragmenelection_clean_defunct_voters_V1 - num_voters */;
            return _toStringu32(
                &m->basic.phragmenelection_clean_defunct_voters_V1.num_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* phragmenelection_clean_defunct_voters_V1 - num_defunct */;
            return _toStringu32(
                &m->basic.phragmenelection_clean_defunct_voters_V1.num_defunct,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_add_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* technicalmembership_swap_member_V1 - remove */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_swap_member_V1.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalmembership_swap_member_V1 - add */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_swap_member_V1.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V1 - members */;
            return _toStringVecAccountId_V1(
                &m->basic.technicalmembership_reset_members_V1.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_change_key_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_set_prime_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.treasury_propose_spend_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* treasury_spend_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_spend_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_spend_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.treasury_spend_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* treasury_remove_approval_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_remove_approval_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* claims_claim_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.claims_claim_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_V1 - ethereum_signature */;
            return _toStringEcdsaSignature_V1(
                &m->basic.claims_claim_V1.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4866: /* module 19 call 2 */
        switch (itemIdx) {
        case 0: /* claims_claim_attest_V1 - dest */;
            return _toStringAccountId_V1(
                &m->basic.claims_claim_attest_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_claim_attest_V1 - ethereum_signature */;
            return _toStringEcdsaSignature_V1(
                &m->basic.claims_claim_attest_V1.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_claim_attest_V1 - statement */;
            return _toStringBytes(
                &m->basic.claims_claim_attest_V1.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4867: /* module 19 call 3 */
        switch (itemIdx) {
        case 0: /* claims_attest_V1 - statement */;
            return _toStringBytes(
                &m->basic.claims_attest_V1.statement,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4868: /* module 19 call 4 */
        switch (itemIdx) {
        case 0: /* claims_move_claim_V1 - old */;
            return _toStringEthereumAddress_V1(
                &m->basic.claims_move_claim_V1.old,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* claims_move_claim_V1 - new_ */;
            return _toStringEthereumAddress_V1(
                &m->basic.claims_move_claim_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* claims_move_claim_V1 - maybe_preclaim */;
            return _toStringOptionAccountId_V1(
                &m->basic.claims_move_claim_V1.maybe_preclaim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.identity_add_registrar_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V1 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V1 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V1.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V1 - reg_index */;
            return _toStringRegistrarIndex_V1(
                &m->basic.identity_cancel_request_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V1 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V1 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V1 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.identity_set_account_id_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6410: /* module 25 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_kill_identity_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6413: /* module 25 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V1 - sub */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_remove_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6414: /* module 25 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* society_bid_V1 - amount */;
            return _toStringBalanceOf(
                &m->basic.society_bid_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* society_unbid_V1 - pos */;
            return _toStringu32(
                &m->basic.society_unbid_V1.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* society_vouch_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.society_vouch_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vouch_V1 - amount */;
            return _toStringBalanceOf(
                &m->basic.society_vouch_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_vouch_V1 - tip */;
            return _toStringBalanceOf(
                &m->basic.society_vouch_V1.tip,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* society_unvouch_V1 - pos */;
            return _toStringu32(
                &m->basic.society_unvouch_V1.pos,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* society_vote_V1 - candidate */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.society_vote_V1.candidate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.society_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* society_defender_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.society_defender_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* society_found_V1 - founder */;
            return _toStringAccountId_V1(
                &m->basic.society_found_V1.founder,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_found_V1 - max_members */;
            return _toStringu32(
                &m->basic.society_found_V1.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* society_found_V1 - rules */;
            return _toStringBytes(
                &m->basic.society_found_V1.rules,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0: /* society_judge_suspended_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.society_judge_suspended_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* society_judge_suspended_member_V1 - forgive */;
            return _toStringbool(
                &m->basic.society_judge_suspended_member_V1.forgive,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0: /* society_set_max_members_V1 - max */;
            return _toStringu32(
                &m->basic.society_set_max_members_V1.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* recovery_set_recovered_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_set_recovered_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_set_recovered_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_set_recovered_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_initiate_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_claim_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6918: /* module 27 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_close_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6919: /* module 27 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6920: /* module 27 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_cancel_recovered_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_vest_other_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* vesting_force_vested_transfer_V1 - source */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_force_vested_transfer_V1.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_force_vested_transfer_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_force_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* vesting_force_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_force_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* vesting_merge_schedules_V1 - schedule1_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V1.schedule1_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_merge_schedules_V1 - schedule2_index */;
            return _toStringu32(
                &m->basic.vesting_merge_schedules_V1.schedule2_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V1 - real */;
            return _toStringAccountId_V1(
                &m->nested.proxy_proxy_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->nested.proxy_proxy_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V1 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_add_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_add_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_remove_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V1 - spawner */;
            return _toStringAccountId_V1(
                &m->basic.proxy_kill_anonymous_V1.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_kill_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V1 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V1 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7689: /* module 30 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->basic.proxy_proxy_announced_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V1 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_threshold_1_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V1 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V1 - call */;
            return _toStringOpaqueCall_V1(
                &m->nested.multisig_as_multi_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V1 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V1.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_approve_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_approve_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_approve_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_cancel_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->nested.multisig_cancel_as_multi_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V1 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V1.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V1 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V1 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V1 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* bounties_propose_bounty_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_bounty_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_bounty_V1 - description */;
            return _toStringBytes(
                &m->basic.bounties_propose_bounty_V1.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8961: /* module 35 call 1 */
        switch (itemIdx) {
        case 0: /* bounties_approve_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_approve_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8962: /* module 35 call 2 */
        switch (itemIdx) {
        case 0: /* bounties_propose_curator_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_propose_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_propose_curator_V1 - curator */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.bounties_propose_curator_V1.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* bounties_propose_curator_V1 - fee */;
            return _toStringCompactBalance(
                &m->basic.bounties_propose_curator_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8963: /* module 35 call 3 */
        switch (itemIdx) {
        case 0: /* bounties_unassign_curator_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_unassign_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8964: /* module 35 call 4 */
        switch (itemIdx) {
        case 0: /* bounties_accept_curator_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_accept_curator_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8965: /* module 35 call 5 */
        switch (itemIdx) {
        case 0: /* bounties_award_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_award_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_award_bounty_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.bounties_award_bounty_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8966: /* module 35 call 6 */
        switch (itemIdx) {
        case 0: /* bounties_claim_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_claim_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8967: /* module 35 call 7 */
        switch (itemIdx) {
        case 0: /* bounties_close_bounty_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_close_bounty_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8968: /* module 35 call 8 */
        switch (itemIdx) {
        case 0: /* bounties_extend_bounty_expiry_V1 - bounty_id */;
            return _toStringCompactu32(
                &m->basic.bounties_extend_bounty_expiry_V1.bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bounties_extend_bounty_expiry_V1 - remark */;
            return _toStringBytes(
                &m->basic.bounties_extend_bounty_expiry_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* childbounties_add_child_bounty_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_add_child_bounty_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_add_child_bounty_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.childbounties_add_child_bounty_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_add_child_bounty_V1 - description */;
            return _toStringVecu8(
                &m->basic.childbounties_add_child_bounty_V1.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* childbounties_propose_curator_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_propose_curator_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_propose_curator_V1 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_propose_curator_V1.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_propose_curator_V1 - curator */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.childbounties_propose_curator_V1.curator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* childbounties_propose_curator_V1 - fee */;
            return _toStringCompactBalance(
                &m->basic.childbounties_propose_curator_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10242: /* module 40 call 2 */
        switch (itemIdx) {
        case 0: /* childbounties_accept_curator_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_accept_curator_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_accept_curator_V1 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_accept_curator_V1.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10243: /* module 40 call 3 */
        switch (itemIdx) {
        case 0: /* childbounties_unassign_curator_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_unassign_curator_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_unassign_curator_V1 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_unassign_curator_V1.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10244: /* module 40 call 4 */
        switch (itemIdx) {
        case 0: /* childbounties_award_child_bounty_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_award_child_bounty_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_award_child_bounty_V1 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_award_child_bounty_V1.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* childbounties_award_child_bounty_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.childbounties_award_child_bounty_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10245: /* module 40 call 5 */
        switch (itemIdx) {
        case 0: /* childbounties_claim_child_bounty_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_claim_child_bounty_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_claim_child_bounty_V1 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_claim_child_bounty_V1.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10246: /* module 40 call 6 */
        switch (itemIdx) {
        case 0: /* childbounties_close_child_bounty_V1 - parent_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_close_child_bounty_V1.parent_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* childbounties_close_child_bounty_V1 - child_bounty_id */;
            return _toStringCompactu32(
                &m->basic.childbounties_close_child_bounty_V1.child_bounty_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* tips_report_awesome_V1 - reason */;
            return _toStringBytes(
                &m->basic.tips_report_awesome_V1.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_report_awesome_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.tips_report_awesome_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* tips_retract_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_retract_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0: /* tips_tip_new_V1 - reason */;
            return _toStringBytes(
                &m->basic.tips_tip_new_V1.reason,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_new_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.tips_tip_new_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* tips_tip_new_V1 - tip_value */;
            return _toStringCompactu128(
                &m->basic.tips_tip_new_V1.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* tips_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* tips_tip_V1 - tip_value */;
            return _toStringCompactu128(
                &m->basic.tips_tip_V1.tip_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* tips_close_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_close_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* tips_slash_tip_V1 - hash */;
            return _toStringHash(
                &m->basic.tips_slash_tip_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* electionprovidermultiphase_governance_fallback_V1 - maybe_max_voters */;
            return _toStringOptionu32(
                &m->basic.electionprovidermultiphase_governance_fallback_V1.maybe_max_voters,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* electionprovidermultiphase_governance_fallback_V1 - maybe_max_targets */;
            return _toStringOptionu32(
                &m->basic.electionprovidermultiphase_governance_fallback_V1.maybe_max_targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* gilt_place_bid_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.gilt_place_bid_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* gilt_place_bid_V1 - duration */;
            return _toStringu32(
                &m->basic.gilt_place_bid_V1.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* gilt_retract_bid_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.gilt_retract_bid_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* gilt_retract_bid_V1 - duration */;
            return _toStringu32(
                &m->basic.gilt_retract_bid_V1.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* gilt_set_target_V1 - target */;
            return _toStringCompactu64(
                &m->basic.gilt_set_target_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* gilt_thaw_V1 - index */;
            return _toStringCompactu32(
                &m->basic.gilt_thaw_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0: /* voterlist_rebag_V1 - dislocated */;
            return _toStringAccountId_V1(
                &m->basic.voterlist_rebag_V1.dislocated,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0: /* voterlist_put_in_front_of_V1 - lighter */;
            return _toStringAccountId_V1(
                &m->basic.voterlist_put_in_front_of_V1.lighter,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* nominationpools_join_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.nominationpools_join_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_join_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_join_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* nominationpools_bond_extra_V1 - extra */;
            return _toStringBondExtraBalanceOfT_V1(
                &m->basic.nominationpools_bond_extra_V1.extra,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* nominationpools_unbond_V1 - member_account */;
            return _toStringAccountId_V1(
                &m->basic.nominationpools_unbond_V1.member_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_unbond_V1 - unbonding_points */;
            return _toStringCompactu128(
                &m->basic.nominationpools_unbond_V1.unbonding_points,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0: /* nominationpools_pool_withdraw_unbonded_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_pool_withdraw_unbonded_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_pool_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.nominationpools_pool_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        case 0: /* nominationpools_withdraw_unbonded_V1 - member_account */;
            return _toStringAccountId_V1(
                &m->basic.nominationpools_withdraw_unbonded_V1.member_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.nominationpools_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        case 0: /* nominationpools_create_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.nominationpools_create_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_create_V1 - root */;
            return _toStringAccountId_V1(
                &m->basic.nominationpools_create_V1.root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_create_V1 - nominator */;
            return _toStringAccountId_V1(
                &m->basic.nominationpools_create_V1.nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_create_V1 - state_toggler */;
            return _toStringAccountId_V1(
                &m->basic.nominationpools_create_V1.state_toggler,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10503: /* module 41 call 7 */
        switch (itemIdx) {
        case 0: /* nominationpools_nominate_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_nominate_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_nominate_V1 - validators */;
            return _toStringVecAccountId_V1(
                &m->basic.nominationpools_nominate_V1.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10504: /* module 41 call 8 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_state_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_set_state_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_state_V1 - state */;
            return _toStringPoolState_V1(
                &m->basic.nominationpools_set_state_V1.state,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10505: /* module 41 call 9 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_metadata_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_set_metadata_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_metadata_V1 - metadata */;
            return _toStringVecu8(
                &m->basic.nominationpools_set_metadata_V1.metadata,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10506: /* module 41 call 10 */
        switch (itemIdx) {
        case 0: /* nominationpools_set_configs_V1 - min_join_bond */;
            return _toStringConfigOpBalanceOfT_V1(
                &m->basic.nominationpools_set_configs_V1.min_join_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_set_configs_V1 - min_create_bond */;
            return _toStringConfigOpBalanceOfT_V1(
                &m->basic.nominationpools_set_configs_V1.min_create_bond,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_set_configs_V1 - max_pools */;
            return _toStringConfigOpu32_V1(
                &m->basic.nominationpools_set_configs_V1.max_pools,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_set_configs_V1 - max_members */;
            return _toStringConfigOpu32_V1(
                &m->basic.nominationpools_set_configs_V1.max_members,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* nominationpools_set_configs_V1 - max_members_per_pool */;
            return _toStringConfigOpu32_V1(
                &m->basic.nominationpools_set_configs_V1.max_members_per_pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10507: /* module 41 call 11 */
        switch (itemIdx) {
        case 0: /* nominationpools_update_roles_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_update_roles_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nominationpools_update_roles_V1 - new_root */;
            return _toStringConfigOpAccountId_V1(
                &m->basic.nominationpools_update_roles_V1.new_root,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nominationpools_update_roles_V1 - new_nominator */;
            return _toStringConfigOpAccountId_V1(
                &m->basic.nominationpools_update_roles_V1.new_nominator,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nominationpools_update_roles_V1 - new_state_toggler */;
            return _toStringConfigOpAccountId_V1(
                &m->basic.nominationpools_update_roles_V1.new_state_toggler,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10508: /* module 41 call 12 */
        switch (itemIdx) {
        case 0: /* nominationpools_chill_V1 - pool_id */;
            return _toStringPoolId_V1(
                &m->basic.nominationpools_chill_V1.pool_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13056: /* module 51 call 0 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_cooldown_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_cooldown_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13057: /* module 51 call 1 */
        switch (itemIdx) {
        case 0: /* configuration_set_validation_upgrade_delay_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_validation_upgrade_delay_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13058: /* module 51 call 2 */
        switch (itemIdx) {
        case 0: /* configuration_set_code_retention_period_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_code_retention_period_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13059: /* module 51 call 3 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_code_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_code_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13060: /* module 51 call 4 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_pov_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_pov_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13061: /* module 51 call 5 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_head_data_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_head_data_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13062: /* module 51 call 6 */
        switch (itemIdx) {
        case 0: /* configuration_set_parathread_cores_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_parathread_cores_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13063: /* module 51 call 7 */
        switch (itemIdx) {
        case 0: /* configuration_set_parathread_retries_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_parathread_retries_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13064: /* module 51 call 8 */
        switch (itemIdx) {
        case 0: /* configuration_set_group_rotation_frequency_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_group_rotation_frequency_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13065: /* module 51 call 9 */
        switch (itemIdx) {
        case 0: /* configuration_set_chain_availability_period_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_chain_availability_period_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13066: /* module 51 call 10 */
        switch (itemIdx) {
        case 0: /* configuration_set_thread_availability_period_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_thread_availability_period_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13067: /* module 51 call 11 */
        switch (itemIdx) {
        case 0: /* configuration_set_scheduling_lookahead_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_scheduling_lookahead_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13068: /* module 51 call 12 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_per_core_V1 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_per_core_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13069: /* module 51 call 13 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_validators_V1 - new_ */;
            return _toStringOptionu32(
                &m->basic.configuration_set_max_validators_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13070: /* module 51 call 14 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_period_V1 - new_ */;
            return _toStringSessionIndex_V1(
                &m->basic.configuration_set_dispute_period_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13071: /* module 51 call 15 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_post_conclusion_acceptance_period_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_post_conclusion_acceptance_period_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13072: /* module 51 call 16 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_max_spam_slots_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_dispute_max_spam_slots_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13073: /* module 51 call 17 */
        switch (itemIdx) {
        case 0: /* configuration_set_dispute_conclusion_by_time_out_period_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_dispute_conclusion_by_time_out_period_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13074: /* module 51 call 18 */
        switch (itemIdx) {
        case 0: /* configuration_set_no_show_slots_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_no_show_slots_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13075: /* module 51 call 19 */
        switch (itemIdx) {
        case 0: /* configuration_set_n_delay_tranches_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_n_delay_tranches_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13076: /* module 51 call 20 */
        switch (itemIdx) {
        case 0: /* configuration_set_zeroth_delay_tranche_width_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_zeroth_delay_tranche_width_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13077: /* module 51 call 21 */
        switch (itemIdx) {
        case 0: /* configuration_set_needed_approvals_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_needed_approvals_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13078: /* module 51 call 22 */
        switch (itemIdx) {
        case 0: /* configuration_set_relay_vrf_modulo_samples_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_relay_vrf_modulo_samples_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13079: /* module 51 call 23 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_count_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13080: /* module 51 call 24 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_queue_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_queue_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13081: /* module 51 call 25 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_downward_message_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_downward_message_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13082: /* module 51 call 26 */
        switch (itemIdx) {
        case 0: /* configuration_set_ump_service_total_weight_V1 - new_ */;
            return _toStringWeight_V1(
                &m->basic.configuration_set_ump_service_total_weight_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13083: /* module 51 call 27 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13084: /* module 51 call 28 */
        switch (itemIdx) {
        case 0: /* configuration_set_max_upward_message_num_per_candidate_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_max_upward_message_num_per_candidate_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13085: /* module 51 call 29 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_open_request_ttl_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_open_request_ttl_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13086: /* module 51 call 30 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_sender_deposit_V1 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_sender_deposit_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13087: /* module 51 call 31 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_recipient_deposit_V1 - new_ */;
            return _toStringBalance(
                &m->basic.configuration_set_hrmp_recipient_deposit_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13088: /* module 51 call 32 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_capacity_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_capacity_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13089: /* module 51 call 33 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_total_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_total_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13090: /* module 51 call 34 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_inbound_channels_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_inbound_channels_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13091: /* module 51 call 35 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parathread_inbound_channels_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parathread_inbound_channels_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13092: /* module 51 call 36 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_channel_max_message_size_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_channel_max_message_size_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13093: /* module 51 call 37 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parachain_outbound_channels_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parachain_outbound_channels_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13094: /* module 51 call 38 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_parathread_outbound_channels_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_parathread_outbound_channels_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13095: /* module 51 call 39 */
        switch (itemIdx) {
        case 0: /* configuration_set_hrmp_max_message_num_per_candidate_V1 - new_ */;
            return _toStringu32(
                &m->basic.configuration_set_hrmp_max_message_num_per_candidate_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13096: /* module 51 call 40 */
        switch (itemIdx) {
        case 0: /* configuration_set_ump_max_individual_weight_V1 - new_ */;
            return _toStringWeight_V1(
                &m->basic.configuration_set_ump_max_individual_weight_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13097: /* module 51 call 41 */
        switch (itemIdx) {
        case 0: /* configuration_set_pvf_checking_enabled_V1 - new_ */;
            return _toStringbool(
                &m->basic.configuration_set_pvf_checking_enabled_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13098: /* module 51 call 42 */
        switch (itemIdx) {
        case 0: /* configuration_set_pvf_voting_ttl_V1 - new_ */;
            return _toStringSessionIndex_V1(
                &m->basic.configuration_set_pvf_voting_ttl_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13099: /* module 51 call 43 */
        switch (itemIdx) {
        case 0: /* configuration_set_minimum_validation_upgrade_delay_V1 - new_ */;
            return _toStringBlockNumber(
                &m->basic.configuration_set_minimum_validation_upgrade_delay_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 13100: /* module 51 call 44 */
        switch (itemIdx) {
        case 0: /* configuration_set_bypass_consistency_check_V1 - new_ */;
            return _toStringbool(
                &m->basic.configuration_set_bypass_consistency_check_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 14592: /* module 57 call 0 */
        switch (itemIdx) {
        case 0: /* initializer_force_approve_V1 - up_to */;
            return _toStringBlockNumber(
                &m->basic.initializer_force_approve_V1.up_to,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15364: /* module 60 call 4 */
        switch (itemIdx) {
        case 0: /* hrmp_force_process_hrmp_open_V1 - channels */;
            return _toStringu32(
                &m->basic.hrmp_force_process_hrmp_open_V1.channels,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15365: /* module 60 call 5 */
        switch (itemIdx) {
        case 0: /* hrmp_force_process_hrmp_close_V1 - channels */;
            return _toStringu32(
                &m->basic.hrmp_force_process_hrmp_close_V1.channels,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 15872: /* module 62 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 17925: /* module 70 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 18432: /* module 72 call 0 */
        switch (itemIdx) {
        case 0: /* auctions_new_auction_V1 - duration */;
            return _toStringCompactu32(
                &m->basic.auctions_new_auction_V1.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_new_auction_V1 - lease_period_index */;
            return _toStringCompactu32(
                &m->basic.auctions_new_auction_V1.lease_period_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18433: /* module 72 call 1 */
        switch (itemIdx) {
        case 0: /* auctions_bid_V1 - para */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V1.para,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* auctions_bid_V1 - auction_index */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V1.auction_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* auctions_bid_V1 - first_slot */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V1.first_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* auctions_bid_V1 - last_slot */;
            return _toStringCompactu32(
                &m->basic.auctions_bid_V1.last_slot,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* auctions_bid_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.auctions_bid_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 18434: /* module 72 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1539: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1551: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 1557: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 10500: // NominationPools:Pool withdraw unbonded
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 10501: // NominationPools:Withdraw Unbonded
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 512: // Timestamp:Set
    case 768: // Indices:Claim
    case 769: // Indices:Transfer
    case 770: // Indices:Free
    case 771: // Indices:Force transfer
    case 772: // Indices:Freeze
    case 1028: // Balances:Transfer all
    case 1029: // Balances:Force unreserve
    case 1536: // Staking:Bond
    case 1537: // Staking:Bond extra
    case 1538: // Staking:Unbond
    case 1539: // Staking:Withdraw Unbonded
    case 1540: // Staking:Validate
    case 1541: // Staking:Nominate
    case 1542: // Staking:Chill
    case 1543: // Staking:Set payee
    case 1544: // Staking:Set controller
    case 1545: // Staking:Set validator count
    case 1546: // Staking:Increase validator count
    case 1548: // Staking:Force no eras
    case 1549: // Staking:Force new era
    case 1550: // Staking:Set invulnerables
    case 1551: // Staking:Force unstake
    case 1552: // Staking:Force new era always
    case 1553: // Staking:Cancel deferred slash
    case 1554: // Staking:Payout stakers
    case 1555: // Staking:Rebond
    case 1556: // Staking:Set history depth
    case 1557: // Staking:Reap stash
    case 1558: // Staking:Kick
    case 1560: // Staking:Chill other
    case 1561: // Staking:Force apply min commission
    case 2048: // Session:Set keys
    case 2049: // Session:Purge keys
    case 2562: // Grandpa:Note stalled
    case 3342: // Democracy:Note preimage
    case 3343: // Democracy:Note preimage operational
    case 3344: // Democracy:Note imminent preimage
    case 3345: // Democracy:Note imminent preimage operational
    case 3584: // Council:Set members
    case 3585: // Council:Execute
    case 3586: // Council:Propose
    case 3587: // Council:Vote
    case 3588: // Council:Close
    case 3589: // Council:Disapprove proposal
    case 3840: // TechnicalCommittee:Set members
    case 3841: // TechnicalCommittee:Execute
    case 3842: // TechnicalCommittee:Propose
    case 3843: // TechnicalCommittee:Vote
    case 3844: // TechnicalCommittee:Close
    case 3845: // TechnicalCommittee:Disapprove proposal
    case 4096: // PhragmenElection:Vote
    case 4097: // PhragmenElection:Remove voter
    case 4098: // PhragmenElection:Submit candidacy
    case 4100: // PhragmenElection:Remove member
    case 4101: // PhragmenElection:Clean defunct voters
    case 4352: // TechnicalMembership:Add member
    case 4353: // TechnicalMembership:Remove member
    case 4354: // TechnicalMembership:Swap member
    case 4355: // TechnicalMembership:Reset members
    case 4356: // TechnicalMembership:Change key
    case 4357: // TechnicalMembership:Set prime
    case 4358: // TechnicalMembership:Clear prime
    case 4608: // Treasury:Propose spend
    case 4609: // Treasury:Reject proposal
    case 4610: // Treasury:Approve proposal
    case 4611: // Treasury:Spend
    case 4612: // Treasury:Remove approval
    case 4864: // Claims:Claim
    case 4866: // Claims:Claim attest
    case 4867: // Claims:Attest
    case 4868: // Claims:Move claim
    case 6144: // Utility:Batch
    case 6146: // Utility:Batch all
    case 6148: // Utility:Force batch
    case 6400: // Identity:Add registrar
    case 6403: // Identity:Clear identity
    case 6404: // Identity:Request judgement
    case 6405: // Identity:Cancel request
    case 6406: // Identity:Set fee
    case 6407: // Identity:Set account id
    case 6410: // Identity:Kill identity
    case 6413: // Identity:Remove sub
    case 6414: // Identity:Quit sub
    case 6656: // Society:Bid
    case 6657: // Society:Unbid
    case 6658: // Society:Vouch
    case 6659: // Society:Unvouch
    case 6660: // Society:Vote
    case 6661: // Society:Defender vote
    case 6662: // Society:Payout
    case 6663: // Society:Found
    case 6664: // Society:Unfound
    case 6665: // Society:Judge suspended member
    case 6667: // Society:Set max members
    case 6913: // Recovery:Set recovered
    case 6915: // Recovery:Initiate recovery
    case 6916: // Recovery:Vouch recovery
    case 6917: // Recovery:Claim recovery
    case 6918: // Recovery:Close recovery
    case 6919: // Recovery:Remove recovery
    case 6920: // Recovery:Cancel recovered
    case 7168: // Vesting:Vest
    case 7169: // Vesting:Vest other
    case 7170: // Vesting:Vested transfer
    case 7171: // Vesting:Force vested transfer
    case 7172: // Vesting:Merge schedules
    case 7681: // Proxy:Add proxy
    case 7682: // Proxy:Remove proxy
    case 7683: // Proxy:Remove proxies
    case 7684: // Proxy:Anonymous
    case 7685: // Proxy:Kill anonymous
    case 7689: // Proxy:Proxy announced
    case 8192: // Preimage:Note preimage
    case 8193: // Preimage:Unnote preimage
    case 8194: // Preimage:Request preimage
    case 8195: // Preimage:Unrequest preimage
    case 8960: // Bounties:Propose bounty
    case 8961: // Bounties:Approve bounty
    case 8962: // Bounties:Propose curator
    case 8963: // Bounties:Unassign curator
    case 8964: // Bounties:Accept curator
    case 8965: // Bounties:Award bounty
    case 8966: // Bounties:Claim bounty
    case 8967: // Bounties:Close bounty
    case 8968: // Bounties:Extend bounty expiry
    case 10240: // ChildBounties:Add child bounty
    case 10241: // ChildBounties:Propose curator
    case 10242: // ChildBounties:Accept curator
    case 10243: // ChildBounties:Unassign curator
    case 10244: // ChildBounties:Award child bounty
    case 10245: // ChildBounties:Claim child bounty
    case 10246: // ChildBounties:Close child bounty
    case 9216: // Tips:Report awesome
    case 9217: // Tips:Retract tip
    case 9218: // Tips:Tip new
    case 9219: // Tips:Tip
    case 9220: // Tips:Close tip
    case 9221: // Tips:Slash tip
    case 9476: // ElectionProviderMultiPhase:Governance fallback
    case 9728: // Gilt:Place bid
    case 9729: // Gilt:Retract bid
    case 9730: // Gilt:Set target
    case 9731: // Gilt:Thaw
    case 9984: // VoterList:Rebag
    case 9985: // VoterList:Put in front of
    case 10496: // NominationPools:Join
    case 10497: // NominationPools:Bond extra
    case 10498: // NominationPools:Claim payout
    case 10499: // NominationPools:Unbond
    case 10500: // NominationPools:Pool withdraw unbonded
    case 10501: // NominationPools:Withdraw Unbonded
    case 10502: // NominationPools:Create
    case 10503: // NominationPools:Nominate
    case 10504: // NominationPools:Set state
    case 10505: // NominationPools:Set metadata
    case 10506: // NominationPools:Set configs
    case 10507: // NominationPools:Update roles
    case 10508: // NominationPools:Chill
    case 13056: // Configuration:Set validation upgrade cooldown
    case 13057: // Configuration:Set validation upgrade delay
    case 13058: // Configuration:Set code retention period
    case 13059: // Configuration:Set max code size
    case 13060: // Configuration:Set max pov size
    case 13061: // Configuration:Set max head data size
    case 13062: // Configuration:Set parathread cores
    case 13063: // Configuration:Set parathread retries
    case 13064: // Configuration:Set group rotation frequency
    case 13065: // Configuration:Set chain availability period
    case 13066: // Configuration:Set thread availability period
    case 13067: // Configuration:Set scheduling lookahead
    case 13068: // Configuration:Set max validators per core
    case 13069: // Configuration:Set max validators
    case 13070: // Configuration:Set dispute period
    case 13071: // Configuration:Set dispute post conclusion acceptance period
    case 13072: // Configuration:Set dispute max spam slots
    case 13073: // Configuration:Set dispute conclusion by time out period
    case 13074: // Configuration:Set no show slots
    case 13075: // Configuration:Set n delay tranches
    case 13076: // Configuration:Set zeroth delay tranche width
    case 13077: // Configuration:Set needed approvals
    case 13078: // Configuration:Set relay vrf modulo samples
    case 13079: // Configuration:Set max upward queue count
    case 13080: // Configuration:Set max upward queue size
    case 13081: // Configuration:Set max downward message size
    case 13082: // Configuration:Set ump service total weight
    case 13083: // Configuration:Set max upward message size
    case 13084: // Configuration:Set max upward message num per candidate
    case 13085: // Configuration:Set hrmp open request ttl
    case 13086: // Configuration:Set hrmp sender deposit
    case 13087: // Configuration:Set hrmp recipient deposit
    case 13088: // Configuration:Set hrmp channel max capacity
    case 13089: // Configuration:Set hrmp channel max total size
    case 13090: // Configuration:Set hrmp max parachain inbound channels
    case 13091: // Configuration:Set hrmp max parathread inbound channels
    case 13092: // Configuration:Set hrmp channel max message size
    case 13093: // Configuration:Set hrmp max parachain outbound channels
    case 13094: // Configuration:Set hrmp max parathread outbound channels
    case 13095: // Configuration:Set hrmp max message num per candidate
    case 13096: // Configuration:Set ump max individual weight
    case 13097: // Configuration:Set pvf checking enabled
    case 13098: // Configuration:Set pvf voting ttl
    case 13099: // Configuration:Set minimum validation upgrade delay
    case 13100: // Configuration:Set bypass consistency check
    case 14592: // Initializer:Force approve
    case 15364: // Hrmp:Force process hrmp open
    case 15365: // Hrmp:Force process hrmp close
    case 15872: // ParasDisputes:Force unfreeze
    case 17925: // Registrar:Reserve
    case 18432: // Auctions:New auction
    case 18433: // Auctions:Bid
    case 18434: // Auctions:Cancel auction
    case 18688: // Crowdloan:Create
    case 18689: // Crowdloan:Contribute
    case 18690: // Crowdloan:Withdraw
    case 18691: // Crowdloan:Refund
    case 18692: // Crowdloan:Dissolve
    case 18693: // Crowdloan:Edit
    case 18694: // Crowdloan:Add memo
    case 18695: // Crowdloan:Poke
    case 18696: // Crowdloan:Contribute all
        return false;
    default:
        return true;
    }
}