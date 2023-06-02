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
    SquareMatrix(const ICollection<T> &collection, size_t a) : Matrix<T>(collection, a, a) {}
    SquareMatrix(const SquareMatrix<T> &matrix) {
        this->_l = matrix._l;
        this->_h = matrix._h;
        this->values = SequencePtr(new ArraySequence<T>(*matrix.values) );
    }
    SquareMatrix(const Matrix<T> &matrix) {
        if (! (matrix._l == matrix._h )) {
            throw SquareMatrixDimensions();
        }
        this->_l = matrix._l;
        this->_h = matrix._h;
        this->values = SequencePtr(new ArraySequence<T>(*matrix.values) );
    }
    SquareMatrix<T> operator*(const T value) const {
        return SquareMatrix<T>(this->MultScal(value));
    }
};


#endif
