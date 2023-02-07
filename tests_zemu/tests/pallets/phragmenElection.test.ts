/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newSubstrateApp } from '@zondax/ledger-substrate'
import { APP_SEED, models, txOperation, defaultOptions } from '../common'

jest.setTimeout(180000)

describe('phragmenElection', function () {
  test.each(models)('tx_phragmenElection_vote_normal', async function (m:any) {
    const blob_phragmenElection_vote = '1900085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await txOperation(sim, app, blob_phragmenElection_vote, m, 'tx_phragmenElection_vote_normal');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_vote_expert', async function (m:any) {
    const blob_phragmenElection_vote = '1900085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await sim.clickRight()
        await sim.clickBoth()
        await sim.clickLeft()
        await txOperation(sim, app, blob_phragmenElection_vote, m, 'tx_phragmenElection_vote_expert');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_removeVoter_normal', async function (m:any) {
    const blob_phragmenElection_removeVoter = '19016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await txOperation(sim, app, blob_phragmenElection_removeVoter, m, 'tx_phragmenElection_removeVoter_normal');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_removeVoter_expert', async function (m:any) {
    const blob_phragmenElection_removeVoter = '19016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await sim.clickRight()
        await sim.clickBoth()
        await sim.clickLeft()
        await txOperation(sim, app, blob_phragmenElection_removeVoter, m, 'tx_phragmenElection_removeVoter_expert');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_submitCandidacy_normal', async function (m:any) {
    const blob_phragmenElection_submitCandidacy = '1902046501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await txOperation(sim, app, blob_phragmenElection_submitCandidacy, m, 'tx_phragmenElection_submitCandidacy_normal');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_submitCandidacy_expert', async function (m:any) {
    const blob_phragmenElection_submitCandidacy = '1902046501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await sim.clickRight()
        await sim.clickBoth()
        await sim.clickLeft()
        await txOperation(sim, app, blob_phragmenElection_submitCandidacy, m, 'tx_phragmenElection_submitCandidacy_expert');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_removeMember_normal', async function (m:any) {
    const blob_phragmenElection_removeMember = '1904005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0301016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await txOperation(sim, app, blob_phragmenElection_removeMember, m, 'tx_phragmenElection_removeMember_normal');
    } finally {
        await sim.close()
    }
})
test.each(models)('tx_phragmenElection_removeMember_expert', async function (m:any) {
    const blob_phragmenElection_removeMember = '1904005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0301016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
        await sim.start({ ...defaultOptions, model: m.name })
        const app = newSubstrateApp(sim.getTransport(), 'ternoa')
        await sim.clickRight()
        await sim.clickBoth()
        await sim.clickLeft()
        await txOperation(sim, app, blob_phragmenElection_removeMember, m, 'tx_phragmenElection_removeMember_expert');
    } finally {
        await sim.close()
    }
})
})
