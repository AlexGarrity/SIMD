
#include <agSIMD/Math.hpp>
#include <gtest/gtest.h>

TEST(MATH_TEST_BYTE, ADD_TEST) {
    ag::SIMD::BQuad q1 (1, 2, 4, 8);
    ag::SIMD::BQuad q2 (16, 32, 64, 128);

    auto r = ag::SIMD::Add(q1, q2);

    ASSERT_EQ(q1.a + q2.a, r.a);
    ASSERT_EQ(q1.b + q2.b, r.b);
    ASSERT_EQ(q1.c + q2.c, r.c);
    ASSERT_EQ(q1.d + q2.d, r.d);
}

TEST(MATH_TEST_BYTE, SUB_TEST) {
    ag::SIMD::BQuad q2 (1, 2, 4, 8);
    ag::SIMD::BQuad q1 (16, 32, 64, 128);

    auto r = ag::SIMD::Sub(q1, q2);

    ASSERT_EQ(q1.a - q2.a, r.a);
    ASSERT_EQ(q1.b - q2.b, r.b);
    ASSERT_EQ(q1.c - q2.c, r.c);
    ASSERT_EQ(q1.d - q2.d, r.d);
}

TEST(MATH_TEST_BYTE, MUL_TEST) {
    ag::SIMD::BQuad q1 (8, 4, 2, 1);
    ag::SIMD::BQuad q2 (16, 32, 64, 128);

    auto r = ag::SIMD::Mul(q1, q2);

    ASSERT_EQ(q1.a * q2.a, r.a);
    ASSERT_EQ(q1.b * q2.b, r.b);
    ASSERT_EQ(q1.c * q2.c, r.c);
    ASSERT_EQ(q1.d * q2.d, r.d);
}

TEST(MATH_TEST_BYTE, DIV_TEST) {
    ag::SIMD::BQuad q2 (1, 2, 4, 8);
    ag::SIMD::BQuad q1 (16, 32, 64, 128);

    auto r = ag::SIMD::Div(q1, q2);

    ASSERT_EQ(q1.a / q2.a, r.a);
    ASSERT_EQ(q1.b / q2.b, r.b);
    ASSERT_EQ(q1.c / q2.c, r.c);
    ASSERT_EQ(q1.d / q2.d, r.d);
}


TEST(MATH_TEST_FLOAT, ADD_TEST) {
    ag::SIMD::FQuad q1 (1.0, 2.0, 4.0, 8.0);
    ag::SIMD::FQuad q2 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Add(q1, q2);

    ASSERT_FLOAT_EQ(q1.a + q2.a, r.a);
    ASSERT_FLOAT_EQ(q1.b + q2.b, r.b);
    ASSERT_FLOAT_EQ(q1.c + q2.c, r.c);
    ASSERT_FLOAT_EQ(q1.d + q2.d, r.d);
}

TEST(MATH_TEST_FLOAT, SUB_TEST) {
    ag::SIMD::FQuad q2 (1.0, 2.0, 4.0, 8.0);
    ag::SIMD::FQuad q1 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Sub(q1, q2);

    ASSERT_FLOAT_EQ(q1.a - q2.a, r.a);
    ASSERT_FLOAT_EQ(q1.b - q2.b, r.b);
    ASSERT_FLOAT_EQ(q1.c - q2.c, r.c);
    ASSERT_FLOAT_EQ(q1.d - q2.d, r.d);
}

TEST(MATH_TEST_FLOAT, MUL_TEST) {
    ag::SIMD::FQuad q1 (8.0, 4.0, 2.0, 1.0);
    ag::SIMD::FQuad q2 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Mul(q1, q2);

    ASSERT_FLOAT_EQ(q1.a * q2.a, r.a);
    ASSERT_FLOAT_EQ(q1.b * q2.b, r.b);
    ASSERT_FLOAT_EQ(q1.c * q2.c, r.c);
    ASSERT_FLOAT_EQ(q1.d * q2.d, r.d);
}

TEST(MATH_TEST_FLOAT, DIV_TEST) {
    ag::SIMD::FQuad q2 (1, 2, 4, 8);
    ag::SIMD::FQuad q1 (16, 32, 64, 128);

    auto r = ag::SIMD::Div(q1, q2);

    ASSERT_FLOAT_EQ(q1.a / q2.a, r.a);
    ASSERT_FLOAT_EQ(q1.b / q2.b, r.b);
    ASSERT_FLOAT_EQ(q1.c / q2.c, r.c);
    ASSERT_FLOAT_EQ(q1.d / q2.d, r.d);
}


TEST(MATH_TEST_DOUBLE, ADD_TEST) {
    ag::SIMD::DQuad q1 (1.0, 2.0, 4.0, 8.0);
    ag::SIMD::DQuad q2 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Add(q1, q2);

    ASSERT_DOUBLE_EQ(q1.a + q2.a, r.a);
    ASSERT_DOUBLE_EQ(q1.b + q2.b, r.b);
    ASSERT_DOUBLE_EQ(q1.c + q2.c, r.c);
    ASSERT_DOUBLE_EQ(q1.d + q2.d, r.d);
}

TEST(MATH_TEST_DOUBLE, SUB_TEST) {
    ag::SIMD::DQuad q2 (1.0, 2.0, 4.0, 8.0);
    ag::SIMD::DQuad q1 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Sub(q1, q2);

    ASSERT_DOUBLE_EQ(q1.a - q2.a, r.a);
    ASSERT_DOUBLE_EQ(q1.b - q2.b, r.b);
    ASSERT_DOUBLE_EQ(q1.c - q2.c, r.c);
    ASSERT_DOUBLE_EQ(q1.d - q2.d, r.d);
}

TEST(MATH_TEST_DOUBLE, MUL_TEST) {
    ag::SIMD::BQuad q1 (8.0, 4.0, 2.0, 1.0);
    ag::SIMD::BQuad q2 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Mul(q1, q2);

    ASSERT_DOUBLE_EQ(q1.a * q2.a, r.a);
    ASSERT_DOUBLE_EQ(q1.b * q2.b, r.b);
    ASSERT_DOUBLE_EQ(q1.c * q2.c, r.c);
    ASSERT_DOUBLE_EQ(q1.d * q2.d, r.d);
}

TEST(MATH_TEST_DOUBLE, DIV_TEST) {
    ag::SIMD::DQuad q2 (1.0, 2.0, 4.0, 8.0);
    ag::SIMD::DQuad q1 (16.0, 32.0, 64.0, 128.0);

    auto r = ag::SIMD::Div(q1, q2);

    ASSERT_DOUBLE_EQ(q1.a / q2.a, r.a);
    ASSERT_DOUBLE_EQ(q1.b / q2.b, r.b);
    ASSERT_DOUBLE_EQ(q1.c / q2.c, r.c);
    ASSERT_DOUBLE_EQ(q1.d / q2.d, r.d);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}