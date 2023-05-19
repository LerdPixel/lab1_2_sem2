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
    std::shared_ptr<IEnumerator<T>> GetEnumerator() {
        return elements->GetEnumerator();
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
    T& operator[] (const size_t index) override {
        return (*elements)[index];
    }
    Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) override {
        LinkedList<T> *list = elements->GetSubList(startIndex, endIndex);
        LinkedListSequence<T> *res = new LinkedListSequence<T>(*list);
        delete list;
        return res;
    }
    size_t GetLength() const override {
        return elements->GetLength();
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
    Sequence <T>* Concat(Sequence <T> *sequence) const override {
        return nullptr;
    }
    /*Sequence <T2>* map(T2*f(T)) const {
        auto e = new GetEnumerator();
        LinkedListSequence<T2> *resSequence = new LinkedListSequence<T2>();
        while (e->next()) {
            resSequence->Append(f(*(*e)));
        }
        delete e;
        return resSequence;
    }
    */
};

#endif
