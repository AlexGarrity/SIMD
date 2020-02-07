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
AG_API u8Quad Add(const u8Quad qA, const u8Quad qB);

AG_API DQuad Mul(const DQuad qA, const DQuad qB);
AG_API FQuad Mul(const FQuad qA, const FQuad qB);
AG_API u8Quad Mul(const u8Quad qA, const u8Quad qB);

AG_API DQuad Sub(const DQuad qA, const DQuad qB);
AG_API FQuad Sub(const FQuad qA, const FQuad qB);
AG_API u8Quad Sub(const u8Quad qA, const u8Quad qB);

AG_API DQuad Div(const DQuad qA, const DQuad qB);
AG_API FQuad Div(const FQuad qA, const FQuad qB);
AG_API u8Quad Div(const u8Quad qA, const u8Quad qB);

} // namespace SIMD
} // namespace ag