#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include "ICollection.h"
#include "smart_ptrs/shared_ptr.h"

template <typename T>
class LinkedList : public IEnumerable<T>, public ICollection<T> {
protected:
    shared_ptr<Node<T>> header;
private:
    shared_ptr<Node<T>> GetNode(size_t index) const;
public:
    class LinkedListEnumerator : public IEnumerator<T> {
        shared_ptr<Node<T>> _n;
        LinkedList<T> *_s;
        bool _st;
    public:
        LinkedListEnumerator(LinkedList<T> *s) : _s(s), _n(s->header), _st(true) {}
        bool next() override {
            if (_st) {
                _st = false;
                if (!_n)
                    return false;
                return true;
            }
            if (!_n || !_n->GetNext())
                return false;
            _n = _n->GetNext();
            return true;
        }
        T& operator * () override { return _n->GetReference(); }
    };
    LinkedList();
    LinkedList(T *items, size_t size);
    LinkedList(const LinkedList<T> &list);
    LinkedList(shared_ptr<Node<T>> head);
    LinkedList(const ICollection<T> &collection);
 //   ~LinkedList();
    shared_ptr<IEnumerator<T>> GetEnumerator() override;
    T GetFirst() const;
    T GetLast() const;
    T Get(size_t index) const override;
    T& operator[](size_t index);
    LinkedList<T> *GetSubList(size_t startIndex, size_t endIndex) const;
    size_t GetLength() const override;
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, size_t index);
    void Set(size_t index, T value);
    LinkedList<T>* Concat(LinkedList<T> *list) const;
    inline bool operator==(const LinkedList<T> &rhs) const;
};

