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
#include <memory>



TEST(PolynTests, multiplex_5) {
    double e1[] {1, 10, 5};
    double m[] {3,4,5};
    double e3[] {30, 10, -26};
    double f1[] {1, 1, 1};
    double f3[] {1, -2, 1};
    MathVector<double> arr1[] = {MathVector<double>(DynamicArray(e1, 3)), MathVector<double>(DynamicArray(f1, 3))};
    MathVector<double> arr2[] = {MathVector<double>(DynamicArray(e3, 3)), MathVector<double>(DynamicArray(f3, 3))};
    MathVector<double> vm = MathVector<double>(DynamicArray(m, 3));

    Polynomial<MathVector<double>> p1(DynamicArray(arr1, 2));
    std::cout << "/* message */" << '\n';
    Polynomial<MathVector<double>> p2(DynamicArray(arr2, 2));
    ASSERT_TRUE(p1 * vm == p2);
}

TEST(PolynTests, multiplex_4) {
    double e[] {7,-3,1};
    double f[] {0};
    Polynomial<double> p1(DynamicArray(e, 3));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(f, 1));
    ASSERT_TRUE(p1 * 0 == p2);
}
TEST(PolynTests, multiplex_3) {
    double e[] {7,-3,1};
    double f[] {3.5,-1.5,0.5};
    Polynomial<double> p1(DynamicArray(e, 3));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(f, 3));
    ASSERT_TRUE(p1 * 0.5 == p2);
}
TEST(PolynTests, multiplex_2) {
    double b[] {1};
    double e[] {7,-3,1};
    double f[] {21,5,-3,2};
    Polynomial<double> p1(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 4));
    ASSERT_TRUE(p1 * p2 == p2);
}
TEST(PolynTests, multiplex_1) {
    double b[] {0};
    double e[] {7,-3,1};
    double f[] {21,5,-3,2};
    Polynomial<double> p1(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 4));
    ASSERT_TRUE(p1 * p2 == p1);
}
TEST(PolynTests, multiplex) {
    double b[] {3, 2};
    double e[] {7,-3,1};
    double f[] {21,5,-3,2};
    Polynomial<double> p1(DynamicArray(b, 2));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 4));
    ASSERT_TRUE(p1 * p2 == p3);
}
TEST(PolynTests, multiplex0) {
    double b[] {3, 2};
    double e[] {7,-3,1};
    double f[] {21,5,-3,2};
    Polynomial<double> p1(DynamicArray(b, 2));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 4));
    ASSERT_TRUE(p1 * p2 == p2 * p1);
}

TEST(PolynTests, plus_3) {
    double e1[] {1, 10, 5};
    double f1[] {1, 1, 1};
    double e3[] {30, 10, -26};
    double f3[] {1, -2, 1};
    double m1[] {2,11,6};
    double m3[] {31,8,-25};
    MathVector<double> arr1[] = {MathVector<double>(DynamicArray(e1, 3)), MathVector<double>(DynamicArray(e3, 3))};
    MathVector<double> arr2[] = {MathVector<double>(DynamicArray(f1, 3)), MathVector<double>(DynamicArray(f3, 3))};
    MathVector<double> arr3[] = {MathVector<double>(DynamicArray(m1, 3)), MathVector<double>(DynamicArray(m3, 3))};
    Polynomial<MathVector<double>> p1(DynamicArray(arr1, 2));
    Polynomial<MathVector<double>> p2(DynamicArray(arr2, 2));
    Polynomial<MathVector<double>> p3(DynamicArray(arr3, 2));
    ASSERT_TRUE(p1 + p2 == p3);
}

