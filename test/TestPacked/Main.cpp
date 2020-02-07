
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

// Conversion Tests
TEST(CONVERSION, BQUAD_ADD) {
  auto r = Add(BQuad8(1), BQuad8(0));

  EXPECT_EQ(B(1), r.qA.a);
  EXPECT_EQ(B(1), r.qA.b);
  EXPECT_EQ(B(1), r.qA.c);
  EXPECT_EQ(B(1), r.qA.d);

  EXPECT_EQ(B(1), r.qB.a);
  EXPECT_EQ(B(1), r.qB.b);
  EXPECT_EQ(B(1), r.qB.c);
  EXPECT_EQ(B(1), r.qB.d);

  EXPECT_EQ(B(1), r.qC.a);
  EXPECT_EQ(B(1), r.qC.b);
  EXPECT_EQ(B(1), r.qC.c);
  EXPECT_EQ(B(1), r.qC.d);

  EXPECT_EQ(B(1), r.qD.a);
  EXPECT_EQ(B(1), r.qD.b);
  EXPECT_EQ(B(1), r.qD.c);
  EXPECT_EQ(B(1), r.qD.d);

  EXPECT_EQ(B(1), r.qE.a);
  EXPECT_EQ(B(1), r.qE.b);
  EXPECT_EQ(B(1), r.qE.c);
  EXPECT_EQ(B(1), r.qE.d);

  EXPECT_EQ(B(1), r.qF.a);
  EXPECT_EQ(B(1), r.qF.b);
  EXPECT_EQ(B(1), r.qF.c);
  EXPECT_EQ(B(1), r.qF.d);

  EXPECT_EQ(B(1), r.qG.a);
  EXPECT_EQ(B(1), r.qG.b);
  EXPECT_EQ(B(1), r.qG.c);
  EXPECT_EQ(B(1), r.qG.d);

  EXPECT_EQ(B(1), r.qH.a);
  EXPECT_EQ(B(1), r.qH.b);
  EXPECT_EQ(B(1), r.qH.c);
  EXPECT_EQ(B(1), r.qH.d);

}

TEST(CONVERSION, BQUAD_SUB) {
  BQuad8 r = Sub(BQuad8(1), BQuad8(0));

  EXPECT_EQ(B(1), r.qA.a);
  EXPECT_EQ(B(1), r.qA.b);
  EXPECT_EQ(B(1), r.qA.c);
  EXPECT_EQ(B(1), r.qA.d);

  EXPECT_EQ(B(1), r.qB.a);
  EXPECT_EQ(B(1), r.qB.b);
  EXPECT_EQ(B(1), r.qB.c);
  EXPECT_EQ(B(1), r.qB.d);

  EXPECT_EQ(B(1), r.qC.a);
  EXPECT_EQ(B(1), r.qC.b);
  EXPECT_EQ(B(1), r.qC.c);
  EXPECT_EQ(B(1), r.qC.d);

  EXPECT_EQ(B(1), r.qD.a);
  EXPECT_EQ(B(1), r.qD.b);
  EXPECT_EQ(B(1), r.qD.c);
  EXPECT_EQ(B(1), r.qD.d);

  EXPECT_EQ(B(1), r.qE.a);
  EXPECT_EQ(B(1), r.qE.b);
  EXPECT_EQ(B(1), r.qE.c);
  EXPECT_EQ(B(1), r.qE.d);

  EXPECT_EQ(B(1), r.qF.a);
  EXPECT_EQ(B(1), r.qF.b);
  EXPECT_EQ(B(1), r.qF.c);
  EXPECT_EQ(B(1), r.qF.d);

  EXPECT_EQ(B(1), r.qG.a);
  EXPECT_EQ(B(1), r.qG.b);
  EXPECT_EQ(B(1), r.qG.c);
  EXPECT_EQ(B(1), r.qG.d);

  EXPECT_EQ(B(1), r.qH.a);
  EXPECT_EQ(B(1), r.qH.b);
  EXPECT_EQ(B(1), r.qH.c);
  EXPECT_EQ(B(1), r.qH.d);

}

