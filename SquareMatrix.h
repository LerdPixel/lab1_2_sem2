#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H
#include "Matrix.h"
#include "ArraySequence.h"

template <class T>
class SquareMatrix : public Matrix<T> {
protected:
    class SquareMatrixDimensions : public std::exception {
    public:
        const char * what () const noexcept override {
            return "SquareMatrixDimensionsCantBeDifferent";
        }
    };
public:
    SquareMatrix() : Matrix<T>() {}
    SquareMatrix(const ICollection<T> &collection, size_t a) {
        if (collection.GetLength() != a * a)
            throw SquareMatrixDimensions();
        this->_l = a;
        this->_h = a;
        this->values = new ArraySequence<T>(collection);
    }
    SquareMatrix(const SquareMatrix<T> &matrix) {
        this->_l = matrix._l;
        this->_h = matrix._h;
        this->values = new ArraySequence<T>(matrix.values);
    }
};


#endif
