#include <iostream>
//#include "Sequence.h"
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedList.h"
int main()
{
    int a[] {1, 2, 3};
    ArraySequence<int> t0 = ArraySequence(a, 3);
    Sequence<int> *t = new ArraySequence<int>(t0);
    t->Append(4);

    Sequence<int> *t2;
    try {
        t2 = t->GetSubsequence(0, 2);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << '\n';
    }
    Sequence<int> *t3 = t->Concat(t2);
    for (size_t i = 0; i < t3->GetLength(); i++) {
        std::cout << t3->Get(i) << '\t';
    }
    std::cout << '\n';

    delete t;
    return 0;
}
