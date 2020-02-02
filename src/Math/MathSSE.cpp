#include "Math/MathSSE.hpp"

#include "Math.hpp"
#include "Quad.hpp"

#include <immintrin.h>

// Extensions are enabled, so use AVX2 rather than regular maths

namespace ag {
namespace SIMD {

// Some handy little helper functions for unpacking __mm256 types
BQuad UnpackChar(__m128i chars) {
  return {B(chars[0]), B(chars[1] >> 8), B(chars[2] >> 16), B(chars[3] >> 24)};
}

BQuad UnpackInt(__m128i ints) {
  return {B(ints[0]), B(ints[1] >> 32), B(ints[2]), B(ints[3] >> 32)};
}

FQuad UnpackFloat(__m128 floats) {
  return {floats[0], floats[1], floats[2], floats[3]};
}

DQuad UnpackDouble(__m128d d1, __m128d d2) {
  return {d1[0], d1[1], d2[0], d2[1]};
}

__m128i PackBQuad(BQuad b) {
  return {iD(b.a) | iD(b.b) << 8 | iD(b.c) << 16 | iD(b.d) << 24};
}

__m128i PackBQuadInt(BQuad b) {
  return {iD(b.a) | iD(b.b) << 32, iD(b.c) | iD(b.d) << 32};
}



BQuad Add(const BQuad qA, const BQuad qB) {
  __m128i a = PackBQuadInt(BQuad(qA.a, qA.b, qA.c, qA.d));
  __m128i b = PackBQuadInt(BQuad(qB.a, qB.b, qB.c, qB.d));
  auto result = _mm_add_epi32(a, b);
  return UnpackInt(result);
}

FQuad Add(const FQuad qA, const FQuad qB) {
  __m128 a{qA.a, qA.b, qA.c, qA.d};
  __m128 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm_add_ps(a, b);
  return UnpackFloat(result);
}

DQuad Add(const DQuad qA, const DQuad qB) {
  __m128d ax{qA.a, qA.b};
  __m128d ay{qA.c, qA.d};
  __m128d bx{qB.a, qB.b};
  __m128d by{qB.c, qB.d};
  auto r1 = _mm_add_pd(ax, bx);
  auto r2 = _mm_add_pd(ay, by);
  return UnpackDouble(r1, r2);
}

BQuad Mul(const BQuad qA, const BQuad qB) {
  __m128i a = PackBQuad(BQuad(qA.a, qA.b, qA.c, qA.d));
  __m128i b = PackBQuad(BQuad(qB.a, qB.b, qB.c, qB.d));
  auto result = _mm_mul_epu32(a, b);
  return UnpackChar(result);
}

FQuad Mul(const FQuad qA, const FQuad qB) {
  __m128 a{qA.a, qA.b, qA.c, qA.d};
  __m128 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm_mul_ps(a, b);
  return UnpackFloat(result);
}

DQuad Mul(const DQuad qA, const DQuad qB) {
  __m128d ax{qA.a, qA.b};
  __m128d ay{qA.c, qA.d};
  __m128d bx{qB.a, qB.b};
  __m128d by{qB.c, qB.d};
  auto r1 = _mm_mul_pd(ax, bx);
  auto r2 = _mm_mul_pd(ay, by);
  return UnpackDouble(r1, r2);
}

BQuad Sub(const BQuad qA, const BQuad qB) {
  __m128i a = PackBQuad(BQuad(qA.a, qA.b, qA.c, qA.d));
  __m128i b = PackBQuad(BQuad(qB.a, qB.b, qB.c, qB.d));
  auto result = _mm_sub_epi16(a, b);
  return UnpackChar(result);
}

FQuad Sub(const FQuad qA, const FQuad qB) {
  __m128 a{qA.a, qA.b, qA.c, qA.d};
  __m128 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm_sub_ps(a, b);
  return UnpackFloat(result);
}

DQuad Sub(const DQuad qA, const DQuad qB) {
  __m128d ax{qA.a, qA.b};
  __m128d ay{qA.c, qA.d};
  __m128d bx{qB.a, qB.b};
  __m128d by{qB.c, qB.d};
  auto r1 = _mm_sub_pd(ax, bx);
  auto r2 = _mm_sub_pd(ay, by);
  return UnpackDouble(r1, r2);
}

BQuad Div(const BQuad qA, const BQuad qB) {
  // This has to be done as floats, as integer division is unsupported
  __m128 a{static_cast<float>(qA.a), static_cast<float>(qA.b),
           static_cast<float>(qA.c), static_cast<float>(qA.d)};
  __m128 b{static_cast<float>(qB.a), static_cast<float>(qB.b),
           static_cast<float>(qB.c), static_cast<float>(qB.d)};
  auto result = _mm_div_ps(a, b);
  return UnpackChar(result);
}

FQuad Div(const FQuad qA, const FQuad qB) {
  __m128 a{qA.a, qA.b, qA.c, qA.d};
  __m128 b{qB.a, qB.b, qB.c, qB.d};
  auto result = _mm_div_ps(a, b);
  return UnpackFloat(result);
}

DQuad Div(const DQuad qA, const DQuad qB) {
  __m128d ax{qA.a, qA.b};
  __m128d ay{qA.c, qA.d};
  __m128d bx{qB.a, qB.b};
  __m128d by{qB.c, qB.d};
  auto r1 = _mm_div_pd(ax, bx);
  auto r2 = _mm_div_pd(ay, by);
  return UnpackDouble(r1, r2);
}

} // namespace SIMD
} // namespace ag