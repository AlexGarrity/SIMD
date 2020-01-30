#pragma once

#define LIB_VERSION "1.0.0"
#define LIB_NAME "agSIMD"

#if defined(_MSC_VER)
// Windows DLL exporting
#ifdef BUILD_LIB
#define AG_API __declspec(dllexport)
#else
#define AG_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
// GCC exports everything anyway...
#ifdef BUILD_LIB
#define AG_API __attribute__((visibility("default")))
#else
#define AG_API
#endif
#else
#error agSIMD is not supported on your platform
#endif

#if defined(FOUND_AVX2)
#include <immintrin.h>
#elif defined(FOUND_SSE2)
#include <immintrin.h>
#else
// No Extensions?
#endif
