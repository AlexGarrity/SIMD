
#include <agSIMD/PackedMath.hpp>
#include <gtest/gtest.h>

using namespace ag::SIMD;
using namespace ag::SIMD::internal;

const BQuad qb1{16, 32, 39, 3};
const BQuad qb2{1, 4, 13, 2};

const BQuad2 qb21{qb1, qb2};
const BQuad2 qb22{qb1, qb1};

const BQuad4 qb41{qb1, qb1, qb2, qb2};
const BQuad4 qb42{qb1, qb2, qb1, qb2};

const BQuad8 qb81{qb41, qb42};
const BQuad8 qb82{qb41, qb41};

const FQuad qf1(FP(qb1.a), FP(qb1.b), FP(qb1.c), FP(qb1.d));
const FQuad qf2(FP(qb2.a), FP(qb2.b), FP(qb2.c), FP(qb2.d));

const FQuad2 qf21{qf1, qf2};
const FQuad2 qf22{qf1, qf1};

// BQuad8 Tests
TEST(T_BYTE, ADD_8) {
  auto r = ag::SIMD::Add(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a + qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qC.b + qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qE.c + qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qG.d + qb82.qG.d), r.qG.d);
}

TEST(T_BYTE, SUB_8) {
  auto r = ag::SIMD::Sub(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a - qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qC.b - qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qE.c - qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qG.d - qb82.qG.d), r.qG.d);
}

TEST(T_BYTE, MUL_8) {
  auto r = ag::SIMD::Mul(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a * qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qC.b * qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qE.c * qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qG.d * qb82.qG.d), r.qG.d);
}

TEST(T_BYTE, DIV_8) {
  auto r = ag::SIMD::Div(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a / qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qC.b / qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qE.c / qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qG.d / qb82.qG.d), r.qG.d);
}

// BQuad4 Tests
TEST(T_BYTE, ADD_4) {
  auto r = ag::SIMD::Add(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a + qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qB.b + qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qC.c + qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qD.d + qb42.qD.d), r.qD.d);
}

TEST(T_BYTE, SUB_4) {
  auto r = ag::SIMD::Sub(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a - qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qB.b - qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qC.c - qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qD.d - qb42.qD.d), r.qD.d);
}

TEST(T_BYTE, MUL_4) {
  auto r = ag::SIMD::Mul(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a * qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qB.b * qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qC.c * qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qD.d * qb42.qD.d), r.qD.d);
}

TEST(T_BYTE, DIV_4) {
  auto r = ag::SIMD::Div(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a / qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qB.b / qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qC.c / qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qD.d / qb42.qD.d), r.qD.d);
}

// FQuad2 Tests
TEST(T_FLOAT, ADD_2) {
  auto r = ag::SIMD::Add(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a + qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qB.b + qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qA.c + qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qB.d + qf22.qB.d, r.qB.d);
}

TEST(T_FLOAT, SUB_2) {
  auto r = ag::SIMD::Sub(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a - qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qB.b - qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qA.c - qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qB.d - qf22.qB.d, r.qB.d);
}

TEST(T_FLOAT, MUL_2) {
  auto r = ag::SIMD::Mul(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a * qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qB.b * qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qA.c * qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qB.d * qf22.qB.d, r.qB.d);
}

TEST(T_FLOAT, DIV_2) {
  auto r = ag::SIMD::Div(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a / qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qB.b / qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qA.c / qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qB.d / qf22.qB.d, r.qB.d);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}