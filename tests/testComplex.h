#ifndef TEST_COMPLEX_H
#define TEST_COMPLEX_H
#include <gtest/gtest.h>
#include "../Complex.h"
#include <string>
#include <iostream>

struct ComplexTests : public testing::Test {
    int size = 8;
    Complex dc[8];
    void SetUp() {
        dc[0] = Complex(2, 5);
        dc[1] = Complex(2, 5);
        dc[2] = Complex(0, 0);
        dc[3] = Complex();
        dc[4] = Complex(2);
        dc[5] = Complex(2, 0);
        dc[6] = Complex(-1.5, 0.5);
        dc[7] = Complex(1.5, 2.0);
    }
    void TearDown() {
    }
};

TEST_F(ComplexTests, ComplexTests_equal_construct1) {
    ASSERT_TRUE(dc[0] == dc[1]);
}
TEST_F(ComplexTests, ComplexTests_equal_construct2) {
    ASSERT_FALSE(dc[0] == dc[2]);
}
TEST_F(ComplexTests, ComplexTests_equal_construct3) {
    ASSERT_TRUE(dc[2] == dc[3]);
}
TEST_F(ComplexTests, ComplexTests_equal_construct4) {
    ASSERT_TRUE(dc[4] == dc[5]);
}

TEST_F(ComplexTests, ComplexTests_re1) {
    ASSERT_EQ(dc[6].Re(), -1.5);
}
TEST_F(ComplexTests, ComplexTests_re2) {
    ASSERT_EQ(dc[3].Re(), 0);
}
TEST_F(ComplexTests, ComplexTests_im1) {
    ASSERT_EQ(dc[6].Im(), 0.5);
}
TEST_F(ComplexTests, ComplexTests_im2) {
    ASSERT_EQ(dc[3].Im(), 0);
}
TEST_F(ComplexTests, ComplexTests_ModSquar1) {
    ASSERT_TRUE(dc[0].ModSquar() == 29);
}
TEST_F(ComplexTests, ComplexTests_ModSquar2) {
    ASSERT_EQ(dc[7].ModSquar(), 6.25);
}
TEST_F(ComplexTests, ComplexTests_ModSquar3) {
    ASSERT_EQ(dc[2].ModSquar(), 0);
}
TEST_F(ComplexTests, ComplexTests_Mod1) {
    ASSERT_EQ(dc[0].Mod(), std::sqrt(29));
}
TEST_F(ComplexTests, ComplexTests_Mod2) {
    ASSERT_EQ(dc[7].Mod(), 2.5);
}
TEST_F(ComplexTests, ComplexTests_Mod3) {
    ASSERT_EQ(dc[2].Mod(), 0);
}
TEST_F(ComplexTests, ComplexTests_plus1) {
    ASSERT_TRUE(dc[2] + dc[3] == dc[3]);
}
TEST_F(ComplexTests, ComplexTests_plus2) {
    ASSERT_TRUE(dc[0] + dc[0] == Complex(4, 10));
}
TEST_F(ComplexTests, ComplexTests_plus3) {
    ASSERT_TRUE(dc[6] + dc[7] == Complex(0, 2.5));
}
TEST_F(ComplexTests, ComplexTests_plus4) {
    ASSERT_TRUE(dc[6] + dc[5] == dc[5] + dc[6]);
}
TEST_F(ComplexTests, ComplexTests_minus1) {
    ASSERT_TRUE(-dc[4] == -dc[5]);
}
TEST_F(ComplexTests, ComplexTests_minus2) {
    ASSERT_TRUE(-dc[0] == Complex(-2, -5));
}
TEST_F(ComplexTests, ComplexTests_minus3) {
    ASSERT_TRUE(-dc[6] == Complex(1.5, -0.5));
}
TEST_F(ComplexTests, ComplexTests_minus4) {
    ASSERT_TRUE(dc[0] + (-dc[0]) == Complex());
}
TEST_F(ComplexTests, ComplexTests_mult1) {
    ASSERT_TRUE(dc[2] * dc[3] == Complex());
}
TEST_F(ComplexTests, ComplexTests_mult2) {
    ASSERT_TRUE(dc[0] * dc[3] == Complex());
}
TEST_F(ComplexTests, ComplexTests_mult3) {
    ASSERT_TRUE(Complex(1, -1)* Complex(3, 6) == Complex(9, 3));
}
TEST_F(ComplexTests, ComplexTests_mult4) {
    ASSERT_TRUE(Complex(1, -1)* Complex(3, 6) == Complex(9, 3));
}
TEST_F(ComplexTests, ComplexTests_mult5) {
    ASSERT_TRUE(dc[6] * dc[5] == dc[5] * dc[6]);
}
TEST_F(ComplexTests, ComplexTests_mult6) {
    ASSERT_TRUE(Complex(1, -1)* Complex(3, 6) == Complex(9, 3));
}
TEST_F(ComplexTests, ComplexTests_divide1) {
//    Complex t = Complex(3, -1) / Complex(-5, 2);
//    std::cout << t.Re() << "   " << Complex(-17/29, -1/29).Re() << '\n';
    ASSERT_TRUE(Complex(3, -1) / Complex(-5, 2) == Complex(-17.0/29.0, -1.0/29.0));
}
TEST_F(ComplexTests, ComplexTests_divide2) {
    ASSERT_TRUE(Complex(4, 1) / Complex(3, 2) == Complex(14.0/13, -5.0/13));
}
TEST_F(ComplexTests, ComplexTests_divide3) {
    ASSERT_TRUE(dc[3] / dc[0] == dc[3]);
}
TEST_F(ComplexTests, ComplexTests_divide3test) {
    ASSERT_TRUE(dc[0] / dc[0] == Complex(1, 0));
}
TEST_F(ComplexTests, ComplexTests_divide4) {
    std::string str;
    try {
        dc[0] / dc[3];
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "Divide by zero exception");
}
TEST_F(ComplexTests, ComplexTests_divide5) {
    std::string str;
    try {
        dc[3] / dc[3];
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "Divide by zero exception");
}
#endif
