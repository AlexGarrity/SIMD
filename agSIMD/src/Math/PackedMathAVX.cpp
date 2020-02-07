#include "Math/PackedMathAVX.hpp"

#include "PackedMath.hpp"
#include "Quad.hpp"

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

__m256i BQuad8ToM256(BQuad8 v) {
  return { 
    iD(v.qA.a) <<  0 | iD(v.qA.b) <<  8 | iD(v.qA.c) << 16 | iD(v.qA.d) << 24
  | iD(v.qB.a) << 32 | iD(v.qB.d) << 40 | iD(v.qB.c) << 48 | iD(v.qB.d) << 56,
    iD(v.qC.a) <<  0 | iD(v.qC.b) <<  8 | iD(v.qC.c) << 16 | iD(v.qC.d) << 24
  | iD(v.qD.a) << 32 | iD(v.qD.d) << 40 | iD(v.qD.c) << 48 | iD(v.qD.d) << 56,
    iD(v.qE.a) <<  0 | iD(v.qE.b) <<  8 | iD(v.qE.c) << 16 | iD(v.qE.d) << 24
  | iD(v.qF.a) << 32 | iD(v.qF.d) << 40 | iD(v.qF.c) << 48 | iD(v.qF.d) << 56,
    iD(v.qG.a) <<  0 | iD(v.qG.b) <<  8 | iD(v.qG.c) << 16 | iD(v.qG.d) << 24
  | iD(v.qH.a) << 32 | iD(v.qH.d) << 40 | iD(v.qH.c) << 48 | iD(v.qH.d) << 56
  };
}

BQuad8 M256ToBQuad8(__m256i v) {
  return {
    BQuad(B(v[0] >>  0), B(v[0] >>  8), B(v[0] >> 16), B(v[0] >> 24)),
    BQuad(B(v[0] >> 32), B(v[0] >> 40), B(v[0] >> 48), B(v[0] >> 56)),
    BQuad(B(v[1] >>  0), B(v[1] >>  8), B(v[1] >> 16), B(v[1] >> 24)),
    BQuad(B(v[1] >> 32), B(v[1] >> 40), B(v[1] >> 48), B(v[1] >> 56)),
    BQuad(B(v[2] >>  0), B(v[2] >>  8), B(v[2] >> 16), B(v[2] >> 24)),
    BQuad(B(v[2] >> 32), B(v[2] >> 40), B(v[2] >> 48), B(v[2] >> 56)),
    BQuad(B(v[3] >>  0), B(v[3] >>  8), B(v[3] >> 16), B(v[3] >> 24)),
    BQuad(B(v[3] >> 32), B(v[3] >> 40), B(v[3] >> 48), B(v[3] >> 56))
  };
}

__m256i BQuad4ToM256(BQuad4 v) {
  return { 
    iD(v.qA.a) << 0 | iD(v.qA.b) << 8 | iD(v.qA.c) << 16 | iD(v.qA.d) << 24,
    iD(v.qB.a) << 0 | iD(v.qB.d) << 8 | iD(v.qB.c) << 16 | iD(v.qB.d) << 24,
    iD(v.qC.a) << 0 | iD(v.qC.b) << 8 | iD(v.qC.c) << 16 | iD(v.qC.d) << 24,
    iD(v.qD.a) << 0 | iD(v.qD.d) << 8 | iD(v.qD.c) << 16 | iD(v.qD.d) << 24
  };
}

BQuad4 M256ToBQuad4(__m256i v) {
  return {
    BQuad(B(v[0] >> 0), B(v[0] >> 8), B(v[0] >> 16), B(v[0] >> 24)),
    BQuad(B(v[0] >> 0), B(v[0] >> 8), B(v[0] >> 16), B(v[0] >> 24)),
    BQuad(B(v[1] >> 0), B(v[1] >> 8), B(v[1] >> 16), B(v[1] >> 24)),
    BQuad(B(v[1] >> 0), B(v[1] >> 8), B(v[1] >> 16), B(v[1] >> 24))
  };
}

