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

describe('technicalCommittee', function () {
  test.each(models)('tx_technicalCommittee_setMembers_normal', async function (m:any) {
    const blob_technicalCommittee_setMembers = '1100085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00020000006501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalCommittee_setMembers, m, 'tx_technicalCommittee_setMembers_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalCommittee_setMembers_expert', async function (m:any) {
    const blob_technicalCommittee_setMembers = '1100085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00020000006501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalCommittee_setMembers, m, 'tx_technicalCommittee_setMembers_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_technicalCommittee_vote_normal', async function (m:any) {
    const blob_technicalCommittee_vote = '1103926713c1b5b77b6b336f46b91430d3da1e6eb93cf4262185910255919ef3eb1204016501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalCommittee_vote, m, 'tx_technicalCommittee_vote_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalCommittee_vote_expert', async function (m:any) {
    const blob_technicalCommittee_vote = '1103926713c1b5b77b6b336f46b91430d3da1e6eb93cf4262185910255919ef3eb1204016501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalCommittee_vote, m, 'tx_technicalCommittee_vote_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_technicalCommittee_propose_normal', async function (m:any) {
  const blob_technicalCommittee_propose = '1102081300040100fa67a487277dcea547e0620803279d69918939c57da02526f59e2034228929761b000080647593c1333c040001026501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
  const sim = new Zemu(m.path)
  try {
    await sim.start({ ...defaultOptions, model: m.name })
    const app = newSubstrateApp(sim.getTransport(),'ternoa')
    await txOperation(sim, app, blob_technicalCommittee_propose, m, 'tx_technicalCommittee_propose_normal');
  } finally {
    await sim.close()
  }
})
test.each(models)('tx_technicalCommittee_close_normal', async function (m:any) {
    const blob_technicalCommittee_close = '1106926713c1b5b77b6b336f46b91430d3da1e6eb93cf4262185910255919ef3eb1204080c106501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalCommittee_close, m, 'tx_technicalCommittee_close_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalCommittee_close_expert', async function (m:any) {
    const blob_technicalCommittee_close = '1106926713c1b5b77b6b336f46b91430d3da1e6eb93cf4262185910255919ef3eb1204080c106501041300002cf61a24a2290c00000001000000a4616ec39009f2d1ce95fc94ce85989d70bcdde565ebda1e8b3de391c1bb8dd1d2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalCommittee_close, m, 'tx_technicalCommittee_close_expert');
    } finally {
      await sim.close()
    }
  })
})