TEST(CONVERSION, BQUAD_MUL) {
  auto r = Mul(BQuad8(1), BQuad8(1));

  EXPECT_EQ(B(1), r.qA.a);
  EXPECT_EQ(B(1), r.qA.b);
  EXPECT_EQ(B(1), r.qA.c);
  EXPECT_EQ(B(1), r.qA.d);

  EXPECT_EQ(B(1), r.qB.a);
  EXPECT_EQ(B(1), r.qB.b);
  EXPECT_EQ(B(1), r.qB.c);
  EXPECT_EQ(B(1), r.qB.d);

  EXPECT_EQ(B(1), r.qC.a);
  EXPECT_EQ(B(1), r.qC.b);
  EXPECT_EQ(B(1), r.qC.c);
  EXPECT_EQ(B(1), r.qC.d);

  EXPECT_EQ(B(1), r.qD.a);
  EXPECT_EQ(B(1), r.qD.b);
  EXPECT_EQ(B(1), r.qD.c);
  EXPECT_EQ(B(1), r.qD.d);

  EXPECT_EQ(B(1), r.qE.a);
  EXPECT_EQ(B(1), r.qE.b);
  EXPECT_EQ(B(1), r.qE.c);
  EXPECT_EQ(B(1), r.qE.d);

  EXPECT_EQ(B(1), r.qF.a);
  EXPECT_EQ(B(1), r.qF.b);
  EXPECT_EQ(B(1), r.qF.c);
  EXPECT_EQ(B(1), r.qF.d);

  EXPECT_EQ(B(1), r.qG.a);
  EXPECT_EQ(B(1), r.qG.b);
  EXPECT_EQ(B(1), r.qG.c);
  EXPECT_EQ(B(1), r.qG.d);

  EXPECT_EQ(B(1), r.qH.a);
  EXPECT_EQ(B(1), r.qH.b);
  EXPECT_EQ(B(1), r.qH.c);
  EXPECT_EQ(B(1), r.qH.d);

}

TEST(CONVERSION, BQUAD_DIV) {
  auto r = Div(BQuad8(1), BQuad8(1));

  EXPECT_EQ(B(1), r.qA.a);
  EXPECT_EQ(B(1), r.qA.b);
  EXPECT_EQ(B(1), r.qA.c);
  EXPECT_EQ(B(1), r.qA.d);

  EXPECT_EQ(B(1), r.qB.a);
  EXPECT_EQ(B(1), r.qB.b);
  EXPECT_EQ(B(1), r.qB.c);
  EXPECT_EQ(B(1), r.qB.d);

  EXPECT_EQ(B(1), r.qC.a);
  EXPECT_EQ(B(1), r.qC.b);
  EXPECT_EQ(B(1), r.qC.c);
  EXPECT_EQ(B(1), r.qC.d);

  EXPECT_EQ(B(1), r.qD.a);
  EXPECT_EQ(B(1), r.qD.b);
  EXPECT_EQ(B(1), r.qD.c);
  EXPECT_EQ(B(1), r.qD.d);

  EXPECT_EQ(B(1), r.qE.a);
  EXPECT_EQ(B(1), r.qE.b);
  EXPECT_EQ(B(1), r.qE.c);
  EXPECT_EQ(B(1), r.qE.d);

  EXPECT_EQ(B(1), r.qF.a);
  EXPECT_EQ(B(1), r.qF.b);
  EXPECT_EQ(B(1), r.qF.c);
  EXPECT_EQ(B(1), r.qF.d);

  EXPECT_EQ(B(1), r.qG.a);
  EXPECT_EQ(B(1), r.qG.b);
  EXPECT_EQ(B(1), r.qG.c);
  EXPECT_EQ(B(1), r.qG.d);

  EXPECT_EQ(B(1), r.qH.a);
  EXPECT_EQ(B(1), r.qH.b);
  EXPECT_EQ(B(1), r.qH.c);
  EXPECT_EQ(B(1), r.qH.d);

}


