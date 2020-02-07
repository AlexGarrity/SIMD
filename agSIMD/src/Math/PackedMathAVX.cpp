#include "Math/PackedMathAVX.hpp"

#include "PackedMath.hpp"
#include "Quad.hpp"

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

__m256i BQuad8ToM256(BQuad8 v) {
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
          static_cast<int64_t>(v.qD.d) << 56,
      static_cast<int64_t>(v.qE.a) << 0 | static_cast<int64_t>(v.qE.b) << 8 |
          static_cast<int64_t>(v.qE.c) << 16 |
          static_cast<int64_t>(v.qE.d) << 24 |
          static_cast<int64_t>(v.qF.a) << 32 |
          static_cast<int64_t>(v.qF.b) << 40 |
          static_cast<int64_t>(v.qF.c) << 48 |
          static_cast<int64_t>(v.qF.d) << 56,
      static_cast<int64_t>(v.qG.a) << 0 | static_cast<int64_t>(v.qG.b) << 8 |
          static_cast<int64_t>(v.qG.c) << 16 |
          static_cast<int64_t>(v.qG.d) << 24 |
          static_cast<int64_t>(v.qH.a) << 32 |
          static_cast<int64_t>(v.qH.b) << 40 |
          static_cast<int64_t>(v.qH.c) << 48 |
          static_cast<int64_t>(v.qH.d) << 56};
}

BQuad8 M256ToBQuad8(__m256i v) {
  return {BQuad(static_cast<BYTE>(v[0] >> 0), static_cast<BYTE>(v[0] >> 8),
                static_cast<BYTE>(v[0] >> 16), static_cast<BYTE>(v[0] >> 24)),
          BQuad(static_cast<BYTE>(v[0] >> 32), static_cast<BYTE>(v[0] >> 40),
                static_cast<BYTE>(v[0] >> 48), static_cast<BYTE>(v[0] >> 56)),
          BQuad(static_cast<BYTE>(v[1] >> 0), static_cast<BYTE>(v[1] >> 8),
                static_cast<BYTE>(v[1] >> 16), static_cast<BYTE>(v[1] >> 24)),
          BQuad(static_cast<BYTE>(v[1] >> 32), static_cast<BYTE>(v[1] >> 40),
                static_cast<BYTE>(v[1] >> 48), static_cast<BYTE>(v[1] >> 56)),
          BQuad(static_cast<BYTE>(v[2] >> 0), static_cast<BYTE>(v[2] >> 8),
                static_cast<BYTE>(v[2] >> 16), static_cast<BYTE>(v[2] >> 24)),
          BQuad(static_cast<BYTE>(v[2] >> 32), static_cast<BYTE>(v[2] >> 40),
                static_cast<BYTE>(v[2] >> 48), static_cast<BYTE>(v[2] >> 56)),
          BQuad(static_cast<BYTE>(v[3] >> 0), static_cast<BYTE>(v[3] >> 8),
                static_cast<BYTE>(v[3] >> 16), static_cast<BYTE>(v[3] >> 24)),
          BQuad(static_cast<BYTE>(v[3] >> 32), static_cast<BYTE>(v[3] >> 40),
                static_cast<BYTE>(v[3] >> 48), static_cast<BYTE>(v[3] >> 56))};
}

__m256i BQuad4ToM256(BQuad4 v) {
  return {
      static_cast<int64_t>(v.qA.a) << 0 | static_cast<int64_t>(v.qA.b) << 8 |
          static_cast<int64_t>(v.qA.c) << 16 |
          static_cast<int64_t>(v.qA.d) << 24,
      static_cast<int64_t>(v.qB.a) << 0 | static_cast<int64_t>(v.qB.b) << 8 |
          static_cast<int64_t>(v.qB.c) << 16 |
          static_cast<int64_t>(v.qB.d) << 24,
      static_cast<int64_t>(v.qC.a) << 0 | static_cast<int64_t>(v.qC.b) << 8 |
          static_cast<int64_t>(v.qC.c) << 16 |
          static_cast<int64_t>(v.qC.d) << 24,
      static_cast<int64_t>(v.qD.a) << 0 | static_cast<int64_t>(v.qD.b) << 8 |
          static_cast<int64_t>(v.qD.c) << 16 |
          static_cast<int64_t>(v.qD.d) << 24};
}

