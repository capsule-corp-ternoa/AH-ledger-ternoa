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
/** ******************************************************************************
 *  (c) 2023 CapsuleCorp
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

// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'
import { defaultOptions } from './common'
const blob_balances_transfer = '0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
const addon = require('../../tests_tools/neon/native')

const Resolve = require('path').resolve
const APP_PATH = Resolve('../app/output/app_sr25519.elf')

jest.setTimeout(180000)

describe('SR25519', function () {
  test('get address sr25519', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000, false, 1)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '5ED8FvTWgsk9AmJoBPj7UyfdTfpJYaKZGA9CKmJWzb4Dk9Wd'
      const expected_pk = '5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test('show address sr25519', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions, model: 'nanos' })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', 's-show_address_sr25519')

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '5ED8FvTWgsk9AmJoBPj7UyfdTfpJYaKZGA9CKmJWzb4Dk9Wd'
      const expected_pk = '5ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test('show address - reject sr25519', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.navigateAndCompareUntilText('.', 's-show_address_reject_sr25519', 'REJECT')

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })
})
