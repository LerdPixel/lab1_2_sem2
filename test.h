#include <gtest/gtest.h>
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include <vector>
#include <memory>
#include <string>
using namespace std;

struct DynamicArrayTests : public testing::Test {
    int size;
    DynamicArray<int>** dc;
    void SetUp() {
        size = 3;
        int a[] {1, 2, 3, 4, 5};
        int b[] {};
        int c[] {1};
        dc = new DynamicArray<int>* [size];
        dc[0] = new DynamicArray<int>(a, 5);
        dc[1] = new DynamicArray<int>(b, 0);
        dc[2] = new DynamicArray<int>(c, 1);

    }
    void TearDown() {
        for (size_t i = 0; i < size; i++) {
            delete dc[i];
        }
        delete [] dc;
    }
};

TEST_F(DynamicArrayTests, DynamicArray_Get2) {
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < dc[k]->GetLength(); ++i) {
            ASSERT_EQ(dc[k]->Get(i), i + 1);
        }
    }
    try {
        dc[1]->Get(0);
    } catch(exception& e) {
        ASSERT_STREQ("IndexOutOfRange", e.what());
    }
    try {dc[0]->Get(-1);}
    catch(exception& e) {
        ASSERT_STREQ("IndexOutOfRange", e.what());
    }
}
/*
TEST_F(DynamicArrayTests, DynamicArray_GetFirst) {
    ASSERT_EQ(dc[0]->GetFirst(), 1);
    ASSERT_EQ(dc[2]->GetFirst(), 1);
}*/
struct DynamicArrayTest : public testing::Test {
    DynamicArray<int> *dc;
    void SetUp() {
        int a[] {1, 2, 3, 4, 5};
        dc = new DynamicArray<int>(a, 5);
    }
    void TearDown() {delete dc;}
};
TEST_F(DynamicArrayTests, DynamicArray_Set) {
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < dc[k]->GetLength(); ++i) {
            dc[k]->Set(i, i);
        }
    }
    ASSERT_EQ(dc[0]->Get(4), 4);
    ASSERT_EQ(dc[2]->Get(0), 0);
    try {
        dc[1]->Set(0, -1);
    } catch(exception& e) {
        ASSERT_STREQ("IndexOutOfRange", e.what());
    }
    try {dc[0]->Set(-1, 3);}
    catch(exception& e) {
        ASSERT_STREQ("IndexOutOfRange", e.what());
    }
}
TEST_F(DynamicArrayTests, DynamicArray_Resize) {
/*    for (size_t i = 0; i < dc[0]->GetLength(); i++) {
        std::cout << dc[0]->Get(i) << '\n';
    }*/
    dc[0]->Resize(3);
    dc[2]->Resize(3);
    ASSERT_EQ(dc[0]->GetLength(), 3);
    ASSERT_EQ(dc[2]->GetLength(), 3);
    ASSERT_EQ(dc[0]->Get(0), 1);
    ASSERT_EQ(dc[2]->Get(0), 1);
    string str;
    try {
        dc[0]->Get(3);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ("IndexOutOfRange", str.c_str());
    dc[0]->Get(2);
    try {dc[0]->Get(2);}
    catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(DynamicArrayTest, DynamicArray_Get) {
    int i = 0;
    for (i; i < dc->GetLength(); ++i) {
        ASSERT_EQ(dc->Get(i), i + 1);
    }
}

struct LinkedListTests : public testing::Test {
    int size;
    LinkedList<int>** dc;
    void SetUp() {
        size = 3;
        int a[] {1, 2, 3, 4, 5};
        int b[] {1};
        int c[] {};
        dc = new LinkedList<int>* [size];
        dc[0] = new LinkedList<int>(a, 5);
        dc[1] = new LinkedList<int>(b, 1);
        dc[2] = new LinkedList<int>();
    }
    void TearDown() {
        for (size_t i = 0; i < size; i++) {
            delete dc[i];
        }
        delete [] dc;
    }
};

TEST_F(LinkedListTests, LinkedList_Get) {
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < dc[k]->GetLength(); ++i) {
            ASSERT_EQ(dc[k]->Get(i), i + 1);
        }
    }
    try {
        dc[1]->Get(0);
    } catch(exception& e) {
        ASSERT_STREQ("IndexOutOfRange", e.what());
    }

    try {dc[0]->Get(-1);}
    catch(exception& e) {

        ASSERT_STREQ("IndexOutOfRange", e.what());
    }

}
