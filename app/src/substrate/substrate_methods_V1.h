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
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif
//get pallet ID from developer -> extrinsics -> first 2 digit as hex -> convert to number
#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_TIMESTAMP_V1 3
#define PD_CALL_BALANCES_V1 4
#define PD_CALL_SESSION_V1 9
#define PD_CALL_STAKING_V1 13
#define PD_CALL_TECHNICALCOMMITTEE_V1 17
#define PD_CALL_TECHNICALMEMBERSHIP_V1 18
#define PD_CALL_MANDATE_V1 19
#define PD_CALL_TREASURY_V1 20
#define PD_CALL_UTILITY_V1 21
#define PD_CALL_COUNCIL_V1 24
#define PD_CALL_PHRAGMENELECTION_V1 25
#define PD_CALL_MULTISIG_V1 27
#define PD_CALL_IDENTITY_V1 28

//---- old IDs -----
// #define PD_CALL_SYSTEM_V1 0
// #define PD_CALL_TIMESTAMP_V1 2
// #define PD_CALL_BALANCES_V1 4
// #define PD_CALL_SESSION_V1 8
// #define PD_CALL_STAKING_V1 6
// #define PD_CALL_TECHNICALCOMMITTEE_V1 15
// #define PD_CALL_TECHNICALMEMBERSHIP_V1 17
// #define PD_CALL_TREASURY_V1 18
// #define PD_CALL_UTILITY_V1 24
// #define PD_CALL_COUNCIL_V1 14
// #define PD_CALL_DEMOCRACY_V1 13
// #define PD_CALL_PHRAGMENELECTION_V1 16
// #define PD_CALL_MULTISIG_V1 31
// #define PD_CALL_IDENTITY_V1 25


#define PD_CALL_BALANCES_TRANSFER_ALL_V1 4
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_t keys;
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

#define PD_CALL_UTILITY_FORCE_BATCH_V1 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_BALANCES_FORCE_UNRESERVE_V1 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_Balance_t amount;
} pd_balances_force_unreserve_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V1 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 12
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 13
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 16
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_KICK_V1 21
typedef struct {
    pd_VecAccountIdLookupOfT_t who;
} pd_staking_kick_V1_t;

#define PD_CALL_STAKING_SET_STAKING_CONFIGS_V1 22
typedef struct {
    pd_ConfigOpBalanceOfT_t min_nominator_bond;
    pd_ConfigOpBalanceOfT_t min_validator_bond;
    pd_ConfigOpu32_t max_nominator_count;
    pd_ConfigOpu32_t max_validator_count;
    pd_ConfigOpPercent_t chill_threshold;
    pd_ConfigOpPerbill_t min_commission;
} pd_staking_set_staking_configs_V1_t;

#define PD_CALL_STAKING_CHILL_OTHER_V1 23
typedef struct {
    pd_AccountId_t controller;
} pd_staking_chill_other_V1_t;

#define PD_CALL_STAKING_FORCE_APPLY_MIN_COMMISSION_V1 24
typedef struct {
    pd_AccountId_t validator_stash;
} pd_staking_force_apply_min_commission_V1_t;

#define PD_CALL_STAKING_SET_MIN_COMMISSION_V1 25
typedef struct {
    pd_Perbill_t new_;
} pd_staking_set_min_commission_V1_t;

#define PD_CALL_COUNCIL_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_council_set_members_V1_t;

#define PD_CALL_COUNCIL_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V1_t;

#define PD_CALL_COUNCIL_PROPOSE_V1 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V1_t;

#define PD_CALL_COUNCIL_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V1_t;

#define PD_CALL_COUNCIL_CLOSE_OLD_WEIGHT_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_old_weight_V1_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V1_t;

#define PD_CALL_COUNCIL_CLOSE_V1 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_MEMBERS_V1 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_technicalcommittee_set_members_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V1 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_OLD_WEIGHT_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_old_weight_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V1 6
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Weight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V1_t;

#define PD_CALL_PHRAGMENELECTION_VOTE_V1 0
typedef struct {
    pd_VecAccountId_t votes;
    pd_CompactBalance_t amount;
} pd_phragmenelection_vote_V1_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_VOTER_V1 1
typedef struct {
} pd_phragmenelection_remove_voter_V1_t;

#define PD_CALL_PHRAGMENELECTION_SUBMIT_CANDIDACY_V1 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_phragmenelection_submit_candidacy_V1_t;

