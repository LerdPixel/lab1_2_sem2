#ifndef TEST_POLYNOMIAL_H
#define TEST_POLYNOMIAL_H
#include <gtest/gtest.h>
#include <string>
#include "../ArraySequence.h"
#include "../Complex.h"
#include "../Matrix.h"
#include "../SquareMatrix.h"
#include "../MathVector.h"
#include "../Polynomial.h"

struct PolynTests : public testing::Test {
/*    Polynomial<double> pd0;
    Polynomial<double> pd1;
    Polynomial<double> pd2;
    Polynomial<SquareMatrix<double>> pm1;
    Polynomial<SquareMatrix<double>> pm2;
    Polynomial<Complex> pc0;
    Polynomial<Complex> pc1;
    Polynomial<Complex> pc2;
*/
    void SetUp() {
/*        double b[] {1, 2, 1, 1};
        double a[] {1, 2, 3, 4};
        double c[] {1, 0, 0, 1};
        double d[] {1, 2, 3, 5, 4, 6};
        double e[] {1, -2, 1};
        double f[] {1, 1};
        Complex arr1[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1)};
        Complex arr2[] {Complex(0, 1), Complex(1)};
        Complex arr3[] {Complex(1, 0)};*/
//        SquareMatrix<double> arrM1[] {SquareMatrix<double>(DynamicArray<double>(b, 4), 2), SquareMatrix<double>(DynamicArray<double>(a, 4), 2)};
//        SquareMatrix<double> arrM2[] {SquareMatrix(DynamicArray<double>(c, 4), 2)};
/*        pd0 = Polynomial<double>(DynamicArray(b, 4));
        pd1 = Polynomial<double>(DynamicArray(e, 3));
        pd2 = Polynomial<double>(DynamicArray(f, 2));
//        pm1 = Polynomial<SquareMatrix<double>>(DynamicArray(arrM1, 2));
//        pm2 = Polynomial<SquareMatrix<double>>(DynamicArray(arrM2, 1));
        pc0 = Polynomial<Complex>(DynamicArray(arr3,1));
        pc1 = Polynomial<Complex>(DynamicArray(arr2,2));
        pc2 = Polynomial<Complex>(DynamicArray(arr1,3));
*/    }
    void TearDown() {    }
};

TEST_F(PolynTests, eq_construct_5) {
    double c[] {1, 0, 0, 1};
//    double zero[] {0, 0, 0, 0};
//    Matrix<double> arrM1[] {Matrix(DynamicArray<double>(c, 4), 2, 2), Matrix(DynamicArray<double>(z, 4), 2, 2)};
    Matrix<double> arrM2[1] {Matrix(DynamicArray<double>(c, 4), 2, 2)};
//    Matrix<double> m3 = arrM1[0] * 0.0;
//    Polynomial<Matrix<double>> p1(DynamicArray<Matrix<double>>(arrM1, 2));
    Polynomial<Matrix<double>> p2 = Polynomial<Matrix<double>>(DynamicArray<Matrix<double>>(arrM2, 1));
//    ASSERT_TRUE(p2 == p2);
}
/*TEST_F(PolynTests, eq_construct_4) {
    double c[] {1, 0, 0, 1};
    double z[] {0, 0, 0, 0};
//    SquareMatrix<double> arrM1[] {SquareMatrix(DynamicArray<double>(c, 4), 2), SquareMatrix(DynamicArray<double>(z, 4), 2)};
//    SquareMatrix<double> arrM2[] {SquareMatrix(DynamicArray<double>(c, 4), 2)};
    SquareMatrix<double> m3 = arrM1[0] * 0.0;
    Polynomial<SquareMatrix<double>> p1 = Polynomial<SquareMatrix<double>>(DynamicArray(arrM1, 2));
    Polynomial<SquareMatrix<double>> p2 = Polynomial<SquareMatrix<double>>(DynamicArray(arrM2, 1));
    ASSERT_TRUE(true);
}
TEST_F(PolynTests, eq_construct_3) {
    Complex arr1[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1)};
    Complex arr2[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1),Complex(0, 0)};
    Polynomial<Complex> p1 = Polynomial<Complex>(DynamicArray(arr1, 3));
    Polynomial<Complex> p2 = Polynomial<Complex>(DynamicArray(arr2, 4));
    ASSERT_TRUE(p1 == p2);
}
TEST_F(PolynTests, eq_construct_2) {
    double b[] {1, 2, 1, 1};
    double e[] {1, 2, 1, 1, 0, 0};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 4));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 6));
    ASSERT_TRUE(p1 == p2);
}
TEST_F(PolynTests, eq_construct_1) {
    double b[] {1, 2, 1, 1};
    double e[] {1, -2, 1};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 4));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    ASSERT_TRUE(p1 == Polynomial<double>(DynamicArray(b, 4)));
}
*/
#endif
