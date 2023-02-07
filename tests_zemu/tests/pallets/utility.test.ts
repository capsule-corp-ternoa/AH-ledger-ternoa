/** ******************************************************************************
 * (c) 2018 - 2022 Zondax AG
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

import Zemu from '@zondax/zemu'
import { newSubstrateApp } from '@zondax/ledger-substrate'
import { APP_SEED, models, txOperation, defaultOptions } from '../common'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

jest.setTimeout(60000)

describe('Utility', function () {
  // test.each(models)('can start and stop container', async function (m:any) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })
  test.each(models)('tx_utility_batch_normal', async function (m:any) {
    const blob_utility_batch = '1500080403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa060403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_utility_batch, m, 'tx_utility_batch_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_utility_batch_expert', async function (m:any) {
    const blob_utility_batch = '1500080403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa060403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_utility_batch, m, 'tx_utility_batch_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_utility_batchAll_normal', async function (m:any) {
    const blob_utility_batchAll = '1502080403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa060403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_utility_batchAll, m, 'tx_utility_batchAll_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_utility_batchAll_expert', async function (m:any) {
    const blob_utility_batchAll = '1502080403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa060403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_utility_batchAll, m, 'tx_utility_batchAll_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_utility_forceBatch_normal', async function (m:any) {
    const blob_utility_forceBatch = '1504080403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa060403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_utility_forceBatch, m, 'tx_utility_forceBatch_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_utility_forceBatch_expert', async function (m:any) {
    const blob_utility_forceBatch = '1504080403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa060403002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e1700000c6d51c8f7aa066501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_utility_forceBatch, m, 'tx_utility_forceBatch_expert');
    } finally {
      await sim.close()
    }
  })
})
