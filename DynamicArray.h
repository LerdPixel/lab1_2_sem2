#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>
//using namespace std;

template <typename T>
class DynamicArray {
protected:
    T *array;
    size_t length;
public:
    DynamicArray();
    DynamicArray(size_t size);
    DynamicArray(T *items, size_t size);
    DynamicArray(const DynamicArray<T> &dynamicArray);
    ~DynamicArray();
    T Get(size_t index) const;
    size_t GetLength() const;
    void Set(int index, T value);
    void Resize(int newSize);
};

template <typename T>
DynamicArray<T> :: DynamicArray() {
    this->length = 0;
    this->array = nullptr;
}
template <typename T>
DynamicArray<T> :: DynamicArray(size_t size) {
    if (size < 0)
        throw std::length_error("Size can't be negative");
    this->length = size;
    this->array = new T [size];
}
template <typename T>
DynamicArray<T> :: DynamicArray(T *items, size_t size) {
    if (size < 0)
        throw std::length_error("Size can't be negative");
    this->length = size;
    this->array = new T [size];
    for (size_t i = 0; i < size; ++i) {
        this->array[i] = items[i];
    }
}
template <typename T>
DynamicArray<T> :: DynamicArray(const DynamicArray<T> &dynamicArray) {
    int length = dynamicArray.GetLength();
    this->array = new T [length];
    for (size_t i = 0; i < length; ++i) {
        this->array[i] = dynamicArray.Get(i);
    }
    this->length = length;
}


template <typename T>
DynamicArray<T> :: ~ DynamicArray() {
    if (array)
        delete [] array;
}

template <typename T>
T DynamicArray<T> :: Get(size_t index) const {
    if (index < 0 || index >= this->length) {
        throw std::out_of_range("IndexOutOfRange");
    }
    return array[index];
}

template <typename T>
void DynamicArray<T> :: Set(int index, T value) {
    if (index < 0 || index >= this->length) {
        throw std::out_of_range("IndexOutOfRange");
    }
    this->array[index] = value;
}

template <typename T>
size_t DynamicArray<T> :: GetLength() const {
    return this->length;
}

template <typename T>
void DynamicArray<T> :: Resize(int newSize) {
    if (newSize < 0)
        throw std::length_error("Size can't be negative");
    T *array = new T [newSize];
    size_t i;
    for (i = 0; i < (newSize < this->length ? newSize : this->length); ++i) {
        array[i] = this->array[i];
    }
    for ( ; i < newSize; ++i) {
        array[i] = 0;
    }
    delete [] this->array;
    this->array = array;
    this->length = newSize;
}

#endif
