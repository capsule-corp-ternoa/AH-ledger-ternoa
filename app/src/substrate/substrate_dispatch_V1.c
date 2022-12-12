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

__Z_INLINE parser_error_t _readMethod_electionprovidermultiphase_governance_fallback_V1(
    parser_context_t* c, pd_electionprovidermultiphase_governance_fallback_V1_t* m)
{
    CHECK_ERROR(_readOptionu32(c, &m->maybe_max_voters))
    CHECK_ERROR(_readOptionu32(c, &m->maybe_max_targets))
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

case 1024: /* module 04 call 00 pallet:balances call:transfer */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
case 1026: /* module 04 call 02 pallet:balances call:force_transfer */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
        break;
case 1027: /* module 04 call 03 pallet:balances call:transfer_keep_alive */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
        CHECK_ERROR(_readMethod_balances_transfer_all_V1(c, &method->basic.balances_transfer_all_V1))
        break;
case 3328: /* module 13 call 00 pallet:staking call:bond */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
case 3330: /* module 13 call 02 pallet:staking call:unbond */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
case 3332: /* module 13 call 04 pallet:staking call:validate */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
case 3333: /* module 13 call 05 pallet:staking call:nominate */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
case 3334: /* module 13 call 06 pallet:staking call:chill */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
        break;
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
case 3347: /* module 13 call 19 pallet:staking call:rebond */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
case 2304: /* module 09 call 00 pallet:session call:set_keys */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;
case 5376: /* module 21 call 00 pallet:utility call:batch */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
        CHECK_ERROR(_readMethod_utility_batch_all_V1(c, &method->basic.utility_batch_all_V1))
        break;
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
        CHECK_ERROR(_readMethod_utility_force_batch_V1(c, &method->basic.utility_force_batch_V1))
        break;

#ifdef SUBSTRATE_PARSER_FULL
case 0: /* module 00 call 00 pallet:system call:fill_block */
        CHECK_ERROR(_readMethod_system_fill_block_V1(c, &method->nested.system_fill_block_V1))
        break;
case 1: /* module 00 call 01 pallet:system call:remark */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
        break;
case 2: /* module 00 call 02 pallet:system call:set_heap_pages */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V1(c, &method->nested.system_set_heap_pages_V1))
        break;
case 3: /* module 00 call 03 pallet:system call:set_code */
        CHECK_ERROR(_readMethod_system_set_code_V1(c, &method->nested.system_set_code_V1))
        break;
case 4: /* module 00 call 04 pallet:system call:set_code_without_checks */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V1(c, &method->nested.system_set_code_without_checks_V1))
        break;
case 8: /* module 00 call 08 pallet:system call:remark_with_event */
        CHECK_ERROR(_readMethod_system_remark_with_event_V1(c, &method->nested.system_remark_with_event_V1))
        break;
case 768: /* module 03 call 00 pallet:timestamp call:set */
        CHECK_ERROR(_readMethod_timestamp_set_V1(c, &method->basic.timestamp_set_V1))
        break;
case 1024: /* module 04 call 00 pallet:balances call:transfer */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
case 1026: /* module 04 call 02 pallet:balances call:force_transfer */
        CHECK_ERROR(_readMethod_balances_force_transfer_V1(c, &method->nested.balances_force_transfer_V1))
        break;
case 1027: /* module 04 call 03 pallet:balances call:transfer_keep_alive */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
        CHECK_ERROR(_readMethod_balances_transfer_all_V1(c, &method->basic.balances_transfer_all_V1))
        break;
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
        break;
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
        break;
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V1(c, &method->basic.staking_force_no_eras_V1))
        break;
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
        CHECK_ERROR(_readMethod_staking_force_new_era_V1(c, &method->basic.staking_force_new_era_V1))
        break;
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V1(c, &method->basic.staking_set_invulnerables_V1))
        break;
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
        CHECK_ERROR(_readMethod_staking_force_unstake_V1(c, &method->basic.staking_force_unstake_V1))
        break;
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V1(c, &method->basic.staking_force_new_era_always_V1))
        break;
case 3345: /* module 13 call 17 pallet:staking call:cancel_deferred_slash */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V1(c, &method->basic.staking_cancel_deferred_slash_V1))
        break;
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
        CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
        break;
case 3349: /* module 13 call 21 pallet:staking call:kick */
        CHECK_ERROR(_readMethod_staking_kick_V1(c, &method->basic.staking_kick_V1))
        break;
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
        CHECK_ERROR(_readMethod_staking_chill_other_V1(c, &method->basic.staking_chill_other_V1))
        break;
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
        CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V1(c, &method->basic.staking_force_apply_min_commission_V1))
        break;
case 2562: /* module 10 call 02 pallet:grandpa call:note_stalled */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V1(c, &method->basic.grandpa_note_stalled_V1))
        break;
case 6656: /* module 26 call 00 pallet:democracy call:propose */
        CHECK_ERROR(_readMethod_democracy_propose_V1(c, &method->nested.democracy_propose_V1))
        break;
case 6657: /* module 26 call 01 pallet:democracy call:second */
        CHECK_ERROR(_readMethod_democracy_second_V1(c, &method->nested.democracy_second_V1))
        break;
case 6658: /* module 26 call 02 pallet:democracy call:vote */
        CHECK_ERROR(_readMethod_democracy_vote_V1(c, &method->nested.democracy_vote_V1))
        break;
case 6659: /* module 26 call 03 pallet:democracy call:emergency_cancel */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V1(c, &method->nested.democracy_emergency_cancel_V1))
        break;
case 6660: /* module 26 call 04 pallet:democracy call:external_propose */
        CHECK_ERROR(_readMethod_democracy_external_propose_V1(c, &method->nested.democracy_external_propose_V1))
        break;
case 6661: /* module 26 call 05 pallet:democracy call:external_propose_majority */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V1(c, &method->nested.democracy_external_propose_majority_V1))
        break;
case 6662: /* module 26 call 06 pallet:democracy call:external_propose_default */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V1(c, &method->nested.democracy_external_propose_default_V1))
        break;
