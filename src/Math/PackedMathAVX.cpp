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

inline WORD BQuadToWord(BQuad v) {
  return (W(v.a) | W(v.b) << 8 | W(v.c) << 16 | W(v.d) << 24);
}

inline BQuad WordToBQuad(WORD v) {
  return {B(v), B(v >> 8), B(v >> 16), B(v >> 24)};
}

inline DWORD BQuad2ToDword(BQuad2 v) {
  return (DWORD(v.qA.a) | DWORD(v.qA.b) << 8 | DWORD(v.qA.c) << 16 |
          DWORD(v.qA.d) << 24 | DWORD(v.qB.a) << 32 | DWORD(v.qB.b) << 40 |
          DWORD(v.qB.c) << 48 | DWORD(v.qB.d) << 56);
}

inline BQuad2 DwordToBQuad2(DWORD v) {
  return {WordToBQuad(v), WordToBQuad(v << 32)};
}

inline BQuad4 M256ToBQuad4(__m256i v) {
  return {WordToBQuad(v[0]), WordToBQuad(v[1]), WordToBQuad(v[2]),
          WordToBQuad(v[3])};
}

inline BQuad8 M256ToBQuad8(__m256i v) {
  return {DwordToBQuad2(v[0]), DwordToBQuad2(v[1]), DwordToBQuad2(v[2]),
          DwordToBQuad2(v[3])};
}

inline DWORD SQuadToDword(SQuad v) {
  return (D(v.a) | (D(v.b) << 16) | (D(v.c) << 32) | (D(v.d) << 48));
}

inline SQuad DwordToSQuad(DWORD v) {
  return {S(v), S(v >> 16), S(v >> 32), S(v >> 48)};
}

// Helper functions to translate BQuads and SQuads
inline BQuad SQuadToBQuad(SQuad v) {
  return BQuad(B(v.a), B(v.b), B(v.c), B(v.d));
}

inline SQuad BQuadToSQuad(BQuad v) {
  return SQuad(S(v.a), S(v.b), S(v.c), S(v.d));
}

// Helper functions to translate BQuad8s and SQuad4s
inline SQuad4 BQuad8UpperToSQuad4(BQuad8 x) {
  return SQuad4(BQuadToSQuad(x.qA), BQuadToSQuad(x.qB), BQuadToSQuad(x.qC),
                BQuadToSQuad(x.qD));
}

inline SQuad4 BQuad8LowerToSQuad4(BQuad8 x) {
  return SQuad4(BQuadToSQuad(x.qE), BQuadToSQuad(x.qF), BQuadToSQuad(x.qG),
                BQuadToSQuad(x.qH));
}

inline BQuad4 SQuad4ToBQuad4(SQuad v) {
#define fn(x) SQuadToBQuad(x)
  return {fn(v.a), fn(v.b), fn(v.c), fn(v.d)};
}

inline BQuad8 SQuad4ToBQuad8(SQuad4 a, SQuad4 b) {
  return {SQuad4ToBQuad4(a), SQuad4ToBQuad4(b)};
}

inline __m256i BQuad4ToM256(BQuad4 v) {
  return {BQuadToWord(v.qA), BQuadToWord(v.qB), BQuadToWord(v.qC),
          BQuadToWord(v.qD)};
}

// Super hacky and I hate it, but it works
inline __m256i BQuad8ToM256(BQuad8 v) {
  return {
      iD(BQuad2ToDword(BQuad2(v.qA, v.qB))), iD(BQuad2ToDword(BQuad2(v.qC, v.qD))),
      iD(BQuad2ToDword(BQuad2(v.qE, v.qF))), iD(BQuad2ToDword(BQuad2(v.qG, v.qH)))};
}

inline __m256i SQuad4ToM256(SQuad4 v) {
  return {iD(SQuadToDword(v.qA)), iD(SQuadToDword(v.qB)), iD(SQuadToDword(v.qC)),
          iD(SQuadToDword(v.qD))};
}

inline SQuad4 M256ToSQuad4(__m256i v) {
  return SQuad4{DwordToSQuad(v[0]), DwordToSQuad(v[1]), DwordToSQuad(v[2]),
                DwordToSQuad(v[3])};
}

inline __m256 FQuad2ToM256(FQuad2 v) {
  return {v.qA.a, v.qA.b, v.qA.c, v.qA.d, v.qB.a, v.qB.b, v.qB.c, v.qB.d};
}

