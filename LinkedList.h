#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"

template <typename T>
class LinkedList {
protected:
    Node<T> *header;
    size_t length;
private:
    Node<T>* GetNode(size_t index) const;
public:
    LinkedList();
    LinkedList(T *items, size_t size);
    LinkedList(const LinkedList<T> &list);
    LinkedList(Node<T>* head);
    ~LinkedList();
    T GetFirst() const;
    T GetLast() const;
    T Get(size_t index) const;
    LinkedList<T> *GetSubList(size_t startIndex, size_t endIndex) const;
    size_t GetLength() const;
    void SetLength();
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, size_t index);
    void Set(size_t index, T value);
    LinkedList<T>* Concat(LinkedList<T> *list) const;
};

template <typename T>
LinkedList<T> :: LinkedList() {
    header = nullptr;
    length = 0;
}
template <typename T>
LinkedList<T> :: LinkedList(T *items, size_t size) {
    if (size < 0)
        throw std::length_error("Size can't be negative");
    length = size;
    if (size == 0) {
        header = nullptr;
    }
    else {
        header = new Node<T>(items[0], nullptr);
        Node<T> *nodeRing = header;
        for (size_t i = 1; i < length; ++i) {
            nodeRing->SetNext(new Node<T>(items[i], nullptr));
            nodeRing = nodeRing->GetNext();
        }
    }
}
template <typename T>
LinkedList<T> :: LinkedList(const LinkedList <T> & list) {
    length = list->length;
    header = new Node<T>(list->header);
    Node<T> *nodeRing = header;
    Node<T> *listnodeRing = list->header->GetNext();
    for (size_t i = 1; i < length; i++) {
        nodeRing->SetNext(new Node<T>(listnodeRing, nullptr));
        nodeRing = nodeRing->GetNext();
        listnodeRing = listnodeRing->GetNext();
    }
}
template <typename T>
LinkedList<T> :: LinkedList(Node<T>* head) {
    header = head;
    size_t i = 0;
    while (head != nullptr) {
        ++i;
        head = head->GetNext();
    }
    length = i;
}
template <typename T>
LinkedList<T> :: ~LinkedList() {
    Node<T> *node = header;
    Node<T> *nodeNext;
    while(node != nullptr) {
        nodeNext = node->GetNext();
        delete node;
        node = nodeNext;
    }
}
template <typename T>
T LinkedList<T> :: GetFirst() const {
    if (length != 0 && header != nullptr) {
        return header->value;
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
T LinkedList<T> :: GetLast() const {
    if (length != 0 && header != nullptr) {
        Node<T>* node = header;
        while (node->GetNext() != nullptr) {
            node = node->GetNext();
        }
        return node->GetValue();
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
T LinkedList<T> :: Get(size_t index) const {
/*    if (index < length && index >= 0 && header != nullptr) {
        Node<T>* node = header;
        for (size_t i = 0; i < index; i++) {
            node = node->GetNext();
        }
        return node->GetValue();
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }*/
    return GetNode(index)->GetValue();
}
template <typename T>
Node<T>* LinkedList<T> :: GetNode(size_t index) const {
    if (index < length && index >= 0 && header != nullptr) {
        Node<T>* node = header;
        for (size_t i = 0; i < index; i++) {
            node = node->GetNext();
        }
        return node;
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
size_t LinkedList<T> :: GetLength() const {
    return length;
}
template <typename T>
void LinkedList<T> :: SetLength() {
    Node<T>* node = header;
    size_t i = 0;
    while (node != nullptr) {
        ++i;
        node = node->GetNext();
    }
    length = i;
}
template <typename T>
void LinkedList<T> :: Append(T item) {
    Node<T>* node = header;
    while (node != nullptr) {
        node = node->GetNext();
    }
    node = new Node<T>(item, nullptr);
    SetLength();
}
template <typename T>
void LinkedList<T> :: Prepend(T item) {
    Node<T>* node = header;
    header = new Node<T>(item, node);
    SetLength();
}
template <typename T>
void LinkedList<T> :: Set(size_t index, T value) {
    if (index < length && index >= 0 && header != nullptr) {
        Node<T>* node = header;
        for (size_t i = 0; i < index; i++) {
            node = node->GetNext();
        }
        node->SetValue(value);
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
LinkedList<T> * LinkedList<T> :: GetSubList(size_t startIndex, size_t endIndex) const {
    if (startIndex < length && startIndex >= 0 && endIndex < length && endIndex >= 0 && header != nullptr) {
        if (startIndex > endIndex) {
            size_t t = startIndex;
            startIndex = endIndex;
            endIndex = t;
        }
        Node<T>* node = GetNode(startIndex);
        Node<T>* newHeader = new Node<T>(node);
        Node<T>* newNode = newHeader;
        for (size_t i = startIndex; i <= endIndex; i++) {
            node = node->GetNext();
            newNode->SetNext(new Node<T>(node));
            newNode = newNode->GetNext();
        }
        newNode->SetNext(nullptr);
        return new LinkedList(newHeader);
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
LinkedList<T>* LinkedList<T> :: Concat(LinkedList<T> *list) const {
    LinkedList<T>* newList = new LinkedList(*this);
    for (size_t i = 0; i < list->length; i++) {
        newList->Append(list->Get(i));
    }
    return newList;
}
template <typename T>
void LinkedList<T> :: InsertAt(T item, size_t index) {
    if (index > length || index < 0)
        throw std::out_of_range("IndexOutOfRange");
    if (index == 0) {
        header = new Node<T>(item, header);
    }
    else {
        Node<T> *stNode = GetNode(index);
        Node<T> *newNode = new Node<T>(item, stNode->GetNext());
        stNode->SetNext(newNode);
    }
}
#endif
