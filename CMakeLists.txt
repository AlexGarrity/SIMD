cmake_minimum_required(VERSION 3.12)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 17)

project(SIMD VERSION 1.0.1 DESCRIPTION "Simple library for handling SIMD maths")

# Build variables
set(BUILD_agSIMD TRUE CACHE BOOL "Build the library")
set(BUILD_SHARED_LIBS TRUE CACHE BOOL "Build the library shared (true) or static (false)")

# Unit test variables
set(TEST_QUAD FALSE CACHE BOOL "Run unit tests to check that the quad component works")
set(TEST_MATH FALSE CACHE BOOL "Run unit tests to check that the math component works")
set(TEST_MATH_PACKED FALSE CACHE BOOL "Run unit tests to check that the packed math component works")

# Extension variables
set(EXTENSION_DISABLE_SSE2 FALSE CACHE BOOL "Force compilation not to use SSE2+ extensions")
set(EXTENSION_DISABLE_SSE4 FALSE CACHE BOOL "Force compilation not to use SSE4+ extensions")
set(EXTENSION_DISABLE_AVX2 FALSE CACHE BOOL "Force compilation not to use AVX2+ extensions")
set(EXTENSION_RESET_CHECKS FALSE CACHE BOOL "Reset the extension checks")

# Switch between building static and shared lib files
if(${BUILD_SHARED_LIBS})
    set (LIBRARY_KEYWORD "SHARED")
else()
    set (LIBRARY_KEYWORD "STATIC")
endif()

# Only test if the user actually awnts to
if (${TEST_QUAD} OR ${TEST_MATH} OR ${TEST_MATH_PACKED})
    enable_testing()
    add_subdirectory(test)
endif()

add_subdirectory(agSIMD)