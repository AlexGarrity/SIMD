
#include <agSIMD/Quad.hpp>
#include <gtest/gtest.h>

using namespace ag::SIMD;

TEST(BQUAD, CREATE) {
  BQuad a{1, 3, 5, 7};
  EXPECT_EQ(a.a, 1);
  EXPECT_EQ(a.b, 3);
  EXPECT_EQ(a.c, 5);
  EXPECT_EQ(a.d, 7);

  BQuad b{1, 1, 1, 1};
  EXPECT_TRUE(b.a == b.b && b.b == b.c && b.c == b.d);

  BQuad c{47};
  EXPECT_TRUE(c.a == c.b && c.b == c.c && c.c == c.d);
}

TEST(FQUAD, CREATE) {
  FQuad a{1.0f, 3.0f, 5.0f, 7.0f};
  EXPECT_FLOAT_EQ(a.a, 1.0f);
  EXPECT_FLOAT_EQ(a.b, 3.0f);
  EXPECT_FLOAT_EQ(a.c, 5.0f);
  EXPECT_FLOAT_EQ(a.d, 7.0f);

  FQuad b{1.0f, 1.0f, 1.0f, 1.0f};
  EXPECT_TRUE(b.a == b.b && b.b == b.c && b.c == b.d);

  FQuad c{47.0f};
  EXPECT_TRUE(c.a == c.b && c.b == c.c && c.c == c.d);
}

TEST(DQUAD, CREATE) {
  FQuad a{1.0, 3.0, 5.0, 7.0};
  EXPECT_DOUBLE_EQ(a.a, 1);
  EXPECT_DOUBLE_EQ(a.b, 3);
  EXPECT_DOUBLE_EQ(a.c, 5);
  EXPECT_DOUBLE_EQ(a.d, 7);

  FQuad b{1.0, 1.0, 1.0, 1.0};
  EXPECT_TRUE(b.a == b.b && b.b == b.c && b.c == b.d);

  FQuad c{47.0};
  EXPECT_TRUE(c.a == c.b && c.b == c.c && c.c == c.d);
}

TEST(BQUAD2, CREATE) {
  BQuad2 a{BQuad{1, 2, 3, 4}, BQuad{5, 6, 7, 8}};
  EXPECT_EQ(a.qA.a, 1);
  EXPECT_EQ(a.qA.b, 2);
  EXPECT_EQ(a.qA.c, 3);
  EXPECT_EQ(a.qA.d, 4);
  EXPECT_EQ(a.qB.a, 5);
  EXPECT_EQ(a.qB.b, 6);
  EXPECT_EQ(a.qB.c, 7);
  EXPECT_EQ(a.qB.d, 8);

  BQuad2 b{BQuad{1}, BQuad{1}};
  EXPECT_TRUE(b.qA.a == b.qA.b && b.qA.b == b.qA.c && b.qA.c == b.qA.d &&
              b.qA.d == b.qB.a && b.qB.a == b.qB.b && b.qB.b == b.qB.c &&
              b.qB.c == b.qB.d);

  BQuad2 c{47};
  EXPECT_TRUE(c.qA.a == c.qA.b && c.qA.b == c.qA.c && c.qA.c == c.qA.d &&
              c.qA.d == c.qB.a && c.qB.a == c.qB.b && c.qB.b == c.qB.c &&
              c.qB.c == c.qB.d);
}

TEST(FQUAD2, CREATE) {
  FQuad2 a{FQuad{1.0f, 2.0f, 3.0f, 4.0f}, FQuad{5.0f, 6.0f, 7.0f, 8.0f}};
  EXPECT_FLOAT_EQ(a.qA.a, 1.0f);
  EXPECT_FLOAT_EQ(a.qA.b, 2.0f);
  EXPECT_FLOAT_EQ(a.qA.c, 3.0f);
  EXPECT_FLOAT_EQ(a.qA.d, 4.0f);
  EXPECT_FLOAT_EQ(a.qB.a, 5.0f);
  EXPECT_FLOAT_EQ(a.qB.b, 6.0f);
  EXPECT_FLOAT_EQ(a.qB.c, 7.0f);
  EXPECT_FLOAT_EQ(a.qB.d, 8.0f);

  FQuad2 b{FQuad{1.0f}, FQuad{1.0f}};
  EXPECT_TRUE(b.qA.a == b.qA.b && b.qA.b == b.qA.c && b.qA.c == b.qA.d &&
              b.qA.d == b.qB.a && b.qB.a == b.qB.b && b.qB.b == b.qB.c &&
              b.qB.c == b.qB.d);

  FQuad2 c{47.0f};
  EXPECT_TRUE(c.qA.a == c.qA.b && c.qA.b == c.qA.c && c.qA.c == c.qA.d &&
              c.qA.d == c.qB.a && c.qB.a == c.qB.b && c.qB.b == c.qB.c &&
              c.qB.c == c.qB.d);
}

int main(int argc, char **argv) {
  printf("----------------------------------------\n");
  printf("%s VERSION %s - %s EXTENSIONS\n", LIB_NAME, LIB_VERSION, LIB_EXTENSION);
  printf("----------------------------------------\n\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
