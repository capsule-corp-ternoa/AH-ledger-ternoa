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
import { newTernoaApp } from '@zondax/ledger-substrate'
import { APP_SEED, models, txOperation, defaultOptions } from './common'

jest.setTimeout(180000)

describe('Balances', function () {
  // test.each(models)('can start and stop container', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })
  test.each(models)('tx_staking_bondExtra_normal', async function (m) {
    const blob_staking_bondExtra = '0d01170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_bondExtra, m, 'tx_staking_bondExtra_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bondExtra_expert', async function (m) {
    const blob_staking_bondExtra = '0d01170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bondExtra, m, 'tx_staking_bondExtra_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_unbond_normal', async function (m) {
    const blob_staking_unbond = '0d02130000e8890423c78a00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_unbond, m, 'tx_staking_unbond_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_unbond_expert', async function (m) {
    const blob_staking_unbond = '0d02130000e8890423c78a00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_unbond, m, 'tx_staking_unbond_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setController_normal', async function (m) {
    const blob_staking_setController = '0d08002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_setController, m, 'tx_staking_setController_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setController_expert', async function (m) {
    const blob_staking_setController = '0d08002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setController, m, 'tx_staking_setController_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_bond_staked_normal', async function (m) {
    const blob_staking_bond_staked = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_bond_staked, m, 'tx_staking_bond_staked_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bond_staked_expert', async function (m) {
    const blob_staking_bond_staked = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bond_staked, m, 'tx_staking_bond_staked_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_bond_stash_normal', async function (m) {
    const blob_staking_bond_stash = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_bond_stash, m, 'tx_staking_bond_stash_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bond_stash_expert', async function (m) {
    const blob_staking_bond_stash = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bond_stash, m, 'tx_staking_bond_stash_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_bond_controller_normal', async function (m) {
    const blob_staking_bond_controller = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010200041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_bond_controller, m, 'tx_staking_bond_controller_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bond_controller_expert', async function (m) {
    const blob_staking_bond_controller = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010200041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bond_controller, m, 'tx_staking_bond_controller_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_bond_none_normal', async function (m) {
    const blob_staking_bond_none = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010400041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_bond_none, m, 'tx_staking_bond_none_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_bond_none_expert', async function (m) {
    const blob_staking_bond_none = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a0010400041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_bond_none, m, 'tx_staking_bond_none_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_nominate_normal', async function (m) {
    const blob_staking_nominate = '0d0508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_nominate, m, 'tx_staking_nominate_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_nominate_expert', async function (m) {
    const blob_staking_nominate = '0d0508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_nominate, m, 'tx_staking_nominate_expert');
    } finally {
      await sim.close()
    }
  })
 
})