case 6663: /* module 26 call 07 pallet:democracy call:fast_track */
        CHECK_ERROR(_readMethod_democracy_fast_track_V1(c, &method->nested.democracy_fast_track_V1))
        break;
case 6664: /* module 26 call 08 pallet:democracy call:veto_external */
        CHECK_ERROR(_readMethod_democracy_veto_external_V1(c, &method->nested.democracy_veto_external_V1))
        break;
case 6665: /* module 26 call 09 pallet:democracy call:cancel_referendum */
        CHECK_ERROR(_readMethod_democracy_cancel_referendum_V1(c, &method->nested.democracy_cancel_referendum_V1))
        break;
case 6666: /* module 26 call 10 pallet:democracy call:cancel_queued */
        CHECK_ERROR(_readMethod_democracy_cancel_queued_V1(c, &method->nested.democracy_cancel_queued_V1))
        break;
case 6667: /* module 26 call 11 pallet:democracy call:delegate */
        CHECK_ERROR(_readMethod_democracy_delegate_V1(c, &method->nested.democracy_delegate_V1))
        break;
case 6668: /* module 26 call 12 pallet:democracy call:undelegate */
        CHECK_ERROR(_readMethod_democracy_undelegate_V1(c, &method->nested.democracy_undelegate_V1))
        break;
case 6669: /* module 26 call 13 pallet:democracy call:clear_public_proposals */
        CHECK_ERROR(_readMethod_democracy_clear_public_proposals_V1(c, &method->nested.democracy_clear_public_proposals_V1))
        break;
case 6670: /* module 26 call 14 pallet:democracy call:note_preimage */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V1(c, &method->basic.democracy_note_preimage_V1))
        break;
case 6671: /* module 26 call 15 pallet:democracy call:note_preimage_operational */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V1(c, &method->basic.democracy_note_preimage_operational_V1))
        break;
case 6672: /* module 26 call 16 pallet:democracy call:note_imminent_preimage */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V1(c, &method->basic.democracy_note_imminent_preimage_V1))
        break;
case 6673: /* module 26 call 17 pallet:democracy call:note_imminent_preimage_operational */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V1(c, &method->basic.democracy_note_imminent_preimage_operational_V1))
        break;
case 6674: /* module 26 call 18 pallet:democracy call:reap_preimage */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V1(c, &method->nested.democracy_reap_preimage_V1))
        break;
case 6675: /* module 26 call 19 pallet:democracy call:unlock */
        CHECK_ERROR(_readMethod_democracy_unlock_V1(c, &method->nested.democracy_unlock_V1))
        break;
case 6676: /* module 26 call 20 pallet:democracy call:remove_vote */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V1(c, &method->nested.democracy_remove_vote_V1))
        break;
case 6677: /* module 26 call 21 pallet:democracy call:remove_other_vote */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V1(c, &method->nested.democracy_remove_other_vote_V1))
        break;
case 6678: /* module 26 call 22 pallet:democracy call:enact_proposal */
        CHECK_ERROR(_readMethod_democracy_enact_proposal_V1(c, &method->nested.democracy_enact_proposal_V1))
        break;
case 6680: /* module 26 call 24 pallet:democracy call:cancel_proposal */
        CHECK_ERROR(_readMethod_democracy_cancel_proposal_V1(c, &method->nested.democracy_cancel_proposal_V1))
        break;
case 6144: /* module 24 call 00 pallet:council call:set_members */
        CHECK_ERROR(_readMethod_council_set_members_V1(c, &method->basic.council_set_members_V1))
        break;
case 6145: /* module 24 call 01 pallet:council call:execute */
        CHECK_ERROR(_readMethod_council_execute_V1(c, &method->basic.council_execute_V1))
        break;
case 6146: /* module 24 call 02 pallet:council call:propose */
        CHECK_ERROR(_readMethod_council_propose_V1(c, &method->basic.council_propose_V1))
        break;
case 6147: /* module 24 call 03 pallet:council call:vote */
        CHECK_ERROR(_readMethod_council_vote_V1(c, &method->basic.council_vote_V1))
        break;
case 6150: /* module 24 call 06 pallet:council call:close */
        CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
        break;
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
        break;
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
        CHECK_ERROR(_readMethod_technicalcommittee_set_members_V1(c, &method->basic.technicalcommittee_set_members_V1))
        break;
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V1(c, &method->basic.technicalcommittee_execute_V1))
        break;
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V1(c, &method->basic.technicalcommittee_propose_V1))
        break;
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V1(c, &method->basic.technicalcommittee_vote_V1))
        break;
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V1(c, &method->basic.technicalcommittee_close_V1))
        break;
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V1(c, &method->basic.technicalcommittee_disapprove_proposal_V1))
        break;
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
        CHECK_ERROR(_readMethod_technicalmembership_add_member_V1(c, &method->basic.technicalmembership_add_member_V1))
        break;
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
        CHECK_ERROR(_readMethod_technicalmembership_remove_member_V1(c, &method->basic.technicalmembership_remove_member_V1))
        break;
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
        CHECK_ERROR(_readMethod_technicalmembership_swap_member_V1(c, &method->basic.technicalmembership_swap_member_V1))
        break;
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
        CHECK_ERROR(_readMethod_technicalmembership_reset_members_V1(c, &method->basic.technicalmembership_reset_members_V1))
        break;
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
        CHECK_ERROR(_readMethod_technicalmembership_change_key_V1(c, &method->basic.technicalmembership_change_key_V1))
        break;
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
        CHECK_ERROR(_readMethod_technicalmembership_set_prime_V1(c, &method->basic.technicalmembership_set_prime_V1))
        break;
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
        CHECK_ERROR(_readMethod_technicalmembership_clear_prime_V1(c, &method->basic.technicalmembership_clear_prime_V1))
        break;
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
        break;
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
        CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
        break;
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
        CHECK_ERROR(_readMethod_identity_request_judgement_V1(c, &method->basic.identity_request_judgement_V1))
        break;
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
        CHECK_ERROR(_readMethod_identity_cancel_request_V1(c, &method->basic.identity_cancel_request_V1))
        break;
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
        CHECK_ERROR(_readMethod_identity_set_fee_V1(c, &method->basic.identity_set_fee_V1))
        break;
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
        CHECK_ERROR(_readMethod_identity_set_account_id_V1(c, &method->basic.identity_set_account_id_V1))
        break;
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
case 6912: /* module 27 call 00 pallet:multisig call:as_multi_threshold_1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->nested.multisig_as_multi_threshold_1_V1))
        break;
case 6913: /* module 27 call 01 pallet:multisig call:as_multi */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->nested.multisig_as_multi_V1))
        break;
