#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H
#include "ArraySequence.h"
#include <memory>

template <class T>
class MathVector {
protected:
    class VectorDimension : public std::exception {
    public:
        const char * what () const noexcept override {
            return "Different MathVector Dimensions";
        }
    };
    typedef std::shared_ptr<Sequence<T>> MVectorPtr;
    class VectorDimension1 : public std::exception {
    public:
        const char * what () const noexcept override {
            return "MathVector Dimensions must be more than 0";
        }
    };
    class VectorDimension3 : public std::exception {
    public:
        const char * what () const noexcept override {
            return "MathVector Dimensions must be 3";
        }
    };
    MVectorPtr values;
public:
    MathVector() {
    }
    MathVector(const ICollection<T> &collection) {
        if (collection.GetLength() == 0)
            throw VectorDimension1();
        values = MVectorPtr(new ArraySequence<T>(collection));
    }
    MathVector(const Sequence<T> &values) {
        if (values.GetLength() == 0)
            throw VectorDimension1();
        this->values = MVectorPtr(new ArraySequence<T>(values));
    }
    MathVector(ICollection<T> *collection) {
        if (collection->GetLength() == 0)
            throw VectorDimension1();
        values = MVectorPtr(new ArraySequence<T>(*collection));
    }
    MathVector(const MathVector<T>& mathvector) {
        values = MVectorPtr(new ArraySequence<T>(*mathvector.values));
    }
    ~MathVector() {}

    size_t GetDimension() const {
        return values->GetLength();
    }
    T Get(size_t index) const {
        if (index < 0 || index >= values->GetLength())
            throw std::out_of_range("IndexOutOfRange");
        return values->Get(index);
    }
    MathVector operator+(const MathVector &rhs) const {
        size_t length = values->GetLength();
        if (length != rhs.values->GetLength()) {
            throw VectorDimension();
        }
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = rhs.values->Get(i) + values->Get(i);
        }
        return MathVector<T>(resValues);
    }
    MathVector operator-() const {
        size_t length = values->GetLength();
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = -values->Get(i);
        }
        return MathVector<T>(resValues);
    }
    T ScalarMult(const MathVector &rhs) const {
        size_t length = values->GetLength();
        if (length != rhs.values->GetLength()) {
            throw VectorDimension();
        }
        T resValue = rhs.values->Get(0) * values->Get(0);
        for (int i = 1; i < length; ++i) {
            resValue += rhs.values->Get(i) * values->Get(i);
        }
        return resValue;
    }
    MathVector MultScal(T value) const {
        size_t length = values->GetLength();
        DynamicArray<T> resValues = DynamicArray<T>(length);
        for (int i = 0; i < length; ++i) {
            resValues[i] = values->Get(i) * value;
        }
        return MathVector<T>(resValues);
    }
    T ModSquar() const {
        size_t length = values->GetLength();
        T resValue = values->Get(0) * values->Get(0);
        for (int i = 1; i < length; ++i) {
            resValue += values->Get(i) * values->Get(i);
        }
        return resValue;
    }
    bool operator==(const MathVector& rhs) const {
        return (*values) == (*rhs.values);
    }
    MathVector operator*(const MathVector &rhs) const {
        if (GetDimension() != 3 || rhs.GetDimension() != 3) {
            throw VectorDimension3();
        }
        T array[] {Get(1) * rhs.Get(2) - Get(2) * rhs.Get(1), - Get(0) * rhs.Get(2) + Get(2) * rhs.Get(0), Get(0) * rhs.Get(1) - Get(1) * rhs.Get(0)};
        return MathVector(DynamicArray(array, 3));
    }
    MathVector operator*(T value) const {
        return MultScal(value);
    }
};

#endif
