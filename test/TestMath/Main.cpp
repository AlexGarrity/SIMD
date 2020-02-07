
#include <agSIMD/Math.hpp>
#include <gtest/gtest.h>

using namespace ag::SIMD;
using namespace ag::SIMD::internal;

const BQuad qb1{16, 32, 39, 0};
const BQuad qb2{1, 4, 13, 2};

const FQuad qf1(FP(qb1.a), FP(qb1.b), FP(qb1.c), FP(qb1.d));
const FQuad qf2(FP(qb2.a), FP(qb2.b), FP(qb2.c), FP(qb2.d));

const DQuad qd1(FP(qb1.a), FP(qb1.b), FP(qb1.c), FP(qb1.d));
const DQuad qd2(FP(qb2.a), FP(qb2.b), FP(qb2.c), FP(qb2.d));

TEST(T_BYTE, ADD) {
  BQuad r = Add(qb1, qb2);

  EXPECT_EQ((std::clamp(qb1.a + qb2.a, 0, UINT8_MAX)), r.a);
  EXPECT_EQ((std::clamp(qb1.b + qb2.b, 0, UINT8_MAX)), r.b);
  EXPECT_EQ((std::clamp(qb1.c + qb2.c, 0, UINT8_MAX)), r.c);
  EXPECT_EQ((std::clamp(qb1.d + qb2.d, 0, UINT8_MAX)), r.d);
}

TEST(T_BYTE, SUB) {
  // Regular maths may fail this as it doesn't use saturation
  BQuad r = Sub(qb1, qb2);

  EXPECT_EQ(B(std::clamp(qb1.a - qb2.a, 0, UINT8_MAX)), r.a);
  EXPECT_EQ(B(std::clamp(qb1.b - qb2.b, 0, UINT8_MAX)), r.b);
  EXPECT_EQ(B(std::clamp(qb1.c - qb2.c, 0, UINT8_MAX)), r.c);
  EXPECT_EQ(B(std::clamp(qb1.d - qb2.d, 0, UINT8_MAX)), r.d );
}

TEST(T_BYTE, MUL) {
  BQuad r = Mul(qb1, qb2);

  EXPECT_EQ((qb1.a * qb2.a) % 256, r.a); // 64
  EXPECT_EQ((qb1.b * qb2.b) % 256, r.b); // 16
  EXPECT_EQ((qb1.c * qb2.c) % 256, r.c); // 4
  EXPECT_EQ((qb1.d * qb2.d) % 256, r.d); // 1
}

TEST(T_BYTE, DIV) {
  BQuad r = Div(qb1, qb2);

  EXPECT_EQ(B(qb1.a / qb2.a), r.a); // /0
  EXPECT_EQ(B(qb1.b / qb2.b), r.b); // 205
  EXPECT_EQ(B(qb1.c / qb2.c), r.c); // /0
  EXPECT_EQ(B(qb1.d / qb2.d), r.d); // /0
}

TEST(T_FLOAT, ADD) {
  FQuad r = Add(qf1, qf2);

  EXPECT_FLOAT_EQ(qf1.a + qf2.a, r.a);
  EXPECT_FLOAT_EQ(qf1.b + qf2.b, r.b);
  EXPECT_FLOAT_EQ(qf1.c + qf2.c, r.c);
  EXPECT_FLOAT_EQ(qf1.d + qf2.d, r.d);
}

TEST(T_FLOAT, SUB) {
  FQuad r = Sub(qf1, qf2);

  EXPECT_FLOAT_EQ(qf1.a - qf2.a, r.a);
  EXPECT_FLOAT_EQ(qf1.b - qf2.b, r.b);
  EXPECT_FLOAT_EQ(qf1.c - qf2.c, r.c);
  EXPECT_FLOAT_EQ(qf1.d - qf2.d, r.d);
}

TEST(T_FLOAT, MUL) {
  FQuad r = Mul(qf1, qf2);

  EXPECT_FLOAT_EQ(qf1.a * qf2.a, r.a);
  EXPECT_FLOAT_EQ(qf1.b * qf2.b, r.b);
  EXPECT_FLOAT_EQ(qf1.c * qf2.c, r.c);
  EXPECT_FLOAT_EQ(qf1.d * qf2.d, r.d);
}

TEST(T_FLOAT, DIV) {
  FQuad r = Div(qf1, qf2);

  EXPECT_FLOAT_EQ(qf1.a / qf2.a, r.a);
  EXPECT_FLOAT_EQ(qf1.b / qf2.b, r.b);
  EXPECT_FLOAT_EQ(qf1.c / qf2.c, r.c);
  EXPECT_FLOAT_EQ(qf1.d / qf2.d, r.d);
}

TEST(T_DOUBLE, ADD) {
  DQuad r = Add(qd1, qd2);

  EXPECT_DOUBLE_EQ(qd1.a + qd2.a, r.a);
  EXPECT_DOUBLE_EQ(qd1.b + qd2.b, r.b);
  EXPECT_DOUBLE_EQ(qd1.c + qd2.c, r.c);
  EXPECT_DOUBLE_EQ(qd1.d + qd2.d, r.d);
}

TEST(T_DOUBLE, SUB) {
  DQuad r = Sub(qd1, qd2);

  EXPECT_DOUBLE_EQ(qd1.a - qd2.a, r.a);
  EXPECT_DOUBLE_EQ(qd1.b - qd2.b, r.b);
  EXPECT_DOUBLE_EQ(qd1.c - qd2.c, r.c);
  EXPECT_DOUBLE_EQ(qd1.d - qd2.d, r.d);
}

TEST(T_DOUBLE, MUL) {
  DQuad r = Mul(qd1, qd2);

  EXPECT_DOUBLE_EQ(qd1.a * qd2.a, r.a);
  EXPECT_DOUBLE_EQ(qd1.b * qd2.b, r.b);
  EXPECT_DOUBLE_EQ(qd1.c * qd2.c, r.c);
  EXPECT_DOUBLE_EQ(qd1.d * qd2.d, r.d);
}

TEST(T_DOUBLE, DIV) {
  DQuad r = Div(qd1, qd2);

  EXPECT_DOUBLE_EQ(qd1.a / qd2.a, r.a);
  EXPECT_DOUBLE_EQ(qd1.b / qd2.b, r.b);
  EXPECT_DOUBLE_EQ(qd1.c / qd2.c, r.c);
  EXPECT_DOUBLE_EQ(qd1.d / qd2.d, r.d);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
