module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  transformIgnorePatterns: ['^.+\\.js$'],
  maxConcurrency:2,
  // modulePathIgnorePatterns: ['<rootDir>/tests/pallets/'],
  // collectCoverage: true,
  // coverageReporters: ["json", "html"],
}
