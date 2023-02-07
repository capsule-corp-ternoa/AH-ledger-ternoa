/*******************************************************************************
*  (c) 2019 - 2023 Zondax AG
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
/** ******************************************************************************
 *  (c) 2023 CapsuleCorp
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
 ******************************************************************************* */

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
   parser_context_t* c, pd_balances_transfer_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
   CHECK_ERROR(_readCompactBalance(c, &m->amount))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V1(
   parser_context_t* c, pd_balances_force_transfer_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->source))
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
   CHECK_ERROR(_readCompactBalance(c, &m->amount))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
   parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
   CHECK_ERROR(_readCompactBalance(c, &m->amount))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V1(
   parser_context_t* c, pd_balances_transfer_all_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
   CHECK_ERROR(_readbool(c, &m->keep_alive))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
   parser_context_t* c, pd_staking_bond_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->controller))
   CHECK_ERROR(_readCompactBalance(c, &m->amount))
   CHECK_ERROR(_readRewardDestination(c, &m->payee))
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
   CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
   parser_context_t* c, pd_staking_nominate_V1_t* m)
{
   CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
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
   CHECK_ERROR(_readRewardDestination(c, &m->payee))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
   parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->controller))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
   parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
   CHECK_ERROR(_readAccountId(c, &m->validator_stash))
   CHECK_ERROR(_readEraIndex(c, &m->era))
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
   CHECK_ERROR(_readKeys(c, &m->keys))
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
#ifndef TARGET_NANOS
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V1(
   parser_context_t* c, pd_system_remark_V1_t* m)
{
   CHECK_ERROR(_readBytes(c, &m->remark))
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
   CHECK_ERROR(_readBytes(c, &m->remark))
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
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
   CHECK_ERROR(_readCompactBalance(c, &m->new_free))
   CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_unreserve_V1(
   parser_context_t* c, pd_balances_force_unreserve_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
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

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V1(
   parser_context_t* c, pd_staking_scale_validator_count_V1_t* m)
{
   CHECK_ERROR(_readPercent(c, &m->factor))
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
   CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V1(
   parser_context_t* c, pd_staking_force_unstake_V1_t* m)
{
   CHECK_ERROR(_readAccountId(c, &m->stash))
   CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V1(
   parser_context_t* c, pd_staking_force_new_era_always_V1_t* m)
{
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V1(
   parser_context_t* c, pd_staking_reap_stash_V1_t* m)
{
   CHECK_ERROR(_readAccountId(c, &m->stash))
   CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V1(
   parser_context_t* c, pd_staking_kick_V1_t* m)
{
   CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->who))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_configs_V1(
   parser_context_t* c, pd_staking_set_staking_configs_V1_t* m)
{
   CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_nominator_bond))
   CHECK_ERROR(_readConfigOpBalanceOfT(c, &m->min_validator_bond))
   CHECK_ERROR(_readConfigOpu32(c, &m->max_nominator_count))
   CHECK_ERROR(_readConfigOpu32(c, &m->max_validator_count))
   CHECK_ERROR(_readConfigOpPercent(c, &m->chill_threshold))
   CHECK_ERROR(_readConfigOpPerbill(c, &m->min_commission))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V1(
   parser_context_t* c, pd_staking_chill_other_V1_t* m)
{
   CHECK_ERROR(_readAccountId(c, &m->controller))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_apply_min_commission_V1(
   parser_context_t* c, pd_staking_force_apply_min_commission_V1_t* m)
{
   CHECK_ERROR(_readAccountId(c, &m->validator_stash))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_set_members_V1(
   parser_context_t* c, pd_council_set_members_V1_t* m)
{
   CHECK_ERROR(_readVecAccountId(c, &m->new_members))
   CHECK_ERROR(_readOptionAccountId(c, &m->prime))
   CHECK_ERROR(_readMemberCount(c, &m->old_count))
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

__Z_INLINE parser_error_t _readMethod_council_close_old_weight_V1(
   parser_context_t* c, pd_council_close_old_weight_V1_t* m)
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

__Z_INLINE parser_error_t _readMethod_council_close_V1(
   parser_context_t* c, pd_council_close_V1_t* m)
{
   CHECK_ERROR(_readHash(c, &m->proposal_hash))
   CHECK_ERROR(_readCompactu32(c, &m->index))
   CHECK_ERROR(_readWeight(c, &m->proposal_weight_bound))
   CHECK_ERROR(_readCompactu32(c, &m->length_bound))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_members_V1(
   parser_context_t* c, pd_technicalcommittee_set_members_V1_t* m)
{
   CHECK_ERROR(_readVecAccountId(c, &m->new_members))
   CHECK_ERROR(_readOptionAccountId(c, &m->prime))
   CHECK_ERROR(_readMemberCount(c, &m->old_count))
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

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_old_weight_V1(
   parser_context_t* c, pd_technicalcommittee_close_old_weight_V1_t* m)
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

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V1(
   parser_context_t* c, pd_technicalcommittee_close_V1_t* m)
{
   CHECK_ERROR(_readHash(c, &m->proposal_hash))
   CHECK_ERROR(_readCompactu32(c, &m->index))
   CHECK_ERROR(_readWeight(c, &m->proposal_weight_bound))
   CHECK_ERROR(_readCompactu32(c, &m->length_bound))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_phragmenelection_vote_V1(
   parser_context_t* c, pd_phragmenelection_vote_V1_t* m)
{
   CHECK_ERROR(_readVecAccountId(c, &m->votes))
   CHECK_ERROR(_readCompactBalance(c, &m->amount))
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
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
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
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_remove_member_V1(
   parser_context_t* c, pd_technicalmembership_remove_member_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_swap_member_V1(
   parser_context_t* c, pd_technicalmembership_swap_member_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->remove))
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->add))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_reset_members_V1(
   parser_context_t* c, pd_technicalmembership_reset_members_V1_t* m)
{
   CHECK_ERROR(_readVecAccountId(c, &m->members))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_change_key_V1(
   parser_context_t* c, pd_technicalmembership_change_key_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_set_prime_V1(
   parser_context_t* c, pd_technicalmembership_set_prime_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->who))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalmembership_clear_prime_V1(
   parser_context_t* c, pd_technicalmembership_clear_prime_V1_t* m)
{
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_mandate_mandate_V1(
    parser_context_t* c, pd_mandate_mandate_V1_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V1(
   parser_context_t* c, pd_treasury_propose_spend_V1_t* m)
{
   CHECK_ERROR(_readCompactBalance(c, &m->amount))
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
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
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->beneficiary))
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
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->account))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_identity_V1(
   parser_context_t* c, pd_identity_set_identity_V1_t* m)
{
   CHECK_ERROR(_readIdentityInfo(c, &m->info))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_subs_V1(
   parser_context_t* c, pd_identity_set_subs_V1_t* m)
{
   CHECK_ERROR(_readVecTupleAccountIdData(c, &m->subs))
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
   CHECK_ERROR(_readRegistrarIndex(c, &m->reg_index))
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
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_provide_judgement_V1(
   parser_context_t* c, pd_identity_provide_judgement_V1_t* m)
{
   CHECK_ERROR(_readCompactu32(c, &m->reg_index))
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
   CHECK_ERROR(_readJudgementBalanceOfT(c, &m->judgement))
   CHECK_ERROR(_readHash(c, &m->identity))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
   parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->target))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_sub_V1(
   parser_context_t* c, pd_identity_add_sub_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
   CHECK_ERROR(_readData(c, &m->data))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rename_sub_V1(
   parser_context_t* c, pd_identity_rename_sub_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
   CHECK_ERROR(_readData(c, &m->data))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V1(
   parser_context_t* c, pd_identity_remove_sub_V1_t* m)
{
   CHECK_ERROR(_readAccountIdLookupOfT(c, &m->sub))
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
   CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
   CHECK_ERROR(_readCall(c, &m->call))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(
   parser_context_t* c, pd_multisig_as_multi_V1_t* m)
{
   CHECK_ERROR(_readu16(c, &m->threshold))
   CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
   CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
   CHECK_ERROR(_readCall(c, &m->call))
   CHECK_ERROR(_readWeight(c, &m->max_weight))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(
   parser_context_t* c, pd_multisig_approve_as_multi_V1_t* m)
{
   CHECK_ERROR(_readu16(c, &m->threshold))
   CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
   CHECK_ERROR(_readOptionTimepoint(c, &m->maybe_timepoint))
   CHECK_ERROR(_readH256(c, &m->call_hash))
   CHECK_ERROR(_readWeight(c, &m->max_weight))
   return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
   parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
   CHECK_ERROR(_readu16(c, &m->threshold))
   CHECK_ERROR(_readVecAccountId(c, &m->other_signatories))
   CHECK_ERROR(_readTimepoint(c, &m->timepoint))
   CHECK_ERROR(_readH256(c, &m->call_hash))
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
       CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->nested.staking_bond_V1))
       break;
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
       CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
       break;
case 3330: /* module 13 call 02 pallet:staking call:unbond */
       CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->nested.staking_unbond_V1))
       break;
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
       CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
       break;
case 3332: /* module 13 call 04 pallet:staking call:validate */
       CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
       break;
case 3333: /* module 13 call 05 pallet:staking call:nominate */
       CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->nested.staking_nominate_V1))
       break;
case 3334: /* module 13 call 06 pallet:staking call:chill */
       CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->nested.staking_chill_V1))
       break;
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
       CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
       break;
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
       CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->nested.staking_set_controller_V1))
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
#ifndef TARGET_NANOS
#endif
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
case 1025: /* module 04 call 01 pallet:balances call:set_balance */
       CHECK_ERROR(_readMethod_balances_set_balance_V1(c, &method->nested.balances_set_balance_V1))
       break;
case 1029: /* module 04 call 05 pallet:balances call:force_unreserve */
       CHECK_ERROR(_readMethod_balances_force_unreserve_V1(c, &method->basic.balances_force_unreserve_V1))
       break;
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
       CHECK_ERROR(_readMethod_staking_set_validator_count_V1(c, &method->basic.staking_set_validator_count_V1))
       break;
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
       CHECK_ERROR(_readMethod_staking_increase_validator_count_V1(c, &method->basic.staking_increase_validator_count_V1))
       break;
case 3339: /* module 13 call 11 pallet:staking call:scale_validator_count */
       CHECK_ERROR(_readMethod_staking_scale_validator_count_V1(c, &method->basic.staking_scale_validator_count_V1))
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
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
       CHECK_ERROR(_readMethod_staking_reap_stash_V1(c, &method->basic.staking_reap_stash_V1))
       break;
case 3349: /* module 13 call 21 pallet:staking call:kick */
       CHECK_ERROR(_readMethod_staking_kick_V1(c, &method->basic.staking_kick_V1))
       break;
case 3350: /* module 13 call 22 pallet:staking call:set_staking_configs */
       CHECK_ERROR(_readMethod_staking_set_staking_configs_V1(c, &method->basic.staking_set_staking_configs_V1))
       break;
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
       CHECK_ERROR(_readMethod_staking_chill_other_V1(c, &method->basic.staking_chill_other_V1))
       break;
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
       CHECK_ERROR(_readMethod_staking_force_apply_min_commission_V1(c, &method->basic.staking_force_apply_min_commission_V1))
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
case 6148: /* module 24 call 04 pallet:council call:close_old_weight */
       CHECK_ERROR(_readMethod_council_close_old_weight_V1(c, &method->basic.council_close_old_weight_V1))
       break;
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
       CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
       break;
case 6150: /* module 24 call 06 pallet:council call:close */
       CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
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
case 4356: /* module 17 call 04 pallet:technicalcommittee call:close_old_weight */
       CHECK_ERROR(_readMethod_technicalcommittee_close_old_weight_V1(c, &method->basic.technicalcommittee_close_old_weight_V1))
       break;
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
       CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V1(c, &method->basic.technicalcommittee_disapprove_proposal_V1))
       break;
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
       CHECK_ERROR(_readMethod_technicalcommittee_close_V1(c, &method->basic.technicalcommittee_close_V1))
       break;
case 6400: /* module 25 call 00 pallet:phragmenelection call:vote */
       CHECK_ERROR(_readMethod_phragmenelection_vote_V1(c, &method->basic.phragmenelection_vote_V1))
       break;
case 6401: /* module 25 call 01 pallet:phragmenelection call:remove_voter */
       CHECK_ERROR(_readMethod_phragmenelection_remove_voter_V1(c, &method->basic.phragmenelection_remove_voter_V1))
       break;
case 6402: /* module 25 call 02 pallet:phragmenelection call:submit_candidacy */
       CHECK_ERROR(_readMethod_phragmenelection_submit_candidacy_V1(c, &method->basic.phragmenelection_submit_candidacy_V1))
       break;
case 6404: /* module 25 call 04 pallet:phragmenelection call:remove_member */
       CHECK_ERROR(_readMethod_phragmenelection_remove_member_V1(c, &method->basic.phragmenelection_remove_member_V1))
       break;
case 6405: /* module 25 call 05 pallet:phragmenelection call:clean_defunct_voters */
       CHECK_ERROR(_readMethod_phragmenelection_clean_defunct_voters_V1(c, &method->basic.phragmenelection_clean_defunct_voters_V1))
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
case 4864: /* module 19 call 00 pallet:mandate call:mandate */
      CHECK_ERROR(_readMethod_mandate_mandate_V1(c, &method->nested.mandate_mandate_V1))
      break;
case 5120: /* module 20 call 00 pallet:treasury call:propose_spend */
       CHECK_ERROR(_readMethod_treasury_propose_spend_V1(c, &method->basic.treasury_propose_spend_V1))
       break;
case 5121: /* module 20 call 01 pallet:treasury call:reject_proposal */
       CHECK_ERROR(_readMethod_treasury_reject_proposal_V1(c, &method->basic.treasury_reject_proposal_V1))
       break;
case 5122: /* module 20 call 02 pallet:treasury call:approve_proposal */
       CHECK_ERROR(_readMethod_treasury_approve_proposal_V1(c, &method->basic.treasury_approve_proposal_V1))
       break;
case 5123: /* module 20 call 03 pallet:treasury call:spend */
       CHECK_ERROR(_readMethod_treasury_spend_V1(c, &method->basic.treasury_spend_V1))
       break;
case 5124: /* module 20 call 04 pallet:treasury call:remove_approval */
       CHECK_ERROR(_readMethod_treasury_remove_approval_V1(c, &method->basic.treasury_remove_approval_V1))
       break;
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
       CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
       break;
case 7169: /* module 28 call 01 pallet:identity call:set_identity */
       CHECK_ERROR(_readMethod_identity_set_identity_V1(c, &method->basic.identity_set_identity_V1))
       break;
case 7170: /* module 28 call 02 pallet:identity call:set_subs */
       CHECK_ERROR(_readMethod_identity_set_subs_V1(c, &method->basic.identity_set_subs_V1))
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
case 7177: /* module 28 call 09 pallet:identity call:provide_judgement */
       CHECK_ERROR(_readMethod_identity_provide_judgement_V1(c, &method->basic.identity_provide_judgement_V1))
       break;
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
       CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
       break;
case 7179: /* module 28 call 11 pallet:identity call:add_sub */
       CHECK_ERROR(_readMethod_identity_add_sub_V1(c, &method->basic.identity_add_sub_V1))
       break;
case 7180: /* module 28 call 12 pallet:identity call:rename_sub */
       CHECK_ERROR(_readMethod_identity_rename_sub_V1(c, &method->basic.identity_rename_sub_V1))
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
    case 9:
        return STR_MO_SESSION;    
    case 13:
        return STR_MO_STAKING;
    case 21:
        return STR_MO_UTILITY;

#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 3:
        return STR_MO_TIMESTAMP;
    case 17:
        return STR_MO_TECHNICALCOMMITTEE;
    case 18:
        return STR_MO_TECHNICALMEMBERSHIP;
    case 19:
        return STR_MO_MANDATE;
    case 20:
        return STR_MO_TREASURY;
    case 24:
        return STR_MO_COUNCIL;
    case 25:
        return STR_MO_PHRAGMENELECTION;
    case 27:
        return STR_MO_MULTISIG;
    case 28:
        return STR_MO_IDENTITY;

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
#ifndef TARGET_NANOS
#endif
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
case 3339: /* module 13 call 11 pallet:staking call:scale_validator_count */
       return STR_ME_SCALE_VALIDATOR_COUNT;
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
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
       return STR_ME_REAP_STASH;
case 3349: /* module 13 call 21 pallet:staking call:kick */
       return STR_ME_KICK;
case 3350: /* module 13 call 22 pallet:staking call:set_staking_configs */
       return STR_ME_SET_STAKING_CONFIGS;
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
       return STR_ME_CHILL_OTHER;
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
       return STR_ME_FORCE_APPLY_MIN_COMMISSION;
case 4864: /* module 19 call 00 pallet:mandate call:mandate */
       return STR_ME_MANDATE;
case 6144: /* module 24 call 00 pallet:council call:set_members */
       return STR_ME_SET_MEMBERS;
case 6145: /* module 24 call 01 pallet:council call:execute */
       return STR_ME_EXECUTE;
case 6146: /* module 24 call 02 pallet:council call:propose */
       return STR_ME_PROPOSE;
case 6147: /* module 24 call 03 pallet:council call:vote */
       return STR_ME_VOTE;
case 6148: /* module 24 call 04 pallet:council call:close_old_weight */
       return STR_ME_CLOSE_OLD_WEIGHT;
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
       return STR_ME_DISAPPROVE_PROPOSAL;
case 6150: /* module 24 call 06 pallet:council call:close */
       return STR_ME_CLOSE;
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
       return STR_ME_SET_MEMBERS;
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
       return STR_ME_EXECUTE;
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
       return STR_ME_PROPOSE;
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
       return STR_ME_VOTE;
case 4356: /* module 17 call 04 pallet:technicalcommittee call:close_old_weight */
       return STR_ME_CLOSE_OLD_WEIGHT;
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
       return STR_ME_DISAPPROVE_PROPOSAL;
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
       return STR_ME_CLOSE;
case 6400: /* module 25 call 00 pallet:phragmenelection call:vote */
       return STR_ME_VOTE;
case 6401: /* module 25 call 01 pallet:phragmenelection call:remove_voter */
       return STR_ME_REMOVE_VOTER;
case 6402: /* module 25 call 02 pallet:phragmenelection call:submit_candidacy */
       return STR_ME_SUBMIT_CANDIDACY;
case 6404: /* module 25 call 04 pallet:phragmenelection call:remove_member */
       return STR_ME_REMOVE_MEMBER;
case 6405: /* module 25 call 05 pallet:phragmenelection call:clean_defunct_voters */
       return STR_ME_CLEAN_DEFUNCT_VOTERS;
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
case 5120: /* module 20 call 00 pallet:treasury call:propose_spend */
       return STR_ME_PROPOSE_SPEND;
case 5121: /* module 20 call 01 pallet:treasury call:reject_proposal */
       return STR_ME_REJECT_PROPOSAL;
case 5122: /* module 20 call 02 pallet:treasury call:approve_proposal */
       return STR_ME_APPROVE_PROPOSAL;
case 5123: /* module 20 call 03 pallet:treasury call:spend */
       return STR_ME_SPEND;
case 5124: /* module 20 call 04 pallet:treasury call:remove_approval */
       return STR_ME_REMOVE_APPROVAL;
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
       return STR_ME_ADD_REGISTRAR;
case 7169: /* module 28 call 01 pallet:identity call:set_identity */
       return STR_ME_SET_IDENTITY;
case 7170: /* module 28 call 02 pallet:identity call:set_subs */
       return STR_ME_SET_SUBS;
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
case 7177: /* module 28 call 09 pallet:identity call:provide_judgement */
       return STR_ME_PROVIDE_JUDGEMENT;
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
       return STR_ME_KILL_IDENTITY;
case 7179: /* module 28 call 11 pallet:identity call:add_sub */
       return STR_ME_ADD_SUB;
case 7180: /* module 28 call 12 pallet:identity call:rename_sub */
       return STR_ME_RENAME_SUB;
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
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
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
case 3339: /* module 13 call 11 pallet:staking call:scale_validator_count */
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
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
       return 2;
case 3349: /* module 13 call 21 pallet:staking call:kick */
       return 1;
case 3350: /* module 13 call 22 pallet:staking call:set_staking_configs */
       return 6;
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
       return 1;
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
       return 1;
case 4864: /* module 19 call 00 pallet:mandate call:mandate */
       return 1;
case 6144: /* module 24 call 00 pallet:council call:set_members */
       return 3;
case 6145: /* module 24 call 01 pallet:council call:execute */
       return 2;
case 6146: /* module 24 call 02 pallet:council call:propose */
       return 3;
case 6147: /* module 24 call 03 pallet:council call:vote */
       return 3;
case 6148: /* module 24 call 04 pallet:council call:close_old_weight */
       return 4;
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
       return 1;
case 6150: /* module 24 call 06 pallet:council call:close */
       return 4;
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
       return 3;
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
       return 2;
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
       return 3;
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
       return 3;
case 4356: /* module 17 call 04 pallet:technicalcommittee call:close_old_weight */
       return 4;
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
       return 1;
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
       return 4;
case 6400: /* module 25 call 00 pallet:phragmenelection call:vote */
       return 2;
case 6401: /* module 25 call 01 pallet:phragmenelection call:remove_voter */
       return 0;
case 6402: /* module 25 call 02 pallet:phragmenelection call:submit_candidacy */
       return 1;
case 6404: /* module 25 call 04 pallet:phragmenelection call:remove_member */
       return 3;
case 6405: /* module 25 call 05 pallet:phragmenelection call:clean_defunct_voters */
       return 2;
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
case 5120: /* module 20 call 00 pallet:treasury call:propose_spend */
       return 2;
case 5121: /* module 20 call 01 pallet:treasury call:reject_proposal */
       return 1;
case 5122: /* module 20 call 02 pallet:treasury call:approve_proposal */
       return 1;
case 5123: /* module 20 call 03 pallet:treasury call:spend */
       return 2;
case 5124: /* module 20 call 04 pallet:treasury call:remove_approval */
       return 1;
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
       return 1;
case 7169: /* module 28 call 01 pallet:identity call:set_identity */
       return 1;
case 7170: /* module 28 call 02 pallet:identity call:set_subs */
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
case 7177: /* module 28 call 09 pallet:identity call:provide_judgement */
       return 4;
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
       return 1;
case 7179: /* module 28 call 11 pallet:identity call:add_sub */
       return 2;
case 7180: /* module 28 call 12 pallet:identity call:rename_sub */
       return 2;
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
       return 1;
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
       return 0;
case 6912: /* module 27 call 00 pallet:multisig call:as_multi_threshold_1 */
       return 2;
case 6913: /* module 27 call 01 pallet:multisig call:as_multi */
       return 5;
case 6914: /* module 27 call 02 pallet:multisig call:approve_as_multi */
       return 5;
case 6915: /* module 27 call 03 pallet:multisig call:cancel_as_multi */
       return 4;
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
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
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
case 3339: /* module 13 call 11 pallet:staking call:scale_validator_count */
       switch (itemIdx) {
       case 0:
           return STR_IT_factor;
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
case 3350: /* module 13 call 22 pallet:staking call:set_staking_configs */
       switch (itemIdx) {
       case 0:
           return STR_IT_min_nominator_bond;
       case 1:
           return STR_IT_min_validator_bond;
       case 2:
           return STR_IT_max_nominator_count;
       case 3:
           return STR_IT_max_validator_count;
       case 4:
           return STR_IT_chill_threshold;
       case 5:
           return STR_IT_min_commission;
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
case 4864: /* module 19 call 00 pallet:mandate call:mandate */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
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
case 6148: /* module 24 call 04 pallet:council call:close_old_weight */
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
case 4356: /* module 17 call 04 pallet:technicalcommittee call:close_old_weight */
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
case 6400: /* module 25 call 00 pallet:phragmenelection call:vote */
       switch (itemIdx) {
       case 0:
           return STR_IT_votes;
       case 1:
           return STR_IT_amount;
       default:
           return NULL;
       }
case 6401: /* module 25 call 01 pallet:phragmenelection call:remove_voter */
       switch (itemIdx) {
       default:
           return NULL;
       }
case 6402: /* module 25 call 02 pallet:phragmenelection call:submit_candidacy */
       switch (itemIdx) {
       case 0:
           return STR_IT_candidate_count;
       default:
           return NULL;
       }
case 6404: /* module 25 call 04 pallet:phragmenelection call:remove_member */
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
case 6405: /* module 25 call 05 pallet:phragmenelection call:clean_defunct_voters */
       switch (itemIdx) {
       case 0:
           return STR_IT_num_voters;
       case 1:
           return STR_IT_num_defunct;
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
case 5120: /* module 20 call 00 pallet:treasury call:propose_spend */
       switch (itemIdx) {
       case 0:
           return STR_IT_amount;
       case 1:
           return STR_IT_beneficiary;
       default:
           return NULL;
       }
case 5121: /* module 20 call 01 pallet:treasury call:reject_proposal */
       switch (itemIdx) {
       case 0:
           return STR_IT_proposal_id;
       default:
           return NULL;
       }
case 5122: /* module 20 call 02 pallet:treasury call:approve_proposal */
       switch (itemIdx) {
       case 0:
           return STR_IT_proposal_id;
       default:
           return NULL;
       }
case 5123: /* module 20 call 03 pallet:treasury call:spend */
       switch (itemIdx) {
       case 0:
           return STR_IT_amount;
       case 1:
           return STR_IT_beneficiary;
       default:
           return NULL;
       }
case 5124: /* module 20 call 04 pallet:treasury call:remove_approval */
       switch (itemIdx) {
       case 0:
           return STR_IT_proposal_id;
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
case 7169: /* module 28 call 01 pallet:identity call:set_identity */
       switch (itemIdx) {
       case 0:
           return STR_IT_info;
       default:
           return NULL;
       }
case 7170: /* module 28 call 02 pallet:identity call:set_subs */
       switch (itemIdx) {
       case 0:
           return STR_IT_subs;
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
case 7177: /* module 28 call 09 pallet:identity call:provide_judgement */
       switch (itemIdx) {
       case 0:
           return STR_IT_reg_index;
       case 1:
           return STR_IT_target;
       case 2:
           return STR_IT_judgement;
       case 3:
           return STR_IT_identity;
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
case 7179: /* module 28 call 11 pallet:identity call:add_sub */
       switch (itemIdx) {
       case 0:
           return STR_IT_sub;
       case 1:
           return STR_IT_data;
       default:
           return NULL;
       }
case 7180: /* module 28 call 12 pallet:identity call:rename_sub */
       switch (itemIdx) {
       case 0:
           return STR_IT_sub;
       case 1:
           return STR_IT_data;
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
           return _toStringAccountIdLookupOfT(
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
           return _toStringAccountIdLookupOfT(
               &m->nested.balances_force_transfer_V1.source,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* balances_force_transfer_V1 - dest */;
           return _toStringAccountIdLookupOfT(
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
           return _toStringAccountIdLookupOfT(
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
           return _toStringAccountIdLookupOfT(
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
           return _toStringAccountIdLookupOfT(
               &m->nested.staking_bond_V1.controller,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* staking_bond_V1 - amount */;
           return _toStringCompactBalance(
               &m->nested.staking_bond_V1.amount,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* staking_bond_V1 - payee */;
           return _toStringRewardDestination(
               &m->nested.staking_bond_V1.payee,
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
               &m->nested.staking_unbond_V1.amount,
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
           return _toStringValidatorPrefs(
               &m->basic.staking_validate_V1.prefs,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3333: /* module 13 call 05 pallet:staking call:nominate */
       switch (itemIdx) {
       case 0: /* staking_nominate_V1 - targets */;
           return _toStringVecAccountIdLookupOfT(
               &m->nested.staking_nominate_V1.targets,
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
           return _toStringRewardDestination(
               &m->basic.staking_set_payee_V1.payee,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3336: /* module 13 call 08 pallet:staking call:set_controller */
       switch (itemIdx) {
       case 0: /* staking_set_controller_V1 - controller */;
           return _toStringAccountIdLookupOfT(
               &m->nested.staking_set_controller_V1.controller,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
       switch (itemIdx) {
       case 0: /* staking_payout_stakers_V1 - validator_stash */;
           return _toStringAccountId(
               &m->basic.staking_payout_stakers_V1.validator_stash,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* staking_payout_stakers_V1 - era */;
           return _toStringEraIndex(
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
           return _toStringKeys(
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
#ifndef TARGET_NANOS
#endif
case 1: /* module 00 call 01 pallet:system call:remark */
       switch (itemIdx) {
       case 0: /* system_remark_V1 - remark */;
           return _toStringBytes(
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
           return _toStringBytes(
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
           return _toStringAccountIdLookupOfT(
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
           return _toStringAccountIdLookupOfT(
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
case 3339: /* module 13 call 11 pallet:staking call:scale_validator_count */
       switch (itemIdx) {
       case 0: /* staking_scale_validator_count_V1 - factor */;
           return _toStringPercent(
               &m->basic.staking_scale_validator_count_V1.factor,
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
           return _toStringVecAccountId(
               &m->basic.staking_set_invulnerables_V1.invulnerables,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
       switch (itemIdx) {
       case 0: /* staking_force_unstake_V1 - stash */;
           return _toStringAccountId(
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
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
       switch (itemIdx) {
       case 0: /* staking_reap_stash_V1 - stash */;
           return _toStringAccountId(
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
           return _toStringVecAccountIdLookupOfT(
               &m->basic.staking_kick_V1.who,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3350: /* module 13 call 22 pallet:staking call:set_staking_configs */
       switch (itemIdx) {
       case 0: /* staking_set_staking_configs_V1 - min_nominator_bond */;
           return _toStringConfigOpBalanceOfT(
               &m->basic.staking_set_staking_configs_V1.min_nominator_bond,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* staking_set_staking_configs_V1 - min_validator_bond */;
           return _toStringConfigOpBalanceOfT(
               &m->basic.staking_set_staking_configs_V1.min_validator_bond,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* staking_set_staking_configs_V1 - max_nominator_count */;
           return _toStringConfigOpu32(
               &m->basic.staking_set_staking_configs_V1.max_nominator_count,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 3: /* staking_set_staking_configs_V1 - max_validator_count */;
           return _toStringConfigOpu32(
               &m->basic.staking_set_staking_configs_V1.max_validator_count,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 4: /* staking_set_staking_configs_V1 - chill_threshold */;
           return _toStringConfigOpPercent(
               &m->basic.staking_set_staking_configs_V1.chill_threshold,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 5: /* staking_set_staking_configs_V1 - min_commission */;
           return _toStringConfigOpPerbill(
               &m->basic.staking_set_staking_configs_V1.min_commission,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
       switch (itemIdx) {
       case 0: /* staking_chill_other_V1 - controller */;
           return _toStringAccountId(
               &m->basic.staking_chill_other_V1.controller,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
       switch (itemIdx) {
       case 0: /* staking_force_apply_min_commission_V1 - validator_stash */;
           return _toStringAccountId(
               &m->basic.staking_force_apply_min_commission_V1.validator_stash,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 4864: /* module 19 call 00 pallet:mandate call:mandate */
        switch (itemIdx) {
        case 0: /* mandate_mandate_V1 - call */;
            return _toStringCall(
                &m->nested.mandate_mandate_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
case 6144: /* module 24 call 00 pallet:council call:set_members */
       switch (itemIdx) {
       case 0: /* council_set_members_V1 - new_members */;
           return _toStringVecAccountId(
               &m->basic.council_set_members_V1.new_members,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* council_set_members_V1 - prime */;
           return _toStringOptionAccountId(
               &m->basic.council_set_members_V1.prime,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* council_set_members_V1 - old_count */;
           return _toStringMemberCount(
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
case 6148: /* module 24 call 04 pallet:council call:close_old_weight */
       switch (itemIdx) {
       case 0: /* council_close_old_weight_V1 - proposal_hash */;
           return _toStringHash(
               &m->basic.council_close_old_weight_V1.proposal_hash,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* council_close_old_weight_V1 - index */;
           return _toStringCompactu32(
               &m->basic.council_close_old_weight_V1.index,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* council_close_old_weight_V1 - proposal_weight_bound */;
           return _toStringCompactu64(
               &m->basic.council_close_old_weight_V1.proposal_weight_bound,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 3: /* council_close_old_weight_V1 - length_bound */;
           return _toStringCompactu32(
               &m->basic.council_close_old_weight_V1.length_bound,
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
           return _toStringWeight(
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
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
       switch (itemIdx) {
       case 0: /* technicalcommittee_set_members_V1 - new_members */;
           return _toStringVecAccountId(
               &m->basic.technicalcommittee_set_members_V1.new_members,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* technicalcommittee_set_members_V1 - prime */;
           return _toStringOptionAccountId(
               &m->basic.technicalcommittee_set_members_V1.prime,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* technicalcommittee_set_members_V1 - old_count */;
           return _toStringMemberCount(
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
case 4356: /* module 17 call 04 pallet:technicalcommittee call:close_old_weight */
       switch (itemIdx) {
       case 0: /* technicalcommittee_close_old_weight_V1 - proposal_hash */;
           return _toStringHash(
               &m->basic.technicalcommittee_close_old_weight_V1.proposal_hash,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* technicalcommittee_close_old_weight_V1 - index */;
           return _toStringCompactu32(
               &m->basic.technicalcommittee_close_old_weight_V1.index,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* technicalcommittee_close_old_weight_V1 - proposal_weight_bound */;
           return _toStringCompactu64(
               &m->basic.technicalcommittee_close_old_weight_V1.proposal_weight_bound,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 3: /* technicalcommittee_close_old_weight_V1 - length_bound */;
           return _toStringCompactu32(
               &m->basic.technicalcommittee_close_old_weight_V1.length_bound,
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
           return _toStringWeight(
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
case 6400: /* module 25 call 00 pallet:phragmenelection call:vote */
       switch (itemIdx) {
       case 0: /* phragmenelection_vote_V1 - votes */;
           return _toStringVecAccountId(
               &m->basic.phragmenelection_vote_V1.votes,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* phragmenelection_vote_V1 - amount */;
           return _toStringCompactBalance(
               &m->basic.phragmenelection_vote_V1.amount,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 6401: /* module 25 call 01 pallet:phragmenelection call:remove_voter */
       switch (itemIdx) {
       default:
           return parser_no_data;
       }
case 6402: /* module 25 call 02 pallet:phragmenelection call:submit_candidacy */
       switch (itemIdx) {
       case 0: /* phragmenelection_submit_candidacy_V1 - candidate_count */;
           return _toStringCompactu32(
               &m->basic.phragmenelection_submit_candidacy_V1.candidate_count,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 6404: /* module 25 call 04 pallet:phragmenelection call:remove_member */
       switch (itemIdx) {
       case 0: /* phragmenelection_remove_member_V1 - who */;
           return _toStringAccountIdLookupOfT(
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
case 6405: /* module 25 call 05 pallet:phragmenelection call:clean_defunct_voters */
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
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
       switch (itemIdx) {
       case 0: /* technicalmembership_add_member_V1 - who */;
           return _toStringAccountIdLookupOfT(
               &m->basic.technicalmembership_add_member_V1.who,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
       switch (itemIdx) {
       case 0: /* technicalmembership_remove_member_V1 - who */;
           return _toStringAccountIdLookupOfT(
               &m->basic.technicalmembership_remove_member_V1.who,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
       switch (itemIdx) {
       case 0: /* technicalmembership_swap_member_V1 - remove */;
           return _toStringAccountIdLookupOfT(
               &m->basic.technicalmembership_swap_member_V1.remove,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* technicalmembership_swap_member_V1 - add */;
           return _toStringAccountIdLookupOfT(
               &m->basic.technicalmembership_swap_member_V1.add,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
       switch (itemIdx) {
       case 0: /* technicalmembership_reset_members_V1 - members */;
           return _toStringVecAccountId(
               &m->basic.technicalmembership_reset_members_V1.members,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
       switch (itemIdx) {
       case 0: /* technicalmembership_change_key_V1 - new_ */;
           return _toStringAccountIdLookupOfT(
               &m->basic.technicalmembership_change_key_V1.new_,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
       switch (itemIdx) {
       case 0: /* technicalmembership_set_prime_V1 - who */;
           return _toStringAccountIdLookupOfT(
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
case 5120: /* module 20 call 00 pallet:treasury call:propose_spend */
       switch (itemIdx) {
       case 0: /* treasury_propose_spend_V1 - amount */;
           return _toStringCompactBalance(
               &m->basic.treasury_propose_spend_V1.amount,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* treasury_propose_spend_V1 - beneficiary */;
           return _toStringAccountIdLookupOfT(
               &m->basic.treasury_propose_spend_V1.beneficiary,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 5121: /* module 20 call 01 pallet:treasury call:reject_proposal */
       switch (itemIdx) {
       case 0: /* treasury_reject_proposal_V1 - proposal_id */;
           return _toStringCompactu32(
               &m->basic.treasury_reject_proposal_V1.proposal_id,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 5122: /* module 20 call 02 pallet:treasury call:approve_proposal */
       switch (itemIdx) {
       case 0: /* treasury_approve_proposal_V1 - proposal_id */;
           return _toStringCompactu32(
               &m->basic.treasury_approve_proposal_V1.proposal_id,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 5123: /* module 20 call 03 pallet:treasury call:spend */
       switch (itemIdx) {
       case 0: /* treasury_spend_V1 - amount */;
           return _toStringCompactBalance(
               &m->basic.treasury_spend_V1.amount,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* treasury_spend_V1 - beneficiary */;
           return _toStringAccountIdLookupOfT(
               &m->basic.treasury_spend_V1.beneficiary,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 5124: /* module 20 call 04 pallet:treasury call:remove_approval */
       switch (itemIdx) {
       case 0: /* treasury_remove_approval_V1 - proposal_id */;
           return _toStringCompactu32(
               &m->basic.treasury_remove_approval_V1.proposal_id,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
       switch (itemIdx) {
       case 0: /* identity_add_registrar_V1 - account */;
           return _toStringAccountIdLookupOfT(
               &m->basic.identity_add_registrar_V1.account,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7169: /* module 28 call 01 pallet:identity call:set_identity */
       switch (itemIdx) {
       case 0: /* identity_set_identity_V1 - info */;
           return _toStringIdentityInfo(
               &m->basic.identity_set_identity_V1.info,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7170: /* module 28 call 02 pallet:identity call:set_subs */
       switch (itemIdx) {
       case 0: /* identity_set_subs_V1 - subs */;
           return _toStringVecTupleAccountIdData(
               &m->basic.identity_set_subs_V1.subs,
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
           return _toStringRegistrarIndex(
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
           return _toStringAccountIdLookupOfT(
               &m->basic.identity_set_account_id_V1.new_,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7177: /* module 28 call 09 pallet:identity call:provide_judgement */
       switch (itemIdx) {
       case 0: /* identity_provide_judgement_V1 - reg_index */;
           return _toStringCompactu32(
               &m->basic.identity_provide_judgement_V1.reg_index,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* identity_provide_judgement_V1 - target */;
           return _toStringAccountIdLookupOfT(
               &m->basic.identity_provide_judgement_V1.target,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* identity_provide_judgement_V1 - judgement */;
           return _toStringJudgementBalanceOfT(
               &m->basic.identity_provide_judgement_V1.judgement,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 3: /* identity_provide_judgement_V1 - identity */;
           return _toStringHash(
               &m->basic.identity_provide_judgement_V1.identity,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
       switch (itemIdx) {
       case 0: /* identity_kill_identity_V1 - target */;
           return _toStringAccountIdLookupOfT(
               &m->basic.identity_kill_identity_V1.target,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7179: /* module 28 call 11 pallet:identity call:add_sub */
       switch (itemIdx) {
       case 0: /* identity_add_sub_V1 - sub */;
           return _toStringAccountIdLookupOfT(
               &m->basic.identity_add_sub_V1.sub,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* identity_add_sub_V1 - data */;
           return _toStringData(
               &m->basic.identity_add_sub_V1.data,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7180: /* module 28 call 12 pallet:identity call:rename_sub */
       switch (itemIdx) {
       case 0: /* identity_rename_sub_V1 - sub */;
           return _toStringAccountIdLookupOfT(
               &m->basic.identity_rename_sub_V1.sub,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 1: /* identity_rename_sub_V1 - data */;
           return _toStringData(
               &m->basic.identity_rename_sub_V1.data,
               outValue, outValueLen,
               pageIdx, pageCount);
       default:
           return parser_no_data;
       }
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
       switch (itemIdx) {
       case 0: /* identity_remove_sub_V1 - sub */;
           return _toStringAccountIdLookupOfT(
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
           return _toStringVecAccountId(
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
           return _toStringVecAccountId(
               &m->nested.multisig_as_multi_V1.other_signatories,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
           return _toStringOptionTimepoint(
               &m->nested.multisig_as_multi_V1.maybe_timepoint,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 3: /* multisig_as_multi_V1 - call */;
           return _toStringCall(
               &m->nested.multisig_as_multi_V1.call,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 4: /* multisig_as_multi_V1 - max_weight */;
           return _toStringWeight(
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
           return _toStringVecAccountId(
               &m->nested.multisig_approve_as_multi_V1.other_signatories,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
           return _toStringOptionTimepoint(
               &m->nested.multisig_approve_as_multi_V1.maybe_timepoint,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 3: /* multisig_approve_as_multi_V1 - call_hash */;
           return _toStringH256(
               &m->nested.multisig_approve_as_multi_V1.call_hash,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 4: /* multisig_approve_as_multi_V1 - max_weight */;
           return _toStringWeight(
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
           return _toStringVecAccountId(
               &m->nested.multisig_cancel_as_multi_V1.other_signatories,
               outValue, outValueLen,
               pageIdx, pageCount);
       case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
           return _toStringTimepoint(
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
   case 3331: // Staking:Withdraw Unbonded
       switch (itemIdx) {
       case 0: // Num slashing spans
           return true;
       default:
           return false;
       }
   case 3343: // Staking:Force unstake
       switch (itemIdx) {
       case 1: // Num slashing spans
           return true;
       default:
           return false;
       }
   case 3348: // Staking:Reap stash
       switch (itemIdx) {
       case 1: // Num slashing spans
           return true;
       default:
           return false;
       }
       switch (itemIdx) {
       case 1: // Num slashing spans
           return true;
       default:
           return false;
       }
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
case 1024: /* module 04 call 00 pallet:balances call:transfer */
case 1028: /* module 04 call 04 pallet:balances call:transfer_all */
case 1029: /* module 04 call 05 pallet:balances call:force_unreserve */
case 3328: /* module 13 call 00 pallet:staking call:bond */
case 3329: /* module 13 call 01 pallet:staking call:bond_extra */
case 3331: /* module 13 call 03 pallet:staking call:withdraw_unbonded */
case 3332: /* module 13 call 04 pallet:staking call:validate */
case 3335: /* module 13 call 07 pallet:staking call:set_payee */
case 3337: /* module 13 call 09 pallet:staking call:set_validator_count */
case 3338: /* module 13 call 10 pallet:staking call:increase_validator_count */
case 3339: /* module 13 call 11 pallet:staking call:scale_validator_count */
case 3340: /* module 13 call 12 pallet:staking call:force_no_eras */
case 3341: /* module 13 call 13 pallet:staking call:force_new_era */
case 3342: /* module 13 call 14 pallet:staking call:set_invulnerables */
case 3343: /* module 13 call 15 pallet:staking call:force_unstake */
case 3344: /* module 13 call 16 pallet:staking call:force_new_era_always */
case 3346: /* module 13 call 18 pallet:staking call:payout_stakers */
case 3347: /* module 13 call 19 pallet:staking call:rebond */
case 3348: /* module 13 call 20 pallet:staking call:reap_stash */
case 3349: /* module 13 call 21 pallet:staking call:kick */
case 3350: /* module 13 call 22 pallet:staking call:set_staking_configs */
case 3334: /* module 13 call 06 pallet:staking call:chill */
case 3351: /* module 13 call 23 pallet:staking call:chill_other */
case 3352: /* module 13 call 24 pallet:staking call:force_apply_min_commission */
case 2304: /* module 09 call 00 pallet:session call:set_keys */
case 2305: /* module 09 call 01 pallet:session call:purge_keys */
case 6144: /* module 24 call 00 pallet:council call:set_members */
case 6145: /* module 24 call 01 pallet:council call:execute */
case 6146: /* module 24 call 02 pallet:council call:propose */
case 6147: /* module 24 call 03 pallet:council call:vote */
case 6148: /* module 24 call 04 pallet:council call:close_old_weight */
case 6149: /* module 24 call 05 pallet:council call:disapprove_proposal */
case 6150: /* module 24 call 06 pallet:council call:close */
case 4352: /* module 17 call 00 pallet:technicalcommittee call:set_members */
case 4353: /* module 17 call 01 pallet:technicalcommittee call:execute */
case 4354: /* module 17 call 02 pallet:technicalcommittee call:propose */
case 4355: /* module 17 call 03 pallet:technicalcommittee call:vote */
case 4356: /* module 17 call 04 pallet:technicalcommittee call:close_old_weight */
case 4357: /* module 17 call 05 pallet:technicalcommittee call:disapprove_proposal */
case 4358: /* module 17 call 06 pallet:technicalcommittee call:close */
case 6400: /* module 25 call 00 pallet:phragmenelection call:vote */
case 6401: /* module 25 call 01 pallet:phragmenelection call:remove_voter */
case 6402: /* module 25 call 02 pallet:phragmenelection call:submit_candidacy */
case 6404: /* module 25 call 04 pallet:phragmenelection call:remove_member */
case 6405: /* module 25 call 05 pallet:phragmenelection call:clean_defunct_voters */
case 4608: /* module 18 call 00 pallet:technicalmembership call:add_member */
case 4609: /* module 18 call 01 pallet:technicalmembership call:remove_member */
case 4610: /* module 18 call 02 pallet:technicalmembership call:swap_member */
case 4611: /* module 18 call 03 pallet:technicalmembership call:reset_members */
case 4612: /* module 18 call 04 pallet:technicalmembership call:change_key */
case 4613: /* module 18 call 05 pallet:technicalmembership call:set_prime */
case 4614: /* module 18 call 06 pallet:technicalmembership call:clear_prime */
case 5120: /* module 20 call 00 pallet:treasury call:propose_spend */
case 5121: /* module 20 call 01 pallet:treasury call:reject_proposal */
case 5122: /* module 20 call 02 pallet:treasury call:approve_proposal */
case 5123: /* module 20 call 03 pallet:treasury call:spend */
case 5124: /* module 20 call 04 pallet:treasury call:remove_approval */
case 5376: /* module 21 call 00 pallet:utility call:batch */
case 5378: /* module 21 call 02 pallet:utility call:batch_all */
case 5380: /* module 21 call 04 pallet:utility call:force_batch */
case 7168: /* module 28 call 00 pallet:identity call:add_registrar */
case 7169: /* module 28 call 01 pallet:identity call:set_identity */
case 7170: /* module 28 call 02 pallet:identity call:set_subs */
case 7171: /* module 28 call 03 pallet:identity call:clear_identity */
case 7172: /* module 28 call 04 pallet:identity call:request_judgement */
case 7173: /* module 28 call 05 pallet:identity call:cancel_request */
case 7174: /* module 28 call 06 pallet:identity call:set_fee */
case 7175: /* module 28 call 07 pallet:identity call:set_account_id */
case 7177: /* module 28 call 09 pallet:identity call:provide_judgement */
case 7178: /* module 28 call 10 pallet:identity call:kill_identity */
case 7179: /* module 28 call 11 pallet:identity call:add_sub */
case 7180: /* module 28 call 12 pallet:identity call:rename_sub */
case 7181: /* module 28 call 13 pallet:identity call:remove_sub */
case 7182: /* module 28 call 14 pallet:identity call:quit_sub */
       return false;
   default:
       return true;
   }
}
