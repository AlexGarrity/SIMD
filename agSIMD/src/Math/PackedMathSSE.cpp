#include "Math/PackedMathSSE.hpp"

#include "PackedMath.hpp"

#include <immintrin.h>

namespace ag {
namespace SIMD {

/*
    Indexes are in bytes, rather than bits

    __mm256i packing for uint8_ts:
        | QUAD1 | QUAD2 | QUAD3 | QUAD4 | QUAD5 | QUAD6 | QUAD7 | QUAD8 |
        | 00-03 | 04-07 | 08-11 | 12-15 | 16-19 | 20-23 | 24-27 | 28-31 |

    __mm256 packing for floats:
        | QUAD1 | QUAD2 |
        | 00-15 | 16-32 |

*/

__m128i u8Quad4ToM128(u8Quad4 v) {
  return {
      static_cast<int64_t>(v.qA.a) << 0 | static_cast<int64_t>(v.qA.b) << 8 |
          static_cast<int64_t>(v.qA.c) << 16 |
          static_cast<int64_t>(v.qA.d) << 24 |
          static_cast<int64_t>(v.qB.a) << 32 |
          static_cast<int64_t>(v.qB.b) << 40 |
          static_cast<int64_t>(v.qB.c) << 48 |
          static_cast<int64_t>(v.qB.d) << 56,
      static_cast<int64_t>(v.qC.a) << 0 | static_cast<int64_t>(v.qC.b) << 8 |
          static_cast<int64_t>(v.qC.c) << 16 |
          static_cast<int64_t>(v.qC.d) << 24 |
          static_cast<int64_t>(v.qD.a) << 32 |
          static_cast<int64_t>(v.qD.b) << 40 |
          static_cast<int64_t>(v.qD.c) << 48 |
          static_cast<int64_t>(v.qD.d) << 56};
}

u8Quad4 M128Tou8Quad4(__m128i v) {
  return {u8Quad(static_cast<uint8_t>(v[0] >> 0), static_cast<uint8_t>(v[0] >> 8),
                static_cast<uint8_t>(v[0] >> 16), static_cast<uint8_t>(v[0] >> 24)),
          u8Quad(static_cast<uint8_t>(v[0] >> 32), static_cast<uint8_t>(v[0] >> 40),
                static_cast<uint8_t>(v[0] >> 48), static_cast<uint8_t>(v[0] >> 56)),
          u8Quad(static_cast<uint8_t>(v[1] >> 0), static_cast<uint8_t>(v[1] >> 8),
                static_cast<uint8_t>(v[1] >> 16), static_cast<uint8_t>(v[1] >> 24)),
          u8Quad(static_cast<uint8_t>(v[1] >> 32), static_cast<uint8_t>(v[1] >> 40),
                static_cast<uint8_t>(v[1] >> 48), static_cast<uint8_t>(v[1] >> 56))};
}

__m128 FQuadToM128(FQuad v) { return {v.a, v.b, v.c, v.d}; }

FQuad M128ToFQuad(__m128 v) { return {v[0], v[1], v[2], v[3]}; }

u8Quad4 Add(u8Quad4 a, u8Quad4 b) {
  auto m1 = u8Quad4ToM128(a);
  auto m2 = u8Quad4ToM128(b);
  auto result = _mm_adds_epu8(m1, m2);
  return M128Tou8Quad4(result);
}

u8Quad4 Sub(u8Quad4 a, u8Quad4 b) {
  auto m1 = u8Quad4ToM128(a);
  auto m2 = u8Quad4ToM128(b);
  auto result = _mm_subs_epu8(m1, m2);
  return M128Tou8Quad4(result);
}

u8Quad4 Mul(u8Quad4 a, u8Quad4 b) {
  // Turns out this is a total pain because there isn't such thing as
  // multiplying uint8_ts...

  // Load the bytes into __m128i's like they're 16 bit values...
  __m128i m1{static_cast<int64_t>(a.qA.a) | static_cast<int64_t>(a.qA.b) << 16 |
                 static_cast<int64_t>(a.qA.c) << 32 |
                 static_cast<int64_t>(a.qA.d) << 48,
             static_cast<int64_t>(a.qB.a) | static_cast<int64_t>(a.qB.b) << 16 |
                 static_cast<int64_t>(a.qB.c) << 32 |
                 static_cast<int64_t>(a.qB.d) << 48};
  __m128i m2{static_cast<int64_t>(a.qC.a) | static_cast<int64_t>(a.qC.b) << 16 |
                 static_cast<int64_t>(a.qC.c) << 32 |
                 static_cast<int64_t>(a.qC.d) << 48,
             static_cast<int64_t>(a.qD.a) | static_cast<int64_t>(a.qD.b) << 16 |
                 static_cast<int64_t>(a.qD.c) << 32 |
                 static_cast<int64_t>(a.qD.d) << 48};
  __m128i m3{static_cast<int64_t>(b.qA.a) | static_cast<int64_t>(b.qA.b) << 16 |
                 static_cast<int64_t>(b.qA.c) << 32 |
                 static_cast<int64_t>(b.qA.d) << 48,
             static_cast<int64_t>(b.qB.a) | static_cast<int64_t>(b.qB.b) << 16 |
                 static_cast<int64_t>(b.qB.c) << 32 |
                 static_cast<int64_t>(b.qB.d) << 48};
  __m128i m4{static_cast<int64_t>(b.qC.a) | static_cast<int64_t>(b.qC.b) << 16 |
                 static_cast<int64_t>(b.qC.c) << 32 |
                 static_cast<int64_t>(b.qC.d) << 48,
             static_cast<int64_t>(b.qD.a) | static_cast<int64_t>(b.qD.b) << 16 |
                 static_cast<int64_t>(b.qD.c) << 32 |
                 static_cast<int64_t>(b.qD.d) << 48};

  auto r1 = _mm_mullo_epi16(m1, m3);
  auto r2 = _mm_mullo_epi16(m2, m4);

  return {
      u8Quad(static_cast<uint8_t>(r1[0]), static_cast<uint8_t>(r1[0] >> 16),
            static_cast<uint8_t>(r1[0] >> 32), static_cast<uint8_t>(r1[0] >> 48)),
      u8Quad(static_cast<uint8_t>(r1[1]), static_cast<uint8_t>(r1[1] >> 16),
            static_cast<uint8_t>(r1[1] >> 32), static_cast<uint8_t>(r1[1] >> 48)),
      u8Quad(static_cast<uint8_t>(r2[0]), static_cast<uint8_t>(r2[0] >> 16),
            static_cast<uint8_t>(r2[0] >> 32), static_cast<uint8_t>(r2[0] >> 48)),
      u8Quad(static_cast<uint8_t>(r2[1]), static_cast<uint8_t>(r2[1] >> 16),
            static_cast<uint8_t>(r2[1] >> 32), static_cast<uint8_t>(r2[1] >> 48)),
  };
}

u8Quad4 Div(u8Quad4 a, u8Quad4 b) {
  auto r1 = Div(a.qA, b.qA);
  auto r2 = Div(a.qB, b.qB);
  auto r3 = Div(a.qC, b.qC);
  auto r4 = Div(a.qD, b.qD);
  return {r1, r2, r3, r4};
}

u8Quad8 Add(u8Quad8 a, u8Quad8 b) {
  u8Quad4 aa{a.qA, a.qB, a.qC, a.qD};
  u8Quad4 ab{a.qE, a.qF, a.qG, a.qH};
  u8Quad4 ba{b.qA, b.qB, b.qC, b.qD};
  u8Quad4 bb{b.qE, b.qF, b.qG, b.qH};

  auto r1 = _mm_adds_epu8(u8Quad4ToM128(aa), u8Quad4ToM128(ba));
  auto r2 = _mm_adds_epu8(u8Quad4ToM128(ab), u8Quad4ToM128(bb));
  return {M128Tou8Quad4(r1), M128Tou8Quad4(r2)};
}

u8Quad8 Sub(u8Quad8 a, u8Quad8 b) {
  u8Quad4 aa{a.qA, a.qB, a.qC, a.qD};
  u8Quad4 ab{a.qE, a.qF, a.qG, a.qH};
  u8Quad4 ba{b.qA, b.qB, b.qC, b.qD};
  u8Quad4 bb{b.qE, b.qF, b.qG, b.qH};

  auto r1 = _mm_subs_epu8(u8Quad4ToM128(aa), u8Quad4ToM128(ba));
  auto r2 = _mm_subs_epu8(u8Quad4ToM128(ab), u8Quad4ToM128(bb));
  return {M128Tou8Quad4(r1), M128Tou8Quad4(r2)};
}

u8Quad8 Mul(u8Quad8 a, u8Quad8 b) {
  u8Quad4 b1{a.qA, a.qB, a.qC, a.qD};
  u8Quad4 b2{a.qE, a.qF, a.qG, a.qH};
  u8Quad4 b3{b.qA, b.qB, b.qC, b.qD};
  u8Quad4 b4{b.qE, b.qF, b.qG, b.qH};

  auto r1 = Mul(b1, b3);
  auto r2 = Mul(b2, b4);

  return {r1, r2};
}

u8Quad8 Div(u8Quad8 a, u8Quad8 b) {
  auto r1 = Div(u8Quad4(a.qA, a.qB, a.qC, a.qD), u8Quad4(b.qA, b.qB, b.qC, b.qD));
  auto r2 = Div(u8Quad4(a.qE, a.qF, a.qG, a.qH), u8Quad4(b.qE, b.qF, b.qG, b.qH));

  return {r1, r2};
}

FQuad2 Add(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_add_ps(FQuadToM128(a.qA), FQuadToM128(b.qA));
  auto r2 = _mm_add_ps(FQuadToM128(a.qB), FQuadToM128(b.qB));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

FQuad2 Sub(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_sub_ps(FQuadToM128(a.qA), FQuadToM128(b.qA));
  auto r2 = _mm_sub_ps(FQuadToM128(a.qB), FQuadToM128(b.qB));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

FQuad2 Mul(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_mul_ps(FQuadToM128(a.qA), FQuadToM128(b.qA));
  auto r2 = _mm_mul_ps(FQuadToM128(a.qB), FQuadToM128(b.qB));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

FQuad2 Div(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_div_ps(FQuadToM128(a.qA), FQuadToM128(b.qA));
  auto r2 = _mm_div_ps(FQuadToM128(a.qB), FQuadToM128(b.qB));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

} // namespace SIMD
} // namespace ag