// BQuad8 Tests
TEST(T_BYTE, ADD_8) {
  auto r = ag::SIMD::Add(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a + qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qA.b + qb82.qA.b), r.qA.b);
  EXPECT_EQ(B(qb81.qA.c + qb82.qA.c), r.qA.c);
  EXPECT_EQ(B(qb81.qA.d + qb82.qA.d), r.qA.d);

  EXPECT_EQ(B(qb81.qB.a + qb82.qB.a), r.qB.a);
  EXPECT_EQ(B(qb81.qB.b + qb82.qB.b), r.qB.b);
  EXPECT_EQ(B(qb81.qB.c + qb82.qB.c), r.qB.c);
  EXPECT_EQ(B(qb81.qB.d + qb82.qB.d), r.qB.d);

  EXPECT_EQ(B(qb81.qC.a + qb82.qC.a), r.qC.a);
  EXPECT_EQ(B(qb81.qC.b + qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qC.c + qb82.qC.c), r.qC.c);
  EXPECT_EQ(B(qb81.qC.d + qb82.qC.d), r.qC.d);

  EXPECT_EQ(B(qb81.qD.a + qb82.qD.a), r.qD.a);
  EXPECT_EQ(B(qb81.qD.b + qb82.qD.b), r.qD.b);
  EXPECT_EQ(B(qb81.qD.c + qb82.qD.c), r.qD.c);
  EXPECT_EQ(B(qb81.qD.d + qb82.qD.d), r.qD.d);

  EXPECT_EQ(B(qb81.qE.a + qb82.qE.a), r.qE.a);
  EXPECT_EQ(B(qb81.qE.b + qb82.qE.b), r.qE.b);
  EXPECT_EQ(B(qb81.qE.c + qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qE.d + qb82.qE.d), r.qE.d);

  EXPECT_EQ(B(qb81.qF.a + qb82.qF.a), r.qF.a);
  EXPECT_EQ(B(qb81.qF.b + qb82.qF.b), r.qF.b);
  EXPECT_EQ(B(qb81.qF.c + qb82.qF.c), r.qF.c);
  EXPECT_EQ(B(qb81.qF.d + qb82.qF.d), r.qF.d);

  EXPECT_EQ(B(qb81.qG.a + qb82.qG.a), r.qG.a);
  EXPECT_EQ(B(qb81.qG.b + qb82.qG.b), r.qG.b);
  EXPECT_EQ(B(qb81.qG.c + qb82.qG.c), r.qG.c);
  EXPECT_EQ(B(qb81.qG.d + qb82.qG.d), r.qG.d);

  EXPECT_EQ(B(qb81.qH.a + qb82.qH.a), r.qH.a);
  EXPECT_EQ(B(qb81.qH.b + qb82.qH.b), r.qH.b);
  EXPECT_EQ(B(qb81.qH.c + qb82.qH.c), r.qH.c);
  EXPECT_EQ(B(qb81.qH.d + qb82.qH.d), r.qH.d);

}

