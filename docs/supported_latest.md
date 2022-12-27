
# Ternoa 1.11.x

## System

| Name                    | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                         |
| ----------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------- |
| Remark                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |
| Set heap pages          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u64`pages<br/>                   |
| Set code                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set code without checks |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Vecu8`code<br/>                  |
| Set storage             |        |                    |                    |                    | `VecKeyValue`items<br/>           |
| Kill storage            |        |                    |                    |                    | `VecKey`keys<br/>                 |
| Kill prefix             |        |                    |                    |                    | `Key`prefix<br/>`u32`subkeys<br/> |
| Remark with event       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Bytes`remark<br/>                |

## Timestamp

| Name | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments            |
| ---- | ------ | ------------------ | ------------------ | ------- | -------------------- |
| Set  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu64`now<br/> |

## Balances

| Name                | Nano S             | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                  |
| ------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------------------ |
| Transfer            | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Set balance         |                    | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`who<br/>`CompactBalance`new_free<br/>`CompactBalance`new_reserved<br/> |
| Force transfer      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`source<br/>`AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>    |
| Transfer keep alive | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`dest<br/>`CompactBalance`amount<br/>                                   |
| Transfer all        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`dest<br/>`bool`keep_alive<br/>                                         |
| Force unreserve     |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`who<br/>`Balance`amount<br/>                                           |


## Session

| Name       | Nano S             | Nano S XL          | Nano SP/X          | Nesting | Arguments                        |
| ---------- | ------------------ | ------------------ | ------------------ | ------- | -------------------------------- |
| Set keys   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `Keys`keys<br/>`Bytes`proof<br/> |
| Purge keys | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         |                                  |

## Grandpa

| Name                         | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                       |
| ---------------------------- | ------ | --------- | --------- | ------- | ----------------------------------------------------------------------------------------------- |
| Report equivocation          |        |           |           |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Report equivocation unsigned |        |           |           |         | `BoxEquivocationProofHashBlockNumber`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/> |
| Note stalled                 |        |           |           |         | `BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>                            |


## Staking

| Name                       | Nano S             | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                                                                                                                                                                 |
| -------------------------- | ------------------ | ------------------ | ------------------ | ------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Bond                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |  | `AccountIdLookupOfT`controller<br/>`CompactBalance`amount<br/>`RewardDestination`payee<br/>                                                                                                                                               |
| Bond extra                 | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Unbond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Withdraw Unbonded          | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `u32`num_slashing_spans<br/>                                                                                                                                                                                                              |
| Validate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `ValidatorPrefs`prefs<br/>                                                                                                                                                                                                                |
| Nominate                   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |  | `VecAccountIdLookupOfT`targets<br/>                                                                                                                                                                                                       |
| Chill                      | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Set payee                  | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `RewardDestination`payee<br/>                                                                                                                                                                                                             |
| Set controller             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountIdLookupOfT`controller<br/>                                                                                                                                                                                                       |
| Set validator count        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`new\_<br/>                                                                                                                                                                                                                    |
| Increase validator count   |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Compactu32`additional<br/>                                                                                                                                                                                                               |
| Scale validator count      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `Percent`factor<br/>                                                                                                                                                                                                                      |
| Force no eras              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Force new era              |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Set invulnerables          |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountId`invulnerables<br/>                                                                                                                                                                                                          |
| Force unstake              |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Force new era always       |                    | :heavy_check_mark: | :heavy_check_mark: |                    |                                                                                                                                                                                                                                           |
| Cancel deferred slash      |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `EraIndex`era<br/>`Vecu32`slash_indices<br/>                                                                                                                                                                                              |
| Payout stakers             | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>`EraIndex`era<br/>                                                                                                                                                                                         |
| Rebond                     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                    | `CompactBalance`amount<br/>                                                                                                                                                                                                               |
| Reap stash                 |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`stash<br/>`u32`num_slashing_spans<br/>                                                                                                                                                                                         |
| Kick                       |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `VecAccountIdLookupOfT`who<br/>                                                                                                                                                                                                           |
| Set staking configs        |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `ConfigOpBalanceOfT`min_nominator_bond<br/>`ConfigOpBalanceOfT`min_validator_bond<br/>`ConfigOpu32`max_nominator_count<br/>`ConfigOpu32`max_validator_count<br/>`ConfigOpPercent`chill_threshold<br/>`ConfigOpPerbill`min_commission<br/> |
| Chill other                |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`controller<br/>                                                                                                                                                                                                                |
| Force apply min commission |                    | :heavy_check_mark: | :heavy_check_mark: |                    | `AccountId`validator_stash<br/>                                                                                                                                                                                                           |

## ElectionProviderMultiPhase

| Name                          | Nano S | Nano S XL | Nano SP/X | Nesting | Arguments                                                                                  |
| ----------------------------- | ------ | --------- | --------- | ------- | ------------------------------------------------------------------------------------------ |
| Submit unsigned               |        |           |           |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>`SolutionOrSnapshotSize`witness<br/> |
| Set minimum untrusted score   |        |           |           |         | `OptionElectionScore`maybe_next_score<br/>                                                 |
| Set emergency election result |        |           |           |         | `SupportsAccountId`supports<br/>                                                           |
| Submit                        |        |           |           |         | `BoxRawSolutionSolutionOfMinerConfig`raw_solution<br/>                                     |
| Governance fallback           |        |:heavy_check_mark:|           |         | `Optionu32`maybe_max_voters<br/>`Optionu32`maybe_max_targets<br/>                          |

## TechnicalCommittee

| Name                | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close old weight    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>                                                                                          |
| Close               |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/>     |

## TechnicalMembership

| Name          | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                   |
| ------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------- |
| Add member    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Remove member |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Swap member   |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`remove<br/>`AccountIdLookupOfT`add<br/> |
| Reset members |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`members<br/>                                  |
| Change key    |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`new\_<br/>                              |
| Set prime     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`who<br/>                                |
| Clear prime   |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                             |

## Treasury

| Name             | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                       |
| ---------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------- |
| Propose spend    |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Reject proposal  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                    |
| Approve proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                    |
| Spend            |        | :heavy_check_mark: | :heavy_check_mark: |         | `CompactBalance`amount<br/>`AccountIdLookupOfT`beneficiary<br/> |
| Remove approval  |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`proposal_id<br/>                                    |

