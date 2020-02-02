cmake_minimum_required(VERSION 3.12)

project(SIMD VERSION 1.0.0 DESCRIPTION "Simple library for handling Pixels")
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 17)

message(STATUS "Using agSIMD Version ${PROJECT_VERSION}")

configure_file("${CMAKE_SOURCE_DIR}/cmake/Core.hpp.in" "${CMAKE_SOURCE_DIR}/include/Core.hpp")

set(CMAKE_BUILD_TYPE "Release")
set(BUILD_agSIMD TRUE CACHE BOOL "Build the library")
set(BUILD_SHARED_LIBS TRUE CACHE BOOL "Build the library shared (true) or static (false)")
set(RUN_UNIT_TESTS FALSE CACHE BOOL "Run unit tests to check that the library works")
set(DISABLE_SSE FALSE CACHE BOOL "Force compilation not to use SSE extensions")
set(DISABLE_AVX FALSE CACHE BOOL "Force compilation not to use AVX extensions")

if (${RUN_UNIT_TESTS})
    set(CMAKE_BUILD_TYPE "Debug")
    include(${CMAKE_SOURCE_DIR}/cmake/UnitTests.cmake)
endif()

if(${BUILD_agSIMD})
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "BUILD_LIB")
endif() 

if(${BUILD_SHARED_LIBS})
    set (LIBRARY_KEYWORD "SHARED")
else()
    set (LIBRARY_KEYWORD "STATIC")
endif()

set(SOURCE
    # Pixel sources
    ${CMAKE_SOURCE_DIR}/src/Math.cpp
    ${CMAKE_SOURCE_DIR}/src/PackedMath.cpp
)

# Check if we have either SSE2 or AVX2
set(HAS_AVX2 -1)
set(HAS_SSE2 -1)

# AVX2 Check goes here
include(${CMAKE_SOURCE_DIR}/cmake/TestAVX2.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/TestSSE2.cmake)

# Check which extensions we have...
TestSSE2()
TestAVX2()

if ("${DISABLE_SSE}" STREQUAL "ON")
    message(NOTICE "We're forcing the compiler not to use SSE")
    set(HAS_SSE2 -1)
endif()
if("${DISABLE_AVX}" STREQUAL "ON")
    message(NOTICE "We're forcing the compiler not to use AVX")
    set(HAS_AVX2 -1)
endif()

# Try AVX2 first because we prefer to use this over SSE
if("${HAS_AVX2}" STREQUAL "0")
    message(NOTICE "CPU supports AVX2, enabling AVX2 maths")
    # Enable the AVX versions of Math and PackedMath
    set(MATH_SOURCE
        ${CMAKE_SOURCE_DIR}/src/Math/MathAVX.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_SOURCE_DIR}/src/Math/PackedMathAVX.cpp
    )
    # Define the stuff we need to turn extensions on
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "ENABLE_EXTENSIONS" "FOUND_AVX2")
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS} ${AVX2_FLAG})

elseif("${HAS_SSE2}" STREQUAL "0")
    # No AVX2, so we'll instead see if we can use SSE2
    message(NOTICE "CPU supports SSE2, enabling SSE2 maths")
    # Enable the AVX versions of Math and PackedMath
    set(MATH_SOURCE
        ${CMAKE_SOURCE_DIR}/src/Math/MathSSE.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_SOURCE_DIR}/src/Math/PackedMathSSE.cpp
    )
    # Define the stuff we need to turn extensions on
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "ENABLE_EXTENSIONS" "FOUND_SSE2")
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS} ${SSE2_FLAG})

else()
    # Enable the vanilla versions of Math and PackedMath
    message(NOTICE "SIMD extensions not available, using vanilla maths")
    message(WARNING "You likely will not see any speed improvement over regular code")
    set(MATH_SOURCE
        ${CMAKE_SOURCE_DIR}/src/Math/Math.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_SOURCE_DIR}/src/Math/PackedMath.cpp
    )
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS})
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
    # No extra definitions needed.  Vanilla C++
endif()

add_library(
    SIMD ${LIBRARY_KEYWORD} ${SOURCE} ${MATH_SOURCE} ${PACKED_MATH_SOURCE}
)

if(NOT "${EXTRA_COMPILE_DEFS}" STREQUAL "")
    add_compile_definitions(${EXTRA_COMPILE_DEFS})
endif()

if(NOT "${EXTRA_COMPILE_FLAGS}" STREQUAL "")
    set_target_properties(SIMD PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
endif()

set_target_properties(
    SIMD PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
    PREFIX "ag"
    OUTPUT_NAME "SIMD"
)

target_include_directories(
    SIMD PRIVATE ${CMAKE_SOURCE_DIR}/include
)

install(
    TARGETS SIMD
    EXPORT agSIMDConfig
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT agSIMDConfig
    NAMESPACE ag::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/agSIMD
)

install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/agSIMD
)
