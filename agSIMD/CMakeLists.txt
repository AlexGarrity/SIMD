message(STATUS "Using ${PROJECT_NAME} Version ${PROJECT_VERSION}")

# Set BUILD_LIB to switch from import to export
if(${BUILD_agSIMD})
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "BUILD_LIB")
endif() 

# Set the math sources
set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Math.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PackedMath.cpp
)

# Are we resetting the checks and doing them again?
if (${EXTENSION_RESET_CHECKS})
    unset(HAS_AVX2 CACHE)
    unset(HAS_SSE4 CACHE)
    unset(HAS_SSE2 CACHE)
endif()

# Check which extensions we have, if we need to
if (NOT DEFINED CACHE{HAS_AVX2})
    include(cmake/TestAVX2.cmake)
    TestAVX2()
endif()
if (NOT DEFINED CACHE{HAS_SSE4})
    include(cmake/TestSSE4.cmake)
    TestSSE4()
endif()
if (NOT DEFINED CACHE{HAS_SSE2})
    include(cmake/TestSSE2.cmake)
    TestSSE2()
endif()

# Disable extensions if the user requests it
if("${EXTENSION_DISABLE_AVX2}" STREQUAL "ON")
    message(NOTICE "We're forcing the compiler not to use AVX2+")
    set(HAS_AVX2 -1)
endif()
if ("${EXTENSION_DISABLE_SSE4}" STREQUAL "ON")
    message(NOTICE "We're forcing the compiler not to use SSE4+")
    set(HAS_AVX2 -1)
    set(HAS_SSE4 -1)
endif()
if ("${EXTENSION_DISABLE_SSE2}" STREQUAL "ON")
    message(NOTICE "We're forcing the compiler not to use SSE2+")
    set(HAS_AVX2 -1)
    set(HAS_SSE4 -1)
    set(HAS_SSE2 -1)
endif()

# Try AVX2 first because we prefer to use this over SSE
if("${HAS_AVX2}" STREQUAL "0")
    message(NOTICE "CPU supports AVX2, enabling AVX2 maths")
    # Enable the AVX versions of Math and PackedMath
    set(MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/MathAVX.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/PackedMathAVX.cpp
    )
    # Define the stuff we need to turn extensions on
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "ENABLE_EXTENSIONS" "FOUND_AVX2")
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS} ${AVX2_FLAG})
    set(PROJECT_EXTENSION AVX2)

elseif("${HAS_SSE4}" STREQUAL "0")
    # No AVX2, so we'll instead see if we can use SSE4
    message(NOTICE "CPU supports SSE4, enabling SSE4 maths")
    # Enable the AVX versions of Math and PackedMath
    set(MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/MathSSE.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/PackedMathSSE.cpp
    )
    # Define the stuff we need to turn extensions on
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "ENABLE_EXTENSIONS" "FOUND_SSE2")
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS} ${SSE4_FLAG})
    set(PROJECT_EXTENSION SSE4)

elseif("${HAS_SSE2}" STREQUAL "0")
    # No SSE4, so we'll instead see if we can use SSE2
    message(NOTICE "CPU supports SSE2, enabling SSE2 maths")
    # Enable the AVX versions of Math and PackedMath
    set(MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/MathSSE.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/PackedMathSSE.cpp
    )
    # Define the stuff we need to turn extensions on
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS} "ENABLE_EXTENSIONS" "FOUND_SSE2")
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS} ${SSE2_FLAG})
    set(PROJECT_EXTENSION SSE2)

else()
    # Enable the vanilla versions of Math and PackedMath
    message(NOTICE "SIMD extensions not available, using vanilla maths")
    message(WARNING "You likely will not see any speed improvement over regular code")
    set(MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/Math.cpp
    )
    set(PACKED_MATH_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Math/PackedMath.cpp
    )
    set(EXTRA_COMPILE_DEFS ${EXTRA_COMPILE_DEFS})
    set(EXTRA_COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
    set(PROJECT_EXTENSION NORM)
    # No extra definitions needed.  Vanilla C++
endif()

# Configure the core file with the project name and version
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/Core.hpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/include/Core.hpp")

# Add the sources to the library
add_library(
    SIMD ${LIBRARY_KEYWORD} ${SOURCE} ${MATH_SOURCE} ${PACKED_MATH_SOURCE}
)

# If we have extra compile definitions, add them now
if(NOT "${EXTRA_COMPILE_DEFS}" STREQUAL "")
    add_compile_definitions(${EXTRA_COMPILE_DEFS})
endif()

# If we have extra compile flags, add them now
if(NOT "${EXTRA_COMPILE_FLAGS}" STREQUAL "")
    set_target_properties(SIMD PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
endif()

# Se the library properties
set_target_properties(
    SIMD PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
    PREFIX "ag"
    OUTPUT_NAME "SIMD"
)

# If we're using an extension, add it to the project name
if (NOT "${PROJECT_EXTENSION}" STREQUAL "")
    set_target_properties(
        SIMD PROPERTIES
        SOVERSION ${PROJECT_VERSION}-${PROJECT_EXTENSION}
    )
endif()

# Add the include directory to the library
target_include_directories(
    SIMD PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Install stuff
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