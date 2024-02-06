#include <iostream>
/* #include <gtest/gtest.h>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Complex.h"
#include "MathVector.h"
#include "Matrix.h" */
#include "smart_ptrs/shared_ptr.h"

int main(int argc, char **argv) {
    auto a = make_shared<int>(1);
    auto b = make_shared<int>(1);
    auto c = make_shared<int>(1);
    shared_ptr<int> d = a;
    int *e = nullptr;
    std::cout << *e << '\n';
    d = b;
    d = c;
    return 0;
}