TEST(T_BYTE, SUB_8) {
  auto r = ag::SIMD::Sub(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a - qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qA.b - qb82.qA.b), r.qA.b);
  EXPECT_EQ(B(qb81.qA.c - qb82.qA.c), r.qA.c);
  EXPECT_EQ(B(qb81.qA.d - qb82.qA.d), r.qA.d);

  EXPECT_EQ(B(qb81.qB.a - qb82.qB.a), r.qB.a);
  EXPECT_EQ(B(qb81.qB.b - qb82.qB.b), r.qB.b);
  EXPECT_EQ(B(qb81.qB.c - qb82.qB.c), r.qB.c);
  EXPECT_EQ(B(qb81.qB.d - qb82.qB.d), r.qB.d);

  EXPECT_EQ(B(qb81.qC.a - qb82.qC.a), r.qC.a);
  EXPECT_EQ(B(qb81.qC.b - qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qC.c - qb82.qC.c), r.qC.c);
  EXPECT_EQ(B(qb81.qC.d - qb82.qC.d), r.qC.d);

  EXPECT_EQ(B(qb81.qD.a - qb82.qD.a), r.qD.a);
  EXPECT_EQ(B(qb81.qD.b - qb82.qD.b), r.qD.b);
  EXPECT_EQ(B(qb81.qD.c - qb82.qD.c), r.qD.c);
  EXPECT_EQ(B(qb81.qD.d - qb82.qD.d), r.qD.d);

  EXPECT_EQ(B(qb81.qE.a - qb82.qE.a), r.qE.a);
  EXPECT_EQ(B(qb81.qE.b - qb82.qE.b), r.qE.b);
  EXPECT_EQ(B(qb81.qE.c - qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qE.d - qb82.qE.d), r.qE.d);

  EXPECT_EQ(B(qb81.qF.a - qb82.qF.a), r.qF.a);
  EXPECT_EQ(B(qb81.qF.b - qb82.qF.b), r.qF.b);
  EXPECT_EQ(B(qb81.qF.c - qb82.qF.c), r.qF.c);
  EXPECT_EQ(B(qb81.qF.d - qb82.qF.d), r.qF.d);

  EXPECT_EQ(B(qb81.qG.a - qb82.qG.a), r.qG.a);
  EXPECT_EQ(B(qb81.qG.b - qb82.qG.b), r.qG.b);
  EXPECT_EQ(B(qb81.qG.c - qb82.qG.c), r.qG.c);
  EXPECT_EQ(B(qb81.qG.d - qb82.qG.d), r.qG.d);

  EXPECT_EQ(B(qb81.qH.a - qb82.qH.a), r.qH.a);
  EXPECT_EQ(B(qb81.qH.b - qb82.qH.b), r.qH.b);
  EXPECT_EQ(B(qb81.qH.c - qb82.qH.c), r.qH.c);
  EXPECT_EQ(B(qb81.qH.d - qb82.qH.d), r.qH.d);

}

TEST(T_BYTE, MUL_8) {
  auto r = ag::SIMD::Mul(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a * qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qA.b * qb82.qA.b), r.qA.b);
  EXPECT_EQ(B(qb81.qA.c * qb82.qA.c), r.qA.c);
  EXPECT_EQ(B(qb81.qA.d * qb82.qA.d), r.qA.d);

  EXPECT_EQ(B(qb81.qB.a * qb82.qB.a), r.qB.a);
  EXPECT_EQ(B(qb81.qB.b * qb82.qB.b), r.qB.b);
  EXPECT_EQ(B(qb81.qB.c * qb82.qB.c), r.qB.c);
  EXPECT_EQ(B(qb81.qB.d * qb82.qB.d), r.qB.d);

  EXPECT_EQ(B(qb81.qC.a * qb82.qC.a), r.qC.a);
  EXPECT_EQ(B(qb81.qC.b * qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qC.c * qb82.qC.c), r.qC.c);
  EXPECT_EQ(B(qb81.qC.d * qb82.qC.d), r.qC.d);

  EXPECT_EQ(B(qb81.qD.a * qb82.qD.a), r.qD.a);
  EXPECT_EQ(B(qb81.qD.b * qb82.qD.b), r.qD.b);
  EXPECT_EQ(B(qb81.qD.c * qb82.qD.c), r.qD.c);
  EXPECT_EQ(B(qb81.qD.d * qb82.qD.d), r.qD.d);

  EXPECT_EQ(B(qb81.qE.a * qb82.qE.a), r.qE.a);
  EXPECT_EQ(B(qb81.qE.b * qb82.qE.b), r.qE.b);
  EXPECT_EQ(B(qb81.qE.c * qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qE.d * qb82.qE.d), r.qE.d);

  EXPECT_EQ(B(qb81.qF.a * qb82.qF.a), r.qF.a);
  EXPECT_EQ(B(qb81.qF.b * qb82.qF.b), r.qF.b);
  EXPECT_EQ(B(qb81.qF.c * qb82.qF.c), r.qF.c);
  EXPECT_EQ(B(qb81.qF.d * qb82.qF.d), r.qF.d);

  EXPECT_EQ(B(qb81.qG.a * qb82.qG.a), r.qG.a);
  EXPECT_EQ(B(qb81.qG.b * qb82.qG.b), r.qG.b);
  EXPECT_EQ(B(qb81.qG.c * qb82.qG.c), r.qG.c);
  EXPECT_EQ(B(qb81.qG.d * qb82.qG.d), r.qG.d);

  EXPECT_EQ(B(qb81.qH.a * qb82.qH.a), r.qH.a);
  EXPECT_EQ(B(qb81.qH.b * qb82.qH.b), r.qH.b);
  EXPECT_EQ(B(qb81.qH.c * qb82.qH.c), r.qH.c);
  EXPECT_EQ(B(qb81.qH.d * qb82.qH.d), r.qH.d);

}