TEST(PolynTests, plus_2) {
    Complex arr1[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1), Complex(0, 1)};
    Complex arr2[] {Complex(0, 1), Complex(1), Complex(1, 5), Complex(-1, 1)};
    Complex arr3[] {Complex(1, 5), Complex(1, 5), Complex(-1, 1), Complex(1, 1)};
    Complex arr4[] {Complex(1, 5), Complex(1, 5), Complex(-1, 1), Complex(1, 1)};
    Complex arrR[] {Complex(1, 3), Complex(-3, 1), Complex(0, -4), Complex(1, 0)};
    Matrix<Complex> arrM1[] = {Matrix<Complex>(DynamicArray(arr1, 4), 2), Matrix<Complex>(DynamicArray(arr3, 4), 2)};
    Matrix<Complex> arrM2[] = {Matrix<Complex>(DynamicArray(arr2, 4), 2), Matrix<Complex>(DynamicArray(arr4, 4), 2)};
    Matrix<Complex> arrMR[] = {Matrix<Complex>(DynamicArray(arrR, 4), 2)};
    Polynomial<Matrix<Complex>> p1 = Polynomial<Matrix<Complex>>(DynamicArray(arrM1, 2));
    Polynomial<Matrix<Complex>> p2 = Polynomial<Matrix<Complex>>(DynamicArray(arrM2, 2));
    Polynomial<Matrix<Complex>> p3 = Polynomial<Matrix<Complex>>(DynamicArray(arrMR, 1));
    ASSERT_TRUE(p1 + (-p2) == p3);
}


TEST(PolynTests, plus_1) {
    Complex arr1[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1)};
    Complex arr2[] {Complex(0, 1), Complex(1)};
    Complex arr3[] {Complex(1, 5), Complex(-1, 1), Complex(1, 1)};
    Polynomial<Complex> p1 = Polynomial<Complex>(DynamicArray(arr1, 3));
    Polynomial<Complex> p2 = Polynomial<Complex>(DynamicArray(arr2, 2));
    Polynomial<Complex> p3 = Polynomial<Complex>(DynamicArray(arr3, 3));
    ASSERT_TRUE(p1 + p2 == p3);
    ASSERT_TRUE(Polynomial<Complex>(DynamicArray(arr1, 3)) + Polynomial<Complex>(DynamicArray(arr2, 2)) == Polynomial<Complex>(DynamicArray(arr3, 3)));
}

TEST(PolynTests, get_Length_Degree_4) {
    double b[] {1};
    double e[] {1, 2, 1, 1, 0, 0};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 6));
    ASSERT_EQ(p2.GetDegree(), 3);
}

TEST(PolynTests, get_Length_Degree_3) {
    double b[] {1};
    double e[] {1, 2, 1, 1, 0, 0};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 6));
    ASSERT_EQ(p1.GetDegree(), 0);
}

TEST(PolynTests, get_Length_Degree_2) {
    double b[] {1};
    double e[] {1, 2, 1, 1, 0, 0};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 6));
    ASSERT_EQ(p2.GetLength(), 4);
}

