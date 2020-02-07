
#include <agSIMD/Quad.hpp>
#include <gtest/gtest.h>

using namespace ag::SIMD;

TEST(BQUAD, CREATE_UNIQUE) {
  BQuad a{1, 3, 5, 7};
  EXPECT_EQ(a.a, 1);
  EXPECT_EQ(a.b, 3);
  EXPECT_EQ(a.c, 5);
  EXPECT_EQ(a.d, 7);
}

TEST(BQUAD, CREATE_SAME) {
  BQuad a{1, 1, 1, 1};
  EXPECT_EQ(a.a, 1);
  EXPECT_EQ(a.b, 1);
  EXPECT_EQ(a.c, 1);
  EXPECT_EQ(a.d, 1);
}

TEST(BQUAD, CREATE_QUICK) {
  BQuad a{47};
  EXPECT_EQ(a.a, 47);
  EXPECT_EQ(a.b, 47);
  EXPECT_EQ(a.c, 47);
  EXPECT_EQ(a.d, 47);
}

TEST(BQUAD2, CREATE_UNIQUE) {
  BQuad2 a{BQuad{1, 2, 3, 4}, BQuad{5, 6, 7, 8}};
  EXPECT_EQ(a.qA.a, 1);
  EXPECT_EQ(a.qA.b, 2);
  EXPECT_EQ(a.qA.c, 3);
  EXPECT_EQ(a.qA.d, 4);
  EXPECT_EQ(a.qB.a, 5);
  EXPECT_EQ(a.qB.b, 6);
  EXPECT_EQ(a.qB.c, 7);
  EXPECT_EQ(a.qB.d, 8);
}

TEST(BQUAD2, CREATE_SAME) {
  BQuad2 a{BQuad{1}, BQuad{1}};
  EXPECT_EQ(a.qA.a, 1);
  EXPECT_EQ(a.qA.b, 1);
  EXPECT_EQ(a.qA.c, 1);
  EXPECT_EQ(a.qA.d, 1);
  EXPECT_EQ(a.qB.a, 1);
  EXPECT_EQ(a.qB.b, 1);
  EXPECT_EQ(a.qB.c, 1);
  EXPECT_EQ(a.qB.d, 1);
}

TEST(BQUAD2, CREATE_QUICK) {
  BQuad2 a{47};
  EXPECT_EQ(a.qA.a, 47);
  EXPECT_EQ(a.qA.b, 47);
  EXPECT_EQ(a.qA.c, 47);
  EXPECT_EQ(a.qA.d, 47);
  EXPECT_EQ(a.qB.a, 47);
  EXPECT_EQ(a.qB.b, 47);
  EXPECT_EQ(a.qB.c, 47);
  EXPECT_EQ(a.qB.d, 47);
}

TEST(BQUAD4, CREATE_UNIQUE) {
  BQuad4 a{BQuad{1, 2, 3, 4}, BQuad{5, 6, 7, 8}, BQuad{9, 10, 11, 12}, BQuad{13, 14, 15, 16}};
  EXPECT_EQ(a.qA.a, 1);
  EXPECT_EQ(a.qA.b, 2);
  EXPECT_EQ(a.qA.c, 3);
  EXPECT_EQ(a.qA.d, 4);
  EXPECT_EQ(a.qB.a, 5);
  EXPECT_EQ(a.qB.b, 6);
  EXPECT_EQ(a.qB.c, 7);
  EXPECT_EQ(a.qB.d, 8);
  EXPECT_EQ(a.qC.a, 9);
  EXPECT_EQ(a.qC.b, 10);
  EXPECT_EQ(a.qC.c, 11);
  EXPECT_EQ(a.qC.d, 12);
  EXPECT_EQ(a.qD.a, 13);
  EXPECT_EQ(a.qD.b, 14);
  EXPECT_EQ(a.qD.c, 15);
  EXPECT_EQ(a.qD.d, 16);
}

TEST(BQUAD4, CREATE_SAME) {
  BQuad4 a{BQuad{1}, BQuad{1}, BQuad{1}, BQuad{1}};
  EXPECT_EQ(a.qA.a, 1);
  EXPECT_EQ(a.qA.b, 1);
  EXPECT_EQ(a.qA.c, 1);
  EXPECT_EQ(a.qA.d, 1);
  EXPECT_EQ(a.qB.a, 1);
  EXPECT_EQ(a.qB.b, 1);
  EXPECT_EQ(a.qB.c, 1);
  EXPECT_EQ(a.qB.d, 1);
  EXPECT_EQ(a.qC.a, 1);
  EXPECT_EQ(a.qC.b, 1);
  EXPECT_EQ(a.qC.c, 1);
  EXPECT_EQ(a.qC.d, 1);
  EXPECT_EQ(a.qD.a, 1);
  EXPECT_EQ(a.qD.b, 1);
  EXPECT_EQ(a.qD.c, 1);
  EXPECT_EQ(a.qD.d, 1);
}

