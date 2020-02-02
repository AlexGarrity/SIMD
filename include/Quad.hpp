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
};

template <typename T> struct AG_API Quad2 {
  Quad<T> a, b;

  Quad2() = default;
  Quad2(T v) : a{v}, b{v} {}

  Quad2(Quad<T> a, Quad<T> b) : a{a}, b{b} {}

  Quad2(Quad4<T> v);
  Quad2(Quad8<T> v);
};

template <typename T> struct AG_API Quad4 {
  Quad<T> a, b, c, d;

  Quad4() = default;
  Quad4(T v) : a{v}, b{v} {}

  Quad4(Quad<T> a, Quad<T> b, Quad<T> c, Quad<T> d) : a{a}, b{b}, c{c}, d{d} {}

  Quad4(Quad2<T> a, Quad2<T> b) : a{a.a}, b{a.b}, c{b.a}, d{b.b} {}

  Quad4(Quad8<T> v);
};

template <typename T> struct AG_API Quad8 {
  Quad<T> a, b, c, d, e, f, g, h;

  Quad8() = default;
  Quad8(T v) : a{v}, b{v} {}

  Quad8(Quad<T> a, Quad<T> b, Quad<T> c, Quad<T> d, Quad<T> e, Quad<T> f,
        Quad<T> g, Quad<T> h)
      : a{a}, b{b}, c{c}, d{d}, e{e}, f{f}, g{g}, h{h} {}

  Quad8(Quad2<T> a, Quad2<T> b, Quad2<T> c, Quad2<T> d)
      : a{a.a}, b{a.b}, c{b.a}, d{b.b}, e{c.a}, f{c.b}, g{d.a}, h{d.b} {}

  Quad8(Quad4<T> a, Quad4<T> b)
      : a{a.a}, b{a.b}, c{a.c}, d{a.d}, e{b.a}, f{b.b}, g{b.c}, h{b.d} {}
};

// Narrowing constructors
// Quad{8,4,2} to Quad
template <typename T> AG_API Quad<T>::Quad(Quad2<T> v) : Quad(v.a) {}
template <typename T> AG_API Quad<T>::Quad(Quad4<T> v) : Quad(v.a) {}
template <typename T> AG_API Quad<T>::Quad(Quad8<T> v) : Quad(v.a) {}

// Quad{8,4} to Quad2
template <typename T> AG_API Quad2<T>::Quad2(Quad4<T> v) : Quad2(v.a, v.b) {}
template <typename T> AG_API Quad2<T>::Quad2(Quad8<T> v) : Quad2(v.a, v.b) {}

// Quad8 to Quad4
template <typename T>
AG_API Quad4<T>::Quad4(Quad8<T> v) : Quad4(v.a, v.b, v.c, v.d) {}

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