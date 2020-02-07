
#include <agSIMD/Math.hpp>
#include <gtest/gtest.h>

using namespace ag::SIMD;

const u8Quad qb1{16, 32, 39, 0};
const u8Quad qb2{1, 4, 13, 2};

const FQuad qf1(static_cast<float>(qb1.a), static_cast<float>(qb1.b), static_cast<float>(qb1.c), static_cast<float>(qb1.d));
const FQuad qf2(static_cast<float>(qb2.a), static_cast<float>(qb2.b), static_cast<float>(qb2.c), static_cast<float>(qb2.d));

const DQuad qd1(static_cast<float>(qb1.a), static_cast<float>(qb1.b), static_cast<float>(qb1.c), static_cast<float>(qb1.d));
const DQuad qd2(static_cast<float>(qb2.a), static_cast<float>(qb2.b), static_cast<float>(qb2.c), static_cast<float>(qb2.d));

TEST(T_uint8_t, ADD) {
  u8Quad r = Add(qb1, qb2);

  EXPECT_EQ((std::clamp(qb1.a + qb2.a, 0, UINT8_MAX)), r.a);
  EXPECT_EQ((std::clamp(qb1.b + qb2.b, 0, UINT8_MAX)), r.b);
  EXPECT_EQ((std::clamp(qb1.c + qb2.c, 0, UINT8_MAX)), r.c);
  EXPECT_EQ((std::clamp(qb1.d + qb2.d, 0, UINT8_MAX)), r.d);
}

TEST(T_uint8_t, SUB) {
  // Regular maths may fail this as it doesn't use saturation
  u8Quad r = Sub(qb1, qb2);

  EXPECT_EQ(static_cast<uint8_t>(std::clamp(qb1.a - qb2.a, 0, UINT8_MAX)), r.a);
  EXPECT_EQ(static_cast<uint8_t>(std::clamp(qb1.b - qb2.b, 0, UINT8_MAX)), r.b);
  EXPECT_EQ(static_cast<uint8_t>(std::clamp(qb1.c - qb2.c, 0, UINT8_MAX)), r.c);
  EXPECT_EQ(static_cast<uint8_t>(std::clamp(qb1.d - qb2.d, 0, UINT8_MAX)), r.d );
}

TEST(T_uint8_t, MUL) {
  u8Quad r = Mul(qb1, qb2);

  EXPECT_EQ((qb1.a * qb2.a) % 256, r.a); // 64
  EXPECT_EQ((qb1.b * qb2.b) % 256, r.b); // 16
  EXPECT_EQ((qb1.c * qb2.c) % 256, r.c); // 4
  EXPECT_EQ((qb1.d * qb2.d) % 256, r.d); // 1
}

TEST(T_uint8_t, DIV) {
  u8Quad r = Div(qb1, qb2);

  EXPECT_EQ(static_cast<uint8_t>(qb1.a / qb2.a), r.a); // /0
  EXPECT_EQ(static_cast<uint8_t>(qb1.b / qb2.b), r.b); // 205
  EXPECT_EQ(static_cast<uint8_t>(qb1.c / qb2.c), r.c); // /0
  EXPECT_EQ(static_cast<uint8_t>(qb1.d / qb2.d), r.d); // /0
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
