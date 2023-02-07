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

describe('treasury', function () {
  // test.each(models)('can start and stop container', async function (m:any) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })
  test.each(models)('tx_treasury_proposeSpend_normal', async function (m:any) {
    const blob_treasury_proposeSpend = '1400170000b89d0d6955a001005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_treasury_proposeSpend, m, 'tx_treasury_proposeSpend_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_treasury_proposeSpend_expert', async function (m:any) {
    const blob_treasury_proposeSpend = '1400170000b89d0d6955a001005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_treasury_proposeSpend, m, 'tx_treasury_proposeSpend_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_treasury_spend_normal', async function (m:any) {
    const blob_treasury_spend = '1403170000b89d0d6955a001005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_treasury_spend, m, 'tx_treasury_spend_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_treasury_spend_expert', async function (m:any) {
    const blob_treasury_spend = '1403170000b89d0d6955a001005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_treasury_spend, m, 'tx_treasury_spend_expert');
    } finally {
      await sim.close()
    }
  })

})
