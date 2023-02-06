
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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_TIMESTAMP = "Timestamp";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_STAKING = "Staking";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_DEMOCRACY = "Democracy";
static const char* STR_MO_COUNCIL = "Council";
static const char* STR_MO_TECHNICALCOMMITTEE = "Technicalcommittee";
static const char* STR_MO_MANDATE = "Mandate";
static const char* STR_MO_TECHNICALMEMBERSHIP = "Technicalmembership";
static const char* STR_MO_TREASURY = "Treasury";
static const char* STR_MO_PHRAGMENELECTION = "Phragmenelection";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_IDENTITY = "Identity";
static const char* STR_MO_MULTISIG = "Multisig";

// Methods names
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_SET = "Set";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_SET_BALANCE = "Set balance";
static const char* STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char* STR_ME_TRANSFER_ALL = "Transfer all";
static const char* STR_ME_FORCE_UNRESERVE = "Force unreserve";
static const char* STR_ME_BOND = "Bond";
static const char* STR_ME_BOND_EXTRA = "Bond extra";
static const char* STR_ME_UNBOND = "Unbond";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_VALIDATE = "Validate";
static const char* STR_ME_NOMINATE = "Nominate";
static const char* STR_ME_CHILL = "Chill";
static const char* STR_ME_SET_PAYEE = "Set payee";
static const char* STR_ME_SET_CONTROLLER = "Set controller";
static const char* STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char* STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char* STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char* STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char* STR_ME_FORCE_NEW_ERA = "Force new era";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char* STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char* STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char* STR_ME_REBOND = "Rebond";
static const char* STR_ME_REAP_STASH = "Reap stash";
static const char* STR_ME_KICK = "Kick";
static const char* STR_ME_SET_STAKING_CONFIGS = "Set staking configs";
static const char* STR_ME_CHILL_OTHER = "Chill other";
static const char* STR_ME_FORCE_APPLY_MIN_COMMISSION = "Force apply min commission";
static const char* STR_ME_SET_KEYS = "Set keys";
static const char* STR_ME_PURGE_KEYS = "Purge keys";
static const char* STR_ME_PROPOSE = "Propose";
static const char* STR_ME_SECOND = "Second";
static const char* STR_ME_VOTE = "Vote";
static const char* STR_ME_EMERGENCY_CANCEL = "Emergency cancel";
static const char* STR_ME_MANDATE = "Mandate";
static const char* STR_ME_EXTERNAL_PROPOSE = "External propose";
static const char* STR_ME_EXTERNAL_PROPOSE_MAJORITY = "External propose majority";
static const char* STR_ME_EXTERNAL_PROPOSE_DEFAULT = "External propose default";
static const char* STR_ME_FAST_TRACK = "Fast track";
static const char* STR_ME_VETO_EXTERNAL = "Veto external";
static const char* STR_ME_CANCEL_REFERENDUM = "Cancel referendum";
static const char* STR_ME_DELEGATE = "Delegate";
static const char* STR_ME_UNDELEGATE = "Undelegate";
static const char* STR_ME_CLEAR_PUBLIC_PROPOSALS = "Clear public proposals";
static const char* STR_ME_UNLOCK = "Unlock";
static const char* STR_ME_REMOVE_VOTE = "Remove vote";
static const char* STR_ME_REMOVE_OTHER_VOTE = "Remove other vote";
static const char* STR_ME_BLACKLIST = "Blacklist";
static const char* STR_ME_CANCEL_PROPOSAL = "Cancel proposal";
static const char* STR_ME_SET_MEMBERS = "Set members";
static const char* STR_ME_EXECUTE = "Execute";
static const char* STR_ME_CLOSE_OLD_WEIGHT = "Close old weight";
static const char* STR_ME_DISAPPROVE_PROPOSAL = "Disapprove proposal";
static const char* STR_ME_CLOSE = "Close";
static const char* STR_ME_REMOVE_VOTER = "Remove voter";
static const char* STR_ME_SUBMIT_CANDIDACY = "Submit candidacy";
static const char* STR_ME_REMOVE_MEMBER = "Remove member";
static const char* STR_ME_CLEAN_DEFUNCT_VOTERS = "Clean defunct voters";
static const char* STR_ME_ADD_MEMBER = "Add member";
static const char* STR_ME_SWAP_MEMBER = "Swap member";
static const char* STR_ME_RESET_MEMBERS = "Reset members";
static const char* STR_ME_CHANGE_KEY = "Change key";
static const char* STR_ME_SET_PRIME = "Set prime";
static const char* STR_ME_CLEAR_PRIME = "Clear prime";
static const char* STR_ME_PROPOSE_SPEND = "Propose spend";
static const char* STR_ME_REJECT_PROPOSAL = "Reject proposal";
static const char* STR_ME_APPROVE_PROPOSAL = "Approve proposal";
static const char* STR_ME_SPEND = "Spend";
static const char* STR_ME_REMOVE_APPROVAL = "Remove approval";
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ALL = "Batch all";
static const char* STR_ME_FORCE_BATCH = "Force batch";
static const char* STR_ME_ADD_REGISTRAR = "Add registrar";
static const char* STR_ME_SET_IDENTITY = "Set identity";
static const char* STR_ME_SET_SUBS = "Set subs";
static const char* STR_ME_CLEAR_IDENTITY = "Clear identity";
static const char* STR_ME_REQUEST_JUDGEMENT = "Request judgement";
static const char* STR_ME_CANCEL_REQUEST = "Cancel request";
static const char* STR_ME_SET_FEE = "Set fee";
static const char* STR_ME_SET_ACCOUNT_ID = "Set account id";
static const char* STR_ME_PROVIDE_JUDGEMENT = "Provide judgement";
static const char* STR_ME_KILL_IDENTITY = "Kill identity";
static const char* STR_ME_ADD_SUB = "Add sub";
static const char* STR_ME_RENAME_SUB = "Rename sub";
static const char* STR_ME_REMOVE_SUB = "Remove sub";
static const char* STR_ME_QUIT_SUB = "Quit sub";
static const char* STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char* STR_ME_AS_MULTI = "As multi";
static const char* STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char* STR_ME_CANCEL_AS_MULTI = "Cancel as multi";

