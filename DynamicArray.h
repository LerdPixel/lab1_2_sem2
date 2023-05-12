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
    DynamicArray(const DynamicArray<T> & dynamicArray);
    ~DynamicArray();
    T Get(size_t index);
    size_t GetLength();
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
    this->length = size;
    this->array = new T [size];
}
template <typename T>
DynamicArray<T> :: DynamicArray(T *items, size_t size) {
    this->length = size;
    this->array = new T [size];
    for (size_t i = 0; i < size; ++i) {
        this->array[i] = items[i];
    }
}

template <typename T>
DynamicArray<T> :: ~ DynamicArray() {
    delete [] this->array;
}

template <typename T>
T DynamicArray<T> :: Get(size_t index) {
    if (index < 0 || index >= this->length) {
        throw std::out_of_range("IndexOutOfRange");
    }
    return this->array[index];
}

template <typename T>
void DynamicArray<T> :: Set(int index, T value) {
    if (index < 0 || index >= this->length) {
        throw std::out_of_range("IndexOutOfRange");
    }
    this->array[index] = value;
}

template <typename T>
size_t DynamicArray<T> :: GetLength(); {
    return this->length;
}

template <typename T>
void DynamicArray<T> :: Resize(int newSize); {
    if (newSize < 0) {
        throw std::length_error("Size can't be negative");
    }
    T *array = new T [newSize];
    for (size_t i = 0; i < newSize; i++) {
        /* code */
    }
    ;
}

#endif
