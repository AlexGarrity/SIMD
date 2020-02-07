#include "Math/MathAVX.hpp"

#include "Math.hpp"
#include "Quad.hpp"

#include <immintrin.h>
#include <iostream>

// Extensions are enabled, so use AVX2 rather than regular maths
namespace ag {
namespace SIMD {

// Conversion macros
using namespace internal;

BQuad Add(const BQuad qA, const BQuad qB) {
  __m256i a{qA.a, qA.b, qA.c, qA.d};
  __m256i b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_adds_epu8(a, b);
  return {B(r[0]), B(r[1]), B(r[2]), B(r[3])};
}

FQuad Add(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_add_ps(a, b);
  return {r[0], r[1], r[2], r[3]};
}

DQuad Add(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_add_pd(a, b);
  return {r[0], r[1], r[2], r[3]};
}

BQuad Mul(const BQuad qA, const BQuad qB) {
  __m256i a {qA.a, qA.b, qA.c, qA.d};
  __m256i b {qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_mul_epu32(a, b);
  return {B(r[0]), B(r[1]), B(r[2]), B(r[3])};
}

FQuad Mul(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_mul_ps(a, b);
  return {r[0], r[1], r[2], r[3]};
}

DQuad Mul(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_mul_pd(a, b);
  return {r[0], r[1], r[2], r[3]};
}

BQuad Sub(const BQuad qA, const BQuad qB) {
  __m256i a{qA.a, qA.b, qA.c, qA.d};
  __m256i b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_subs_epu8(a, b);
  return {B(r[0]), B(r[1]), B(r[2]), B(r[3])};
}

FQuad Sub(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_sub_ps(a, b);
  return {r[0], r[1], r[2], r[3]};
}

DQuad Sub(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_sub_pd(a, b);
  return {r[0], r[1], r[2], r[3]};
}

BQuad Div(const BQuad qA, const BQuad qB) {
  __m256 a{FP(qA.a), FP(qA.b), FP(qA.c), FP(qA.d)};
  __m256 b{FP(qB.a), FP(qB.b), FP(qB.c), FP(qB.d)};
  auto r = _mm256_div_ps(a, b);
  return {B(r[0]), B(r[1]), B(r[2]), B(r[3])};
}

FQuad Div(const FQuad qA, const FQuad qB) {
  __m256 a{qA.a, qA.b, qA.c, qA.d};
  __m256 b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_div_ps(a, b);
  return {r[0], r[1], r[2], r[3]};
}

DQuad Div(const DQuad qA, const DQuad qB) {
  __m256d a{qA.a, qA.b, qA.c, qA.d};
  __m256d b{qB.a, qB.b, qB.c, qB.d};
  auto r = _mm256_div_pd(a, b);
  return {r[0], r[1], r[2], r[3]};
}

} // namespace SIMD
} // namespace ag