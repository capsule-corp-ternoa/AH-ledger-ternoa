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

describe('multisig', function () {
  test.each(models)('tx_multisig_asMultiThreshold1_normal', async function (m:any) {
    const blob_multisig_asMultiThreshold1 = '1b000c5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e90b5ab205c6974c9ea841be688864633dc9ca8a357843eeacf2314649965fe220403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_multisig_asMultiThreshold1, m, 'tx_multisig_asMultiThreshold1_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_multisig_asMultiThreshold1_expert', async function (m:any) {
    const blob_multisig_asMultiThreshold1 = '1b000c5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e90b5ab205c6974c9ea841be688864633dc9ca8a357843eeacf2314649965fe220403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_multisig_asMultiThreshold1, m, 'tx_multisig_asMultiThreshold1_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_multisig_approveAsMulti_normal', async function (m:any) {
    const blob_multisig_approveAsMulti = '1b0202000c5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e90b5ab205c6974c9ea841be688864633dc9ca8a357843eeacf2314649965fe2200b933992e1dc26b462f41c20b21090a6f6617fc826a3ad60abaf603f54c6003da4264962e006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_multisig_approveAsMulti, m, 'tx_multisig_approveAsMulti_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_multisig_approveAsMulti_expert', async function (m:any) {
    const blob_multisig_approveAsMulti = '1b0202000c5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e90b5ab205c6974c9ea841be688864633dc9ca8a357843eeacf2314649965fe2200b933992e1dc26b462f41c20b21090a6f6617fc826a3ad60abaf603f54c6003da4264962e006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_multisig_approveAsMulti, m, 'tx_multisig_approveAsMulti_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_multisig_cancelAsMulti_normal', async function (m:any) {
    const blob_multisig_cancelAsMulti = '1b0302000c5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e90b5ab205c6974c9ea841be688864633dc9ca8a357843eeacf2314649965fe22204e000001000000b933992e1dc26b462f41c20b21090a6f6617fc826a3ad60abaf603f54c6003da6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_multisig_cancelAsMulti, m, 'tx_multisig_cancelAsMulti_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_multisig_cancelAsMulti_expert', async function (m:any) {
    const blob_multisig_cancelAsMulti = '1b0302000c5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e90b5ab205c6974c9ea841be688864633dc9ca8a357843eeacf2314649965fe22204e000001000000b933992e1dc26b462f41c20b21090a6f6617fc826a3ad60abaf603f54c6003da6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_multisig_cancelAsMulti, m, 'tx_multisig_cancelAsMulti_expert');
    } finally {
      await sim.close()
    }
  })
})
