
set (TEST_NAME ${PROJECT_NAME}TestMath)

file(GLOB_RECURSE TEST_SRC
    Main.cpp
)

add_executable(${TEST_NAME} ${TEST_SRC})

if(NOT "${EXTRA_COMPILE_FLAGS}" STREQUAL "")
    set_target_properties(${TEST_NAME} PROPERTIES COMPILE_FLAGS ${EXTRA_COMPILE_FLAGS})
endif()

target_link_libraries(${TEST_NAME} SIMD libgtest libgmock) 

gtest_discover_tests(${TEST_NAME})