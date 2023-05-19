#ifndef IENUMERABLE
#define IENUMERABLE
#include <memory>
#include "IEnumerator.h"

template <class T> class IEnumerable {
public:
    virtual IEnumerator<T> *getEnumerator() = 0;
};

#endif