TEST(T_BYTE, DIV_8) {
  auto r = ag::SIMD::Div(qb81, qb82);

  EXPECT_EQ(B(qb81.qA.a / qb82.qA.a), r.qA.a);
  EXPECT_EQ(B(qb81.qA.b / qb82.qA.b), r.qA.b);
  EXPECT_EQ(B(qb81.qA.c / qb82.qA.c), r.qA.c);
  EXPECT_EQ(B(qb81.qA.d / qb82.qA.d), r.qA.d);

  EXPECT_EQ(B(qb81.qB.a / qb82.qB.a), r.qB.a);
  EXPECT_EQ(B(qb81.qB.b / qb82.qB.b), r.qB.b);
  EXPECT_EQ(B(qb81.qB.c / qb82.qB.c), r.qB.c);
  EXPECT_EQ(B(qb81.qB.d / qb82.qB.d), r.qB.d);

  EXPECT_EQ(B(qb81.qC.a / qb82.qC.a), r.qC.a);
  EXPECT_EQ(B(qb81.qC.b / qb82.qC.b), r.qC.b);
  EXPECT_EQ(B(qb81.qC.c / qb82.qC.c), r.qC.c);
  EXPECT_EQ(B(qb81.qC.d / qb82.qC.d), r.qC.d);

  EXPECT_EQ(B(qb81.qD.a / qb82.qD.a), r.qD.a);
  EXPECT_EQ(B(qb81.qD.b / qb82.qD.b), r.qD.b);
  EXPECT_EQ(B(qb81.qD.c / qb82.qD.c), r.qD.c);
  EXPECT_EQ(B(qb81.qD.d / qb82.qD.d), r.qD.d);

  EXPECT_EQ(B(qb81.qE.a / qb82.qE.a), r.qE.a);
  EXPECT_EQ(B(qb81.qE.b / qb82.qE.b), r.qE.b);
  EXPECT_EQ(B(qb81.qE.c / qb82.qE.c), r.qE.c);
  EXPECT_EQ(B(qb81.qE.d / qb82.qE.d), r.qE.d);

  EXPECT_EQ(B(qb81.qF.a / qb82.qF.a), r.qF.a);
  EXPECT_EQ(B(qb81.qF.b / qb82.qF.b), r.qF.b);
  EXPECT_EQ(B(qb81.qF.c / qb82.qF.c), r.qF.c);
  EXPECT_EQ(B(qb81.qF.d / qb82.qF.d), r.qF.d);

  EXPECT_EQ(B(qb81.qG.a / qb82.qG.a), r.qG.a);
  EXPECT_EQ(B(qb81.qG.b / qb82.qG.b), r.qG.b);
  EXPECT_EQ(B(qb81.qG.c / qb82.qG.c), r.qG.c);
  EXPECT_EQ(B(qb81.qG.d / qb82.qG.d), r.qG.d);

  EXPECT_EQ(B(qb81.qH.a / qb82.qH.a), r.qH.a);
  EXPECT_EQ(B(qb81.qH.b / qb82.qH.b), r.qH.b);
  EXPECT_EQ(B(qb81.qH.c / qb82.qH.c), r.qH.c);
  EXPECT_EQ(B(qb81.qH.d / qb82.qH.d), r.qH.d);

}

