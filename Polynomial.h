#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "LinkedListSequence.h"

template <class T>
class Polynomial {
protected:
    class PolynomialNotDegree : public std::exception {
    public:
        const char * what () const noexcept override {
            return "PolynomialWithoutDegree";
        }
    };
    Sequence<T> *coefficients;
    Polynomial<T> sumWithSortedDegrees(const Polynomial<T> &rhs) {
        size_t i;
        size_t minDegree = rhs.values->GetLength();
        size_t maxDegree = coefficients->GetLength();
        LinkedListSequence<T> resCoefficients = LinkedListSequence<T>();
        for (i = 0; i < minDegree; ++i) {
            resCoefficients.Append(coefficients->Get(i) + rhs.coefficients->Get(i));
        }
        for (; i < maxDegree; ++i) {
            resCoefficients.Append(coefficients->Get(i));
        }
        return Polynomial(resCoefficients);
    }
    void zeroCutter() {
        int i;
        for (i = coefficients->GetLength() - 1; i > 0; --i) {
            if(! ( coefficients->Get(i) == (coefficients->Get(i) * 0) ) )
                break;
        }
        if (i != coefficients->GetLength() - 1) {
            Sequence<T> *t = coefficients;
            coefficients = coefficients->GetSubsequence(0, i + 1);
            delete t;
        }
    }
public:
    Polynomial(const ICollection<T> &values) {
        if (values.GetLength() == 0)
            throw PolynomialNotDegree();
        coefficients = new LinkedListSequence<T>(values);
//        zeroCutter();
    }
    Polynomial(ICollection<T> *values) {
        if (values->GetLength() == 0)
            throw PolynomialNotDegree();
        coefficients = new LinkedListSequence<T>(*values);
//        zeroCutter();
    }
    Polynomial(const Polynomial<T> &polyn) {
        coefficients = new LinkedListSequence<T>(*polyn.coefficients);
    }
    Polynomial() {
        //throw PolynomialNotDegree();
    }
    Polynomial(T value) {
        T array[] = {value};
        coefficients = new LinkedListSequence<T>(array, 1);
    }
    ~Polynomial() {
        if (coefficients)
            delete coefficients;
    }
    size_t GetLength() const {
        return coefficients->GetLength();
    }
    size_t GetDegree() const {
        return coefficients->GetLength() - 1;
    }
    size_t GetUpdatedDegree() {

        return coefficients->GetLength() - 1;
    }
    Polynomial<T> operator+(const Polynomial<T> &rhs) const {
        Polynomial<T> res;
        if (coefficients->GetLength() >= rhs.coefficients->GetLength()) {
            res = sumWithSortedDegrees(rhs);
        }
        else {
            res = rhs.sumWithSortedDegrees(*this);
        }
        res.zeroCutter();
        return res;
    }
    Polynomial<T> operator*(const Polynomial<T> &polyn2) const {
        int len1 = GetLength(), len2 = polyn2.GetLength();
        int len = len1 + len2 - 1;
        DynamicArray<T> res = DynamicArray<T>(len);
        for (int i = 0; i < len; ++i) {
            res[i] = coefficients->Get(0) * 0;
        }
        for (int i = 0; i < len1; ++i) {
            for (int j = 0; j < len2; ++j) {
                res[i + j] = res[i+j] + coefficients->Get(i) * polyn2.coefficients->Get(j);
            }
        }
        return Polynomial<T>(res);
    }
    Polynomial<T> operator*(T value) const {
        int len = GetLength();
        DynamicArray<T> res = DynamicArray<T>(len);
        for (int i = 0; i < GetLength(); ++i) {
            res[i] = coefficients->Get(i) * value;
        }
        return Polynomial<T>(res);
    }
    T calculation(T value) { // calculated by Horner's method
        T res = value * 0;
        for (int i = GetDegree(); i >= 0; --i) {
            res = res * value + coefficients->Get(i);
        }
        return res;
    }
    Polynomial<T> composition(const Polynomial<T> &polyn2) {
        Polynomial<T> res(coefficients->Get(0) * 0);
        for (int i = GetDegree(); i >= 0; --i) {
            res = res * polyn2 + Polynomial<T>(coefficients->Get(i));
        }
        return res;
    }
    bool operator==(const Polynomial<T> &rhs) {
        return (*coefficients) == (*rhs.coefficients);
    }
};

#endif