case 6914: /* module 27 call 02 pallet:multisig call:approve_as_multi */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->nested.multisig_approve_as_multi_V1))
        break;
case 6915: /* module 27 call 03 pallet:multisig call:cancel_as_multi */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->nested.multisig_cancel_as_multi_V1))
        break;
case 5632: /* module 22 call 00 pallet:preimage call:note_preimage */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V1(c, &method->basic.preimage_note_preimage_V1))
        break;
case 5633: /* module 22 call 01 pallet:preimage call:unnote_preimage */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V1(c, &method->basic.preimage_unnote_preimage_V1))
        break;
case 5634: /* module 22 call 02 pallet:preimage call:request_preimage */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V1(c, &method->basic.preimage_request_preimage_V1))
        break;
case 5635: /* module 22 call 03 pallet:preimage call:unrequest_preimage */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V1(c, &method->basic.preimage_unrequest_preimage_V1))
        break;
case 3844: /* module 15 call 04 pallet:electionprovidermultiphase call:governance_fallback */
        CHECK_ERROR(_readMethod_electionprovidermultiphase_governance_fallback_V1(c, &method->basic.electionprovidermultiphase_governance_fallback_V1))
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

#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 2:
        return STR_MO_TIMESTAMP;
    case 10:
        return STR_MO_GRANDPA;
    case 13:
        return STR_MO_DEMOCRACY;
    case 14:
        return STR_MO_COUNCIL;
    case 15:
        return STR_MO_TECHNICALCOMMITTEE;
    case 17:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 18:
        return STR_MO_TREASURY;
    case 25:
        return STR_MO_IDENTITY;
    case 31:
        return STR_MO_MULTISIG;
    case 32:
        return STR_MO_PREIMAGE;
    case 37:
        return STR_MO_ELECTIONPROVIDERMULTIPHASE;
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
case 1024: /* module 04 call 00 pallet:balances call:transfer */
        return STR_ME_TRANSFER;
case 1026: /* module 04 call 02 pallet:balances call:force_transfer */
        return STR_ME_FORCE_TRANSFER;
case 1027: /* module 04 call 03 pallet:balances call:transfer_keep_alive */
        return STR_ME_TRANSFER_KEEP_ALIVE;
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
        return STR_ME_TRANSFER_ALL;
case 3328: /* module 13 call 00 pallet:staking call:bond */
        return STR_ME_BOND;
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
        return STR_ME_BOND_EXTRA;
case 3330: /* module 13 call 02 pallet:staking call:unbond */
        return STR_ME_UNBOND;
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
        return STR_ME_WITHDRAW_UNBONDED;
case 3332: /* module 13 call 04 pallet:staking call:validate */
        return STR_ME_VALIDATE;
case 3333: /* module 13 call 05 pallet:staking call:nominate */
        return STR_ME_NOMINATE;
case 3334: /* module 13 call 06 pallet:staking call:chill */
        return STR_ME_CHILL;
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
        return STR_ME_SET_PAYEE;
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
        return STR_ME_SET_CONTROLLER;
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
        return STR_ME_PAYOUT_STAKERS;
case 3347: /* module 13 call 19 pallet:staking call:rebond */
        return STR_ME_REBOND;
case 2304: /* module 09 call 00 pallet:session call:set_keys */
        return STR_ME_SET_KEYS;
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
        return STR_ME_PURGE_KEYS;
case 5376: /* module 21 call 00 pallet:utility call:batch */
        return STR_ME_BATCH;
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
        return STR_ME_BATCH_ALL;
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
        return STR_ME_FORCE_BATCH;
    default:
        return _getMethod_Name_V1_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V1_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
case 0: /* module 00 call 00 pallet:system call:fill_block */
        return STR_ME_FILL_BLOCK;
case 1: /* module 00 call 01 pallet:system call:remark */
        return STR_ME_REMARK;
case 2: /* module 00 call 02 pallet:system call:set_heap_pages */
        return STR_ME_SET_HEAP_PAGES;
case 3: /* module 00 call 03 pallet:system call:set_code */
        return STR_ME_SET_CODE;
case 4: /* module 00 call 04 pallet:system call:set_code_without_checks */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
case 8: /* module 00 call 08 pallet:system call:remark_with_event */
        return STR_ME_REMARK_WITH_EVENT;
case 768: /* module 03 call 00 pallet:timestamp call:set */
        return STR_ME_SET;
case 1025: /* module 04 call 01 pallet:balances call:set_balance */
        return STR_ME_SET_BALANCE;
case 1029: /* module 04 call 05 pallet:balances call:force_unreserve */
        return STR_ME_FORCE_UNRESERVE;
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
        return STR_ME_SET_VALIDATOR_COUNT;
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
        return STR_ME_FORCE_NO_ERAS;
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
        return STR_ME_FORCE_NEW_ERA;
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
        return STR_ME_SET_INVULNERABLES;
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
        return STR_ME_FORCE_UNSTAKE;
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
case 3345: /* module 13 call 17 pallet:staking call:cancel_deferred_slash */
        return STR_ME_CANCEL_DEFERRED_SLASH;
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
        return STR_ME_REAP_STASH;
case 3349: /* module 13 call 21 pallet:staking call:kick */
        return STR_ME_KICK;
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
        return STR_ME_CHILL_OTHER;
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
        return STR_ME_FORCE_APPLY_MIN_COMMISSION;
