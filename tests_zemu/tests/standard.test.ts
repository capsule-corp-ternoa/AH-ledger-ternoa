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
import { models, defaultOptions } from './common'


jest.setTimeout(180000)

describe('Standard', function () {
  test.each(models)('can start and stop container', async function (m:any) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('main menu', async function (m:any) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      //double = 0
      //left -
      //right +
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, [1,0,0,5,-6])
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get app version', async function (m:any) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')
      const resp = await app.getVersion()

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
      expect(resp).toHaveProperty('test_mode')
      expect(resp).toHaveProperty('major')
      expect(resp).toHaveProperty('minor')
      expect(resp).toHaveProperty('patch')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get address', async function (m:any) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log('------------------------------------------------------')
      console.log('resp', resp)
      console.log('------------------------------------------------------')

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

  test.each(models)('show address', async function (m:any) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address`)

      const resp = await respRequest

      console.log('------------------------------------------------------')
      console.log('resp', resp)
      console.log('------------------------------------------------------')

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

  test.each(models)('show address - reject', async function (m:any) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newSubstrateApp(sim.getTransport(),'ternoa')

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.navigateAndCompareUntilText('.', `${m.prefix.toLowerCase()}-show_address_reject`, 'REJECT')

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })
})