__m256 FQuad2ToM256(FQuad2 v) {
  return {v.qA.a, v.qA.b, v.qA.c, v.qA.d, v.qB.a, v.qB.b, v.qB.c, v.qB.d};
}

FQuad2 M256ToFQuad2(__m256 v) {
  return {
    FQuad(v[0], v[1], v[2], v[3]),
    FQuad(v[4], v[5], v[6], v[7])
  };
}


BQuad4 Add(BQuad4 a, BQuad4 b) {
  return Add(BQuad8(a,a), BQuad8(b,b));
}

BQuad4 Sub(BQuad4 a, BQuad4 b) {
  return Sub(BQuad8(a,a), BQuad8(b,b));
}

BQuad4 Mul(BQuad4 a, BQuad4 b) {
  __m256i m1 = {
    iD(a.qA.a) << 0 | iD(a.qA.a) << 16 | iD(a.qA.a) << 32 | iD(a.qA.a) << 48, 
    iD(a.qB.a) << 0 | iD(a.qB.a) << 16 | iD(a.qB.a) << 32 | iD(a.qB.a) << 48,
    iD(a.qC.a) << 0 | iD(a.qC.a) << 16 | iD(a.qC.a) << 32 | iD(a.qC.a) << 48, 
    iD(a.qD.a) << 0 | iD(a.qD.a) << 16 | iD(a.qD.a) << 32 | iD(a.qD.a) << 48
  };

  __m256i m2 = {
    iD(b.qA.a) << 0 | iD(b.qA.a) << 16 | iD(b.qA.a) << 32 | iD(b.qA.a) << 48, 
    iD(b.qB.a) << 0 | iD(b.qB.a) << 16 | iD(b.qB.a) << 32 | iD(b.qB.a) << 48,
    iD(b.qC.a) << 0 | iD(b.qC.a) << 16 | iD(b.qC.a) << 32 | iD(b.qC.a) << 48, 
    iD(b.qD.a) << 0 | iD(b.qD.a) << 16 | iD(b.qD.a) << 32 | iD(b.qD.a) << 48
  };

  auto r1 = _mm256_mulhrs_epi16(m1, m2);

  return {
    BQuad(B(r1[0]), B(r1[0] << 16), B(r1[0] << 32), B(r1[0] << 48)),
    BQuad(B(r1[1]), B(r1[1] << 16), B(r1[1] << 32), B(r1[1] << 48)),
    BQuad(B(r1[2]), B(r1[2] << 16), B(r1[2] << 32), B(r1[2] << 48)),
    BQuad(B(r1[3]), B(r1[3] << 16), B(r1[3] << 32), B(r1[3] << 48))
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
  auto m1 = BQuad8ToM256(a);
  auto m2 = BQuad8ToM256(b);
  auto result = _mm256_adds_epu8(m1, m2);
  return M256ToBQuad8(result);
}

BQuad8 Sub(BQuad8 a, BQuad8 b) {
  auto m1 = BQuad8ToM256(a);
  auto m2 = BQuad8ToM256(b);
  auto result = _mm256_subs_epu8(m1, m2);
  return M256ToBQuad8(result);
}

BQuad8 Mul(BQuad8 a, BQuad8 b) {
  BQuad4 aa {a.qA, a.qB, a.qC, a.qD};
  BQuad4 ab {a.qE, a.qF, a.qG, a.qH};
  BQuad4 ba {b.qA, b.qB, b.qC, b.qD};
  BQuad4 bb {b.qE, b.qF, b.qG, b.qH};

  auto r1 = Mul(aa, ba);
  auto r2 = Mul(ab, bb);

  return {r1, r2};
}

BQuad8 Div(BQuad8 a, BQuad8 b) {
  BQuad4 aa {a.qA, a.qB, a.qC, a.qD};
  BQuad4 ab {a.qE, a.qF, a.qG, a.qH};
  BQuad4 ba {b.qA, b.qB, b.qC, b.qD};
  BQuad4 bb {b.qE, b.qF, b.qG, b.qH};

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