template <typename T>
LinkedList<T> :: LinkedList() {
}
template <typename T>
LinkedList<T> :: LinkedList(T *items, size_t size) {
    if (size < 0)
        throw std::length_error("Size can't be negative");
    if (size == 0) {
//        header();
    }
    else {
        header = make_shared<Node<T>>(items[0]);
        shared_ptr<Node<T>> nodeRing = header;
        for (size_t i = 1; i < size; ++i) {
            nodeRing->SetNext(make_shared<Node<T>>(items[i]));
            nodeRing = nodeRing->GetNext();
        }
    }
}
template <typename T>
LinkedList<T> :: LinkedList(const LinkedList <T> &list) {
    if (!list.header) {
        //header();
        return;
    }
    header = make_shared<Node<T>>(*list.header);
    shared_ptr<Node<T>> node = header;
    shared_ptr<Node<T>> listNode = list.header->GetNext();
    while(listNode) {
        node->SetNext(make_shared<Node<T>>(*listNode));
        node = node->GetNext();
        listNode = listNode->GetNext();
    }
}
template <typename T>
LinkedList<T> :: LinkedList(shared_ptr<Node<T>> head) {
    header = head;
    while (head) {
        head = head->GetNext();
    }
}
template <typename T>
LinkedList<T> :: LinkedList(const ICollection<T> &collection) {
    size_t length = collection.GetLength();
    if (length == 0) {
   //     header();
    }
    else {
        header = make_shared<Node<T>>(collection.Get(0));
        shared_ptr<Node<T>> nodeRing = header;
        for (size_t i = 1; i < length; ++i) {
            nodeRing->SetNext(make_shared<Node<T>>(collection.Get(i)));
            nodeRing = nodeRing->GetNext();
        }
    }
}
/*template <typename T>
LinkedList<T> :: ~LinkedList() {
    Node<T> *node = header;
    Node<T> *nodeNext;
    while(node != nullptr) {
        nodeNext = node->GetNext();
        delete node;
        node = nodeNext;
    }
}*/
template <typename T>
shared_ptr<IEnumerator<T>> LinkedList<T> :: GetEnumerator() {
    return shared_ptr<IEnumerator<T>>(new LinkedList<T>::LinkedListEnumerator(this));
}
template <typename T>
T LinkedList<T> :: GetFirst() const {
    if (header) {
        return header->GetValue();
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
T LinkedList<T> :: GetLast() const {
    if (header) {
        shared_ptr<Node<T>> node = header;
        while (node->GetNext()) {
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
    return GetNode(index)->GetValue();
}
template <typename T>
T& LinkedList<T> :: operator[](size_t index) {
    return GetNode(index)->GetReference();
}
template <typename T>
shared_ptr<Node<T>> LinkedList<T> :: GetNode(size_t index) const {
    size_t length = GetLength();
    if (index < length && index >= 0 && header) {
        shared_ptr<Node<T>> node = header;
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
    shared_ptr<Node<T>> node = header;
    size_t i = 0;
    while (node) {
        node = node->GetNext();
        ++i;
    }
    return i;
}
template <typename T>
void LinkedList<T> :: Append(T item) {
    if (!header) {
        header = make_shared<Node<T>>(item);
        return;
    }
    shared_ptr<Node<T>> node = header;
    while (node->GetNext()) {
        node = node->GetNext();
    }
    node->SetNext(make_shared<Node<T>>(item));
}
template <typename T>
void LinkedList<T> :: Prepend(T item) {
    shared_ptr<Node<T>> node = header;
    header = make_shared<Node<T>>(item, node);
}
template <typename T>
void LinkedList<T> :: Set(size_t index, T value) {
    size_t length = GetLength();
    if (index < length && index >= 0 && header) {
        shared_ptr<Node<T>> node = header;
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
LinkedList<T>* LinkedList<T> :: GetSubList(size_t startIndex, size_t endIndex) const {
    size_t length = GetLength();
    if (startIndex <= length && startIndex >= 0 && endIndex <= length && endIndex >= 0) {
        if (startIndex > endIndex) {
            size_t t = startIndex;
            startIndex = endIndex;
            endIndex = t;
        }
        else if (startIndex == endIndex)
            return new LinkedList();
        shared_ptr<Node<T>> node = GetNode(startIndex);
        shared_ptr<Node<T>> newHeader = make_shared<Node<T>>(*node);
        shared_ptr<Node<T>> newNode = newHeader;
        for (size_t i = startIndex + 1; i < endIndex; ++i) {
            node = node->GetNext();
            newNode->SetNext(make_shared<Node<T>>(*node));
            newNode = newNode->GetNext();
        }
        newNode->SetNext(shared_ptr<Node<T>>());
        return new LinkedList(newHeader);
    }
    else {
        throw std::out_of_range("IndexOutOfRange");
    }
}
template <typename T>
LinkedList<T>* LinkedList<T> :: Concat(LinkedList<T> *list) const {
    LinkedList<T>* newList = new LinkedList(*this);
    size_t listLength = list->GetLength();
    for (size_t i = 0; i < listLength; ++i) {
        newList->Append(list->Get(i));
    }
    return newList;
}
template <typename T>
void LinkedList<T> :: InsertAt(T item, size_t index) {
    size_t length = GetLength();
    if (index > length || index < 0)
        throw std::out_of_range("IndexOutOfRange");
    if (index == 0 || !header) {
        header = make_shared<Node<T>>(item, header);
    }
    else {
        shared_ptr<Node<T>> stNode = GetNode(index-1);
        shared_ptr<Node<T>> newNode = make_shared<Node<T>>(item, stNode->GetNext());
        stNode->SetNext(newNode);
    }
}
template <typename T>
inline bool LinkedList<T> :: operator==(const LinkedList<T> &rhs) const {
    shared_ptr<Node<T>> nodeL = this->header, nodeR = rhs.header;
    while(nodeL && nodeR) {
        if (nodeL->GetValue() != nodeR->GetValue())
            return false;
        nodeL = nodeL->GetNext();
        nodeR = nodeR->GetNext();
    }
    if (!(nodeL || nodeR)) {
        return true;
    }
    return false;
}
#endif
