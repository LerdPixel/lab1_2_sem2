#ifndef MATRIX_H
#define MATRIX_H
#include "MathVector.h"
#include "Complex.h"

template <typename T>
void prtSeq(Sequence<T>* a) {
    for (size_t i = 0; i < a->GetLength(); i++) {
        std::cout << i<<"  " << a->Get(i) << '\n';
    }
}

template <class T>
class Matrix {
protected:
    Sequence<T> *values;
    size_t _l;
    size_t _h;
    class MatrixDimension : public std::exception {
    public:
        const char * what () const noexcept override {
            return "Different matrix dimensions";
        }
    };
    class MatrixDimension1 : public std::exception {
    public:
        const char * what () const noexcept override {
            return "Matrix dimensions must be more than 0";
        }
    };
public:
    Matrix() {
        _l = 0;
        _h = 0;
        values = new ArraySequence<T>();
//        prtSeq(values);
        std::cout<<"Matrix() : " << _l << "  _h = " << _h << '\n';
    }
    Matrix(const Matrix<T> &matrix) {
        values = new ArraySequence<T>(*matrix.values);
        _l = matrix._l;
        _h = matrix._h;
//        prtSeq(values);
        std::cout<<"Matrix(matrix) : " << _l << "  _h = " << _h << '\n';
    }
    Matrix(const ICollection<T> &collection, size_t l, size_t h) {
        if (collection.GetLength() != l * h)
            throw MatrixDimension();
        if (l == 0 || h == 0) { // is able to simplify
            _l = 0;
            _h = 0;
        }
        else {
            _l = l;
            _h = h;
        }
        this->values = new ArraySequence<T>(collection);
//        prtSeq(values);
        std::cout<<"Matrix(collection) : " << _l << "  _h = " << _h << '\n';
    }
    ~Matrix() {
//        prtSeq(values);

        if (values)
            delete values;
    }
    Matrix<T> operator+(const Matrix &rhs) const {
        size_t length = values->GetLength();
        if (length != rhs.values->GetLength() || _l != rhs._l || _h != rhs._h) {
            throw MatrixDimension();
        }
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = rhs.values->Get(i) + values->Get(i);
        }
        return Matrix<T>(resValues, _l, _h);
    }
    Matrix<T> operator-() const {
        size_t length = values->GetLength();
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = -values->Get(i);
        }
        return Matrix<T>(resValues, _l, _h);
    }
    T Get(size_t l, size_t h) const {
        if (l < 0 || l >= _l || h < 0 || h >= _h)
            throw std::out_of_range("IndexOutOfRange");
        return values->Get(l + h * _l);
    }
    void Set(size_t l, size_t h, T value) {
        if (l < 0 || l >= _l || h < 0 || h >= _h)
            throw std::out_of_range("IndexOutOfRange");
        (*values)[l + h * _l] = value;
    }
    MathVector<T> GetHorizontalVector(size_t h) const {
        if (h < 0 || h >= _h)
            throw std::out_of_range("IndexOutOfRange");
        Sequence<T>* resValues = values->GetSubsequence(_l * h, _l * (h + 1));
        MathVector<T> res = MathVector<T>(*resValues);
        delete resValues;
        return res;
    }
    MathVector<T> GetVerticalVector(size_t l) const {
        if (l < 0 || l >= _l)
            throw std::out_of_range("IndexOutOfRange");
        ArraySequence<T> *resValues = new ArraySequence<T>();
        for (int i = 0; i < _h; i++) {
            resValues->Append(Get(l, i));
        }
        MathVector<T> res = MathVector<T>(resValues);
        delete resValues;
        return res;
    }
    Matrix<T> operator*(const Matrix &rhs) const {
        if (_l != rhs._h) {
            throw MatrixDimension();
        }
        DynamicArray<T> resValues = DynamicArray<T>(_h * rhs._l);
        for (int i = 0; i < _h; ++i) {
            for (int j = 0; j < rhs._l; ++j) {
                resValues[j + i * rhs._l] = GetHorizontalVector(i).ScalarMult(rhs.GetVerticalVector(j));
            }
        }
        return Matrix<T>(resValues, rhs._l, _h);
    }
/*    template <typename T2>
    Matrix<T> operator*(const T2 value) const {
        std::cout << "massage !!!" << '\n';
//        std::cout << "value i = " << i << " is = " << values->Get(i) << '\n';
        size_t length = values->GetLength();
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = values->Get(i) * value;
        }
        return Matrix<T>(resValues, _l, _h);
    }
*/

    Matrix<T> MultScal(const T value) const {
        size_t length = values->GetLength();
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = values->Get(i) * value;
        }
        return Matrix<T>(resValues, _l, _h);
    }
    Matrix<T> operator*(const T value) const {
        return MultScal(value);
    }
    Matrix<T> operator*(const MathVector<T> &rhs) const {
        if (_l != rhs.GetDimension())
            throw MatrixDimension();
        DynamicArray<T> resValues = DynamicArray<T>(_h);
        for (int i = 0; i < _h; ++i) {
            resValues[i] = GetHorizontalVector(i).ScalarMult(rhs);
        }
        return Matrix<T>(resValues, 1, _h);
    }

    bool operator==(const Matrix& rhs) const {
        return _l == rhs._l && _h == rhs._h && ( (*values) == (*rhs.values) );
    }
    template <class T1>
    friend Matrix<T1> operator*(T1 value, const Matrix<T1> &rhs);
};

template <class T1>
Matrix<T1> operator*(T1 value, const Matrix<T1> &rhs) {
    return rhs.MultScal(value);
}


#endif