#define PD_CALL_PHRAGMENELECTION_REMOVE_MEMBER_V1 4
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_bool_t slash_bond;
    pd_bool_t rerun_election;
} pd_phragmenelection_remove_member_V1_t;

#define PD_CALL_PHRAGMENELECTION_CLEAN_DEFUNCT_VOTERS_V1 5
typedef struct {
    pd_u32_t num_voters;
    pd_u32_t num_defunct;
} pd_phragmenelection_clean_defunct_voters_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_ADD_MEMBER_V1 0
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_add_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_REMOVE_MEMBER_V1 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_remove_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SWAP_MEMBER_V1 2
typedef struct {
    pd_AccountIdLookupOfT_t remove;
    pd_AccountIdLookupOfT_t add;
} pd_technicalmembership_swap_member_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_RESET_MEMBERS_V1 3
typedef struct {
    pd_VecAccountId_t members;
} pd_technicalmembership_reset_members_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CHANGE_KEY_V1 4
typedef struct {
    pd_AccountIdLookupOfT_t new_;
} pd_technicalmembership_change_key_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_SET_PRIME_V1 5
typedef struct {
    pd_AccountIdLookupOfT_t who;
} pd_technicalmembership_set_prime_V1_t;

#define PD_CALL_TECHNICALMEMBERSHIP_CLEAR_PRIME_V1 6
typedef struct {
} pd_technicalmembership_clear_prime_V1_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_propose_spend_V1_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V1 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V1_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V1 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V1_t;

#define PD_CALL_TREASURY_SPEND_V1 3
typedef struct {
    pd_CompactBalance_t amount;
    pd_AccountIdLookupOfT_t beneficiary;
} pd_treasury_spend_V1_t;

#define PD_CALL_TREASURY_REMOVE_APPROVAL_V1 4
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_remove_approval_V1_t;

#define PD_CALL_MANDATE_MANDATE_V1 0
typedef struct {
    pd_Call_t call;
} pd_mandate_mandate_V1_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V1 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V1_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V1 0
typedef struct {
    pd_AccountIdLookupOfT_t account;
} pd_identity_add_registrar_V1_t;

#define PD_CALL_IDENTITY_SET_IDENTITY_V1 1
typedef struct {
    pd_IdentityInfo_t info;
} pd_identity_set_identity_V1_t;

#define PD_CALL_IDENTITY_SET_SUBS_V1 2
typedef struct {
    pd_VecTupleAccountIdData_t subs;
} pd_identity_set_subs_V1_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V1 3
typedef struct {
} pd_identity_clear_identity_V1_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V1 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V1_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V1 5
typedef struct {
    pd_RegistrarIndex_t reg_index;
} pd_identity_cancel_request_V1_t;

#define PD_CALL_IDENTITY_SET_FEE_V1 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V1_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V1 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountIdLookupOfT_t new_;
} pd_identity_set_account_id_V1_t;

#define PD_CALL_IDENTITY_PROVIDE_JUDGEMENT_V1 9
typedef struct {
    pd_Compactu32_t reg_index;
    pd_AccountIdLookupOfT_t target;
    pd_JudgementBalanceOfT_t judgement;
    pd_Hash_t identity;
} pd_identity_provide_judgement_V1_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V1 10
typedef struct {
    pd_AccountIdLookupOfT_t target;
} pd_identity_kill_identity_V1_t;

#define PD_CALL_IDENTITY_ADD_SUB_V1 11
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_add_sub_V1_t;

#define PD_CALL_IDENTITY_RENAME_SUB_V1 12
typedef struct {
    pd_AccountIdLookupOfT_t sub;
    pd_Data_t data;
} pd_identity_rename_sub_V1_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V1 13
typedef struct {
    pd_AccountIdLookupOfT_t sub;
} pd_identity_remove_sub_V1_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V1 14
typedef struct {
} pd_identity_quit_sub_V1_t;

#endif

