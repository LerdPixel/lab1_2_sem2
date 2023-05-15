#ifndef ENUMERABLE
#define ENUMERABLE

template <class T> class Enumerable {
public:
    virtual Enumerator<T> *getEnumerator() = 0;
};

#endif
