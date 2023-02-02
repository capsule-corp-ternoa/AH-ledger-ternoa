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

describe('technicalMembership', function () {
  // test.each(models)('can start and stop container', async function (m:any) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })
  test.each(models)('tx_technicalMembership_addMember_normal', async function (m:any) {
    const blob_technicalMembership_addMember = '1200005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_addMember, m, 'tx_technicalMembership_addMember_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_addMember_expert', async function (m:any) {
    const blob_technicalMembership_addMember = '1200005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_addMember, m, 'tx_technicalMembership_addMember_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_removeMember_normal', async function (m:any) {
    const blob_technicalMembership_removeMember = '1201005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_removeMember, m, 'tx_technicalMembership_removeMember_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_removeMember_expert', async function (m:any) {
    const blob_technicalMembership_removeMember = '1201005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_removeMember, m, 'tx_technicalMembership_removeMember_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_swapMember_normal', async function (m:any) {
    const blob_technicalMembership_swapMember = '1202005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_swapMember, m, 'tx_technicalMembership_swapMember_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_swapMember_expert', async function (m:any) {
    const blob_technicalMembership_swapMember = '1202005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e6501041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_swapMember, m, 'tx_technicalMembership_swapMember_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_resetMembers_normal', async function (m:any) {
    const blob_technicalMembership_resetMembers = '1203085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_resetMembers, m, 'tx_technicalMembership_resetMembers_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_resetMembers_expert', async function (m:any) {
    const blob_technicalMembership_resetMembers = '1203085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_resetMembers, m, 'tx_technicalMembership_resetMembers_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_changeKey_normal', async function (m:any) {
    const blob_technicalMembership_changeKey = '1204005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_changeKey, m, 'tx_technicalMembership_changeKey_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_changeKey_expert', async function (m:any) {
    const blob_technicalMembership_changeKey = '1204005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_changeKey, m, 'tx_technicalMembership_changeKey_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_setPrime_normal', async function (m:any) {
    const blob_technicalMembership_setPrime = '1205005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_setPrime, m, 'tx_technicalMembership_setPrime_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_setPrime_expert', async function (m:any) {
    const blob_technicalMembership_setPrime = '1205005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_setPrime, m, 'tx_technicalMembership_setPrime_expert');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_clearPrime_normal', async function (m:any) {
    const blob_technicalMembership_clearPrime = '120600041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await txOperation(sim, app, blob_technicalMembership_clearPrime, m, 'tx_technicalMembership_clearPrime_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_technicalMembership_clearPrime_expert', async function (m:any) {
    const blob_technicalMembership_clearPrime = '120600041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_technicalMembership_clearPrime, m, 'tx_technicalMembership_clearPrime_expert');
    } finally {
      await sim.close()
    }
  })
})