case 2562: /* module 10 call 02 pallet:grandpa call:note_stalled */
        return STR_ME_NOTE_STALLED;
case 6656: /* module 26 call 00 pallet:democracy call:propose */
        return STR_ME_PROPOSE;
case 6657: /* module 26 call 01 pallet:democracy call:second */
        return STR_ME_SECOND;
case 6658: /* module 26 call 02 pallet:democracy call:vote */
        return STR_ME_VOTE;
case 6659: /* module 26 call 03 pallet:democracy call:emergency_cancel */
        return STR_ME_EMERGENCY_CANCEL;
case 6660: /* module 26 call 04 pallet:democracy call:external_propose */
        return STR_ME_EXTERNAL_PROPOSE;
case 6661: /* module 26 call 05 pallet:democracy call:external_propose_majority */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
case 6662: /* module 26 call 06 pallet:democracy call:external_propose_default */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
case 6663: /* module 26 call 07 pallet:democracy call:fast_track */
        return STR_ME_FAST_TRACK;
case 6664: /* module 26 call 08 pallet:democracy call:veto_external */
        return STR_ME_VETO_EXTERNAL;
case 6665: /* module 26 call 09 pallet:democracy call:cancel_referendum */
        return STR_ME_CANCEL_REFERENDUM;
case 6666: /* module 26 call 10 pallet:democracy call:cancel_queued */
        return STR_ME_CANCEL_QUEUED;
case 6667: /* module 26 call 11 pallet:democracy call:delegate */
        return STR_ME_DELEGATE;
case 6668: /* module 26 call 12 pallet:democracy call:undelegate */
        return STR_ME_UNDELEGATE;
case 6669: /* module 26 call 13 pallet:democracy call:clear_public_proposals */
        return STR_ME_CLEAR_PUBLIC_PROPOSALS;
case 6670: /* module 26 call 14 pallet:democracy call:note_preimage */
        return STR_ME_NOTE_PREIMAGE;
case 6671: /* module 26 call 15 pallet:democracy call:note_preimage_operational */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
case 6672: /* module 26 call 16 pallet:democracy call:note_imminent_preimage */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
case 6673: /* module 26 call 17 pallet:democracy call:note_imminent_preimage_operational */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
case 6674: /* module 26 call 18 pallet:democracy call:reap_preimage */
        return STR_ME_REAP_PREIMAGE;
case 6675: /* module 26 call 19 pallet:democracy call:unlock */
        return STR_ME_UNLOCK;
case 6676: /* module 26 call 20 pallet:democracy call:remove_vote */
        return STR_ME_REMOVE_VOTE;
case 6677: /* module 26 call 21 pallet:democracy call:remove_other_vote */
        return STR_ME_REMOVE_OTHER_VOTE;
case 6678: /* module 26 call 22 pallet:democracy call:enact_proposal */
        return STR_ME_ENACT_PROPOSAL;
case 6680: /* module 26 call 24 pallet:democracy call:cancel_proposal */
        return STR_ME_CANCEL_PROPOSAL;
case 6144: /* module 24 call 00 pallet:council call:set_members */
        return STR_ME_SET_MEMBERS;
case 6145: /* module 24 call 01 pallet:council call:execute */
        return STR_ME_EXECUTE;
case 6146: /* module 24 call 02 pallet:council call:propose */
        return STR_ME_PROPOSE;
case 6147: /* module 24 call 03 pallet:council call:vote */
        return STR_ME_VOTE;
case 6150: /* module 24 call 06 pallet:council call:close */
        return STR_ME_CLOSE;
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
        return STR_ME_DISAPPROVE_PROPOSAL;
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
        return STR_ME_SET_MEMBERS;
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
        return STR_ME_EXECUTE;
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
        return STR_ME_PROPOSE;
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
        return STR_ME_VOTE;
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
        return STR_ME_CLOSE;
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
        return STR_ME_DISAPPROVE_PROPOSAL;
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
        return STR_ME_ADD_MEMBER;
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
        return STR_ME_REMOVE_MEMBER;
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
        return STR_ME_SWAP_MEMBER;
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
        return STR_ME_RESET_MEMBERS;
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
        return STR_ME_CHANGE_KEY;
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
        return STR_ME_SET_PRIME;
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
        return STR_ME_CLEAR_PRIME;
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
        return STR_ME_ADD_REGISTRAR;
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
        return STR_ME_CLEAR_IDENTITY;
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
        return STR_ME_REQUEST_JUDGEMENT;
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
        return STR_ME_CANCEL_REQUEST;
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
        return STR_ME_SET_FEE;
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
        return STR_ME_SET_ACCOUNT_ID;
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
        return STR_ME_KILL_IDENTITY;
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
        return STR_ME_REMOVE_SUB;
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
        return STR_ME_QUIT_SUB;
case 6912: /* module 27 call 00 pallet:multisig call:as_multi_threshold_1 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
case 6913: /* module 27 call 01 pallet:multisig call:as_multi */
        return STR_ME_AS_MULTI;
case 6914: /* module 27 call 02 pallet:multisig call:approve_as_multi */
        return STR_ME_APPROVE_AS_MULTI;
case 6915: /* module 27 call 03 pallet:multisig call:cancel_as_multi */
        return STR_ME_CANCEL_AS_MULTI;
case 5632: /* module 22 call 00 pallet:preimage call:note_preimage */
        return STR_ME_NOTE_PREIMAGE;
case 5633: /* module 22 call 01 pallet:preimage call:unnote_preimage */
        return STR_ME_UNNOTE_PREIMAGE;
case 5634: /* module 22 call 02 pallet:preimage call:request_preimage */
        return STR_ME_REQUEST_PREIMAGE;
