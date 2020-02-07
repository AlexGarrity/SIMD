#pragma once

#include "Core.hpp"

#include <cstdint>

// Quad header provides a bunch of quad classes for use in maths functions
// This serves to reduce the size of the maths implementation files and to
// modularise the quads

namespace ag {
namespace SIMD {

// Forward declare for use in narrowing constructors
template <typename T> struct Quad;

template <typename T> struct Quad2;

template <typename T> struct Quad4;

template <typename T> struct Quad8;

template <typename T> struct AG_API Quad {
  T a, b, c, d;

  Quad() = default;
  Quad(T a, T b, T c, T d) : a{a}, b{b}, c{c}, d{d} {}
  Quad(T v) : a{v}, b{v}, c{v}, d{v} {}

  Quad(Quad2<T> v);
  Quad(Quad4<T> v);
  Quad(Quad8<T> v);

  inline bool operator==(const Quad<T> &other) {
    return (a == other.a & b == other.b & c == other.c & d == other.d);
  }
};

template <typename T> struct AG_API Quad2 {
  Quad<T> qA, qB;

  Quad2() = default;
  Quad2(T v) : qA{v}, qB{v} {}

  Quad2(Quad<T> a, Quad<T> b) : qA{a}, qB{b} {}

  Quad2(Quad4<T> v);
  Quad2(Quad8<T> v);

  inline bool operator==(const Quad2<T> &other) {
    return (qA == other.qA & qB == other.qB);
  }
};

template <typename T> struct AG_API Quad4 {
  Quad<T> qA, qB, qC, qD;

  Quad4() = default;
  Quad4(T v) : qA{v}, qB{v}, qC{v}, qD{v} {}

  Quad4(Quad<T> a, Quad<T> b, Quad<T> c, Quad<T> d)
      : qA{a}, qB{b}, qC{c}, qD{d} {}

  Quad4(Quad2<T> a, Quad2<T> b) : qA{a.qA}, qB{a.qB}, qC{b.qA}, qD{b.qB} {}

  Quad4(Quad8<T> v);

  inline bool operator==(const Quad4<T> &other) {
    return (qA == other.qA & qB == other.qB & qC == other.qC & qD == other.qD);
  }
};

template <typename T> struct AG_API Quad8 {
  Quad<T> qA, qB, qC, qD, qE, qF, qG, qH;

  Quad8() = default;
  Quad8(T v) : qA{v}, qB{v}, qC{v}, qD{v}, qE{v}, qF{v}, qG{v}, qH{v} {}

  Quad8(Quad<T> a, Quad<T> b, Quad<T> c, Quad<T> d, Quad<T> e, Quad<T> f,
        Quad<T> g, Quad<T> h)
      : qA{a}, qB{b}, qC{c}, qD{d}, qE{e}, qF{f}, qG{g}, qH{h} {}

  Quad8(Quad2<T> a, Quad2<T> b, Quad2<T> c, Quad2<T> d)
      : qA{a.qA}, qB{a.qB}, qC{b.qA}, qD{b.qB}, qE{c.qA}, qF{c.qB}, qG{d.qA},
        qH{d.qB} {}

  Quad8(Quad4<T> a, Quad4<T> b)
      : qA{a.qA}, qB{a.qB}, qC{a.qC}, qD{a.qD}, qE{b.qA}, qF{b.qB}, qG{b.qC},
        qH{b.qD} {}
};

// Narrowing constructors
// Quad{8,4,2} to Quad
template <typename T> AG_API Quad<T>::Quad(Quad2<T> v) : Quad(v.qA) {}
template <typename T> AG_API Quad<T>::Quad(Quad4<T> v) : Quad(v.qA) {}
template <typename T> AG_API Quad<T>::Quad(Quad8<T> v) : Quad(v.qA) {}

// Quad{8,4} to Quad2
template <typename T> AG_API Quad2<T>::Quad2(Quad4<T> v) : Quad2(v.qA, v.qB) {}
template <typename T> AG_API Quad2<T>::Quad2(Quad8<T> v) : Quad2(v.qA, v.qB) {}

// Quad8 to Quad4
template <typename T>
AG_API Quad4<T>::Quad4(Quad8<T> v) : Quad4(v.qA, v.qB, v.qC, v.qD) {}

#define BYTE uint8_t
#define SHORT int16_t
#define WORD uint32_t
#define DWORD uint64_t

using BQuad = Quad<BYTE>;
using SQuad = Quad<SHORT>;
using FQuad = Quad<float>;
using DQuad = Quad<double>;

using BQuad2 = Quad2<BYTE>;
using SQuad2 = Quad2<SHORT>;
using FQuad2 = Quad2<float>;

using BQuad4 = Quad4<BYTE>;
using SQuad4 = Quad4<SHORT>;

using BQuad8 = Quad8<BYTE>;

} // namespace SIMD
} // namespace ag