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

describe('council', function () {
  test.each(models)('tx_council_setMembers_normal', async function (m:any) {
    const blob_council_setMembers = '1800085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e015ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03020000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_council_setMembers, m, 'tx_council_setMembers_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_council_setMembers_expert', async function (m:any) {
    const blob_council_setMembers = '1800085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e015ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03020000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_council_setMembers, m, 'tx_council_setMembers_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_council_execute_normal', async function (m:any) {
    const blob_council_execute = '18011300040100fa67a487277dcea547e0620803279d69918939c57da02526f59e2034228929761b000080647593c1333c040001026501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_council_execute, m, 'tx_council_execute_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_council_execute_expert', async function (m:any) {
    const blob_council_execute = '18011300040100fa67a487277dcea547e0620803279d69918939c57da02526f59e2034228929761b000080647593c1333c040001026501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_council_execute, m, 'tx_council_execute_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_council_propose_normal', async function (m:any) {
    const blob_council_propose = '1802081300040100fa67a487277dcea547e0620803279d69918939c57da02526f59e2034228929761b000080647593c1333c040001026501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_council_propose, m, 'tx_council_propose_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_council_propose_expert', async function (m:any) {
    const blob_council_propose = '1802081300040100fa67a487277dcea547e0620803279d69918939c57da02526f59e2034228929761b000080647593c1333c040001026501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_council_propose, m, 'tx_council_propose_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_council_vote_normal', async function (m:any) {
    const blob_council_vote = '18038b974490045356fa0ae2d98f771060b715981aa16c862f0a7c3d3495680f2d2700016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_council_vote, m, 'tx_council_vote_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_council_vote_expert', async function (m:any) {
    const blob_council_vote = '18038b974490045356fa0ae2d98f771060b715981aa16c862f0a7c3d3495680f2d2700016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_council_vote, m, 'tx_council_vote_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_council_disapproveProposal_normal', async function (m:any) {
    const blob_council_disapproveProposal = '18058b974490045356fa0ae2d98f771060b715981aa16c862f0a7c3d3495680f2d276501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_council_disapproveProposal, m, 'tx_council_disapproveProposal_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_council_disapproveProposal_expert', async function (m:any) {
    const blob_council_disapproveProposal = '18058b974490045356fa0ae2d98f771060b715981aa16c862f0a7c3d3495680f2d276501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_council_disapproveProposal, m, 'tx_council_disapproveProposal_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_council_close_normal', async function (m:any) {
    const blob_council_close = '18068b974490045356fa0ae2d98f771060b715981aa16c862f0a7c3d3495680f2d2700080c106501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_council_close, m, 'tx_council_close_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_council_close_expert', async function (m:any) {
    const blob_council_close = '18068b974490045356fa0ae2d98f771060b715981aa16c862f0a7c3d3495680f2d2700080c106501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_council_close, m, 'tx_council_close_expert');
    } finally {
      await sim.close()
    }
  })
})
