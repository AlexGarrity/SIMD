cmake_minimum_required(VERSION 3.12)

include(GoogleTest)
enable_testing()

find_package(GTest REQUIRED)
find_package(agSIMD REQUIRED)

set (TEST_NAME ${PROJECT_NAME}TestPacked)

file(GLOB_RECURSE TEST_SRC
    ${SIMD_SOURCE_DIR}/test/TestPacked.cpp
)


add_executable(${TEST_NAME} ${TEST_SRC})

if(NOT "${EXTRA_COMPILE_FLAGS}" STREQUAL "")
    set_target_properties(${TEST_NAME} PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
endif()

target_link_libraries(${TEST_NAME} gtest gtest_main ag::SIMD)

gtest_discover_tests(${TEST_NAME})