TEST(PolynTests, get_Length_Degree_1) {
    double b[] {1};
    double e[] {1, 2, 1, 1, 0, 0};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 6));
    ASSERT_EQ(p1.GetLength(), 1);
}
TEST(PolynTests, eq_construct_6) {
    double b[] {2};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 1));
    ASSERT_TRUE(p1 == Polynomial<double>(2));
}
TEST(PolynTests, eq_construct_5) {
    double c[] {1, 0, 0, 1};
    double zero[] {0, 0, 0, 0};
    Matrix<double> arrM1[] {Matrix(DynamicArray<double>(c, 4), 2, 2), Matrix(DynamicArray<double>(zero, 4), 2, 2)};
    Matrix<double> arrM2[1] {Matrix(DynamicArray<double>(c, 4), 2, 2)};
    Matrix<double> m3 = arrM1[0] * 0.0;
    Polynomial<Matrix<double>> p1(DynamicArray<Matrix<double>>(arrM1, 2));
    Polynomial<Matrix<double>> p2(DynamicArray<Matrix<double>>(arrM2, 1));
    ASSERT_TRUE(p2 == p2);
}
TEST(PolynTests, eq_construct_4) {
    double c[] {1, 0, 0, 1};
    double z[] {0, 0, 0, 0};
    Matrix<double> arrM1[] {Matrix(DynamicArray<double>(c, 4), 2), Matrix(DynamicArray<double>(z, 4), 2)};
    Matrix<double> arrM2[] {Matrix(DynamicArray<double>(c, 4), 2)};
    Matrix<double> m3 = arrM1[0] * 0.0;
    Polynomial<Matrix<double>> p1 = Polynomial<Matrix<double>>(DynamicArray(arrM1, 2));
    Polynomial<Matrix<double>> p2 = Polynomial<Matrix<double>>(DynamicArray(arrM2, 1));
    ASSERT_TRUE(true);
}
TEST(PolynTests, eq_construct_3) {
    Complex arr1[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1)};
    Complex arr2[] {Complex(1, 4), Complex(-2, 1), Complex(1, 1),Complex(0, 0)};
    Polynomial<Complex> p1 = Polynomial<Complex>(DynamicArray(arr1, 3));
    Polynomial<Complex> p2 = Polynomial<Complex>(DynamicArray(arr2, 4));
    ASSERT_TRUE(p1 == p2);
}
TEST(PolynTests, eq_construct_2) {
    double b[] {1, 2, 1, 1};
    double e[] {1, 2, 1, 1, 0, 0};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 4));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 6));
    ASSERT_TRUE(p1 == p2);
}
TEST(PolynTests, eq_construct_1) {
    double b[] {1, 2, 1, 1};
    double e[] {1, -2, 1};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 4));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    ASSERT_TRUE(p1 == Polynomial<double>(DynamicArray(b, 4)));
}
TEST(PolynTests, minus1) {
    double e[] {7,-3,1};
    Polynomial<double> p1(DynamicArray(e, 3));
    ASSERT_TRUE(-(-p1) == p1);
}
TEST(PolynTests, minus2) {
    double c[] {1, 0, 0, 1};
    double z[] {0, 0, 0, 0};
    Matrix<double> arrM1[] {Matrix(DynamicArray<double>(z, 4), 2), Matrix(DynamicArray<double>(z, 4), 2)};
    Polynomial<Matrix<double>> p1 = Polynomial<Matrix<double>>(DynamicArray(arrM1, 2));
    ASSERT_TRUE(-p1 == p1);

}
TEST(PolynTests, calculation) {
    double c[] {6, 11, 6, 1};
    Polynomial<double> p1(DynamicArray(c, 4));
    ASSERT_EQ(p1.Calculation(0), 6);
}
TEST(PolynTests, calculation1) {
    double c[] {6, 11, 6, 1};
    Polynomial<double> p1(DynamicArray(c, 4));
    ASSERT_EQ(p1.Calculation(-4), -6);

}
TEST(PolynTests, calculation2) {
    Polynomial<double> p1(0.0);
    ASSERT_EQ(p1.Calculation(-4), 0);
}
TEST(PolynTests, Composition_1) {
    double b[] {-1, 2};
    double e[] {-1, 0, 1};
    double f[] {-3, 0, 2};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 2));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 3));
    ASSERT_TRUE(p1.Composition(p2) == p3);
}
TEST(PolynTests, Composition_2) {
    double b[] {-1,-10, 1, 2};
    double e[] {5, -3, 1};
    double f[] {224, -450, 429, -240, 85, -18, 2};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 4));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 3));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 7));
    ASSERT_TRUE(p1.Composition(p2) == p3);
}
TEST(PolynTests, Composition_3) {
    double b[] {-1, 2};
    double e[] {0};
    double f[] {-1};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 2));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 1));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 1));
    ASSERT_TRUE(p1.Composition(p2) == p3);
}
TEST(PolynTests, Composition_4) {
    double b[] {-1, 2};
    double e[] {1};
    double f[] {1};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 2));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 1));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 1));
    ASSERT_TRUE(p1.Composition(p2) == p2);
}
TEST(PolynTests, Composition_5) {
    double b[] {1};
    double e[] {-1, 2};
    double f[] {1};
    Polynomial<double> p1 = Polynomial<double>(DynamicArray(b, 1));
    Polynomial<double> p2 = Polynomial<double>(DynamicArray(e, 2));
    Polynomial<double> p3 = Polynomial<double>(DynamicArray(f, 1));
    ASSERT_TRUE(p1.Composition(p2) == p1);
}

#endif