## Utility

| Name          | Nano S             | Nano S XL          | Nano SP/X          | Nesting | Arguments                                       |
| ------------- | ------------------ | ------------------ | ------------------ | ------- | ----------------------------------------------- |
| Batch         | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| As derivative |                    |                    |                    |         | `u16`index<br/>`Call`call<br/>                  |
| Batch all     | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| Dispatch as   |                    |                    |                    |         | `BoxPalletsOrigin`as_origin<br/>`Call`call<br/> |
| Force batch   | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |         | `VecCall`calls<br/>                             |
| With weight   |                    | :heavy_check_mark: | :heavy_check_mark: |         | `Call`call<br/>`Weight`weight<br/>              |


## Preimage

| Name               | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments         |
| ------------------ | ------ | ------------------ | ------------------ | ------- | ----------------- |
| Note preimage      |        | :heavy_check_mark: | :heavy_check_mark: |         | `Vecu8`bytes<br/> |
| Unnote preimage    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Request preimage   |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |
| Unrequest preimage |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`hash<br/>   |

## Council

| Name                | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                         |
| ------------------- | ------ | ------------------ | ------------------ | ------- | ----------------------------------------------------------------------------------------------------------------- |
| Set members         |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecAccountId`new_members<br/>`OptionAccountId`prime<br/>`MemberCount`old_count<br/>                              |
| Execute             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Proposal`proposal<br/>`Compactu32`length_bound<br/>                                                              |
| Propose             |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`threshold<br/>`Proposal`proposal<br/>`Compactu32`length_bound<br/>                                    |
| Vote                |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal<br/>`Compactu32`index<br/>`bool`approve<br/>                                                       |
| Close old weight    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Compactu64`proposal_weight_bound<br/>`Compactu32`length_bound<br/> |
| Disapprove proposal |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>                                                                                          |
| Close               |        | :heavy_check_mark: | :heavy_check_mark: |         | `Hash`proposal_hash<br/>`Compactu32`index<br/>`Weight`proposal_weight_bound<br/>`Compactu32`length_bound<br/>     |


## Democracy

| Name                      | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                      |
| ------------------------- | ------ | ------------------ | ------------------ | ------------------ | ------------------------------------------------------------------------------ |
| Propose                   |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>`CompactBalance`amount<br/>                       |
| Second                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`proposal<br/>                                                      |
| Vote                      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`ref_index<br/>`AccountVote`vote<br/>                               |
| Emergency cancel          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex`ref_index<br/>                                                |
| External propose          |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>                                                  |
| External propose majority |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>                                                  |
| External propose default  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `BoundedCallOfT`proposal<br/>                                                  |
| Fast track                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `H256`proposal_hash<br/>`BlockNumber`voting_period<br/>`BlockNumber`delay<br/> |
| Veto external             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `H256`proposal_hash<br/>                                                       |
| Cancel referendum         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`ref_index<br/>                                                     |
| Delegate                  |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`to<br/>`Conviction`conviction<br/>`Balance`balance<br/>    |
| Undelegate                |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                |
| Clear public proposals    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |                                                                                |
| Unlock                    |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>                                                |
| Remove vote               |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `ReferendumIndex`index<br/>                                                    |
| Remove other vote         |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `AccountIdLookupOfT`target<br/>`ReferendumIndex`index<br/>                     |
| Blacklist                 |        | :heavy_check_mark: | :heavy_check_mark: |                    | `H256`proposal_hash<br/>`OptionReferendumIndex`maybe_ref_index<br/>            |
| Cancel proposal           |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `Compactu32`prop_index<br/>                                                    |





