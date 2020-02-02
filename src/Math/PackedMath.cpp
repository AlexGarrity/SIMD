#include "Math/PackedMath.hpp"

#include "PackedMath.hpp"

namespace ag {
namespace SIMD {

BQuad4 Add(BQuad4 a, BQuad4 b) {
  BQuad4 out;
  out.a = Add(a.a, b.a);
  out.b = Add(a.b, b.b);
  out.c = Add(a.c, b.c);
  out.d = Add(a.d, b.d);
  return out;
}

BQuad4 Mul(BQuad4 a, BQuad4 b) {
  BQuad4 out;
  out.a = Mul(a.a, b.a);
  out.b = Mul(a.b, b.b);
  out.c = Mul(a.c, b.c);
  out.d = Mul(a.d, b.d);
  return out;
}

BQuad4 Sub(BQuad4 a, BQuad4 b) {
  BQuad4 out;
  out.a = Sub(a.a, b.a);
  out.b = Sub(a.b, b.b);
  out.c = Sub(a.c, b.c);
  out.d = Sub(a.d, b.d);
  return out;
}

BQuad4 Div(BQuad4 a, BQuad4 b) {
  BQuad4 out;
  out.a = Div(a.a, b.a);
  out.b = Div(a.b, b.b);
  out.c = Div(a.c, b.c);
  out.d = Div(a.d, b.d);
  return out;
}

BQuad8 Add(BQuad8 a, BQuad8 b) {
  BQuad8 out;
  out.a = Add(a.a, b.a);
  out.b = Add(a.b, b.b);
  out.c = Add(a.c, b.c);
  out.d = Add(a.d, b.d);
  out.e = Add(a.e, b.e);
  out.f = Add(a.f, b.f);
  out.g = Add(a.g, b.g);
  out.h = Add(a.h, b.h);
  return out;
}

BQuad8 Mul(BQuad8 a, BQuad8 b) {
  BQuad8 out;
  out.a = Mul(a.a, b.a);
  out.b = Mul(a.b, b.b);
  out.c = Mul(a.c, b.c);
  out.d = Mul(a.d, b.d);
  out.e = Mul(a.e, b.e);
  out.f = Mul(a.f, b.f);
  out.g = Mul(a.g, b.g);
  out.h = Mul(a.h, b.h);
  return out;
}

BQuad8 Sub(BQuad8 a, BQuad8 b) {
  BQuad8 out;
  out.a = Sub(a.a, b.a);
  out.b = Sub(a.b, b.b);
  out.c = Sub(a.c, b.c);
  out.d = Sub(a.d, b.d);
  out.e = Sub(a.e, b.e);
  out.f = Sub(a.f, b.f);
  out.g = Sub(a.g, b.g);
  out.h = Sub(a.h, b.h);
  return out;
}

BQuad8 Div(BQuad8 a, BQuad8 b) {
  BQuad8 out;
  out.a = Div(a.a, b.a);
  out.b = Div(a.b, b.b);
  out.c = Div(a.c, b.c);
  out.d = Div(a.d, b.d);
  out.e = Div(a.e, b.e);
  out.f = Div(a.f, b.f);
  out.g = Div(a.g, b.g);
  out.h = Div(a.h, b.h);
  return out;
}

FQuad2 Add(FQuad2 a, FQuad2 b) { return {Add(a.a, b.a), Add(a.b, b.b)}; }

FQuad2 Mul(FQuad2 a, FQuad2 b) { return {Mul(a.a, b.a), Mul(a.b, b.b)}; }

FQuad2 Sub(FQuad2 a, FQuad2 b) { return {Sub(a.a, b.a), Sub(a.b, b.b)}; }

FQuad2 Div(FQuad2 a, FQuad2 b) { return {Div(a.a, b.a), Div(a.b, b.b)}; }

} // namespace SIMD
} // namespace ag