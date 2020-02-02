cmake_minimum_required(VERSION 3.12)

include(GoogleTest)
enable_testing()

find_package(GTest REQUIRED)
find_package(agSIMD REQUIRED)

set (TEST_NAME ${PROJECT_NAME}TestMath)

file(GLOB_RECURSE TEST_SRC
    ${CMAKE_SOURCE_DIR}/test/TestMath.cpp
)


add_executable(${TEST_NAME} ${TEST_SRC})

target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${TEST_NAME} gtest gtest_main ag::SIMD)

gtest_discover_tests(${TEST_NAME})