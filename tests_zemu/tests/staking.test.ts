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

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})
describe('Staking', function () {
  // test.each(models)('can start and stop container', async function (m) {
  //   const sim = new Zemu(m.path)
  //   try {
  //     await sim.start({ ...defaultOptions, model: m.name })
  //   } finally {
  //     await sim.close()
  //   }
  // })

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
    const blob_staking_unbond = '0d02170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
    const blob_staking_unbond = '0d02170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
test.each(models)('tx_staking_chill_normal', async function (m) {
    const blob_staking_chill = '0d0600041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_chill, m, 'tx_staking_chill_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_chill_expert', async function (m) {
    const blob_staking_chill = '0d0600041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_chill, m, 'tx_staking_chill_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setPayee_normal', async function (m) {
    const blob_staking_setPayee = '0d070000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_setPayee, m, 'tx_staking_setPayee_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setPayee_expert', async function (m) {
    const blob_staking_setPayee = '0d070000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setPayee, m, 'tx_staking_setPayee_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setController_normal', async function (m) {
    const blob_staking_setController = '0d08005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
    const blob_staking_setController = '0d08005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
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
test.each(models)('tx_staking_forceNoEras_normal', async function (m) {
    const blob_staking_forceNoEras = '0d0c00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_forceNoEras, m, 'tx_staking_forceNoEras_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceNoEras_expert', async function (m) {
    const blob_staking_forceNoEras = '0d0c00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceNoEras, m, 'tx_staking_forceNoEras_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceNewEra_normal', async function (m) {
    const blob_staking_forceNewEra = '0d0d00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_forceNewEra, m, 'tx_staking_forceNewEra_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceNewEra_expert', async function (m) {
    const blob_staking_forceNewEra = '0d0d00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceNewEra, m, 'tx_staking_forceNewEra_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_setInvulnerables_normal', async function (m) {
    const blob_staking_setInvulnerables = '0d0e085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_setInvulnerables, m, 'tx_staking_setInvulnerables_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_setInvulnerables_expert', async function (m) {
    const blob_staking_setInvulnerables = '0d0e085ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf032a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_setInvulnerables, m, 'tx_staking_setInvulnerables_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceNewEraAlways_normal', async function (m) {
    const blob_staking_forceNewEraAlways = '0d1000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_forceNewEraAlways, m, 'tx_staking_forceNewEraAlways_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceNewEraAlways_expert', async function (m) {
    const blob_staking_forceNewEraAlways = '0d1000041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceNewEraAlways, m, 'tx_staking_forceNewEraAlways_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_rebond_normal', async function (m) {
    const blob_staking_rebond = '0d13170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_rebond, m, 'tx_staking_rebond_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_rebond_expert', async function (m) {
    const blob_staking_rebond = '0d13170000b89d0d6955a00100041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_rebond, m, 'tx_staking_rebond_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_kick_normal', async function (m) {
    const blob_staking_kick = '0d1508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_kick, m, 'tx_staking_kick_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_kick_expert', async function (m) {
    const blob_staking_kick = '0d1508005ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf03002a0f95b2b19f46a67d10ff7c1cbc80ec27970aaa073ce796585bd201aab7ed7e00041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_kick, m, 'tx_staking_kick_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_chillOther_normal', async function (m) {
    const blob_staking_chillOther = '0d175ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_chillOther, m, 'tx_staking_chillOther_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_chillOther_expert', async function (m) {
    const blob_staking_chillOther = '0d175ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_chillOther, m, 'tx_staking_chillOther_expert');
    } finally {
      await sim.close()
    }
  })
test.each(models)('tx_staking_forceApplyMinCommission_normal', async function (m) {
    const blob_staking_forceApplyMinCommission = '0d185ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await txOperation(sim, app, blob_staking_forceApplyMinCommission, m, 'tx_staking_forceApplyMinCommission_normal');
    } finally {
      await sim.close()
    }
  })
  test.each(models)('tx_staking_forceApplyMinCommission_expert', async function (m) {
    const blob_staking_forceApplyMinCommission = '0d185ee4922bdb199b22175df9f13b8b7bf282896b7dccfce815c9621f9c2a9fdf0300041300002cf61a24a2290b0000000100000018bcdb75a0bba577b084878db2dc2546eb21504eaad4b564bb7d47f9d02b6aced2b169b41debe3843d84ec7baca76ccdad3408cb6ed0a8ce7fa3f3f0119cd8db'
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newTernoaApp(sim.getTransport())
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()
      await txOperation(sim, app, blob_staking_forceApplyMinCommission, m, 'tx_staking_forceApplyMinCommission_expert');
    } finally {
      await sim.close()
    }
  })

})
