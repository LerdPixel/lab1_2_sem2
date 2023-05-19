#ifndef ENUMERATOR_H
#define ENUMERATOR_H

template <class T> class IEnumerator {
public:
    virtual bool next() = 0;
    virtual T& operator * () = 0;
};

#endif
