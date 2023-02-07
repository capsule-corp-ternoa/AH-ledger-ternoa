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

describe('Balances', function () {
  // test.each(models)('can start and stop container', async function (m:any) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })
  test.each(models)('pallets/tx_balances_transfer_normal', async function (m:any) {
    const blob_balances_transfer = '0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_balances_transfer, m, 'pallets/tx_balances_transfer_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_balances_transfer_expert', async function (m:any) {
    const blob_balances_transfer = '0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_balances_transfer, m, 'tx_balances_transfer_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_balances_setBalance_normal', async function (m:any) {
    const blob_balances_setBalance = '0401005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a001170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_balances_setBalance, m, 'tx_balances_setBalance_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_balances_setBalance_expert', async function (m:any) {
    const blob_balances_setBalance = '0401005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a001170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_balances_setBalance, m, 'tx_balances_setBalance_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_balances_forceTransfer_normal', async function (m:any) {
    const blob_balances_forceTransfer = '0402005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_balances_forceTransfer, m, 'tx_balances_forceTransfer_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_balances_forceTransfer_expert', async function (m:any) {
    const blob_balances_forceTransfer = '0402005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_balances_forceTransfer, m, 'tx_balances_forceTransfer_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_balances_transferKeepAlive_normal', async function (m:any) {
    const blob_balances_transferKeepAlive = '0403005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_balances_transferKeepAlive, m, 'tx_balances_transferKeepAlive_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_balances_transferKeepAlive_expert', async function (m:any) {
    const blob_balances_transferKeepAlive = '0403005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_balances_transferKeepAlive, m, 'tx_balances_transferKeepAlive_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_balances_transferAll_normal', async function (m:any) {
    const blob_balances_transferAll = '0404005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf030100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_balances_transferAll, m, 'tx_balances_transferAll_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_balances_transferAll_expert', async function (m:any) {
    const blob_balances_transferAll = '0404005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf030100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_balances_transferAll, m, 'tx_balances_transferAll_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_balances_forceUnreserve_normal', async function (m:any) {
    const blob_balances_forceUnreserve = '0405005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf030000b89d0d6955a0010000000000000000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_balances_forceUnreserve, m, 'tx_balances_forceUnreserve_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_balances_forceUnreserve_expert', async function (m:any) {
    const blob_balances_forceUnreserve = '0405005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf030000b89d0d6955a0010000000000000000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_balances_forceUnreserve, m, 'tx_balances_forceUnreserve_expert');
    } finally {
      await sim.close()
    }
  })

})
