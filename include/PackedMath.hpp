#pragma once

#include "Core.hpp"
#include "Math.hpp"

namespace ag {
namespace SIMD {

// Byte operations
AG_API BQuad4 Add(BQuad4 a, BQuad4 b);
AG_API BQuad4 Mul(BQuad4 a, BQuad4 b);
AG_API BQuad4 Sub(BQuad4 a, BQuad4 b);
AG_API BQuad4 Div(BQuad4 a, BQuad4 b);

AG_API BQuad8 Add(BQuad8 a, BQuad8 b);
AG_API BQuad8 Mul(BQuad8 a, BQuad8 b);
AG_API BQuad8 Sub(BQuad8 a, BQuad8 b);
AG_API BQuad8 Div(BQuad8 a, BQuad8 b);

// Float operations
AG_API FQuad2 Add(FQuad2 a, FQuad2 b);
AG_API FQuad2 Mul(FQuad2 a, FQuad2 b);
AG_API FQuad2 Sub(FQuad2 a, FQuad2 b);
AG_API FQuad2 Div(FQuad2 a, FQuad2 b);

} // namespace SIMD
} // namespace ag