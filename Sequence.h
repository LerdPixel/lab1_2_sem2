#ifndef SEQUENCE_H
#define SEQUENCE_H
#include "IEnumerator.h"
#include "IEnumerable.h"

template <class T>
class Sequence : public IEnumerable<T>{
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(size_t index) const = 0;
    virtual T& operator[] (const size_t index) = 0;
    virtual Sequence<T>* GetSubsequence(size_t startIndex, size_t endIndex) = 0;
    virtual size_t GetLength() const = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void Set(size_t index, T item) = 0;
    virtual void InsertAt(T item, size_t index) = 0;
    virtual Sequence <T>* Concat(Sequence <T> *list) const = 0;
    bool operator==(const Sequence<T> &rhs) const {
        size_t leftLen = GetLength();
//        std::cout << "==start=="<<GetLength()<<"  "<< rhs.GetLength() << '\n';

        if (leftLen != rhs.GetLength()) {
            return false;
        }
//        std::cout << "  len ok" << '\n';
        for (size_t i = 0; i < leftLen; i++) {
//            std::cout << i << "   left:" << Get(i) << "   right:" << rhs.Get(i) << '\n';

            if (Get(i) != rhs.Get(i))
                return false;
        }
        return true;
    }
    template <class T_SEQ, class T2>
    Sequence <T2>* Map(T2 (*f)(T)) {
        IEnumerable<T> *base = this;
        auto e = base->GetEnumerator();
        T_SEQ *resSequence = new T_SEQ();
        while (e->next()) {
//            std::cout<< *(*e)<<" " << f(*(*e)) << '\n';
            resSequence->Append(f(*(*e)));
        }
        return resSequence;
    }
    template <class T1>
    T1 Reduce(T1 (*f)(T, T1), T1 iter) {
        IEnumerable<T> *base = this;
        auto e = base->GetEnumerator();
        while (e->next()) {
            iter = f(*(*e), iter);
        }
        return iter;
    }
};

#endif
