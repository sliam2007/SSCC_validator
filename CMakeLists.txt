cmake_minimum_required(VERSION 3.12)

project(SSCC_validator LANGUAGES CXX)

enable_testing()

add_executable(
    SSCC_validator
    main.cpp
    SsccValidator.cpp
    SsccValidator.h
)

add_executable(
    SSCC_validator_tests
    tests/SsccValidatorTests.cpp
    SsccValidator.cpp
    SsccValidator.h
)

set_property(TARGET SSCC_validator PROPERTY CXX_STANDARD 17)
set_property(TARGET SSCC_validator_tests PROPERTY CXX_STANDARD 17)

add_test(
    NAME SSCCValidatorTest
    COMMAND SSCC_validator_tests
)