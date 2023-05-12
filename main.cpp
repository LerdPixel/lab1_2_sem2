#include <iostream>
#include "Sequence.h"
#include "DynamicArray.h"


int main()
{
    int a[] {1, 2, 3};
    DynamicArray<int> *t = new DynamicArray<int>(a, 3);
    std::cout << t->Get(-1) << '\n';

/*    try {
        std::cout << t->Get(-1) << '\n';
    }
    catch (const std::exception &err) {
        std::cout << err.what() << '\n';
    }
*/
    delete t;
    return 0;
}