case 5635: /* module 22 call 03 pallet:preimage call:unrequest_preimage */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 10240: /* module x40 call 0 */
        return STR_ME_ADD_CHILD_BOUNTY;
    case 10241: /* module x40 call 1 */
        return STR_ME_PROPOSE_CURATOR;
    case 10242: /* module x40 call 2 */
        return STR_ME_ACCEPT_CURATOR;
    case 10243: /* module x40 call 3 */
        return STR_ME_UNASSIGN_CURATOR;
    case 10244: /* module x40 call 4 */
        return STR_ME_AWARD_CHILD_BOUNTY;
    case 10245: /* module x40 call 5 */
        return STR_ME_CLAIM_CHILD_BOUNTY;
    case 10246: /* module x40 call 6 */
        return STR_ME_CLOSE_CHILD_BOUNTY;
case 3844: /* module 15 call 04 pallet:electionprovidermultiphase call:governance_fallback */
        return STR_ME_GOVERNANCE_FALLBACK;
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
case 1024: /* module 04 call 00 pallet:balances call:transfer */
        return 2;
case 1026: /* module 04 call 02 pallet:balances call:force_transfer */
        return 3;
case 1027: /* module 04 call 03 pallet:balances call:transfer_keep_alive */
        return 2;
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
        return 2;
case 3328: /* module 13 call 00 pallet:staking call:bond */
        return 3;
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
        return 1;
case 3330: /* module 13 call 02 pallet:staking call:unbond */
        return 1;
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
        return 1;
case 3332: /* module 13 call 04 pallet:staking call:validate */
        return 1;
case 3333: /* module 13 call 05 pallet:staking call:nominate */
        return 1;
case 3334: /* module 13 call 06 pallet:staking call:chill */
        return 0;
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
        return 1;
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
        return 1;
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
        return 2;
case 3347: /* module 13 call 19 pallet:staking call:rebond */
        return 1;
case 2304: /* module 09 call 00 pallet:session call:set_keys */
        return 2;
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
        return 0;
case 5376: /* module 21 call 00 pallet:utility call:batch */
        return 1;
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
        return 1;
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
        return 1;
    case 18688: /* module x73 call 0 */
        return 6;
    case 18689: /* module x73 call 1 */
        return 3;
    case 18690: /* module x73 call 2 */
        return 2;
    case 18691: /* module x73 call 3 */
        return 1;
    case 18692: /* module x73 call 4 */
        return 1;
    case 18693: /* module x73 call 5 */
        return 6;
    case 18694: /* module x73 call 6 */
        return 2;
    case 18695: /* module x73 call 7 */
        return 1;
    case 18696: /* module x73 call 8 */
        return 2;
#ifdef SUBSTRATE_PARSER_FULL
case 0: /* module 00 call 00 pallet:system call:fill_block */
        return 1;
case 1: /* module 00 call 01 pallet:system call:remark */
        return 1;
case 2: /* module 00 call 02 pallet:system call:set_heap_pages */
        return 1;
case 3: /* module 00 call 03 pallet:system call:set_code */
        return 1;
case 4: /* module 00 call 04 pallet:system call:set_code_without_checks */
        return 1;
case 8: /* module 00 call 08 pallet:system call:remark_with_event */
        return 1;
case 768: /* module 03 call 00 pallet:timestamp call:set */
        return 1;
case 1025: /* module 04 call 01 pallet:balances call:set_balance */
        return 3;
case 1029: /* module 04 call 05 pallet:balances call:force_unreserve */
        return 2;
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
        return 1;
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
        return 1;
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
        return 0;
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
        return 0;
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
        return 1;
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
        return 2;
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
        return 0;
case 3345: /* module 13 call 17 pallet:staking call:cancel_deferred_slash */
        return 2;
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
        return 2;
case 3349: /* module 13 call 21 pallet:staking call:kick */
        return 1;
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
        return 1;
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
        return 1;
case 2562: /* module 10 call 02 pallet:grandpa call:note_stalled */
        return 2;
case 6656: /* module 26 call 00 pallet:democracy call:propose */
        return 2;
case 6657: /* module 26 call 01 pallet:democracy call:second */
        return 2;
case 6658: /* module 26 call 02 pallet:democracy call:vote */
        return 2;
case 6659: /* module 26 call 03 pallet:democracy call:emergency_cancel */
        return 1;
case 6660: /* module 26 call 04 pallet:democracy call:external_propose */
        return 1;
case 6661: /* module 26 call 05 pallet:democracy call:external_propose_majority */
        return 1;
case 6662: /* module 26 call 06 pallet:democracy call:external_propose_default */
        return 1;
case 6663: /* module 26 call 07 pallet:democracy call:fast_track */
        return 3;
case 6664: /* module 26 call 08 pallet:democracy call:veto_external */
        return 1;
case 6665: /* module 26 call 09 pallet:democracy call:cancel_referendum */
        return 1;
case 6666: /* module 26 call 10 pallet:democracy call:cancel_queued */
        return 1;
case 6667: /* module 26 call 11 pallet:democracy call:delegate */
        return 3;
case 6668: /* module 26 call 12 pallet:democracy call:undelegate */
        return 0;
case 6669: /* module 26 call 13 pallet:democracy call:clear_public_proposals */
        return 0;
case 6670: /* module 26 call 14 pallet:democracy call:note_preimage */
        return 1;
case 6671: /* module 26 call 15 pallet:democracy call:note_preimage_operational */
        return 1;
case 6672: /* module 26 call 16 pallet:democracy call:note_imminent_preimage */
        return 1;
case 6673: /* module 26 call 17 pallet:democracy call:note_imminent_preimage_operational */
        return 1;
case 6674: /* module 26 call 18 pallet:democracy call:reap_preimage */
        return 2;
case 6675: /* module 26 call 19 pallet:democracy call:unlock */
        return 1;
case 6676: /* module 26 call 20 pallet:democracy call:remove_vote */
        return 1;
case 6677: /* module 26 call 21 pallet:democracy call:remove_other_vote */
        return 2;
case 6678: /* module 26 call 22 pallet:democracy call:enact_proposal */
        return 2;
case 6680: /* module 26 call 24 pallet:democracy call:cancel_proposal */
        return 1;
case 6144: /* module 24 call 00 pallet:council call:set_members */
        return 3;
case 6145: /* module 24 call 01 pallet:council call:execute */
        return 2;
