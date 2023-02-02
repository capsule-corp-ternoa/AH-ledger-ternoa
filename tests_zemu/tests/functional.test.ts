import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newSubstrateApp } from '@zondax/ledger-substrate'
import { APP_SEED, models, txOperation, defaultOptions } from './common'

jest.setTimeout(180000)

describe('functional', function () {
 test.each(models)('can start and stop container', async function (m:any) {
        const sim = new Zemu(m.path)
        try {
          await sim.start({ ...defaultOptions, model: m.name })
          const app = newSubstrateApp(sim.getTransport(),'ternoa')
        } finally {
          await sim.close()
        }
      })
      test.each(models)('tx_balances_transfer_normal', async function (m:any) {
        const blob_balances_transfer = '0400005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
        const sim = new Zemu(m.path)
        try {
          await sim.start({ ...defaultOptions, model: m.name })
          const app = newSubstrateApp(sim.getTransport(),'ternoa')
          await txOperation(sim, app, blob_balances_transfer, m, 'tx_balances_transfer_normal');
        } finally {
          await sim.close()
        }
      })
    //   test.each(models)('tx_staking_bond_normal', async function (m:any) {
    //     const blob_staking_bond = '0d00005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03170000b89d0d6955a001006501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    //     const sim = new Zemu(m.path)
    //     try {
    //       await sim.start({ ...defaultOptions, model: m.name })
    //       const app = newSubstrateApp(sim.getTransport(),'ternoa')
    //       await txOperation(sim, app, blob_staking_bond, m, 'tx_staking_bond_normal');
    //     } finally {
    //       await sim.close()
    //     }
    //   })
    //   test.each(models)('tx_staking_bondExtra_normal', async function (m:any) {
    //     const blob_staking_bondExtra = '0d01170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    //     const sim = new Zemu(m.path)
    //     try {
    //       await sim.start({ ...defaultOptions, model: m.name })
    //       const app = newSubstrateApp(sim.getTransport(),'ternoa')
    //       await txOperation(sim, app, blob_staking_bondExtra, m, 'tx_staking_bondExtra_normal');
    //     } finally {
    //       await sim.close()
    //     }
    //   })
    //   test.each(models)('tx_staking_unbond_normal', async function (m:any) {
    //     const blob_staking_unbond = '0d02170000b89d0d6955a0016501041300002cf61a24a2290a00000001000000b830bd7275da92f5064e9fead7605a63d2a8c6841267b96f57122867ac9a3abcd2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    //     const sim = new Zemu(m.path)
    //     try {
    //       await sim.start({ ...defaultOptions, model: m.name })
    //       const app = newSubstrateApp(sim.getTransport(),'ternoa')
    //       await txOperation(sim, app, blob_staking_unbond, m, 'tx_staking_unbond_normal');
    //     } finally {
    //       await sim.close()
    //     }
    //   })
})