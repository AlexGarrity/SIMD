#pragma once

// PixelMath automatically chooses the right version of the header dependent of
// whether or not you enabled extensions It otherwise does nothing

#include <cstdint>

#include "Core.hpp"

#include "Quad.hpp"

namespace ag {
namespace SIMD {

// Some useful conversions...
#define B(x) static_cast<BYTE>(x)
#define S(x) static_cast<SHORT>(x)
#define W(x) static_cast<WORD>(x)
#define D(x) static_cast<DWORD>(x)
#define iD(x) static_cast<int64_t>(x)
#define FP(x) static_cast<float>(x)
#define DP(x) static_cast<double>(x)

// Save lots of space
#define BYTEQUAD                                                               \
  const BYTE a1, const BYTE a2, const BYTE b1, const BYTE b2, const BYTE c1,   \
      const BYTE c2, const BYTE d1, const BYTE d2
#define FLOATQUAD                                                              \
  const float a1, const float a2, const float b1, const float b2,              \
      const float c1, const float c2, const float d1, const float d2
#define DOUBLEQUAD                                                             \
  const double a1, const double a2, const double b1, const double b2,          \
      const double c1, const double c2, const double d1, const double d2

// Save lots more space
#define BQUADPAIR const BQuad qA, const BQuad qB
#define FQUADPAIR const FQuad qA, const FQuad qB
#define DQUADPAIR const DQuad qA, const DQuad qB

// Declarations of maths functions
AG_API DQuad Add(DOUBLEQUAD);
AG_API FQuad Add(FLOATQUAD);
AG_API BQuad Add(BYTEQUAD);

AG_API DQuad Mul(DOUBLEQUAD);
AG_API FQuad Mul(FLOATQUAD);
AG_API BQuad Mul(BYTEQUAD);

AG_API DQuad Sub(DOUBLEQUAD);
AG_API FQuad Sub(FLOATQUAD);
AG_API BQuad Sub(BYTEQUAD);

AG_API DQuad Div(DOUBLEQUAD);
AG_API FQuad Div(FLOATQUAD);
AG_API BQuad Div(BYTEQUAD);

AG_API DQuad Add(DQUADPAIR);
AG_API FQuad Add(FQUADPAIR);
AG_API BQuad Add(BQUADPAIR);

AG_API DQuad Mul(DQUADPAIR);
AG_API FQuad Mul(FQUADPAIR);
AG_API BQuad Mul(BQUADPAIR);

AG_API DQuad Sub(DQUADPAIR);
AG_API FQuad Sub(FQUADPAIR);
AG_API BQuad Sub(BQUADPAIR);

AG_API DQuad Div(DQUADPAIR);
AG_API FQuad Div(FQUADPAIR);
AG_API BQuad Div(BQUADPAIR);

} // namespace Pixel
} // namespace ag