BQuad4 M256ToBQuad4(__m256i v) {
  return {BQuad(static_cast<BYTE>(v[0] >> 0), static_cast<BYTE>(v[0] >> 8),
                static_cast<BYTE>(v[0] >> 16), static_cast<BYTE>(v[0] >> 24)),
          BQuad(static_cast<BYTE>(v[1] >> 0), static_cast<BYTE>(v[1] >> 8),
                static_cast<BYTE>(v[1] >> 16), static_cast<BYTE>(v[1] >> 24)),
          BQuad(static_cast<BYTE>(v[2] >> 0), static_cast<BYTE>(v[2] >> 8),
                static_cast<BYTE>(v[2] >> 16), static_cast<BYTE>(v[2] >> 24)),
          BQuad(static_cast<BYTE>(v[3] >> 0), static_cast<BYTE>(v[3] >> 8),
                static_cast<BYTE>(v[3] >> 16), static_cast<BYTE>(v[3] >> 24))};
}

__m256 FQuad2ToM256(FQuad2 v) {
  return {v.qA.a, v.qA.b, v.qA.c, v.qA.d, v.qB.a, v.qB.b, v.qB.c, v.qB.d};
}

FQuad2 M256ToFQuad2(__m256 v) {
  return {FQuad(v[0], v[1], v[2], v[3]), FQuad(v[4], v[5], v[6], v[7])};
}

BQuad4 Add(BQuad4 a, BQuad4 b) {
  auto m1 = BQuad4ToM256(a);
  auto m2 = BQuad4ToM256(b);
  auto r = _mm256_adds_epu8(m1, m2);
  return M256ToBQuad4(r);
}

BQuad4 Sub(BQuad4 a, BQuad4 b) {
  auto m1 = BQuad4ToM256(a);
  auto m2 = BQuad4ToM256(b);
  auto r = _mm256_subs_epu8(m1, m2);
  return M256ToBQuad4(r);
}

BQuad4 Mul(BQuad4 a, BQuad4 b) {
  __m256i m1 = {
      static_cast<int64_t>(a.qA.a) << 0 | static_cast<int64_t>(a.qA.b) << 16 |
          static_cast<int64_t>(a.qA.c) << 32 |
          static_cast<int64_t>(a.qA.d) << 48,
      static_cast<int64_t>(a.qB.a) << 0 | static_cast<int64_t>(a.qB.b) << 16 |
          static_cast<int64_t>(a.qB.c) << 32 |
          static_cast<int64_t>(a.qB.d) << 48,
      static_cast<int64_t>(a.qC.a) << 0 | static_cast<int64_t>(a.qC.b) << 16 |
          static_cast<int64_t>(a.qC.c) << 32 |
          static_cast<int64_t>(a.qC.d) << 48,
      static_cast<int64_t>(a.qD.a) << 0 | static_cast<int64_t>(a.qD.b) << 16 |
          static_cast<int64_t>(a.qD.c) << 32 |
          static_cast<int64_t>(a.qD.d) << 48};

  __m256i m2 = {
      static_cast<int64_t>(b.qA.a) << 0 | static_cast<int64_t>(b.qA.b) << 16 |
          static_cast<int64_t>(b.qA.c) << 32 |
          static_cast<int64_t>(b.qA.d) << 48,
      static_cast<int64_t>(b.qB.a) << 0 | static_cast<int64_t>(b.qB.b) << 16 |
          static_cast<int64_t>(b.qB.c) << 32 |
          static_cast<int64_t>(b.qB.d) << 48,
      static_cast<int64_t>(b.qC.a) << 0 | static_cast<int64_t>(b.qC.b) << 16 |
          static_cast<int64_t>(b.qC.c) << 32 |
          static_cast<int64_t>(b.qC.d) << 48,
      static_cast<int64_t>(b.qD.a) << 0 | static_cast<int64_t>(b.qD.b) << 16 |
          static_cast<int64_t>(b.qD.c) << 32 |
          static_cast<int64_t>(b.qD.d) << 48};

  auto r1 = _mm256_mullo_epi16(m1, m2);

  return {BQuad(static_cast<BYTE>(r1[0]), static_cast<BYTE>(r1[0] >> 16),
                static_cast<BYTE>(r1[0] >> 32), static_cast<BYTE>(r1[0] >> 48)),
          BQuad(static_cast<BYTE>(r1[1]), static_cast<BYTE>(r1[1] >> 16),
                static_cast<BYTE>(r1[1] >> 32), static_cast<BYTE>(r1[1] >> 48)),
          BQuad(static_cast<BYTE>(r1[2]), static_cast<BYTE>(r1[2] >> 16),
                static_cast<BYTE>(r1[2] >> 32), static_cast<BYTE>(r1[2] >> 48)),
          BQuad(static_cast<BYTE>(r1[3]), static_cast<BYTE>(r1[3] >> 16),
                static_cast<BYTE>(r1[3] >> 32),
                static_cast<BYTE>(r1[3] >> 48))};
}

