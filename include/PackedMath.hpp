#pragma once

#include "Core.hpp"
#include "Math.hpp"

namespace ag {
namespace SIMD {

// Byte operations
AG_API BQuad4 Add(const BQuad4 a, const BQuad4 b);
AG_API BQuad4 Mul(const BQuad4 a, const BQuad4 b);
AG_API BQuad4 Sub(const BQuad4 a, const BQuad4 b);
AG_API BQuad4 Div(const BQuad4 a, const BQuad4 b);

AG_API BQuad8 Add(const BQuad8 a, const BQuad8 b);
AG_API BQuad8 Mul(const BQuad8 a, const BQuad8 b);
AG_API BQuad8 Sub(const BQuad8 a, const BQuad8 b);
AG_API BQuad8 Div(const BQuad8 a, const BQuad8 b);

// Float operations
AG_API FQuad2 Add(const FQuad2 a, const FQuad2 b);
AG_API FQuad2 Mul(const FQuad2 a, const FQuad2 b);
AG_API FQuad2 Sub(const FQuad2 a, const FQuad2 b);
AG_API FQuad2 Div(const FQuad2 a, const FQuad2 b);

} // namespace SIMD
} // namespace ag