case 6146: /* module 24 call 02 pallet:council call:propose */
        return 3;
case 6147: /* module 24 call 03 pallet:council call:vote */
        return 3;
case 6150: /* module 24 call 06 pallet:council call:close */
        return 4;
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
        return 1;
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
        return 3;
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
        return 2;
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
        return 3;
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
        return 3;
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
        return 4;
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
        return 1;
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
        return 1;
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
        return 1;
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
        return 2;
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
        return 1;
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
        return 1;
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
        return 1;
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
        return 0;
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
        return 1;
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
        return 0;
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
        return 2;
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
        return 1;
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
        return 2;
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
        return 2;
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
        return 1;
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
        return 1;
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
        return 0;
case 6912: /* module 27 call 00 pallet:multisig call:as_multi_threshold_1 */
        return 2;
case 6913: /* module 27 call 01 pallet:multisig call:as_multi */
        return 6;
case 6914: /* module 27 call 02 pallet:multisig call:approve_as_multi */
        return 5;
case 6915: /* module 27 call 03 pallet:multisig call:cancel_as_multi */
        return 4;
case 5632: /* module 22 call 00 pallet:preimage call:note_preimage */
        return 1;
case 5633: /* module 22 call 01 pallet:preimage call:unnote_preimage */
        return 1;
case 5634: /* module 22 call 02 pallet:preimage call:request_preimage */
        return 1;
case 5635: /* module 22 call 03 pallet:preimage call:unrequest_preimage */
        return 1;
    case 10240: /* module x40 call 0 */
        return 3;
    case 10241: /* module x40 call 1 */
        return 4;
    case 10242: /* module x40 call 2 */
        return 2;
    case 10243: /* module x40 call 3 */
        return 2;
    case 10244: /* module x40 call 4 */
        return 3;
    case 10245: /* module x40 call 5 */
        return 2;
    case 10246: /* module x40 call 6 */
        return 2;
case 3844: /* module 15 call 04 pallet:electionprovidermultiphase call:governance_fallback */
        return 2;
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
case 1024: /* module 04 call 00 pallet:balances call:transfer */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 1026: /* module 04 call 02 pallet:balances call:force_transfer */
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
case 1027: /* module 04 call 03 pallet:balances call:transfer_keep_alive */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_keep_alive;
        default:
            return NULL;
        }
case 3328: /* module 13 call 00 pallet:staking call:bond */
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
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 3330: /* module 13 call 02 pallet:staking call:unbond */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
case 3332: /* module 13 call 04 pallet:staking call:validate */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
case 3333: /* module 13 call 05 pallet:staking call:nominate */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
case 3334: /* module 13 call 06 pallet:staking call:chill */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
case 3347: /* module 13 call 19 pallet:staking call:rebond */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 2304: /* module 09 call 00 pallet:session call:set_keys */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 5376: /* module 21 call 00 pallet:utility call:batch */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 18688: /* module x73 call 0 */
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
    case 18689: /* module x73 call 1 */
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
    case 18690: /* module x73 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18691: /* module x73 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18692: /* module x73 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18693: /* module x73 call 5 */
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
    case 18694: /* module x73 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 18695: /* module x73 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 18696: /* module x73 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_signature;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
case 0: /* module 00 call 00 pallet:system call:fill_block */
        switch (itemIdx) {
        case 0:
            return STR_IT_ratio;
        default:
            return NULL;
        }
case 1: /* module 00 call 01 pallet:system call:remark */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
case 2: /* module 00 call 02 pallet:system call:set_heap_pages */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
case 3: /* module 00 call 03 pallet:system call:set_code */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
case 4: /* module 00 call 04 pallet:system call:set_code_without_checks */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
case 8: /* module 00 call 08 pallet:system call:remark_with_event */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
case 768: /* module 03 call 00 pallet:timestamp call:set */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
case 1025: /* module 04 call 01 pallet:balances call:set_balance */
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
case 1029: /* module 04 call 05 pallet:balances call:force_unreserve */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 3345: /* module 13 call 17 pallet:staking call:cancel_deferred_slash */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
case 3349: /* module 13 call 21 pallet:staking call:kick */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        default:
            return NULL;
        }
case 2562: /* module 10 call 02 pallet:grandpa call:note_stalled */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
case 6656: /* module 26 call 00 pallet:democracy call:propose */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
case 6657: /* module 26 call 01 pallet:democracy call:second */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
case 6658: /* module 26 call 02 pallet:democracy call:vote */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
case 6659: /* module 26 call 03 pallet:democracy call:emergency_cancel */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
case 6660: /* module 26 call 04 pallet:democracy call:external_propose */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
case 6661: /* module 26 call 05 pallet:democracy call:external_propose_majority */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
case 6662: /* module 26 call 06 pallet:democracy call:external_propose_default */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
case 6663: /* module 26 call 07 pallet:democracy call:fast_track */
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
case 6664: /* module 26 call 08 pallet:democracy call:veto_external */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
case 6665: /* module 26 call 09 pallet:democracy call:cancel_referendum */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
case 6666: /* module 26 call 10 pallet:democracy call:cancel_queued */
        switch (itemIdx) {
        case 0:
            return STR_IT_which;
        default:
            return NULL;
        }
case 6667: /* module 26 call 11 pallet:democracy call:delegate */
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
case 6668: /* module 26 call 12 pallet:democracy call:undelegate */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 6669: /* module 26 call 13 pallet:democracy call:clear_public_proposals */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 6670: /* module 26 call 14 pallet:democracy call:note_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
case 6671: /* module 26 call 15 pallet:democracy call:note_preimage_operational */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
case 6672: /* module 26 call 16 pallet:democracy call:note_imminent_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
case 6673: /* module 26 call 17 pallet:democracy call:note_imminent_preimage_operational */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
case 6674: /* module 26 call 18 pallet:democracy call:reap_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
case 6675: /* module 26 call 19 pallet:democracy call:unlock */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
case 6676: /* module 26 call 20 pallet:democracy call:remove_vote */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
case 6677: /* module 26 call 21 pallet:democracy call:remove_other_vote */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
case 6678: /* module 26 call 22 pallet:democracy call:enact_proposal */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
case 6680: /* module 26 call 24 pallet:democracy call:cancel_proposal */
        switch (itemIdx) {
        case 0:
            return STR_IT_prop_index;
        default:
            return NULL;
        }
