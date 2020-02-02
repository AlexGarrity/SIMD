#include "Math/MathSSE.hpp"

#include "Math.hpp"
#include "Quad.hpp"

#include <immintrin.h>

// Extensions are enabled, so use AVX2 rather than regular maths

namespace ag {
namespace SIMD {

// Some handy little helper functions for unpacking __mm256 types
BQuad UnpackChar(__m128i v) {
  return {B(v[0]), B(v[0] >> 8), B(v[0] >> 16), B(v[0] >> 24)};
}

BQuad UnpackShort(__m128i v) {
  return {B(v[0]), B(v[0] >> 16), B(v[0] >> 32), B(v[0] >> 48)};
}

BQuad UnpackInt(__m128i v) {
  return {B(v[0]), B(v[0] >> 32), B(v[1]), B(v[1] >> 32)};
}

FQuad UnpackFloat(__m128 v) {
  return {v[0], v[1], v[2], v[3]};
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

__m128i PackBQuadShort(BQuad b) {
  return {iD(b.a) | iD(b.b) << 16 | iD(b.c) << 32 | iD(b.d) << 48};
}



BQuad Add(const BQuad qA, const BQuad qB) {
  __m128i a = PackBQuad(qA);
  __m128i b = PackBQuad(qB);

  printf("a:\t%i\t%i\t%i\t%i\n", qA.a, qA.b, qA.c, qA.d);
  printf("b:\t%i\t%i\t%i\t%i\n", qB.a, qB.b, qB.c, qB.d);

  auto r = _mm_adds_epu8(a, b);

  printf("r:\t%i\t%i\t%i\t%i\n", r.a, r.b, r.c, r.d);

  return UnpackChar(r);
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
  __m128i a = PackBQuadShort(qA);
  __m128i b = PackBQuadShort(qB);
  auto result = _mm_mullo_epi16(a, b);
  return UnpackShort(result);
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
  __m128i a = PackBQuad(qA);
  __m128i b = PackBQuad(qB);
  auto result = _mm_subs_epu8(a, b);
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
  __m128 a{FP(qA.a), FP(qA.b),
           FP(qA.c), FP(qA.d)};
  __m128 b{FP(qB.a), FP(qB.b),
           FP(qB.c), FP(qB.d)};
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