// BQuad4 Tests
TEST(T_BYTE, ADD_4) {
  auto r = ag::SIMD::Add(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a + qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qA.b + qb42.qA.b), r.qA.b);
  EXPECT_EQ(B(qb41.qA.c + qb42.qA.c), r.qA.c);
  EXPECT_EQ(B(qb41.qA.d + qb42.qA.d), r.qA.d);

  EXPECT_EQ(B(qb41.qB.a + qb42.qB.a), r.qB.a);
  EXPECT_EQ(B(qb41.qB.b + qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qB.c + qb42.qB.c), r.qB.c);
  EXPECT_EQ(B(qb41.qB.d + qb42.qB.d), r.qB.d);

  EXPECT_EQ(B(qb41.qC.a + qb42.qC.a), r.qC.a);
  EXPECT_EQ(B(qb41.qC.b + qb42.qC.b), r.qC.b);
  EXPECT_EQ(B(qb41.qC.c + qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qC.d + qb42.qC.d), r.qC.d);

  EXPECT_EQ(B(qb41.qD.a + qb42.qD.a), r.qD.a);
  EXPECT_EQ(B(qb41.qD.b + qb42.qD.b), r.qD.b);
  EXPECT_EQ(B(qb41.qD.c + qb42.qD.c), r.qD.c);
  EXPECT_EQ(B(qb41.qD.d + qb42.qD.d), r.qD.d);

}

TEST(T_BYTE, SUB_4) {
  auto r = ag::SIMD::Sub(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a - qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qA.b - qb42.qA.b), r.qA.b);
  EXPECT_EQ(B(qb41.qA.c - qb42.qA.c), r.qA.c);
  EXPECT_EQ(B(qb41.qA.d - qb42.qA.d), r.qA.d);

  EXPECT_EQ(B(qb41.qB.a - qb42.qB.a), r.qB.a);
  EXPECT_EQ(B(qb41.qB.b - qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qB.c - qb42.qB.c), r.qB.c);
  EXPECT_EQ(B(qb41.qB.d - qb42.qB.d), r.qB.d);

  EXPECT_EQ(B(qb41.qC.a - qb42.qC.a), r.qC.a);
  EXPECT_EQ(B(qb41.qC.b - qb42.qC.b), r.qC.b);
  EXPECT_EQ(B(qb41.qC.c - qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qC.d - qb42.qC.d), r.qC.d);

  EXPECT_EQ(B(qb41.qD.a - qb42.qD.a), r.qD.a);
  EXPECT_EQ(B(qb41.qD.b - qb42.qD.b), r.qD.b);
  EXPECT_EQ(B(qb41.qD.c - qb42.qD.c), r.qD.c);
  EXPECT_EQ(B(qb41.qD.d - qb42.qD.d), r.qD.d);

}

TEST(T_BYTE, MUL_4) {
  auto r = ag::SIMD::Mul(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a * qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qA.b * qb42.qA.b), r.qA.b);
  EXPECT_EQ(B(qb41.qA.c * qb42.qA.c), r.qA.c);
  EXPECT_EQ(B(qb41.qA.d * qb42.qA.d), r.qA.d);

  EXPECT_EQ(B(qb41.qB.a * qb42.qB.a), r.qB.a);
  EXPECT_EQ(B(qb41.qB.b * qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qB.c * qb42.qB.c), r.qB.c);
  EXPECT_EQ(B(qb41.qB.d * qb42.qB.d), r.qB.d);

  EXPECT_EQ(B(qb41.qC.a * qb42.qC.a), r.qC.a);
  EXPECT_EQ(B(qb41.qC.b * qb42.qC.b), r.qC.b);
  EXPECT_EQ(B(qb41.qC.c * qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qC.d * qb42.qC.d), r.qC.d);

  EXPECT_EQ(B(qb41.qD.a * qb42.qD.a), r.qD.a);
  EXPECT_EQ(B(qb41.qD.b * qb42.qD.b), r.qD.b);
  EXPECT_EQ(B(qb41.qD.c * qb42.qD.c), r.qD.c);
  EXPECT_EQ(B(qb41.qD.d * qb42.qD.d), r.qD.d);

}

