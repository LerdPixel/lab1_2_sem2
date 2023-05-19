#ifndef LINKED_LIST_SEQUENCE_H
#define LINKED_LIST_SEQUENCE_H
#include "LinkedList.h"
#include "Sequence.h"


template <typename T>
class LinkedListSequence : public Sequence<T> {
protected:
    LinkedList<T> *elements;
public:
    LinkedListSequence() {
        this->elements = new LinkedList<T>();
    }
    LinkedListSequence(T* items, size_t count) {
        this->elements = new LinkedList<T>(items, count);
    }
    LinkedListSequence(Sequence<T> *sequence) {
        size_t length = sequence->GetLength();
        this->elements = new LinkedList<T>();
        for (size_t i = 0; i < length; ++i) {
            elements->Append(sequence->Get(i));
        }
    }
    LinkedListSequence(LinkedList<T> &list) {
        this->elements = new LinkedList<T>(list);
    }
    T GetFirst() const override {
        return elements->GetFirst();
    }
    T GetLast() const override {
        return elements->GetLast();
    }
    T Get(size_t index) const override {
        return elements->Get(index);
    }
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override {
        LinkedList<T> *list = elements->GetSubList(startIndex, endIndex);
        LinkedListSequence<T> *res = new LinkedListSequence<T>(*list);
        delete list;
        return res;
    }
    size_t GetLength() override {
        return this->elements->GetLength();
    }
    void Append(T item) override {
        elements->Append(item);
    }
    void Prepend(T item) override {
        elements->Prepend(item);
    }
    void Set(size_t index, T item) override {
        elements->Set(index, item);
    }
/*    T& operator[] (const size_t& index) {
        if (index < 0 || index > this->elements->GetLength())
            throw std::out_of_range("IndexOutOfRange");
        return this->elements->Get(index);
    }*/
    void InsertAt(T item, size_t index) override {
        elements->InsertAt(index, item);
    }
    Sequence <T>* Concat(Sequence <T> *sequence) {
        LinkedList<T> *list = elements->Concat(sequence->elements);
        LinkedListSequence<T> *res = new LinkedListSequence<T>(*list);
        delete list;
        return res;
    }

};

#endif
