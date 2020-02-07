#include "Math/MathSSE.hpp"

#include "Math.hpp"
#include "Quad.hpp"

#include <immintrin.h>

// Extensions are enabled, so use AVX2 rather than regular maths

namespace ag {
namespace SIMD {

// Some handy little helper functions for unpacking __mm256 types
u8Quad UnpackChar(__m128i v) {
  return {static_cast<uint8_t>(v[0]), static_cast<uint8_t>(v[0] >> 8),
          static_cast<uint8_t>(v[0] >> 16), static_cast<uint8_t>(v[0] >> 24)};
}

u8Quad UnpackShort(__m128i v) {
  return {static_cast<uint8_t>(v[0]), static_cast<uint8_t>(v[0] >> 16),
          static_cast<uint8_t>(v[0] >> 32), static_cast<uint8_t>(v[0] >> 48)};
}

u8Quad UnpackInt(__m128i v) {
  return {static_cast<uint8_t>(v[0]), static_cast<uint8_t>(v[0] >> 32),
          static_cast<uint8_t>(v[1]), static_cast<uint8_t>(v[1] >> 32)};
}

u8Quad UnpackFloatToChar(__m128 v) {
  return {static_cast<uint8_t>(v[0]), static_cast<uint8_t>(v[1]),
          static_cast<uint8_t>(v[2]), static_cast<uint8_t>(v[3])};
}

FQuad UnpackFloat(__m128 v) { return {v[0], v[1], v[2], v[3]}; }

DQuad UnpackDouble(__m128d d1, __m128d d2) {
  return {d1[0], d1[1], d2[0], d2[1]};
}

__m128i Packu8Quad(u8Quad b) {
  return {iD(b.a) | iD(b.b) << 8 | iD(b.c) << 16 | iD(b.d) << 24};
}

__m128i Packu8QuadInt(u8Quad b) {
  return {iD(b.a) | iD(b.b) << 32, iD(b.c) | iD(b.d) << 32};
}

__m128i Packu8QuadShort(u8Quad b) {
  return {iD(b.a) | iD(b.b) << 16 | iD(b.c) << 32 | iD(b.d) << 48};
}

u8Quad Add(const u8Quad qA, const u8Quad qB) {
  __m128i a = Packu8Quad(qA);
  __m128i b = Packu8Quad(qB);

  auto r = _mm_adds_epu8(a, b);

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

u8Quad Mul(const u8Quad qA, const u8Quad qB) {
  __m128i a = Packu8QuadShort(qA);
  __m128i b = Packu8QuadShort(qB);
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

u8Quad Sub(const u8Quad qA, const u8Quad qB) {
  __m128i a = Packu8Quad(qA);
  __m128i b = Packu8Quad(qB);
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

u8Quad Div(const u8Quad qA, const u8Quad qB) {
  // This has to be done as floats, as integer division is unsupported
  __m128 a{static_cast<float>(qA.a), static_cast<float>(qA.b),
           static_cast<float>(qA.c), static_cast<float>(qA.d)};
  __m128 b{static_cast<float>(qB.a), static_cast<float>(qB.b),
           static_cast<float>(qB.c), static_cast<float>(qB.d)};
  auto result = _mm_div_ps(a, b);
  return UnpackFloatToChar(result);
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