## Multisig

| Name                 | Nano S | Nano S XL          | Nano SP/X          | Nesting            | Arguments                                                                                                                               |
| -------------------- | ------ | ------------------ | ------------------ | ------------------ | --------------------------------------------------------------------------------------------------------------------------------------- |
| As multi threshold 1 |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `VecAccountId`other_signatories<br/>`Call`call<br/>                                                                                     |
| As multi             |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`Call`call<br/>`Weight`max_weight<br/>      |
| Approve as multi     |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`OptionTimepoint`maybe_timepoint<br/>`H256`call_hash<br/>`Weight`max_weight<br/> |
| Cancel as multi      |        | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: | `u16`threshold<br/>`VecAccountId`other_signatories<br/>`Timepoint`timepoint<br/>`H256`call_hash<br/>                                    |



## Identity

| Name              | Nano S | Nano S XL          | Nano SP/X          | Nesting | Arguments                                                                                                       |
| ----------------- | ------ | ------------------ | ------------------ | ------- | --------------------------------------------------------------------------------------------------------------- |
| Add registrar     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`account<br/>                                                                                |
| Set identity      |        | :heavy_check_mark: | :heavy_check_mark: |         | `IdentityInfo`info<br/>                                                                                         |
| Set subs          |        | :heavy_check_mark: | :heavy_check_mark: |         | `VecTupleAccountIdData`subs<br/>                                                                                |
| Clear identity    |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                 |
| Request judgement |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`reg_index<br/>`Compactu128`max_fee<br/>                                                             |
| Cancel request    |        | :heavy_check_mark: | :heavy_check_mark: |         | `RegistrarIndex`reg_index<br/>                                                                                  |
| Set fee           |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`Compactu128`fee<br/>                                                                     |
| Set account id    |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`index<br/>`AccountIdLookupOfT`new\_<br/>                                                            |
| Set fields        |        |                    |                    |         | `Compactu32`index<br/>`IdentityFields`fields<br/>                                                               |
| Provide judgement |        | :heavy_check_mark: | :heavy_check_mark: |         | `Compactu32`reg_index<br/>`AccountIdLookupOfT`target<br/>`JudgementBalanceOfT`judgement<br/>`Hash`identity<br/> |
| Kill identity     |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`target<br/>                                                                                 |
| Add sub           |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Rename sub        |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>`Data`data<br/>                                                                     |
| Remove sub        |        | :heavy_check_mark: | :heavy_check_mark: |         | `AccountIdLookupOfT`sub<br/>                                                                                    |
| Quit sub          |        | :heavy_check_mark: | :heavy_check_mark: |         |                                                                                                                 |

