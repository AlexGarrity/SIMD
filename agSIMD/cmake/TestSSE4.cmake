
function(TestSSE4)
    message(STATUS "Checking for SSE4.1 support")

    message(DEBUG "Auto-detecting compiler flag")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        message(DEBUG "Compiler ID is \"GNU\".  Using -msse4")
        set(EXTENSION_FLAG -msse4)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(DEBUG "Compiler ID is \"Clang\".  Using -msse4")
        set(EXTENSION_FLAG -msse4)
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message(DEBUG "Compiler ID is \"MSVC\".  Using /arch:SSE4")
        set(EXTENSION_FLAG /arch:SSE4)
    else()
        message(FATAL_ERROR "Extensions are unsupported on this compiler.  Please use GNU, Clang, or MSVC")
    endif()

    try_run(
        EXIT_CODE COMPILE_CODE ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake/SSE4.cpp
        COMPILE_DEFINITIONS ${EXTENSION_FLAG}
    )
    
    message(DEBUG "SSE4.1 support returned ${EXIT_CODE}")
    set(SSE4_FLAG ${EXTENSION_FLAG} CACHE INTERNAL "The flag required to complile SSE4" FORCE)
    set(HAS_SSE4 ${EXIT_CODE} CACHE INTERNAL "Does the system has SSE4?" FORCE)
    set(HAS_SSE2 ${EXIT_CODE} CACHE INTERNAL "Does the system has SSE2?" FORCE)
endfunction()