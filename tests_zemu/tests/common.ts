import Zemu, { DeviceModel, DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { SubstrateApp } from '@zondax/ledger-substrate'
// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'

const addon = require('../../tests_tools/neon/native')

const Resolve = require('path').resolve


export const txOperation = async (sim: Zemu, app: SubstrateApp, blob: string, m: any, testName: string, sr25519: boolean = false, shortcut: boolean = false) => {
  console.log('performing:', `${m.prefix.toLowerCase()}-${testName}`)
  const pathAccount = 0x80000000
  const pathChange = 0x80000000
  const pathIndex = 0x80000000
  const txBlob = Buffer.from(blob, 'hex')
  const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
  const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

  // do not wait here.. we need to navigate
  const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
  // Wait until we are not in the main menu
  
  await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
  if (shortcut) {
    // Shortcut to accept menu
    await sim.clickBoth()

    // Accept tx
    await sim.clickBoth()
  } else {
    await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-${testName}`)
  }

  const signatureResponse = await signatureRequest
  expect(signatureResponse.return_code).toEqual(0x9000)
  expect(signatureResponse.error_message).toEqual('No errors')
  // Now verify the signature
  let prehash = txBlob
  if (txBlob.length > 256) {
    const context = blake2bInit(32)
    blake2bUpdate(context, txBlob)
    prehash = Buffer.from(blake2bFinal(context))
  }

  //ed25519 validation
  const validED = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
  expect(validED).toEqual(true)
  if (sr25519 == true) {
    //sr25519 validation
    const signingcontext = Buffer.from([])
    const validSR = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1))
    expect(validSR).toEqual(true)
  }
}

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

// const APP_PATH = Resolve('../app/output/app_sr25519.elf')
//only enable ed or sr, do not enable both 
export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
  // { name: 'app_sr25519', prefix: 'SP', path: APP_PATH_SP },
]

export const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}
