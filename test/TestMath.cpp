
#include "../include/Quad.hpp"
#include "../include/Math.hpp"
#include <gtest/gtest.h>

using namespace ag::SIMD;

TEST(T_BYTE, ADD) {
  BQuad q1(0, 2, 39, 8);
  BQuad q2(16, 32, 64, 128);

  auto r = Add(q1, q2);

  ASSERT_EQ(q1.a + q2.a, r.a);
  ASSERT_EQ(q1.b + q2.b, r.b);
  ASSERT_EQ(q1.c + q2.c, r.c);
  ASSERT_EQ(q1.d + q2.d, r.d);
}

TEST(T_BYTE, SUB) {
  BQuad q1(16, 39, 4, 128);
  BQuad q2(1, 2, 4, 0);

  auto r = Sub(q1, q2);

  ASSERT_EQ(q1.a - q2.a, r.a);
  ASSERT_EQ(q1.b - q2.b, r.b);
  ASSERT_EQ(q1.c - q2.c, r.c);
  ASSERT_EQ(q1.d - q2.d, r.d);
}

TEST(T_BYTE, MUL) {
  BQuad q1(9, 3, 2, 1);
  BQuad q2(1, 2, 4, 8);

  auto r = Mul(q1, q2);


  ASSERT_EQ(q1.a * q2.a, r.a); // 64
  ASSERT_EQ(q1.b * q2.b, r.b); // 16
  ASSERT_EQ(q1.c * q2.c, r.c); // 4
  ASSERT_EQ(q1.d * q2.d, r.d); // 1
}

TEST(T_BYTE, DIV) {
  BQuad q1(16, 32, 64, 128);
  BQuad q2(1, 2, 18, 7);

  auto r = Div(q1, q2);

  ASSERT_EQ(q1.a / q2.a, r.a); // /0
  ASSERT_EQ(q1.b / q2.b, r.b); // 205
  ASSERT_EQ(q1.c / q2.c, r.c); // /0
  ASSERT_EQ(q1.d / q2.d, r.d); // /0
}

TEST(T_FLOAT, ADD) {
  FQuad q1(1.0, 2.0, 4.0, 8.0);
  FQuad q2(16.0, 32.0, 64.0, 128.0);

  auto r = Add(q1, q2);

  ASSERT_FLOAT_EQ(q1.a + q2.a, r.a);
  ASSERT_FLOAT_EQ(q1.b + q2.b, r.b);
  ASSERT_FLOAT_EQ(q1.c + q2.c, r.c);
  ASSERT_FLOAT_EQ(q1.d + q2.d, r.d);
}

TEST(T_FLOAT, SUB) {
  FQuad q2(1.0, 2.0, 4.0, 8.0);
  FQuad q1(16.0, 32.0, 64.0, 128.0);

  auto r = Sub(q1, q2);

  ASSERT_FLOAT_EQ(q1.a - q2.a, r.a);
  ASSERT_FLOAT_EQ(q1.b - q2.b, r.b);
  ASSERT_FLOAT_EQ(q1.c - q2.c, r.c);
  ASSERT_FLOAT_EQ(q1.d - q2.d, r.d);
}

TEST(T_FLOAT, MUL) {
  FQuad q1(8.0, 4.0, 2.0, 1.0);
  FQuad q2(16.0, 32.0, 64.0, 128.0);

  auto r = Mul(q1, q2);

  ASSERT_FLOAT_EQ(q1.a * q2.a, r.a);
  ASSERT_FLOAT_EQ(q1.b * q2.b, r.b);
  ASSERT_FLOAT_EQ(q1.c * q2.c, r.c);
  ASSERT_FLOAT_EQ(q1.d * q2.d, r.d);
}

TEST(T_FLOAT, DIV) {
  FQuad q2(1, 2, 4, 8);
  FQuad q1(16, 32, 64, 128);

  auto r = Div(q1, q2);

  ASSERT_FLOAT_EQ(q1.a / q2.a, r.a);
  ASSERT_FLOAT_EQ(q1.b / q2.b, r.b);
  ASSERT_FLOAT_EQ(q1.c / q2.c, r.c);
  ASSERT_FLOAT_EQ(q1.d / q2.d, r.d);
}

TEST(T_DOUBLE, ADD) {
  DQuad q1(1.0, 2.0, 4.0, 8.0);
  DQuad q2(16.0, 32.0, 64.0, 128.0);

  auto r = Add(q1, q2);

  ASSERT_DOUBLE_EQ(q1.a + q2.a, r.a);
  ASSERT_DOUBLE_EQ(q1.b + q2.b, r.b);
  ASSERT_DOUBLE_EQ(q1.c + q2.c, r.c);
  ASSERT_DOUBLE_EQ(q1.d + q2.d, r.d);
}

TEST(T_DOUBLE, SUB) {
  DQuad q2(1.0, 2.0, 4.0, 8.0);
  DQuad q1(16.0, 32.0, 64.0, 128.0);

  auto r = Sub(q1, q2);

  ASSERT_DOUBLE_EQ(q1.a - q2.a, r.a);
  ASSERT_DOUBLE_EQ(q1.b - q2.b, r.b);
  ASSERT_DOUBLE_EQ(q1.c - q2.c, r.c);
  ASSERT_DOUBLE_EQ(q1.d - q2.d, r.d);
}

TEST(T_DOUBLE, MUL) {
  DQuad q1(8.0, 4.0, 2.0, 1.0);
  DQuad q2(16.0, 32.0, 64.0, 128.0);

  auto r = Mul(q1, q2);

  ASSERT_DOUBLE_EQ(q1.a * q2.a, r.a);
  ASSERT_DOUBLE_EQ(q1.b * q2.b, r.b);
  ASSERT_DOUBLE_EQ(q1.c * q2.c, r.c);
  ASSERT_DOUBLE_EQ(q1.d * q2.d, r.d);
}

TEST(T_DOUBLE, DIV) {
  DQuad q2(1.0, 2.0, 4.0, 8.0);
  DQuad q1(16.0, 32.0, 64.0, 128.0);

  auto r = Div(q1, q2);

  ASSERT_DOUBLE_EQ(q1.a / q2.a, r.a);
  ASSERT_DOUBLE_EQ(q1.b / q2.b, r.b);
  ASSERT_DOUBLE_EQ(q1.c / q2.c, r.c);
  ASSERT_DOUBLE_EQ(q1.d / q2.d, r.d);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}