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

describe('identity', function () {
  test.each(models)('tx_identity_addRegistrar_normal', async function (m:any) {
    const blob_identity_addRegistrar = '1c00002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_addRegistrar, m, 'tx_identity_addRegistrar_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_addRegistrar_expert', async function (m:any) {
    const blob_identity_addRegistrar = '1c00002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_addRegistrar, m, 'tx_identity_addRegistrar_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_clearIdentity_normal', async function (m:any) {
    const blob_identity_clearIdentity = '1c036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_clearIdentity, m, 'tx_identity_clearIdentity_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_clearIdentity_expert', async function (m:any) {
    const blob_identity_clearIdentity = '1c036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_clearIdentity, m, 'tx_identity_clearIdentity_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_requestJudgement_normal', async function (m:any) {
    const blob_identity_requestJudgement = '1c0404170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_requestJudgement, m, 'tx_identity_requestJudgement_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_requestJudgement_expert', async function (m:any) {
    const blob_identity_requestJudgement = '1c0404170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_requestJudgement, m, 'tx_identity_requestJudgement_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_cancelRequest_normal', async function (m:any) {
    const blob_identity_cancelRequest = '1c05010000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_cancelRequest, m, 'tx_identity_cancelRequest_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_cancelRequest_expert', async function (m:any) {
    const blob_identity_cancelRequest = '1c05010000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_cancelRequest, m, 'tx_identity_cancelRequest_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_setFee_normal', async function (m:any) {
    const blob_identity_setFee = '1c0604170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_setFee, m, 'tx_identity_setFee_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_setFee_expert', async function (m:any) {
    const blob_identity_setFee = '1c0604170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_setFee, m, 'tx_identity_setFee_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_setAccountId_normal', async function (m:any) {
    const blob_identity_setAccountId = '1c0704005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_setAccountId, m, 'tx_identity_setAccountId_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_setAccountId_expert', async function (m:any) {
    const blob_identity_setAccountId = '1c0704005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_setAccountId, m, 'tx_identity_setAccountId_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_killIdentity_normal', async function (m:any) {
    const blob_identity_killIdentity = '1c0a005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_killIdentity, m, 'tx_identity_killIdentity_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_killIdentity_expert', async function (m:any) {
    const blob_identity_killIdentity = '1c0a005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_killIdentity, m, 'tx_identity_killIdentity_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_removeSub_normal', async function (m:any) {
    const blob_identity_removeSub = '1c0d005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_removeSub, m, 'tx_identity_removeSub_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_removeSub_expert', async function (m:any) {
    const blob_identity_removeSub = '1c0d005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_removeSub, m, 'tx_identity_removeSub_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_identity_quitSub_normal', async function (m:any) {
    const blob_identity_quitSub = '1c0e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_identity_quitSub, m, 'tx_identity_quitSub_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_identity_quitSub_expert', async function (m:any) {
    const blob_identity_quitSub = '1c0e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_identity_quitSub, m, 'tx_identity_quitSub_expert');
    } finally {
      await sim.close()
    }
})
})
