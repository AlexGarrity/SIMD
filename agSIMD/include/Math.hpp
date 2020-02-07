#pragma once

// PixelMath automatically chooses the right version of the header dependent of
// whether or not you enabled extensions It otherwise does nothing

#include <cstdint>

#include "Core.hpp"

#include "Quad.hpp"

namespace ag {
namespace SIMD {

AG_API DQuad Add(const DQuad qA, const DQuad qB);
AG_API FQuad Add(const FQuad qA, const FQuad qB);
AG_API BQuad Add(const BQuad qA, const BQuad qB);

AG_API DQuad Mul(const DQuad qA, const DQuad qB);
AG_API FQuad Mul(const FQuad qA, const FQuad qB);
AG_API BQuad Mul(const BQuad qA, const BQuad qB);

AG_API DQuad Sub(const DQuad qA, const DQuad qB);
AG_API FQuad Sub(const FQuad qA, const FQuad qB);
AG_API BQuad Sub(const BQuad qA, const BQuad qB);

AG_API DQuad Div(const DQuad qA, const DQuad qB);
AG_API FQuad Div(const FQuad qA, const FQuad qB);
AG_API BQuad Div(const BQuad qA, const BQuad qB);

} // namespace SIMD
} // namespace ag