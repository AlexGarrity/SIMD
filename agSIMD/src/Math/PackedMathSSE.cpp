#include "Math/PackedMathSSE.hpp"

#include "PackedMath.hpp"

#include <immintrin.h>

namespace ag {
namespace SIMD {

// Conversion macros
using namespace internal;

/*
    Indexes are in bytes, rather than bits

    __mm256i packing for uint8_ts:
        | QUAD1 | QUAD2 | QUAD3 | QUAD4 | QUAD5 | QUAD6 | QUAD7 | QUAD8 |
        | 00-03 | 04-07 | 08-11 | 12-15 | 16-19 | 20-23 | 24-27 | 28-31 |

    __mm256 packing for floats:
        | QUAD1 | QUAD2 |
        | 00-15 | 16-32 |

*/

__m128i BQuad4ToM128(BQuad4 v) {
  return { 
    iD(v.qA.a) <<  0 | iD(v.qA.b) <<  8 | iD(v.qA.c) << 16 | iD(v.qA.d) << 24
  | iD(v.qB.a) << 32 | iD(v.qB.b) << 40 | iD(v.qB.c) << 48 | iD(v.qB.d) << 56,
    iD(v.qC.a) <<  0 | iD(v.qC.b) <<  8 | iD(v.qC.c) << 16 | iD(v.qC.d) << 24
  | iD(v.qD.a) << 32 | iD(v.qD.b) << 40 | iD(v.qD.c) << 48 | iD(v.qD.d) << 56
  };
}

BQuad4 M128ToBQuad4(__m128i v) {
  return {
    BQuad(B(v[0] >>  0), B(v[0] >>  8), B(v[0] >> 16), B(v[0] >> 24)),
    BQuad(B(v[0] >> 32), B(v[0] >> 40), B(v[0] >> 48), B(v[0] >> 56)),
    BQuad(B(v[1] >>  0), B(v[1] >>  8), B(v[1] >> 16), B(v[1] >> 24)),
    BQuad(B(v[1] >> 32), B(v[1] >> 40), B(v[1] >> 48), B(v[1] >> 56))
  };
}


__m128 FQuadToM128(FQuad v) {
  return {
    v.a, v.b, v.c, v.d
  };
}

FQuad M128ToFQuad(__m128 v) {
  return { v[0], v[1], v[2], v[3] };
}

BQuad4 Add(BQuad4 a, BQuad4 b) {
  auto m1 = BQuad4ToM128(a);
  auto m2 = BQuad4ToM128(b);
  auto result = _mm_adds_epu8(m1, m2);
  return M128ToBQuad4(result);
}

BQuad4 Sub(BQuad4 a, BQuad4 b) {
  auto m1 = BQuad4ToM128(a);
  auto m2 = BQuad4ToM128(b);
  auto result = _mm_subs_epu8(m1, m2);
  return M128ToBQuad4(result);
}

BQuad4 Mul(BQuad4 a, BQuad4 b) {
  // Turns out this is a total pain because there isn't such thing as multiplying BYTEs...

  // Load the bytes into __m128i's like they're 16 bit values...
  __m128i m1 {
    iD(a.qA.a) | iD(a.qA.b) << 16 | iD(a.qA.c) << 32 | iD(a.qA.d) << 48,
    iD(a.qB.a) | iD(a.qB.b) << 16 | iD(a.qB.c) << 32 | iD(a.qB.d) << 48
  };
    __m128i m2 {
    iD(a.qC.a) | iD(a.qC.b) << 16 | iD(a.qC.c) << 32 | iD(a.qC.d) << 48,
    iD(a.qD.a) | iD(a.qD.b) << 16 | iD(a.qD.c) << 32 | iD(a.qD.d) << 48
  };
    __m128i m3 {
    iD(b.qA.a) | iD(b.qA.b) << 16 | iD(b.qA.c) << 32 | iD(b.qA.d) << 48,
    iD(b.qB.a) | iD(b.qB.b) << 16 | iD(b.qB.c) << 32 | iD(b.qB.d) << 48
  };
    __m128i m4 {
    iD(b.qC.a) | iD(b.qC.b) << 16 | iD(b.qC.c) << 32 | iD(b.qC.d) << 48,
    iD(b.qD.a) | iD(b.qD.b) << 16 | iD(b.qD.c) << 32 | iD(b.qD.d) << 48
  };

  auto r1 = _mm_mullo_epi16(m1, m3);
  auto r2 = _mm_mullo_epi16(m2, m4);

  return {
    BQuad(B(r1[0]), B(r1[0] >> 16), B(r1[0] >> 32), B(r1[0] >> 48)),
    BQuad(B(r1[1]), B(r1[1] >> 16), B(r1[1] >> 32), B(r1[1] >> 48)),
    BQuad(B(r2[0]), B(r2[0] >> 16), B(r2[0] >> 32), B(r2[0] >> 48)),
    BQuad(B(r2[1]), B(r2[1] >> 16), B(r2[1] >> 32), B(r2[1] >> 48)),
  };
}

BQuad4 Div(BQuad4 a, BQuad4 b) {
  auto r1 = Div(a.qA, b.qA);
  auto r2 = Div(a.qB, b.qB);
  auto r3 = Div(a.qC, b.qC);
  auto r4 = Div(a.qD, b.qD);
  return {r1, r2, r3, r4};
}

BQuad8 Add(BQuad8 a, BQuad8 b) {
  BQuad4 aa{a.qA, a.qB, a.qC, a.qD};
  BQuad4 ab{a.qE, a.qF, a.qG, a.qH};
  BQuad4 ba{b.qA, b.qB, b.qC, b.qD};
  BQuad4 bb{b.qE, b.qF, b.qG, b.qH};

  auto r1 = _mm_adds_epu8(BQuad4ToM128(aa), BQuad4ToM128(ba));
  auto r2 = _mm_adds_epu8(BQuad4ToM128(ab), BQuad4ToM128(bb));
  return {M128ToBQuad4(r1), M128ToBQuad4(r2)};
}

BQuad8 Sub(BQuad8 a, BQuad8 b) {
  BQuad4 aa{a.qA, a.qB, a.qC, a.qD};
  BQuad4 ab{a.qE, a.qF, a.qG, a.qH};
  BQuad4 ba{b.qA, b.qB, b.qC, b.qD};
  BQuad4 bb{b.qE, b.qF, b.qG, b.qH};

  auto r1 = _mm_subs_epu8(BQuad4ToM128(aa), BQuad4ToM128(ba));
  auto r2 = _mm_subs_epu8(BQuad4ToM128(ab), BQuad4ToM128(bb));
  return {M128ToBQuad4(r1), M128ToBQuad4(r2)};
}

BQuad8 Mul(BQuad8 a, BQuad8 b) {
  BQuad4 b1{a.qA, a.qB, a.qC, a.qD};
  BQuad4 b2{a.qE, a.qF, a.qG, a.qH};
  BQuad4 b3{b.qA, b.qB, b.qC, b.qD};
  BQuad4 b4{b.qE, b.qF, b.qG, b.qH};

  auto r1 = Mul(b1, b3);
  auto r2 = Mul(b2, b4);

  return {r1, r2};
}

BQuad8 Div(BQuad8 a, BQuad8 b) {
  auto r1 = Div(BQuad4(a.qA, a.qB, a.qC, a.qD), BQuad4(b.qA, b.qB, b.qC, b.qD));
  auto r2 = Div(BQuad4(a.qE, a.qF, a.qG, a.qH), BQuad4(b.qE, b.qF, b.qG, b.qH));

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