BQuad4 Div(BQuad4 a, BQuad4 b) {
  auto r1 = Div(a.qA, b.qA);
  auto r2 = Div(a.qB, b.qB);
  auto r3 = Div(a.qC, b.qC);
  auto r4 = Div(a.qD, b.qD);

  return {r1, r2, r3, r4};
}

BQuad8 Add(BQuad8 a, BQuad8 b) {
  auto m1 = BQuad8ToM256(a);
  auto m2 = BQuad8ToM256(b);
  auto r = _mm256_adds_epu8(m1, m2);
  return M256ToBQuad8(r);
}

BQuad8 Sub(BQuad8 a, BQuad8 b) {
  auto m1 = BQuad8ToM256(a);
  auto m2 = BQuad8ToM256(b);
  auto r = _mm256_subs_epu8(m1, m2);
  return M256ToBQuad8(r);
}

BQuad8 Mul(BQuad8 a, BQuad8 b) {
  BQuad4 aa{a.qA, a.qB, a.qC, a.qD};
  BQuad4 ab{a.qE, a.qF, a.qG, a.qH};
  BQuad4 ba{b.qA, b.qB, b.qC, b.qD};
  BQuad4 bb{b.qE, b.qF, b.qG, b.qH};

  auto r1 = Mul(aa, ba);
  auto r2 = Mul(ab, bb);

  return {r1, r2};
}

BQuad8 Div(BQuad8 a, BQuad8 b) {
  BQuad4 aa{a.qA, a.qB, a.qC, a.qD};
  BQuad4 ab{a.qE, a.qF, a.qG, a.qH};
  BQuad4 ba{b.qA, b.qB, b.qC, b.qD};
  BQuad4 bb{b.qE, b.qF, b.qG, b.qH};

  auto r1 = Div(aa, ba);
  auto r2 = Div(ab, bb);

  return {r1, r2};
}

FQuad2 Add(FQuad2 a, FQuad2 b) {
  auto m1 = FQuad2ToM256(a);
  auto m2 = FQuad2ToM256(b);
  auto r = _mm256_add_ps(m1, m2);
  return M256ToFQuad2(r);
}

FQuad2 Sub(FQuad2 a, FQuad2 b) {
  auto m1 = FQuad2ToM256(a);
  auto m2 = FQuad2ToM256(b);
  auto r = _mm256_sub_ps(m1, m2);
  return M256ToFQuad2(r);
}

FQuad2 Mul(FQuad2 a, FQuad2 b) {
  auto m1 = FQuad2ToM256(a);
  auto m2 = FQuad2ToM256(b);
  auto r = _mm256_mul_ps(m1, m2);
  return M256ToFQuad2(r);
}

FQuad2 Div(FQuad2 a, FQuad2 b) {
  auto m1 = FQuad2ToM256(a);
  auto m2 = FQuad2ToM256(b);
  auto r = _mm256_div_ps(m1, m2);
  return M256ToFQuad2(r);
}

} // namespace SIMD
} // namespace ag