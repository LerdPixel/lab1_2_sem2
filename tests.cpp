#include <iostream>
#include <gtest/gtest.h>
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "test.h"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