FQuad2 M256ToFQuad2(__m256 v) {
  FQuad2 o;
  o.qA.a = v[0];
  o.qA.b = v[1];
  o.qA.c = v[2];
  o.qA.d = v[3];

  o.qB.a = v[4];
  o.qB.b = v[5];
  o.qB.c = v[6];
  o.qB.d = v[7];
  return o;
}

BQuad4 Add(BQuad4 a, BQuad4 b) {
  auto result = _mm256_adds_epu8(BQuad4ToM256(a), BQuad4ToM256(b));
  return M256ToBQuad4(result);
}

BQuad4 Sub(BQuad4 a, BQuad4 b) {
  auto result = _mm256_subs_epu8(BQuad4ToM256(a), BQuad4ToM256(b));
  return M256ToBQuad4(result);
}

BQuad4 Mul(BQuad4 a, BQuad4 b) {
  auto sq1 = SQuad4(BQuadToSQuad(a.qA), BQuadToSQuad(a.qB), BQuadToSQuad(a.qC),
                    BQuadToSQuad(a.qD));
  auto sq2 = SQuad4(BQuadToSQuad(b.qA), BQuadToSQuad(b.qB), BQuadToSQuad(b.qC),
                    BQuadToSQuad(b.qD));

  auto m1 = SQuad4ToM256(sq1);
  auto m2 = SQuad4ToM256(sq2);

  auto r1 = _mm256_mullo_epi16(m1, m2);

  auto sq = M256ToSQuad4(r1);

  return SQuad4ToBQuad4(sq);
}

BQuad4 Div(BQuad4 a, BQuad4 b) {
  auto r1 = Div(a.qA, b.qA);
  auto r2 = Div(a.qB, b.qB);
  auto r3 = Div(a.qC, b.qC);
  auto r4 = Div(a.qD, b.qD);

  return {r1, r2, r3, r4};
}

BQuad8 Add(BQuad8 a, BQuad8 b) {
  auto result = _mm256_adds_epu8(BQuad8ToM256(a), BQuad8ToM256(b));
  return M256ToBQuad8(result);
}

BQuad8 Sub(BQuad8 a, BQuad8 b) {
  auto result = _mm256_subs_epu8(BQuad8ToM256(a), BQuad8ToM256(b));
  return M256ToBQuad8(result);
}

BQuad8 Mul(BQuad8 a, BQuad8 b) {
  auto sq1 = BQuad8LowerToSQuad4(a);
  auto sq2 = BQuad8UpperToSQuad4(a);
  auto sq3 = BQuad8LowerToSQuad4(b);
  auto sq4 = BQuad8UpperToSQuad4(b);

  auto m1 = SQuad4ToM256(sq1);
  auto m2 = SQuad4ToM256(sq2);
  auto m3 = SQuad4ToM256(sq3);
  auto m4 = SQuad4ToM256(sq4);

  auto r1 = _mm256_mullo_epi16(m1, m3);
  auto r2 = _mm256_mullo_epi16(m2, m4);

  auto sq = SQuad4ToBQuad8(M256ToSQuad4(r1), M256ToSQuad4(r2));

  return sq;
}

BQuad8 Div(BQuad8 a, BQuad8 b) {
  auto r1 = Div(BQuad4(a.qA, a.qB, a.qC, a.qD), BQuad4(b.qA, b.qB, b.qC, b.qD));
  auto r2 = Div(BQuad4(a.qE, a.qF, a.qG, a.qH), BQuad4(b.qE, b.qF, b.qG, b.qH));

  return {r1, r2};
}

FQuad2 Add(FQuad2 a, FQuad2 b) {
  auto result = _mm256_add_ps(FQuad2ToM256(a), FQuad2ToM256(b));
  return M256ToFQuad2(result);
}

FQuad2 Sub(FQuad2 a, FQuad2 b) {
  auto result = _mm256_sub_ps(FQuad2ToM256(a), FQuad2ToM256(b));
  return M256ToFQuad2(result);
}

FQuad2 Mul(FQuad2 a, FQuad2 b) {
  auto result = _mm256_mul_ps(FQuad2ToM256(a), FQuad2ToM256(b));
  return M256ToFQuad2(result);
}

FQuad2 Div(FQuad2 a, FQuad2 b) {
  auto result = _mm256_div_ps(FQuad2ToM256(a), FQuad2ToM256(b));
  return M256ToFQuad2(result);
}

} // namespace SIMD
} // namespace ag