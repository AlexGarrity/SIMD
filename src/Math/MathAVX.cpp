#include "Math/MathAVX.hpp"

#include "Math.hpp"
#include "Quad.hpp"

#include <immintrin.h>
#include <iostream>

// Extensions are enabled, so use AVX2 rather than regular maths
namespace ag {
namespace SIMD {

// Some handy little helper functions for unpacking __mm256 types
inline BQuad UnpackChar(__m256i v) {
  return {B(v[0]), B(v[1]), B(v[2]), B(v[3])};
}

inline FQuad UnpackFloat(__m256 v) {
  return {FP(v[0]), FP(v[1]), FP(v[2]), FP(v[3])};
}

inline DQuad UnpackDouble(__m256d v) {
  return {DP(v[0]), DP(v[1]), DP(v[2]), DP(v[3])};
}

BQuad Add(const BQuad qA, const BQuad qB) {
  __m256i a{qA.a, qA.b, qA.c, qA.d};
  __m256i b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_adds_epu8(a, b);
  return UnpackChar(result);
}

FQuad Add(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_add_ps(a, b);
  return UnpackFloat(result);
}

DQuad Add(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_add_pd(a, b);
  return UnpackDouble(result);
}

BQuad Mul(const BQuad qA, const BQuad qB) {
  __m256i a{qA.a, qA.b, qA.c, qA.d};
  __m256i b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_mul_epu32(a, b);
  return UnpackChar(result);
}

FQuad Mul(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_mul_ps(a, b);
  return UnpackFloat(result);
}

DQuad Mul(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_mul_pd(a, b);
  return UnpackDouble(result);
}

BQuad Sub(const BQuad qA, const BQuad qB) {
  __m256i a{qA.a, qA.b, qA.c, qA.d};
  __m256i b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_sub_epi16(a, b);
  return UnpackChar(result);
}

FQuad Sub(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_sub_ps(a, b);
  return UnpackFloat(result);
}

DQuad Sub(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_sub_pd(a, b);
  return UnpackDouble(result);
}

BQuad Div(const BQuad qA, const BQuad qB) {
  __m256 a{FP(qA.a), FP(qA.b), FP(qA.c), FP(qA.d)};
  __m256 b{FP(qB.a), FP(qB.b), FP(qB.c), FP(qB.d)};
  auto result = _mm256_div_ps(a, b);
  return UnpackChar(result);
}

FQuad Div(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_div_ps(a, b);
  return UnpackFloat(result);
}

DQuad Div(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm256_div_pd(a, b);
  return UnpackDouble(result);
}

} // namespace SIMD
} // namespace ag