case 6144: /* module 24 call 00 pallet:council call:set_members */
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
case 6145: /* module 24 call 01 pallet:council call:execute */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
case 6146: /* module 24 call 02 pallet:council call:propose */
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
case 6147: /* module 24 call 03 pallet:council call:vote */
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
case 6150: /* module 24 call 06 pallet:council call:close */
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
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
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
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
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
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
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
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
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
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new_;
        default:
            return NULL;
        }
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
        switch (itemIdx) {
        default:
            return NULL;
        }
case 6912: /* module 27 call 00 pallet:multisig call:as_multi_threshold_1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
case 6913: /* module 27 call 01 pallet:multisig call:as_multi */
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
case 6914: /* module 27 call 02 pallet:multisig call:approve_as_multi */
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
case 6915: /* module 27 call 03 pallet:multisig call:cancel_as_multi */
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
case 5632: /* module 22 call 00 pallet:preimage call:note_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
case 5633: /* module 22 call 01 pallet:preimage call:unnote_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
case 5634: /* module 22 call 02 pallet:preimage call:request_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
case 5635: /* module 22 call 03 pallet:preimage call:unrequest_preimage */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 10240: /* module x40 call 0 */
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
    case 10241: /* module x40 call 1 */
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
    case 10242: /* module x40 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10243: /* module x40 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10244: /* module x40 call 4 */
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
    case 10245: /* module x40 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
    case 10246: /* module x40 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_parent_bounty_id;
        case 1:
            return STR_IT_child_bounty_id;
        default:
            return NULL;
        }
case 3844: /* module 15 call 04 pallet:electionprovidermultiphase call:governance_fallback */
        switch (itemIdx) {
        case 0:
            return STR_IT_maybe_max_voters;
        case 1:
            return STR_IT_maybe_max_targets;
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
case 1024: /* module 04 call 00 pallet:balances call:transfer */
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
case 1026: /* module 04 call 02 pallet:balances call:force_transfer */
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
case 1027: /* module 04 call 03 pallet:balances call:transfer_keep_alive */
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
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
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
case 3328: /* module 13 call 00 pallet:staking call:bond */
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
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3330: /* module 13 call 02 pallet:staking call:unbond */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3332: /* module 13 call 04 pallet:staking call:validate */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3333: /* module 13 call 05 pallet:staking call:nominate */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3334: /* module 13 call 06 pallet:staking call:chill */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
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
case 3347: /* module 13 call 19 pallet:staking call:rebond */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 2304: /* module 09 call 00 pallet:session call:set_keys */
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
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 5376: /* module 21 call 00 pallet:utility call:batch */
        switch (itemIdx) {
        case 0: /* utility_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }

#ifdef SUBSTRATE_PARSER_FULL
case 0: /* module 00 call 00 pallet:system call:fill_block */
        switch (itemIdx) {
        case 0: /* system_fill_block_V1 - ratio */;
            return _toStringPerbill_V1(
                &m->nested.system_fill_block_V1.ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 1: /* module 00 call 01 pallet:system call:remark */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 2: /* module 00 call 02 pallet:system call:set_heap_pages */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V1 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V1.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3: /* module 00 call 03 pallet:system call:set_code */
        switch (itemIdx) {
        case 0: /* system_set_code_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4: /* module 00 call 04 pallet:system call:set_code_without_checks */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V1 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V1.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 8: /* module 00 call 08 pallet:system call:remark_with_event */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_with_event_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 768: /* module 03 call 00 pallet:timestamp call:set */
        switch (itemIdx) {
        case 0: /* timestamp_set_V1 - now */;
            return _toStringCompactu64(
                &m->basic.timestamp_set_V1.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 1025: /* module 04 call 01 pallet:balances call:set_balance */
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
case 1029: /* module 04 call 05 pallet:balances call:force_unreserve */
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
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V1 - new_ */;
            return _toStringCompactu32(
                &m->basic.staking_set_validator_count_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V1 - additional */;
            return _toStringCompactu32(
                &m->basic.staking_increase_validator_count_V1.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V1 - invulnerables */;
            return _toStringVecAccountId_V1(
                &m->basic.staking_set_invulnerables_V1.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
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
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 3345: /* module 13 call 17 pallet:staking call:cancel_deferred_slash */
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
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
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
case 3349: /* module 13 call 21 pallet:staking call:kick */
        switch (itemIdx) {
        case 0: /* staking_kick_V1 - who */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_kick_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
        switch (itemIdx) {
        case 0: /* staking_chill_other_V1 - controller */;
            return _toStringAccountId_V1(
                &m->basic.staking_chill_other_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
        switch (itemIdx) {
        case 0: /* staking_force_apply_min_commission_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_force_apply_min_commission_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 2562: /* module 10 call 02 pallet:grandpa call:note_stalled */
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
case 6656: /* module 26 call 00 pallet:democracy call:propose */
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
case 6657: /* module 26 call 01 pallet:democracy call:second */
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
case 6658: /* module 26 call 02 pallet:democracy call:vote */
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
case 6659: /* module 26 call 03 pallet:democracy call:emergency_cancel */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V1 - ref_index */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_emergency_cancel_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6660: /* module 26 call 04 pallet:democracy call:external_propose */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_external_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6661: /* module 26 call 05 pallet:democracy call:external_propose_majority */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_external_propose_majority_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6662: /* module 26 call 06 pallet:democracy call:external_propose_default */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_external_propose_default_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6663: /* module 26 call 07 pallet:democracy call:fast_track */
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
case 6664: /* module 26 call 08 pallet:democracy call:veto_external */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V1 - proposal_hash */;
            return _toStringHash(
                &m->nested.democracy_veto_external_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6665: /* module 26 call 09 pallet:democracy call:cancel_referendum */
        switch (itemIdx) {
        case 0: /* democracy_cancel_referendum_V1 - ref_index */;
            return _toStringCompactu32(
                &m->nested.democracy_cancel_referendum_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6666: /* module 26 call 10 pallet:democracy call:cancel_queued */
        switch (itemIdx) {
        case 0: /* democracy_cancel_queued_V1 - which */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_cancel_queued_V1.which,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6667: /* module 26 call 11 pallet:democracy call:delegate */
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
case 6668: /* module 26 call 12 pallet:democracy call:undelegate */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 6669: /* module 26 call 13 pallet:democracy call:clear_public_proposals */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 6670: /* module 26 call 14 pallet:democracy call:note_preimage */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6671: /* module 26 call 15 pallet:democracy call:note_preimage_operational */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6672: /* module 26 call 16 pallet:democracy call:note_imminent_preimage */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6673: /* module 26 call 17 pallet:democracy call:note_imminent_preimage_operational */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6674: /* module 26 call 18 pallet:democracy call:reap_preimage */
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
case 6675: /* module 26 call 19 pallet:democracy call:unlock */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V1 - target */;
            return _toStringAccountId_V1(
                &m->nested.democracy_unlock_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6676: /* module 26 call 20 pallet:democracy call:remove_vote */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->nested.democracy_remove_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6677: /* module 26 call 21 pallet:democracy call:remove_other_vote */
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
case 6678: /* module 26 call 22 pallet:democracy call:enact_proposal */
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
case 6680: /* module 26 call 24 pallet:democracy call:cancel_proposal */
        switch (itemIdx) {
        case 0: /* democracy_cancel_proposal_V1 - prop_index */;
            return _toStringCompactu32(
                &m->nested.democracy_cancel_proposal_V1.prop_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6144: /* module 24 call 00 pallet:council call:set_members */
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
case 6145: /* module 24 call 01 pallet:council call:execute */
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
case 6146: /* module 24 call 02 pallet:council call:propose */
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
case 6147: /* module 24 call 03 pallet:council call:vote */
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
case 6150: /* module 24 call 06 pallet:council call:close */
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
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
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
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
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
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
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
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
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
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
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
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
        switch (itemIdx) {
        case 0: /* technicalmembership_add_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_add_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
        switch (itemIdx) {
        case 0: /* technicalmembership_remove_member_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_remove_member_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
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
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
        switch (itemIdx) {
        case 0: /* technicalmembership_reset_members_V1 - members */;
            return _toStringVecAccountId_V1(
                &m->basic.technicalmembership_reset_members_V1.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
        switch (itemIdx) {
        case 0: /* technicalmembership_change_key_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_change_key_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
        switch (itemIdx) {
        case 0: /* technicalmembership_set_prime_V1 - who */;
            return _toStringAccountId_V1(
                &m->basic.technicalmembership_set_prime_V1.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.identity_add_registrar_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
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
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V1 - reg_index */;
            return _toStringRegistrarIndex_V1(
                &m->basic.identity_cancel_request_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
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
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
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
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_kill_identity_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V1 - sub */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_remove_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
case 6912: /* module 27 call 00 pallet:multisig call:as_multi_threshold_1 */
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
case 6913: /* module 27 call 01 pallet:multisig call:as_multi */
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
case 6914: /* module 27 call 02 pallet:multisig call:approve_as_multi */
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
case 6915: /* module 27 call 03 pallet:multisig call:cancel_as_multi */
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
case 5632: /* module 22 call 00 pallet:preimage call:note_preimage */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V1 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V1.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 5633: /* module 22 call 01 pallet:preimage call:unnote_preimage */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V1 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 5634: /* module 22 call 02 pallet:preimage call:request_preimage */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V1 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 5635: /* module 22 call 03 pallet:preimage call:unrequest_preimage */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V1 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V1.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 3844: /* module 15 call 04 pallet:electionprovidermultiphase call:governance_fallback */
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
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
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
case 768: /* module 03 call 00 pallet:timestamp call:set */
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
    case 1285: // Balances:Force unreserve
case 3328: /* module 13 call 00 pallet:staking call:bond */
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
case 3330: /* module 13 call 02 pallet:staking call:unbond */
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
case 3332: /* module 13 call 04 pallet:staking call:validate */
case 3333: /* module 13 call 05 pallet:staking call:nominate */
case 3334: /* module 13 call 06 pallet:staking call:chill */
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
case 3345: /* module 13 call 17 pallet:staking call:cancel_deferred_slash */
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
case 3347: /* module 13 call 19 pallet:staking call:rebond */
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
case 3349: /* module 13 call 21 pallet:staking call:kick */
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
case 2304: /* module 09 call 00 pallet:session call:set_keys */
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
case 2562: /* module 10 call 02 pallet:grandpa call:note_stalled */
case 6670: /* module 26 call 14 pallet:democracy call:note_preimage */
case 6671: /* module 26 call 15 pallet:democracy call:note_preimage_operational */
case 6672: /* module 26 call 16 pallet:democracy call:note_imminent_preimage */
case 6673: /* module 26 call 17 pallet:democracy call:note_imminent_preimage_operational */
case 6144: /* module 24 call 00 pallet:council call:set_members */
case 6145: /* module 24 call 01 pallet:council call:execute */
case 6146: /* module 24 call 02 pallet:council call:propose */
case 6147: /* module 24 call 03 pallet:council call:vote */
case 6150: /* module 24 call 06 pallet:council call:close */
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
case 5376: /* module 21 call 00 pallet:utility call:batch */
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
case 5632: /* module 22 call 00 pallet:preimage call:note_preimage */
case 5633: /* module 22 call 01 pallet:preimage call:unnote_preimage */
case 5634: /* module 22 call 02 pallet:preimage call:request_preimage */
case 5635: /* module 22 call 03 pallet:preimage call:unrequest_preimage */
case 3844: /* module 15 call 04 pallet:electionprovidermultiphase call:governance_fallback */
        return false;
    default:
        return true;
    }
}