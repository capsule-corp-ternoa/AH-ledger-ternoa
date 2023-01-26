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
import { APP_SEED, models, txOperation, defaultOptions } from './common'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

jest.setTimeout(60000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

describe('Utility', function () {
  // test.each(models)('can start and stop container', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })

  // test.each(models)('utility batch', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //     const app = newSubstrateApp(sim.getTransport(),'ternoa')
  //     const pathAccount = 0x80000000
  //     const pathChange = 0x80000000
  //     const pathIndex = 0x80000000

  //     const txBlob = Buffer.from(txUtility_batch, 'hex')

  //     const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  //     const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  //     // do not wait here.. we need to navigate
  //     const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
  //     // Wait until we are not in the main menu
  //     await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

  //     await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-utility-batch`)

  //     const signatureResponse = await signatureRequest
  //     console.log(signatureResponse)

  //     expect(signatureResponse.return_code).toEqual(0x9000)
  //     expect(signatureResponse.error_message).toEqual('No errors')

  //     // Now verify the signature
  //     let prehash = txBlob
  //     if (txBlob.length > 256) {
  //       const context = blake2bInit(32)
  //       blake2bUpdate(context, txBlob)
  //       prehash = Buffer.from(blake2bFinal(context))
  //     }
  //     const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  //     expect(valid).toEqual(true)
  //   } finally {
  //     await sim.close()
  //   }
  // })
  test.each(models)('tx_utility_batch_normal', async function (m) {
    const blob_utility_batch = '1500080400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_utility_batch, m, 'tx_utility_batch_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_utility_batch_expert', async function (m) {
    const blob_utility_batch = '1500080400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
  test.each(models)('tx_utility_batchAll_normal', async function (m) {
    const blob_utility_batchAll = '1502080400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_utility_batchAll, m, 'tx_utility_batchAll_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_utility_batchAll_expert', async function (m) {
    const blob_utility_batchAll = '1502080400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
  test.each(models)('tx_utility_forceBatch_normal', async function (m) {
    const blob_utility_forceBatch = '1504080400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_utility_forceBatch, m, 'tx_utility_forceBatch_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_utility_forceBatch_expert', async function (m) {
    const blob_utility_forceBatch = '1504080400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0317000050efe2d6e41a1b6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
