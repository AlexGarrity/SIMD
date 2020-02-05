#include "Math/PackedMath.hpp"

#include "PackedMath.hpp"

namespace ag {
namespace SIMD {

BQuad4 Add(const BQuad4 a, const BQuad4 b) {
  BQuad4 out {0};
  out.qA = Add(a.qA, b.qA);
  out.qB = Add(a.qB, b.qB);
  out.qC = Add(a.qC, b.qC);
  out.qD = Add(a.qD, b.qD);
  return out;
}

BQuad4 Mul(const BQuad4 a, const BQuad4 b) {
  BQuad4 out {0};
  out.qA = Mul(a.qA, b.qA);
  out.qB = Mul(a.qB, b.qB);
  out.qC = Mul(a.qC, b.qC);
  out.qD = Mul(a.qD, b.qD);
  return out;
}

BQuad4 Sub(const BQuad4 a, const BQuad4 b) {
  BQuad4 out {0};
  out.qA = Sub(a.qA, b.qA);
  out.qB = Sub(a.qB, b.qB);
  out.qC = Sub(a.qC, b.qC);
  out.qD = Sub(a.qD, b.qD);
  return out;
}

BQuad4 Div(const BQuad4 a, const BQuad4 b) {
  BQuad8 out {0};
  out.qA = Div(a.qA, b.qA);
  out.qB = Div(a.qB, b.qB);
  out.qC = Div(a.qC, b.qC);
  out.qD = Div(a.qD, b.qD);
  return out;
}

BQuad8 Add(const BQuad8 a, const BQuad8 b) {
  BQuad8 out {0};
  out.qA = Add(a.qA, b.qA);
  out.qB = Add(a.qB, b.qB);
  out.qC = Add(a.qC, b.qC);
  out.qD = Add(a.qD, b.qD);
  out.qE = Add(a.qE, b.qE);
  out.qF = Add(a.qF, b.qF);
  out.qG = Add(a.qG, b.qG);
  out.qH = Add(a.qH, b.qH);
  return out;
}

BQuad8 Mul(const BQuad8 a, const BQuad8 b) {
  BQuad8 out {0};
  out.qA = Mul(a.qA, b.qA);
  out.qB = Mul(a.qB, b.qB);
  out.qC = Mul(a.qC, b.qC);
  out.qD = Mul(a.qD, b.qD);
  out.qE = Mul(a.qE, b.qE);
  out.qF = Mul(a.qF, b.qF);
  out.qG = Mul(a.qG, b.qG);
  out.qH = Mul(a.qH, b.qH);
  return out;
}

BQuad8 Sub(const BQuad8 a, const BQuad8 b) {
  BQuad8 out {0};
  out.qA = Sub(a.qA, b.qA);
  out.qB = Sub(a.qB, b.qB);
  out.qC = Sub(a.qC, b.qC);
  out.qD = Sub(a.qD, b.qD);
  out.qE = Sub(a.qE, b.qE);
  out.qF = Sub(a.qF, b.qF);
  out.qG = Sub(a.qG, b.qG);
  out.qH = Sub(a.qH, b.qH);
  return out;
}

BQuad8 Div(const BQuad8 a, const BQuad8 b) {
  BQuad8 out {0};
  out.qA = Div(a.qA, b.qA);
  out.qB = Div(a.qB, b.qB);
  out.qC = Div(a.qC, b.qC);
  out.qD = Div(a.qD, b.qD);
  out.qE = Div(a.qE, b.qE);
  out.qF = Div(a.qF, b.qF);
  out.qG = Div(a.qG, b.qG);
  out.qH = Div(a.qH, b.qH);
  return out;
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