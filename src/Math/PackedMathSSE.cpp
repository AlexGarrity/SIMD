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

inline WORD BQuadToWord(BQuad v) {
  return (W(v.a) | W(v.b) << 8 | W(v.c) << 16 | W(v.d) << 24);
}

inline BQuad WordToBQuad(WORD v) {
  return {B(v), B(v >> 8), B(v >> 16), B(v >> 24)};
}

inline DWORD BQuad2ToDword(BQuad2 v) {
  return (DWORD(v.a.a) | DWORD(v.a.b) << 8 | DWORD(v.a.c) << 16 |
          DWORD(v.a.d) << 24 | DWORD(v.a.a) << 32 | DWORD(v.a.b) << 40 |
          DWORD(v.a.c) << 48 | DWORD(v.a.d) << 56);
}

inline BQuad2 DwordToBQuad2(DWORD v) {
  return {WordToBQuad(v), WordToBQuad(v << 32)};
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

inline BQuad4 M128ToBQuad4(__m128i v) {
  return {WordToBQuad(v[0]), WordToBQuad(v[1]), WordToBQuad(v[2]),
          WordToBQuad(v[3])};
}

__m128i BQuad4ToM128(BQuad4 v) {
  __m128i out;
  out[0] = D(BQuadToWord(v.a)) | D(BQuadToWord(v.b)) << 32;
  out[1] = D(BQuadToWord(v.c)) | D(BQuadToWord(v.d)) << 32;
  return out;
}

inline __m128i SQuad2ToM128(SQuad2 v) {
  return {
      iD(SQuadToDword(v.a)),
      iD(SQuadToDword(v.b)),
  };
}

inline SQuad2 M128ToSQuad2(__m128i v) {
  return {DwordToSQuad(v[0]), DwordToSQuad(v[1])};
}

__m128 FQuadToM128(FQuad v) { return {v.a, v.b, v.c, v.d}; }

FQuad M128ToFQuad(__m128 v) { return {v[0], v[1], v[2], v[3]}; }

BQuad4 Add(BQuad4 a, BQuad4 b) {
  auto result = _mm_adds_epu8(BQuad4ToM128(a), BQuad4ToM128(b));
  return M128ToBQuad4(result);
}

BQuad4 Sub(BQuad4 a, BQuad4 b) {
  auto result = _mm_subs_epu8(BQuad4ToM128(a), BQuad4ToM128(b));
  return M128ToBQuad4(result);
}

BQuad4 Mul(BQuad4 a, BQuad4 b) {
  auto s1 = SQuad2(BQuadToSQuad(a.a), BQuadToSQuad(a.b));
  auto s2 = SQuad2(BQuadToSQuad(a.c), BQuadToSQuad(a.d));
  auto s3 = SQuad2(BQuadToSQuad(b.a), BQuadToSQuad(b.b));
  auto s4 = SQuad2(BQuadToSQuad(b.c), BQuadToSQuad(b.d));

  auto m1 = SQuad2ToM128(s1);
  auto m2 = SQuad2ToM128(s2);
  auto m3 = SQuad2ToM128(s3);
  auto m4 = SQuad2ToM128(s4);

  auto r1 = _mm_mullo_epi16(m1, m3);
  auto r2 = _mm_mullo_epi16(m2, m4);

  auto rs1 = M128ToSQuad2(r1);
  auto rs2 = M128ToSQuad2(r2);

  return {SQuadToBQuad(rs1.a), SQuadToBQuad(rs1.b), SQuadToBQuad(rs2.a),
          SQuadToBQuad(rs2.b)};
}

BQuad4 Div(BQuad4 a, BQuad4 b) {
  auto r1 = Div(a.a, b.a);
  auto r2 = Div(a.b, b.b);
  auto r3 = Div(a.c, b.c);
  auto r4 = Div(a.d, b.d);
  return {r1, r2, r4, r4};
}

BQuad8 Add(BQuad8 a, BQuad8 b) {
  BQuad4 aa{a.a, a.b, a.c, a.d};
  BQuad4 ab{a.e, a.f, a.g, a.h};
  BQuad4 ba{b.a, b.b, b.c, b.d};
  BQuad4 bb{b.e, b.f, b.g, b.h};

  auto r1 = _mm_adds_epu8(BQuad4ToM128(aa), BQuad4ToM128(ba));
  auto r2 = _mm_adds_epu8(BQuad4ToM128(ba), BQuad4ToM128(bb));
  return {M128ToBQuad4(r1), M128ToBQuad4(r2)};
}

BQuad8 Sub(BQuad8 a, BQuad8 b) {
  BQuad4 aa{a.a, a.b, a.c, a.d};
  BQuad4 ab{a.e, a.f, a.g, a.h};
  BQuad4 ba{b.a, b.b, b.c, b.d};
  BQuad4 bb{b.e, b.f, b.g, b.h};

  auto r1 = _mm_subs_epu8(BQuad4ToM128(aa), BQuad4ToM128(ba));
  auto r2 = _mm_subs_epu8(BQuad4ToM128(ba), BQuad4ToM128(bb));
  return {M128ToBQuad4(r1), M128ToBQuad4(r2)};
}

BQuad8 Mul(BQuad8 a, BQuad8 b) {
  auto b1 = BQuad4(a.a, a.b, a.c, a.d);
  auto b2 = BQuad4(a.e, a.f, a.g, a.h);
  auto b3 = BQuad4(b.a, b.b, b.c, b.d);
  auto b4 = BQuad4(b.e, b.f, b.g, b.h);

  auto r1 = Mul(b1, b3);
  auto r2 = Mul(b2, b4);

  return {r1, r2};
}

BQuad8 Div(BQuad8 a, BQuad8 b) {
  auto r1 = Div(BQuad4(a.a, a.b, a.c, a.d), BQuad4(b.a, b.b, b.c, b.d));
  auto r2 = Div(BQuad4(a.e, a.f, a.g, a.h), BQuad4(b.e, b.f, b.g, b.h));

  return {r1, r2};
}

FQuad2 Add(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_add_ps(FQuadToM128(a.a), FQuadToM128(b.a));
  auto r2 = _mm_add_ps(FQuadToM128(a.b), FQuadToM128(b.b));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

FQuad2 Sub(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_sub_ps(FQuadToM128(a.a), FQuadToM128(b.a));
  auto r2 = _mm_sub_ps(FQuadToM128(a.b), FQuadToM128(b.b));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

FQuad2 Mul(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_mul_ps(FQuadToM128(a.a), FQuadToM128(b.a));
  auto r2 = _mm_mul_ps(FQuadToM128(a.b), FQuadToM128(b.b));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

FQuad2 Div(FQuad2 a, FQuad2 b) {
  auto r1 = _mm_div_ps(FQuadToM128(a.a), FQuadToM128(b.a));
  auto r2 = _mm_div_ps(FQuadToM128(a.b), FQuadToM128(b.b));
  return {M128ToFQuad(r1), M128ToFQuad(r2)};
}

} // namespace SIMD
} // namespace ag