TEST(BQUAD4, CREATE_QUICK) {
  BQuad4 a{47};
  EXPECT_EQ(a.qA.a, 47);
  EXPECT_EQ(a.qA.b, 47);
  EXPECT_EQ(a.qA.c, 47);
  EXPECT_EQ(a.qA.d, 47);
  EXPECT_EQ(a.qB.a, 47);
  EXPECT_EQ(a.qB.b, 47);
  EXPECT_EQ(a.qB.c, 47);
  EXPECT_EQ(a.qB.d, 47);
  EXPECT_EQ(a.qC.a, 47);
  EXPECT_EQ(a.qC.b, 47);
  EXPECT_EQ(a.qC.c, 47);
  EXPECT_EQ(a.qC.d, 47);
  EXPECT_EQ(a.qD.a, 47);
  EXPECT_EQ(a.qD.b, 47);
  EXPECT_EQ(a.qD.c, 47);
  EXPECT_EQ(a.qD.d, 47);
}

TEST(FQUAD, CREATE_UNIQUE) {
  FQuad a{1.0f, 3.0f, 5.0f, 7.0f};
  EXPECT_FLOAT_EQ(a.a, 1.0f);
  EXPECT_FLOAT_EQ(a.b, 3.0f);
  EXPECT_FLOAT_EQ(a.c, 5.0f);
  EXPECT_FLOAT_EQ(a.d, 7.0f);
}

TEST(FQUAD, CREATE_SAME) {
  FQuad a{1.0f, 1.0f, 1.0f, 1.0f};
  EXPECT_FLOAT_EQ(a.a, 1.0f);
  EXPECT_FLOAT_EQ(a.b, 1.0f);
  EXPECT_FLOAT_EQ(a.c, 1.0f);
  EXPECT_FLOAT_EQ(a.d, 1.0f);
}

TEST(FQUAD, CREATE_QUICK) {
  FQuad a{47.0f};
  EXPECT_FLOAT_EQ(a.a, 47.0f);
  EXPECT_FLOAT_EQ(a.b, 47.0f);
  EXPECT_FLOAT_EQ(a.c, 47.0f);
  EXPECT_FLOAT_EQ(a.d, 47.0f);
}

TEST(FQUAD2, CREATE_UNIQUE) {
  FQuad2 a{FQuad{1.0f, 2.0f, 3.0f, 4.0f}, FQuad{5.0f, 6.0f, 7.0f, 8.0f}};
  EXPECT_FLOAT_EQ(a.qA.a, 1.0f);
  EXPECT_FLOAT_EQ(a.qA.b, 2.0f);
  EXPECT_FLOAT_EQ(a.qA.c, 3.0f);
  EXPECT_FLOAT_EQ(a.qA.d, 4.0f);
  EXPECT_FLOAT_EQ(a.qB.a, 5.0f);
  EXPECT_FLOAT_EQ(a.qB.b, 6.0f);
  EXPECT_FLOAT_EQ(a.qB.c, 7.0f);
  EXPECT_FLOAT_EQ(a.qB.d, 8.0f);
}

TEST(FQUAD2, CREATE_SAME) {
  FQuad2 a{FQuad{1.0f}, FQuad{1.0f}};
  EXPECT_FLOAT_EQ(a.qA.a, 1.0f);
  EXPECT_FLOAT_EQ(a.qA.b, 1.0f);
  EXPECT_FLOAT_EQ(a.qA.c, 1.0f);
  EXPECT_FLOAT_EQ(a.qA.d, 1.0f);
  EXPECT_FLOAT_EQ(a.qB.a, 1.0f);
  EXPECT_FLOAT_EQ(a.qB.b, 1.0f);
  EXPECT_FLOAT_EQ(a.qB.c, 1.0f);
  EXPECT_FLOAT_EQ(a.qB.d, 1.0f);
}

TEST(FQUAD2, CREATE_QUICK) {
  FQuad2 a{47.0f};
  EXPECT_FLOAT_EQ(a.qA.a, 47.0f);
  EXPECT_FLOAT_EQ(a.qA.b, 47.0f);
  EXPECT_FLOAT_EQ(a.qA.c, 47.0f);
  EXPECT_FLOAT_EQ(a.qA.d, 47.0f);
  EXPECT_FLOAT_EQ(a.qB.a, 47.0f);
  EXPECT_FLOAT_EQ(a.qB.b, 47.0f);
  EXPECT_FLOAT_EQ(a.qB.c, 47.0f);
  EXPECT_FLOAT_EQ(a.qB.d, 47.0f);
}

TEST(DQUAD, CREATE_UNIQUE) {
  FQuad a{1.0, 3.0, 5.0, 7.0};
  EXPECT_DOUBLE_EQ(a.a, 1.0);
  EXPECT_DOUBLE_EQ(a.b, 3.0);
  EXPECT_DOUBLE_EQ(a.c, 5.0);
  EXPECT_DOUBLE_EQ(a.d, 7.0);
}

TEST(DQUAD, CREATE_SAME) {
  FQuad a{1.0, 1.0, 1.0, 1.0};
  EXPECT_DOUBLE_EQ(a.a, 1.0);
  EXPECT_DOUBLE_EQ(a.b, 1.0);
  EXPECT_DOUBLE_EQ(a.c, 1.0);
  EXPECT_DOUBLE_EQ(a.d, 1.0);
}

TEST(DQUAD, CREATE_QUICK) {
  FQuad a{47.0};
  EXPECT_DOUBLE_EQ(a.a, 47.0);
  EXPECT_DOUBLE_EQ(a.b, 47.0);
  EXPECT_DOUBLE_EQ(a.c, 47.0);
  EXPECT_DOUBLE_EQ(a.d, 47.0);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
