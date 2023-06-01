#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H
#include <gtest/gtest.h>
#include <string>
#include "../ArraySequence.h"
#include "../Complex.h"
#include "../SquareMatrix.h"
#include "../MathVector.h"
struct SquareMatrixTests : public testing::Test {
    int size;
    int msize;
    ArraySequence<double>** dc;
    SquareMatrix<double>** ms;
    void SetUp() {
        size = 5;
        msize = 7;
        double b[] {1, 1, 1, 1};
        double a[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
        double c[] {1, 0, 0, 1};
        double d[] {1, 2, 3, 5, 4, 6, 7, 8, 9};
        dc = new ArraySequence<double>* [size];
        ms = new SquareMatrix<double>* [msize];
        dc[0] = new ArraySequence<double>(a, 9);
        dc[1] = new ArraySequence<double>(b, 4);
        dc[2] = new ArraySequence<double>(c, 4);
        dc[3] = new ArraySequence<double>(d, 9);
        dc[4] = new ArraySequence<double>();
        ms[0] = new SquareMatrix(*dc[0], 3);
        ms[1] = new SquareMatrix(*dc[0], 3);
        ms[2] = new SquareMatrix(*dc[1], 2);
        ms[3] = new SquareMatrix(*dc[2], 2);
        ms[4] = new SquareMatrix(*dc[3], 3);
        ms[5] = new SquareMatrix(*dc[3], 3);
        ms[6] = new SquareMatrix(*dc[4], 0);
    }
    void TearDown() {
        for (size_t i = 0; i < size; i++) {
            if (dc[i])
                delete dc[i];
        }
        for (size_t i = 0; i < msize; i++) {
            if (ms[i])
                delete ms[i];
        }
        if (ms)
            delete [] ms;
        delete [] dc;
    }
};
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_construct_0) {
    ASSERT_EQ(0, 0);
}

TEST_F(SquareMatrixTests, SquareMatrixTests_equal_construct_1) {
    double a[] = {1,2,3,4,5,6,7,8,9};
    ASSERT_TRUE(SquareMatrix(DynamicArray(a, 9), 3) == SquareMatrix<double>(DynamicArray<double>(a, 9), 3));
}

TEST_F(SquareMatrixTests, SquareMatrixTests_equal_construct_2) {
    ASSERT_TRUE(*ms[6] == SquareMatrix<double>());
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_construct_3) {
    ASSERT_FALSE(*ms[2] == *ms[3]);
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_sum_1) {
    double b[] = {2,4,6,8,10,12,14,16,18};
    ASSERT_TRUE((*ms[0]) + (*ms[0]) == SquareMatrix<double>(DynamicArray<double>(b, 9), 3));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_sum_2) {
    double b[] = {2,1,1,2};
    ASSERT_TRUE((*ms[3]) + (*ms[2]) == SquareMatrix<double>(DynamicArray<double>(b, 4), 2));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_sum_3) {
    ASSERT_TRUE((*ms[3]) + (*ms[2]) == (*ms[2]) + (*ms[3]));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_sum_4) {
    std::string str;
    try {
        (*ms[0] + *ms[3]);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "Different matrix dimensions");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_sum_5) {
    std::string str;
    try {
        (*ms[3] + *ms[6]);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "Different matrix dimensions");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_minus_2) {
    double a[] = {0,0,0,0,0,0,0,0,0};
    ASSERT_TRUE((*ms[0]) + (- *ms[0]) == SquareMatrix<double>(DynamicArray<double>(a, 9), 3));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_equal_minus_3) {
    double a[] = {-1,0,0,-1};
    ASSERT_TRUE(-(*ms[3]) == SquareMatrix<double>(DynamicArray<double>(a, 4), 2));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_1) {
    double a[] = {0,1};
    ASSERT_TRUE(ms[3]->GetHorizontalVector(1) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_2) {
    double a[] = {1,0};
    ASSERT_TRUE(ms[3]->GetHorizontalVector(0) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_3) {
    double a[] = {1,2,3};
    ASSERT_TRUE(ms[0]->GetHorizontalVector(0) == MathVector<double>(DynamicArray<double>(a, 3)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_3_5) {
    double a[] = {7,8,9};
    ASSERT_TRUE(ms[1]->GetHorizontalVector(2) == MathVector<double>(DynamicArray<double>(a, 3)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_4) {
    std::string str;
    try {
        ms[0]->GetHorizontalVector(-1);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_5) {
    std::string str;
    try {
        ms[0]->GetHorizontalVector(3);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getHorizontal_6) {
    std::string str;
    try {
        ms[6]->GetHorizontalVector(0);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getVertical_1) {
    double a[] = {0,1};
    ASSERT_TRUE(ms[3]->GetVerticalVector(1) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getVertical_2) {
    double a[] = {1,0};
    ASSERT_TRUE(ms[3]->GetVerticalVector(0) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getVertical_3) {
    double a[] = {1,4,7};
    ASSERT_TRUE(ms[0]->GetVerticalVector(0) == MathVector<double>(DynamicArray<double>(a, 3)));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getVertical_4) {
    std::string str;
    try {
        ms[0]->GetVerticalVector(-1);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getVertical_5) {
    std::string str;
    try {
        ms[0]->GetVerticalVector(3);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(SquareMatrixTests, SquareMatrixTests_getVertical_6) {
    std::string str;
    try {
        ms[6]->GetVerticalVector(0);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(SquareMatrixTests, SquareMatrixTests_multScal_2) {
    double a[] = {0,0,0,0};
    ASSERT_TRUE(ms[3]->MultScal(0) == SquareMatrix<double>(DynamicArray<double>(a, 4), 2));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_multScal_3) {
    ASSERT_TRUE(ms[6]->MultScal(10) == SquareMatrix<double>());
}
TEST_F(SquareMatrixTests, SquareMatrixTests_multiplication_3) {
    ASSERT_TRUE( ( (*ms[2]) * (*ms[3]) ) == *ms[2]);
}
TEST_F(SquareMatrixTests, SquareMatrixTests_multiplication_4) {
    ASSERT_TRUE((*ms[6])*(*ms[6]) == *ms[6]);
}
TEST_F(SquareMatrixTests, SquareMatrixTests_multiplication_double_2) {
    double a[] {-1,0,0,-1};
    ASSERT_TRUE((*ms[3])* -1 == SquareMatrix<double>(DynamicArray(a, 4), 2));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_multiplication_double_1) {
    double a[] {-1.5,0,0,-1.5};
    ASSERT_TRUE(-1.5 * (*ms[3]) == SquareMatrix<double>(DynamicArray(a, 4), 2));
}
TEST_F(SquareMatrixTests, SquareMatrixTests_multiplication_Complex_1) {
    Complex a[] {Complex(-1.5, 3),Complex(0,0),Complex(0,3),Complex(-1.5,4)};
    Complex z[] {Complex(0, 0),Complex(0,0),Complex(0, 0),Complex(0, 0)};
    ASSERT_TRUE(SquareMatrix<Complex>(DynamicArray(a, 4), 2) * 0.0 == SquareMatrix<Complex>(DynamicArray<Complex>(z, 4), 2));
}
#endif
