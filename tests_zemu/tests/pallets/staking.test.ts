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

describe('Staking', function () {
  test.each(models)('tx_staking_bond_normal', async function (m:any) {
    const blob_staking_bond = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a001006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_bond, m, 'tx_staking_bond_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bond_expert', async function (m:any) {
    const blob_staking_bond = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a001006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bond, m, 'tx_staking_bond_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_bondExtra_normal', async function (m:any) {
    const blob_staking_bondExtra = '0d01170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_bondExtra, m, 'tx_staking_bondExtra_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bondExtra_expert', async function (m:any) {
    const blob_staking_bondExtra = '0d01170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bondExtra, m, 'tx_staking_bondExtra_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_unbond_normal', async function (m:any) {
    const blob_staking_unbond = '0d02170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_unbond, m, 'tx_staking_unbond_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_unbond_expert', async function (m:any) {
    const blob_staking_unbond = '0d02170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_unbond, m, 'tx_staking_unbond_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_withdrawUnbonded_normal', async function (m:any) {
    const blob_staking_withdrawUnbonded = '0d03000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_withdrawUnbonded, m, 'tx_staking_withdrawUnbonded_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_withdrawUnbonded_expert', async function (m:any) {
    const blob_staking_withdrawUnbonded = '0d03000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_withdrawUnbonded, m, 'tx_staking_withdrawUnbonded_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_validate_normal', async function (m:any) {
    const blob_staking_validate = '0d0414016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_validate, m, 'tx_staking_validate_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_validate_expert', async function (m:any) {
    const blob_staking_validate = '0d0414016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_validate, m, 'tx_staking_validate_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_nominate_normal', async function (m:any) {
    const blob_staking_nominate = '0d0508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_nominate, m, 'tx_staking_nominate_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_nominate_expert', async function (m:any) {
    const blob_staking_nominate = '0d0508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_nominate, m, 'tx_staking_nominate_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_chill_normal', async function (m:any) {
    const blob_staking_chill = '0d066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_chill, m, 'tx_staking_chill_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_chill_expert', async function (m:any) {
    const blob_staking_chill = '0d066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_chill, m, 'tx_staking_chill_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setPayee_normal', async function (m:any) {
    const blob_staking_setPayee = '0d07006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_setPayee, m, 'tx_staking_setPayee_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setPayee_expert', async function (m:any) {
    const blob_staking_setPayee = '0d07006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setPayee, m, 'tx_staking_setPayee_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setController_normal', async function (m:any) {
    const blob_staking_setController = '0d08005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_setController, m, 'tx_staking_setController_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setController_expert', async function (m:any) {
    const blob_staking_setController = '0d08005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setController, m, 'tx_staking_setController_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setValidatorCount_normal', async function (m:any) {
    const blob_staking_setValidatorCount = '0d09286501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_setValidatorCount, m, 'tx_staking_setValidatorCount_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setValidatorCount_expert', async function (m:any) {
    const blob_staking_setValidatorCount = '0d09286501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setValidatorCount, m, 'tx_staking_setValidatorCount_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_increaseValidatorCount_normal', async function (m:any) {
    const blob_staking_increaseValidatorCount = '0d0a146501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_increaseValidatorCount, m, 'tx_staking_increaseValidatorCount_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_increaseValidatorCount_expert', async function (m:any) {
    const blob_staking_increaseValidatorCount = '0d0a146501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_increaseValidatorCount, m, 'tx_staking_increaseValidatorCount_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_scaleValidatorCount_normal', async function (m:any) {
    const blob_staking_scaleValidatorCount = '0d0b146501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_scaleValidatorCount, m, 'tx_staking_scaleValidatorCount_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_scaleValidatorCount_expert', async function (m:any) {
    const blob_staking_scaleValidatorCount = '0d0b146501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_scaleValidatorCount, m, 'tx_staking_scaleValidatorCount_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceNoEras_normal', async function (m:any) {
    const blob_staking_forceNoEras = '0d0c6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_forceNoEras, m, 'tx_staking_forceNoEras_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceNoEras_expert', async function (m:any) {
    const blob_staking_forceNoEras = '0d0c6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceNoEras, m, 'tx_staking_forceNoEras_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceNewEra_normal', async function (m:any) {
    const blob_staking_forceNewEra = '0d0d6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_forceNewEra, m, 'tx_staking_forceNewEra_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceNewEra_expert', async function (m:any) {
    const blob_staking_forceNewEra = '0d0d6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceNewEra, m, 'tx_staking_forceNewEra_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setInvulnerables_normal', async function (m:any) {
    const blob_staking_setInvulnerables = '0d0e085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_setInvulnerables, m, 'tx_staking_setInvulnerables_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setInvulnerables_expert', async function (m:any) {
    const blob_staking_setInvulnerables = '0d0e085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setInvulnerables, m, 'tx_staking_setInvulnerables_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceUnstake_normal', async function (m:any) {
    const blob_staking_forceUnstake = '0d0f5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_forceUnstake, m, 'tx_staking_forceUnstake_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceUnstake_expert', async function (m:any) {
    const blob_staking_forceUnstake = '0d0f5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceUnstake, m, 'tx_staking_forceUnstake_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceNewEraAlways_normal', async function (m:any) {
    const blob_staking_forceNewEraAlways = '0d106501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_forceNewEraAlways, m, 'tx_staking_forceNewEraAlways_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceNewEraAlways_expert', async function (m:any) {
    const blob_staking_forceNewEraAlways = '0d106501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceNewEraAlways, m, 'tx_staking_forceNewEraAlways_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_payoutStakers_normal', async function (m:any) {
    const blob_staking_payoutStakers = '0d125ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03140000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_payoutStakers, m, 'tx_staking_payoutStakers_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_payoutStakers_expert', async function (m:any) {
    const blob_staking_payoutStakers = '0d125ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03140000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_payoutStakers, m, 'tx_staking_payoutStakers_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_rebond_normal', async function (m:any) {
    const blob_staking_rebond = '0d13170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_rebond, m, 'tx_staking_rebond_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_rebond_expert', async function (m:any) {
    const blob_staking_rebond = '0d13170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_rebond, m, 'tx_staking_rebond_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_reapStash_normal', async function (m:any) {
    const blob_staking_reapStash = '0d145ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_reapStash, m, 'tx_staking_reapStash_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_reapStash_expert', async function (m:any) {
    const blob_staking_reapStash = '0d145ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_reapStash, m, 'tx_staking_reapStash_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_kick_normal', async function (m:any) {
    const blob_staking_kick = '0d1508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_kick, m, 'tx_staking_kick_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_kick_expert', async function (m:any) {
    const blob_staking_kick = '0d1508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_kick, m, 'tx_staking_kick_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setStakingConfigs_normal', async function (m:any) {
    const blob_staking_setStakingConfigs = '0d160000000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_setStakingConfigs, m, 'tx_staking_setStakingConfigs_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setStakingConfigs_expert', async function (m:any) {
    const blob_staking_setStakingConfigs = '0d160000000000006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setStakingConfigs, m, 'tx_staking_setStakingConfigs_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_chillOther_normal', async function (m:any) {
    const blob_staking_chillOther = '0d175ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_chillOther, m, 'tx_staking_chillOther_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_chillOther_expert', async function (m:any) {
    const blob_staking_chillOther = '0d175ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_chillOther, m, 'tx_staking_chillOther_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceApplyMinCommission_normal', async function (m:any) {
    const blob_staking_forceApplyMinCommission = '0d185ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_staking_forceApplyMinCommission, m, 'tx_staking_forceApplyMinCommission_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceApplyMinCommission_expert', async function (m:any) {
    const blob_staking_forceApplyMinCommission = '0d185ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf036501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceApplyMinCommission, m, 'tx_staking_forceApplyMinCommission_expert');
    } finally {
      await sim.close()
    }
  })
})
