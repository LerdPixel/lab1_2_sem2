#ifndef TEST_MATRIX_H
#define TEST_MATRIX_H
#include <gtest/gtest.h>
#include <string>
#include "../ArraySequence.h"
#include "../Complex.h"
#include "../Matrix.h"
#include "../MathVector.h"
struct MatrixTests : public testing::Test {
    int size;
    int msize;
    ArraySequence<double>** dc;
    Matrix<double>** ms;
    void SetUp() {
        size = 5;
        msize = 7;
        double b[] {1, 1, 1, 1};
        double a[] {1, 2, 3, 4, 5, 6};
        double c[] {1, 0, 0, 1};
        double d[] {1, 2, 3, 5, 4, 6};
        dc = new ArraySequence<double>* [size];
        ms = new Matrix<double>* [msize];
        dc[0] = new ArraySequence<double>(a, 6);
        dc[1] = new ArraySequence<double>(b, 4);
        dc[2] = new ArraySequence<double>(c, 4);
        dc[3] = new ArraySequence<double>(d, 6);
        dc[4] = new ArraySequence<double>();
        ms[0] = new Matrix(*dc[0], 2, 3);
        ms[1] = new Matrix(*dc[0], 3, 2);
        ms[2] = new Matrix(*dc[1], 2, 2);
        ms[3] = new Matrix(*dc[2], 2, 2);
        ms[4] = new Matrix(*dc[3], 2, 3);
        ms[5] = new Matrix(*dc[3], 3, 2);
        ms[6] = new Matrix(*dc[4], 0, 0);
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

TEST_F(MatrixTests, MatrixTests_equal_construct_1) {
    double a[] = {1,2,3,4,5,6};
    ASSERT_TRUE(Matrix(DynamicArray(a, 6), 2, 3) == Matrix<double>(DynamicArray<double>(a, 6), 2, 3));
}

TEST_F(MatrixTests, MatrixTests_equal_construct_2) {
    ASSERT_TRUE(*ms[6] == Matrix<double>());
}
TEST_F(MatrixTests, MatrixTests_equal_construct_3) {
    ASSERT_FALSE(*ms[2] == *ms[3]);
}
TEST_F(MatrixTests, MatrixTests_equal_sum_1) {
    double a[] = {1,2,3,4,5,6};
    double b[] = {2,4,6,8,10,12};
    ASSERT_TRUE(Matrix(DynamicArray(a, 6), 2, 3) + (*ms[0]) == Matrix<double>(DynamicArray<double>(b, 6), 2, 3));
}
TEST_F(MatrixTests, MatrixTests_equal_sum_2) {
    double b[] = {2,1,1,2};
    ASSERT_TRUE((*ms[3]) + (*ms[2]) == Matrix<double>(DynamicArray<double>(b, 4), 2, 2));
}
TEST_F(MatrixTests, MatrixTests_equal_sum_3) {
    ASSERT_TRUE((*ms[3]) + (*ms[2]) == (*ms[2]) + (*ms[3]));
}
TEST_F(MatrixTests, MatrixTests_equal_sum_4) {
    std::string str;
    try {
        (*ms[0] + *ms[1]);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "Different matrix dimensions");
}
TEST_F(MatrixTests, MatrixTests_equal_sum_5) {
    std::string str;
    try {
        (*ms[3] + *ms[6]);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "Different matrix dimensions");
}
TEST_F(MatrixTests, MatrixTests_equal_minus_1) {
    double a[] = {0,0,0,-1,1,0};
    ASSERT_TRUE((*ms[0]) + (- *ms[4]) == Matrix<double>(DynamicArray<double>(a, 6), 2, 3));
}
TEST_F(MatrixTests, MatrixTests_equal_minus_2) {
    double a[] = {0,0,0,0,0,0};
    ASSERT_TRUE((*ms[0]) + (- *ms[0]) == Matrix<double>(DynamicArray<double>(a, 6), 2, 3));
}
TEST_F(MatrixTests, MatrixTests_equal_minus_3) {
    double a[] = {-1,0,0,-1};
    ASSERT_TRUE(-(*ms[3]) == Matrix<double>(DynamicArray<double>(a, 4), 2, 2));
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_1) {
    double a[] = {0,1};
    ASSERT_TRUE(ms[3]->GetHorizontalVector(1) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_2) {
    double a[] = {1,0};
    ASSERT_TRUE(ms[3]->GetHorizontalVector(0) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_3) {
    double a[] = {1,2};
    ASSERT_TRUE(ms[0]->GetHorizontalVector(0) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_3_5) {
    double a[] = {1,2,3};
    ASSERT_TRUE(ms[1]->GetHorizontalVector(0) == MathVector<double>(DynamicArray<double>(a, 3)));
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_4) {
    std::string str;
    try {
        ms[0]->GetHorizontalVector(-1);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_5) {
    std::string str;
    try {
        ms[0]->GetHorizontalVector(3);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(MatrixTests, MatrixTests_getHorizontal_6) {
    std::string str;
    try {
        ms[6]->GetHorizontalVector(0);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(MatrixTests, MatrixTests_getVertical_1) {
    double a[] = {0,1};
    ASSERT_TRUE(ms[3]->GetVerticalVector(1) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(MatrixTests, MatrixTests_getVertical_2) {
    double a[] = {1,0};
    ASSERT_TRUE(ms[3]->GetVerticalVector(0) == MathVector<double>(DynamicArray<double>(a, 2)));
}
TEST_F(MatrixTests, MatrixTests_getVertical_3) {
    double a[] = {1,3,5};
    ASSERT_TRUE(ms[0]->GetVerticalVector(0) == MathVector<double>(DynamicArray<double>(a, 3)));
}
TEST_F(MatrixTests, MatrixTests_getVertical_4) {
    std::string str;
    try {
        ms[0]->GetVerticalVector(-1);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(MatrixTests, MatrixTests_getVertical_5) {
    std::string str;
    try {
        ms[0]->GetVerticalVector(2);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(MatrixTests, MatrixTests_getVertical_6) {
    std::string str;
    try {
        ms[6]->GetVerticalVector(0);
    } catch(std::exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(MatrixTests, MatrixTests_multScal_1) {
    double a[] = {2,4,6,8,10,12};
    ASSERT_TRUE(ms[0]->MultScal(2) == Matrix<double>(DynamicArray<double>(a, 6), 2, 3));
}
TEST_F(MatrixTests, MatrixTests_multScal_2) {
    double a[] = {0,0,0,0};
    ASSERT_TRUE(ms[3]->MultScal(0) == Matrix<double>(DynamicArray<double>(a, 4), 2, 2));
}
TEST_F(MatrixTests, MatrixTests_multScal_3) {
    ASSERT_TRUE(ms[6]->MultScal(10) == Matrix<double>());
}
TEST_F(MatrixTests, MatrixTests_multiplication_1) {
    double a[] = {9,12,15,19,26,33,29,40,51};
    ASSERT_TRUE(*ms[0] * (*ms[1]) == Matrix<double>(DynamicArray<double>(a, 9), 3, 3));
}
TEST_F(MatrixTests, MatrixTests_multiplication_2) {
    double a[] = {22,28,49,64};
    ASSERT_TRUE((*ms[1])*(*ms[0]) == Matrix<double>(DynamicArray<double>(a, 4), 2, 2));
}
TEST_F(MatrixTests, MatrixTests_multiplication_3) {
    ASSERT_TRUE((*ms[2]) * (*ms[3]) == *ms[2]);
}
TEST_F(MatrixTests, MatrixTests_multiplication_4) {
    ASSERT_TRUE((*ms[6])*(*ms[6]) == *ms[6]);
}
TEST_F(MatrixTests, MatrixTests_multiplication_vect) {
    double a[] {-1,1};
    double b[] {1,1,1};
    ASSERT_TRUE((*ms[0])* MathVector(DynamicArray(a, 2)) == Matrix(DynamicArray(b, 3), 1, 3));
}
TEST_F(MatrixTests, MatrixTests_multiplication_vect_2) {
    double a[] {-2,1};
    ASSERT_TRUE((*ms[3])* MathVector(DynamicArray(a, 2)) == Matrix<double>(DynamicArray(a, 2), 1, 2));
}
TEST_F(MatrixTests, MatrixTests_multiplication_double_2) {
    double a[] {-1,0,0,-1};
    ASSERT_TRUE((*ms[3])* -1 == Matrix<double>(DynamicArray(a, 4), 2, 2));
}
TEST_F(MatrixTests, MatrixTests_multiplication_double_1) {
    double a[] {-1.5,0,0,-1.5};
    ASSERT_TRUE(-1.5 * (*ms[3]) == Matrix<double>(DynamicArray(a, 4), 2, 2));
}
TEST_F(MatrixTests, MatrixTests_multiplication_double_3) {
    double a[] {0,0,0,0};
    ASSERT_TRUE(((*ms[3]) * 0) == Matrix<double>(DynamicArray(a, 4), 2, 2));
}
#endif
