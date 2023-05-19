#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H
#include "DynamicArray.h"
#include "Sequence.h"


template <typename T>
class ArraySequence : public Sequence<T> {
protected:
    DynamicArray<T> *elements;
public:
    ArraySequence() {
        this->elements = new DynamicArray<T>();
    }
    ArraySequence(T* items, size_t count) {
        this->elements = new DynamicArray<T>(items, count);
    }
    ArraySequence(Sequence<T> *sequence) {
        size_t length = sequence->GetLength();
        T array[length];
        for (size_t i = 0; i < length; i++) {
            array[i] = sequence->Get(i);
        }
        this->elements = new DynamicArray<T>(array, length);
    }
    ArraySequence(DynamicArray<T> &dynamicArray) {
        this->elements = new DynamicArray<T>(dynamicArray);
    }
    std::shared_ptr<IEnumerator<T>> GetEnumerator() {
        return elements->GetEnumerator();
    }
    T GetFirst() const override {
        return elements->Get(0);
    }
    T GetLast() const override {
        return elements->Get(elements->GetLength() - 1);
    }
    T Get(size_t index) const override {
        return elements->Get(index);
    }
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override {
        if (startIndex < 0 || startIndex >= this->GetLength() || endIndex < 0 || endIndex >= this->GetLength())
            throw std::out_of_range("IndexOutOfRange");
        if (startIndex > endIndex) {
            size_t t = startIndex;
            startIndex = endIndex;
            endIndex = t;
        }
        DynamicArray<T> dynamicArray = DynamicArray<T>(endIndex - startIndex + 1);
        for (size_t i = startIndex; i <= endIndex; ++i) {
            dynamicArray.Set(i - startIndex, this->elements->Get(i));
        }
        return new ArraySequence<T>(dynamicArray);
    }
    size_t GetLength() const override {
        return this->elements->GetLength();
    }
    void Append(T item) override {
        size_t currentLength = this->elements->GetLength();
        this->elements->Resize(currentLength + 1);
        this->elements->Set(currentLength, item);
    }
    void Prepend(T item) override {
        size_t currentLength = this->elements->GetLength();
        this->elements->Resize(currentLength + 1);
        for (size_t i = currentLength - 1; i >= 0; --i) {
            this->elements->Set(i + 1, this->elements->Get(i));
        }
        this->elements->Set(0, item);
    }
    void Set(size_t index, T item) override {
        elements->Set(index, item);
    }
    T& operator[] (const size_t index) {
        return this->elements[index];
    }
    void InsertAt(T item, size_t index) override {
        if (index < 0 || index > this->elements->GetLength())
            throw std::out_of_range("IndexOutOfRange");
        this->elements->Resize(this->elements->GetLength() + 1);
        for (size_t i = this->elements->GetLength(); i > index; --i) {
            this->elements->Set(i, this->elements->Get(i - 1));
        }
        this->elements->Set(index, item);
    }
    Sequence <T>* Concat(Sequence <T> *sequence) {
        ArraySequence<T> *resSequence = new ArraySequence<T>(*this->elements);
        resSequence->elements->Resize(sequence->GetLength() + this->GetLength());
        for (size_t i = 0; i < sequence->GetLength(); ++i) {
            resSequence->elements->Set(i + GetLength(), sequence->Get(i));
        }
        return resSequence;
    }
/*    Sequence <T2>* map(T2*f(T)) const {
        auto e = new GetEnumerator();
        ArraySequence<T2> *resSequence = new ArraySequence<T2>();
        while (e->next()) {
            resSequence->Append(f(*(*e)));
        }
        delete e;
        return resSequence;
    }*/
};

#endif
