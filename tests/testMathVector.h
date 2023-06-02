#ifndef TEST_MATH_VECTOR_H
#define TEST_MATH_VECTOR_H
#include <gtest/gtest.h>
#include "../MathVector.h"
#include "../Complex.h"
#include <string>

struct MathVectorTests : public testing::Test {
    int size;
    MathVector<int> **dc;
    Sequence<int>** ac;
    void SetUp() {
        size = 4;
        int a[] {1, 2, 3};
        int d[] {0, 3, 4};
        int e[] {-3, -3, -3};
        int b[] {1};
        ac = new Sequence<int>* [size];
        dc = new MathVector<int>* [size];
        ac[0] = new ArraySequence<int>(a, 3);
        ac[1] = new ArraySequence<int>(d, 3);
        ac[2] = new ArraySequence<int>(e, 3);
        ac[3] = new ArraySequence<int>(b, 1);
        for (int i = 0; i < size; i++) {
            dc[i] = new MathVector<int>(ac[i]);
        }
    }
    void TearDown() {
        for (int i = 0; i < size; i++) {
            if (ac[i])
                delete ac[i];
            if (dc[i])
                delete dc[i];
        }
        delete [] ac;
        delete [] dc;
    }
};
TEST_F(MathVectorTests, MathVectorTests_eq_construct1) {
    int a[] {1,2,3};
    ASSERT_TRUE(MathVector(DynamicArray(a, 3)) == *dc[0]);
}
TEST_F(MathVectorTests, MathVectorTests_eq_construct2) {
    std::string str;
    try {
        MathVector<int>();
    } catch(std::exception& e) {
        str = e.what();
    }
//    ASSERT_STREQ(str.c_str(), "MathVector Dimensions must be more than 0");
}
TEST_F(MathVectorTests, MathVectorTests_eq_construct3) {
    int a[] {1,2,3};
    ASSERT_FALSE(MathVector(DynamicArray(a, 3)) == *dc[2]);
}
TEST_F(MathVectorTests, MathVectorTests_plus_1) {
    int a[] {1,5,7};
    ASSERT_TRUE(MathVector(DynamicArray(a, 3)) == ( (*dc[0])+(*dc[1]) ) );
}
TEST_F(MathVectorTests, MathVectorTests_plus_2) {
    ASSERT_TRUE(( (*dc[1])+(*dc[0]) ) == ( (*dc[0])+(*dc[1]) ) );
}
TEST_F(MathVectorTests, MathVectorTests_plus_3) {
    Complex a[] {Complex(1, -2), Complex(5)};
    Complex b[] {Complex(0, 1), Complex(-3, -2)};
    Complex c[] {Complex(1, -1), Complex(2, -2)};
    ASSERT_TRUE(MathVector(DynamicArray(c, 2)) == MathVector(DynamicArray(a, 2)) + MathVector(DynamicArray(b, 2)) );
}
TEST_F(MathVectorTests, MathVectorTests_minus_3) {
    Complex a[] {Complex(1, -2), Complex(5)};
    Complex c[] {Complex(-1, 2), Complex(-5)};
    ASSERT_TRUE(-MathVector(DynamicArray(c, 2)) == MathVector(DynamicArray(a, 2)));
    ASSERT_TRUE(MathVector(DynamicArray(c, 2)) == -MathVector(DynamicArray(a, 2)));
    ASSERT_TRUE(-(-MathVector(DynamicArray(c, 2))) == MathVector(DynamicArray(c, 2)));
}
TEST_F(MathVectorTests, MathVectorTests_minus_2) {
    int a[] {3,3,3};
    ASSERT_TRUE(MathVector<int>(DynamicArray<int>(a, 3)) == -(*dc[2]));
}
TEST_F(MathVectorTests, MathVectorTests_scalarmult_1) {
    int a[] {6,4,-2};
    ASSERT_EQ(MathVector<int>(DynamicArray<int>(a, 3)).ScalarMult(*dc[0]), 8);
}
TEST_F(MathVectorTests, MathVectorTests_modSquar_1) {
    ASSERT_EQ(dc[0]->ModSquar(), 14);
}
TEST_F(MathVectorTests, MathVectorTests_modSquar_2) {
    ASSERT_EQ(dc[1]->ModSquar(), 25);
}
TEST_F(MathVectorTests, MathVectorTests_modSquar_3) {
    ASSERT_EQ(dc[2]->ModSquar(), 27);
}
TEST_F(MathVectorTests, MathVectorTests_modSquar_4) {
    ASSERT_EQ(dc[3]->ModSquar(), 1);
}

#endif