TEST(T_BYTE, DIV_4) {
  auto r = ag::SIMD::Div(qb41, qb42);

  EXPECT_EQ(B(qb41.qA.a / qb42.qA.a), r.qA.a);
  EXPECT_EQ(B(qb41.qB.a / qb42.qB.a), r.qB.a);
  EXPECT_EQ(B(qb41.qC.a / qb42.qC.a), r.qC.a);
  EXPECT_EQ(B(qb41.qD.a / qb42.qD.a), r.qD.a);
  EXPECT_EQ(B(qb41.qA.b / qb42.qA.b), r.qA.b);
  EXPECT_EQ(B(qb41.qB.b / qb42.qB.b), r.qB.b);
  EXPECT_EQ(B(qb41.qC.b / qb42.qC.b), r.qC.b);
  EXPECT_EQ(B(qb41.qD.b / qb42.qD.b), r.qD.b);
  EXPECT_EQ(B(qb41.qA.c / qb42.qA.c), r.qA.c);
  EXPECT_EQ(B(qb41.qB.c / qb42.qB.c), r.qB.c);
  EXPECT_EQ(B(qb41.qC.c / qb42.qC.c), r.qC.c);
  EXPECT_EQ(B(qb41.qD.c / qb42.qD.c), r.qD.c);
  EXPECT_EQ(B(qb41.qA.d / qb42.qA.d), r.qA.d);

  EXPECT_EQ(B(qb41.qB.d / qb42.qB.d), r.qB.d);

  EXPECT_EQ(B(qb41.qC.d / qb42.qC.d), r.qC.d);

  EXPECT_EQ(B(qb41.qD.d / qb42.qD.d), r.qD.d);

}

// FQuad2 Tests
TEST(T_FLOAT, ADD_2) {
  auto r = ag::SIMD::Add(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a + qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qA.b + qf22.qA.b, r.qA.b);
  EXPECT_FLOAT_EQ(qf21.qA.c + qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qA.d + qf22.qA.d, r.qA.d);
  EXPECT_FLOAT_EQ(qf21.qB.a + qf22.qB.a, r.qB.a);
  EXPECT_FLOAT_EQ(qf21.qB.b + qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qB.c + qf22.qB.c, r.qB.c);
  EXPECT_FLOAT_EQ(qf21.qB.d + qf22.qB.d, r.qB.d);
}

TEST(T_FLOAT, SUB_2) {
  auto r = ag::SIMD::Sub(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a - qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qA.b - qf22.qA.b, r.qA.b);
  EXPECT_FLOAT_EQ(qf21.qA.c - qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qA.d - qf22.qA.d, r.qA.d);
  EXPECT_FLOAT_EQ(qf21.qB.a - qf22.qB.a, r.qB.a);
  EXPECT_FLOAT_EQ(qf21.qB.b - qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qB.c - qf22.qB.c, r.qB.c);
  EXPECT_FLOAT_EQ(qf21.qB.d - qf22.qB.d, r.qB.d);
}

TEST(T_FLOAT, MUL_2) {
  auto r = ag::SIMD::Mul(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a * qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qA.b * qf22.qA.b, r.qA.b);
  EXPECT_FLOAT_EQ(qf21.qA.c * qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qA.d * qf22.qA.d, r.qA.d);
  EXPECT_FLOAT_EQ(qf21.qB.a * qf22.qB.a, r.qB.a);
  EXPECT_FLOAT_EQ(qf21.qB.b * qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qB.c * qf22.qB.c, r.qB.c);
  EXPECT_FLOAT_EQ(qf21.qB.d * qf22.qB.d, r.qB.d);
}

TEST(T_FLOAT, DIV_2) {
  auto r = ag::SIMD::Div(qf21, qf22);

  EXPECT_FLOAT_EQ(qf21.qA.a / qf22.qA.a, r.qA.a);
  EXPECT_FLOAT_EQ(qf21.qA.b / qf22.qA.b, r.qA.b);
  EXPECT_FLOAT_EQ(qf21.qA.c / qf22.qA.c, r.qA.c);
  EXPECT_FLOAT_EQ(qf21.qA.d / qf22.qA.d, r.qA.d);
  EXPECT_FLOAT_EQ(qf21.qB.a / qf22.qB.a, r.qB.a);
  EXPECT_FLOAT_EQ(qf21.qB.b / qf22.qB.b, r.qB.b);
  EXPECT_FLOAT_EQ(qf21.qB.c / qf22.qB.c, r.qB.c);
  EXPECT_FLOAT_EQ(qf21.qB.d / qf22.qB.d, r.qB.d);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}