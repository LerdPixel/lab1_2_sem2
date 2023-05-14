#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

template <typename T>
class LinkedList {
protected:
    Node<T> *header;
    size_t length;
public:
    LinkedList();
    LinkedList(T *items, size_t size);
    LinkedList (LinkedList <T> & list const);
    ~LinkedList();
    T GetFirst() const;
    T GetLast() const;
    T Get(size_t index const);
    LinkedList<T> *GetSubList(int startIndex, int endIndex) const;
    size_t GetLength() const;
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    void Set(int index, T value);
    LinkedList<T>* Concat(LinkedList<T> *list);
};

template <typename T>
LinkedList :: LinkedList() {
    header = nullptr;
    length = 0;
}
template <typename T>
LinkedList :: LinkedList(T *items, size_t size) {
    if (size < 0)
        throw std::length_error("Size can't be negative");
    length = size;
    if (size == 0) {
        header = nullptr;
    }
    else {
        header = new Node<T>(items[0], nullptr);
        Node<T> *chaneRing = header;
        for (size_t i = 1; i < length; ++i) {
            chaneRing->SetNext(new Node<T>(items[i], nullptr));
            chaneRing = chaneRing->GetNext();
        }
    }
}
LinkedList :: LinkedList(LinkedList <T> & list const) {
    length = list->length;
    header = new Node<T>(list->header);
    Node<T> *chaneRing = header;
    Node<T> *listChaneRing = list->header->GetNext();
        for (size_t i = 1; i < length; i++) {
            chaneRing->SetNext(new Node<T>(listChaneRing, nullptr));
            chaneRing = chaneRing->GetNext();
            listChaneRing = listChaneRing->GetNext();
        }
    }
}
LinkedList :: T GetFirst() const {
    if (length != 0 && header != nullptr) {
        return header->value;
    }
    else {
        throw std::length_error("Size can't be negative");
    }
}
#endif
