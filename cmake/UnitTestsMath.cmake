cmake_minimum_required(VERSION 3.12)

include(GoogleTest)
enable_testing()

find_package(GTest REQUIRED)

set (TEST_NAME ${PROJECT_NAME}TestMath)

file(GLOB_RECURSE TEST_SRC
    ${SIMD_SOURCE_DIR}/test/TestMath.cpp
)


add_executable(${TEST_NAME} ${TEST_SRC} ${SOURCE} ${MATH_SOURCE} ${PACKED_MATH_SOURCE})

if(NOT "${EXTRA_COMPILE_FLAGS}" STREQUAL "")
    set_target_properties(${TEST_NAME} PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
endif()

target_include_directories(${TEST_NAME} PRIVATE ${SIMD_SOURCE_DIR}/include)

target_link_libraries(${TEST_NAME} gtest gtest_main)

gtest_discover_tests(${TEST_NAME})