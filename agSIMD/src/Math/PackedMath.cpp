#include "Math/PackedMath.hpp"

#include "PackedMath.hpp"

namespace ag {
namespace SIMD {

BQuad4 Add(const BQuad4 a, const BQuad4 b) {
  return {
    Add(a.qA, b.qA),
    Add(a.qB, b.qB),
    Add(a.qC, b.qC),
    Add(a.qD, b.qD)
  };
}

BQuad4 Mul(const BQuad4 a, const BQuad4 b) {
  return {
    Mul(a.qA, b.qA),
    Mul(a.qB, b.qB),
    Mul(a.qC, b.qC),
    Mul(a.qD, b.qD)
  };
}

BQuad4 Sub(const BQuad4 a, const BQuad4 b) {
  return {
    Sub(a.qA, b.qA),
    Sub(a.qB, b.qB),
    Sub(a.qC, b.qC),
    Sub(a.qD, b.qD)
  };
}

BQuad4 Div(const BQuad4 a, const BQuad4 b) {
  return {
    Div(a.qA, b.qA),
    Div(a.qB, b.qB),
    Div(a.qC, b.qC),
    Div(a.qD, b.qD)
  };
}

BQuad8 Add(const BQuad8 a, const BQuad8 b) {
  return {
    Add(a.qA, b.qA),
    Add(a.qB, b.qB),
    Add(a.qC, b.qC),
    Add(a.qD, b.qD),
    Add(a.qE, b.qE),
    Add(a.qF, b.qF),
    Add(a.qG, b.qG),
    Add(a.qH, b.qH)
  };
}

BQuad8 Mul(const BQuad8 a, const BQuad8 b) {
  return {
    Mul(a.qA, b.qA),
    Mul(a.qB, b.qB),
    Mul(a.qC, b.qC),
    Mul(a.qD, b.qD),
    Mul(a.qE, b.qE),
    Mul(a.qF, b.qF),
    Mul(a.qG, b.qG),
    Mul(a.qH, b.qH)
  };
}

BQuad8 Sub(const BQuad8 a, const BQuad8 b) {
  return {
    Sub(a.qA, b.qA),
    Sub(a.qB, b.qB),
    Sub(a.qC, b.qC),
    Sub(a.qD, b.qD),
    Sub(a.qE, b.qE),
    Sub(a.qF, b.qF),
    Sub(a.qG, b.qG),
    Sub(a.qH, b.qH)
  };
}

BQuad8 Div(const BQuad8 a, const BQuad8 b) {
  return {
    Div(a.qA, b.qA),
    Div(a.qB, b.qB),
    Div(a.qC, b.qC),
    Div(a.qD, b.qD),
    Div(a.qE, b.qE),
    Div(a.qF, b.qF),
    Div(a.qG, b.qG),
    Div(a.qH, b.qH)
  };
}

FQuad2 Add(const FQuad2 a, const FQuad2 b) {
  return {Add(a.qA, b.qA), Add(a.qB, b.qB)};
}

FQuad2 Mul(const FQuad2 a, const FQuad2 b) {
  return {Mul(a.qA, b.qA), Mul(a.qB, b.qB)};
}

FQuad2 Sub(const FQuad2 a, const FQuad2 b) {
  return {Sub(a.qA, b.qA), Sub(a.qB, b.qB)};
}

FQuad2 Div(const FQuad2 a, const FQuad2 b) {
  return {Div(a.qA, b.qA), Div(a.qB, b.qB)};
}

} // namespace SIMD
} // namespace ag