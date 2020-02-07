#pragma once

#include "Core.hpp"
#include "Math.hpp"

namespace ag {
namespace SIMD {

// Byte operations
AG_API u8Quad4 Add(const u8Quad4 a, const u8Quad4 b);
AG_API u8Quad4 Mul(const u8Quad4 a, const u8Quad4 b);
AG_API u8Quad4 Sub(const u8Quad4 a, const u8Quad4 b);
AG_API u8Quad4 Div(const u8Quad4 a, const u8Quad4 b);

AG_API u8Quad8 Add(const u8Quad8 a, const u8Quad8 b);
AG_API u8Quad8 Mul(const u8Quad8 a, const u8Quad8 b);
AG_API u8Quad8 Sub(const u8Quad8 a, const u8Quad8 b);
AG_API u8Quad8 Div(const u8Quad8 a, const u8Quad8 b);

// Float operations
AG_API FQuad2 Add(const FQuad2 a, const FQuad2 b);
AG_API FQuad2 Mul(const FQuad2 a, const FQuad2 b);
AG_API FQuad2 Sub(const FQuad2 a, const FQuad2 b);
AG_API FQuad2 Div(const FQuad2 a, const FQuad2 b);

} // namespace SIMD
} // namespace ag