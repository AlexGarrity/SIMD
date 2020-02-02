#include "Math/Math.hpp"

#include "Math.hpp"
#include "Quad.hpp"

namespace ag {
namespace SIMD {

// No extensions so we'll use regular functions...

// Some templated helpers to save space
template <typename T>
Quad<T> Add(T a1, T a2, T b1, T b2, T c1, T c2, T d1, T d2) {
  return {static_cast<T>(a1 + a2), static_cast<T>(b1 + b2),
          static_cast<T>(c1 + c2), static_cast<T>(d1 + d2)};
}

template <typename T>
Quad<T> Mul(T a1, T a2, T b1, T b2, T c1, T c2, T d1, T d2) {
  return {static_cast<T>(a1 * a2), static_cast<T>(b1 * b2),
          static_cast<T>(c1 * c2), static_cast<T>(d1 * d2)};
}

template <typename T>
Quad<T> Sub(T a1, T a2, T b1, T b2, T c1, T c2, T d1, T d2) {
  return {static_cast<T>(a1 - a2), static_cast<T>(b1 - b2),
          static_cast<T>(c1 - c2), static_cast<T>(d1 - d2)};
}

template <typename T>
Quad<T> Div(T a1, T a2, T b1, T b2, T c1, T c2, T d1, T d2) {
  return {static_cast<T>(a1 / a2), static_cast<T>(b1 / b2),
          static_cast<T>(c1 / c2), static_cast<T>(d1 / d2)};
}

BQuad Add(const BQuad qA, const BQuad qB) {
  return Add<BYTE>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

FQuad Add(const FQuad qA, const FQuad qB) {
  return Add<float>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

DQuad Add(const DQuad qA, const DQuad qB) {
  return Add<double>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

BQuad Mul(const BQuad qA, const BQuad qB) {
  return Mul<BYTE>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

FQuad Mul(const FQuad qA, const FQuad qB) {
  return Mul<float>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

DQuad Mul(const DQuad qA, const DQuad qB) {
  return Mul<double>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

BQuad Sub(const BQuad qA, const BQuad qB) {
  return Sub<BYTE>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

FQuad Sub(const FQuad qA, const FQuad qB) {
  return Sub<float>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

DQuad Sub(const DQuad qA, const DQuad qB) {
  return Sub<double>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

BQuad Div(const BQuad qA, const BQuad qB) {
  return Div<BYTE>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

FQuad Div(const FQuad qA, const FQuad qB) {
  return Div<float>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

DQuad Div(const DQuad qA, const DQuad qB) {
  return Div<double>(qA.a, qB.a, qA.b, qB.b, qA.c, qB.c, qA.d, qB.d);
}

} // namespace SIMD
} // namespace ag