// Items names
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_now = "Now";
static const char* STR_IT_index = "Index";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_reserved = "New reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_keep_alive = "Keep alive";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_factor = "Factor";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_min_nominator_bond = "Min nominator bond";
static const char* STR_IT_min_validator_bond = "Min validator bond";
static const char* STR_IT_max_nominator_count = "Max nominator count";
static const char* STR_IT_max_validator_count = "Max validator count";
static const char* STR_IT_chill_threshold = "Chill threshold";
static const char* STR_IT_min_commission = "Min commission";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_proposal = "Proposal";
static const char* STR_IT_ref_index = "Ref index";
static const char* STR_IT_vote = "Vote";
static const char* STR_IT_proposal_hash = "Proposal hash";
static const char* STR_IT_voting_period = "Voting period";
static const char* STR_IT_delay = "Delay";
static const char* STR_IT_to = "To";
static const char* STR_IT_conviction = "Conviction";
static const char* STR_IT_balance = "Balance";
static const char* STR_IT_target = "Target";
static const char* STR_IT_maybe_ref_index = "Maybe ref index";
static const char* STR_IT_prop_index = "Prop index";
static const char* STR_IT_new_members = "New members";
static const char* STR_IT_prime = "Prime";
static const char* STR_IT_old_count = "Old count";
static const char* STR_IT_length_bound = "Length bound";
static const char* STR_IT_threshold = "Threshold";
static const char* STR_IT_approve = "Approve";
static const char* STR_IT_proposal_weight_bound = "Proposal weight bound";
static const char* STR_IT_votes = "Votes";
static const char* STR_IT_candidate_count = "Candidate count";
static const char* STR_IT_slash_bond = "Slash bond";
static const char* STR_IT_rerun_election = "Rerun election";
static const char* STR_IT_num_voters = "Num voters";
static const char* STR_IT_num_defunct = "Num defunct";
static const char* STR_IT_remove = "Remove";
static const char* STR_IT_add = "Add";
static const char* STR_IT_members = "Members";
static const char* STR_IT_beneficiary = "Beneficiary";
static const char* STR_IT_proposal_id = "Proposal id";
static const char* STR_IT_call_hash = "Call hash";
static const char* STR_IT_call = "Call";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_account = "Account";
static const char* STR_IT_info = "Info";
static const char* STR_IT_subs = "Subs";
static const char* STR_IT_reg_index = "Reg index";
static const char* STR_IT_max_fee = "Max fee";
static const char* STR_IT_fee = "Fee";
static const char* STR_IT_judgement = "Judgement";
static const char* STR_IT_identity = "Identity";
static const char* STR_IT_sub = "Sub";
static const char* STR_IT_data = "Data";
static const char* STR_IT_other_signatories = "Other signatories";
static const char* STR_IT_maybe_timepoint = "Maybe timepoint";
static const char* STR_IT_max_weight = "Max weight";
static const char* STR_IT_timepoint = "Timepoint";

#ifdef __cplusplus
}
#endif