typedef union {
    pd_balances_transfer_all_V1_t balances_transfer_all_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_all_V1_t utility_batch_all_V1;
    pd_utility_force_batch_V1_t utility_force_batch_V1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_balances_force_unreserve_V1_t balances_force_unreserve_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_scale_validator_count_V1_t staking_scale_validator_count_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_kick_V1_t staking_kick_V1;
    pd_staking_set_staking_configs_V1_t staking_set_staking_configs_V1;
    pd_staking_chill_other_V1_t staking_chill_other_V1;
    pd_staking_force_apply_min_commission_V1_t staking_force_apply_min_commission_V1;
    pd_staking_set_min_commission_V1_t staking_set_min_commission_V1;
    pd_council_set_members_V1_t council_set_members_V1;
    pd_council_execute_V1_t council_execute_V1;
    pd_council_propose_V1_t council_propose_V1;
    pd_council_vote_V1_t council_vote_V1;
    pd_council_close_old_weight_V1_t council_close_old_weight_V1;
    pd_council_disapprove_proposal_V1_t council_disapprove_proposal_V1;
    pd_council_close_V1_t council_close_V1;
    pd_technicalcommittee_set_members_V1_t technicalcommittee_set_members_V1;
    pd_technicalcommittee_execute_V1_t technicalcommittee_execute_V1;
    pd_technicalcommittee_propose_V1_t technicalcommittee_propose_V1;
    pd_technicalcommittee_vote_V1_t technicalcommittee_vote_V1;
    pd_technicalcommittee_close_old_weight_V1_t technicalcommittee_close_old_weight_V1;
    pd_technicalcommittee_disapprove_proposal_V1_t technicalcommittee_disapprove_proposal_V1;
    pd_technicalcommittee_close_V1_t technicalcommittee_close_V1;
    pd_phragmenelection_vote_V1_t phragmenelection_vote_V1;
    pd_phragmenelection_remove_voter_V1_t phragmenelection_remove_voter_V1;
    pd_phragmenelection_submit_candidacy_V1_t phragmenelection_submit_candidacy_V1;
    pd_phragmenelection_remove_member_V1_t phragmenelection_remove_member_V1;
    pd_phragmenelection_clean_defunct_voters_V1_t phragmenelection_clean_defunct_voters_V1;
    pd_technicalmembership_add_member_V1_t technicalmembership_add_member_V1;
    pd_technicalmembership_remove_member_V1_t technicalmembership_remove_member_V1;
    pd_technicalmembership_swap_member_V1_t technicalmembership_swap_member_V1;
    pd_technicalmembership_reset_members_V1_t technicalmembership_reset_members_V1;
    pd_technicalmembership_change_key_V1_t technicalmembership_change_key_V1;
    pd_technicalmembership_set_prime_V1_t technicalmembership_set_prime_V1;
    pd_technicalmembership_clear_prime_V1_t technicalmembership_clear_prime_V1;
    pd_treasury_propose_spend_V1_t treasury_propose_spend_V1;
    pd_treasury_reject_proposal_V1_t treasury_reject_proposal_V1;
    pd_treasury_approve_proposal_V1_t treasury_approve_proposal_V1;
    pd_treasury_spend_V1_t treasury_spend_V1;
    pd_treasury_remove_approval_V1_t treasury_remove_approval_V1;
    pd_utility_with_weight_V1_t utility_with_weight_V1;
    pd_identity_add_registrar_V1_t identity_add_registrar_V1;
    pd_identity_set_identity_V1_t identity_set_identity_V1;
    pd_identity_set_subs_V1_t identity_set_subs_V1;
    pd_identity_clear_identity_V1_t identity_clear_identity_V1;
    pd_identity_request_judgement_V1_t identity_request_judgement_V1;
    pd_identity_cancel_request_V1_t identity_cancel_request_V1;
    pd_identity_set_fee_V1_t identity_set_fee_V1;
    pd_identity_set_account_id_V1_t identity_set_account_id_V1;
    pd_identity_provide_judgement_V1_t identity_provide_judgement_V1;
    pd_identity_kill_identity_V1_t identity_kill_identity_V1;
    pd_identity_add_sub_V1_t identity_add_sub_V1;
    pd_identity_rename_sub_V1_t identity_rename_sub_V1;
    pd_identity_remove_sub_V1_t identity_remove_sub_V1;
    pd_identity_quit_sub_V1_t identity_quit_sub_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 2
typedef struct {
    pd_AccountIdLookupOfT_t source;
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_AccountIdLookupOfT_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecAccountIdLookupOfT_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
    pd_AccountIdLookupOfT_t controller;
} pd_staking_set_controller_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Bytes_t remark;
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
    pd_Bytes_t remark;
} pd_system_remark_with_event_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 1
typedef struct {
    pd_AccountIdLookupOfT_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_Call_t call;
    pd_Weight_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_OptionTimepoint_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_t other_signatories;
    pd_Timepoint_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_system_remark_with_event_V1_t system_remark_with_event_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_mandate_mandate_V1_t mandate_mandate_V1;
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
