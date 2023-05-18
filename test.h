#include <gtest/gtest.h>
#include "DynamicArray.h"
#include "ArraySequence.h"
#include "LinkedList.h"
//#include "LinkedListSequence.h"
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
    LinkedList<int>* dc2;
    LinkedList<int>* dc3;
    void SetUp() {
        size = 4;
        int a[] {1, 2, 3, 4, 5};
        int b[] {1};
        int c[] {};
        int d[] {1, 2, 3, 5, 4};
        dc = new LinkedList<int>* [size];
        dc[0] = new LinkedList<int>(a, 5);
        dc[1] = new LinkedList<int>(b, 1);
        dc[2] = new LinkedList<int>();
        dc[3] = new LinkedList<int>(a, 5);
        dc3 = new LinkedList<int>(b, 1);
        dc2 = new LinkedList<int>(d, 5);
    }
    void TearDown() {
        for (size_t i = 0; i < size; i++) {
            delete dc[i];
        }
        delete dc2;
        delete dc3;
        delete [] dc;
    }
};

TEST_F(LinkedListTests, LinkedList_Get_123) {
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < dc[k]->GetLength(); ++i) {
            ASSERT_EQ(dc[k]->Get(i), i + 1);
        }
    }
}

TEST_F(LinkedListTests, LinkedList_Get_edgeCase1) {
    string str;
    try {
        dc[2]->Get(0);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(LinkedListTests, LinkedList_Get_edgeCase2) {
    string str;
    try {dc[0]->Get(-1);}
    catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(LinkedListTests, LinkedList_GetFirst_1) {
    for (int k = 0; k < 2; ++k) {
        ASSERT_EQ(dc[k]->GetFirst(), 1);
    }
}

TEST_F(LinkedListTests, LinkedList_GetFirst_edgeCase1) {
    string str;
    try {
        dc[2]->GetFirst();
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(LinkedListTests, LinkedList_GetFirst_2) {
    ASSERT_EQ(dc2->GetFirst(), 1);
}

TEST_F(LinkedListTests, LinkedList_GetLast_1) {
    for (int k = 0; k < 2; ++k) {
        ASSERT_EQ(dc[k]->GetLast(), dc[k]->GetLength());
    }
}

TEST_F(LinkedListTests, LinkedList_GetLast_edgeCase1) {
    string str;
    try {
        dc[2]->GetLast();
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(LinkedListTests, LinkedList_GetLast_2) {
    ASSERT_EQ(dc[0]->GetLast(), 5);
}

TEST_F(LinkedListTests, LinkedList_Equel) {
    ASSERT_TRUE(*dc[0]==*dc[3]);
    ASSERT_TRUE(*dc[1]==*dc3);
    ASSERT_TRUE(*dc[0]==*dc[0]);
    ASSERT_FALSE(*dc[0]==*dc2);
    ASSERT_TRUE(*dc[2]==LinkedList<int>());
}

TEST_F(LinkedListTests, LinkedList_GetLength_1) {ASSERT_EQ(dc[0]->GetLength(), 5);}
TEST_F(LinkedListTests, LinkedList_GetLength_2) {ASSERT_EQ(dc[1]->GetLength(), 1);}
TEST_F(LinkedListTests, LinkedList_GetLength_3) {ASSERT_EQ(dc[2]->GetLength(), 0);}
TEST_F(LinkedListTests, LinkedList_GetLength_4) {ASSERT_EQ(dc[3]->GetLength(), 5);}
TEST_F(LinkedListTests, LinkedList_GetLength_5) {ASSERT_EQ(dc2->GetLength(), 5);}
TEST_F(LinkedListTests, LinkedList_GetLength_6) {ASSERT_EQ(dc3->GetLength(), 1);}

TEST_F(LinkedListTests, LinkedList_Append_1) {
    int array [] {1,2,3,4,5,6};
    int a = 6;
    dc[0]->Append(a);
    ASSERT_TRUE(*dc[0] == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_Append_2) {
    int array [] {1,2,3};
    dc[1]->Append(2);
    dc[1]->Append(3);
    ASSERT_TRUE(*dc[1] == LinkedList<int>(array, 3));
}
TEST_F(LinkedListTests, LinkedList_Append_edge) {
    dc[2]->Append(1);
    ASSERT_TRUE(*dc[2] == *dc[1]);
}

TEST_F(LinkedListTests, LinkedList_Prepend_1) {
    int array [] {1,2,3,1};
    dc[1]->Prepend(3);
    dc[1]->Prepend(2);
    dc[1]->Prepend(1);
    ASSERT_TRUE(*dc[1] == LinkedList<int>(array, 4));
}
TEST_F(LinkedListTests, LinkedList_Prepend_2) {
    int array [] {0,1,2,3,4,5};
    dc[0]->Prepend(0);
    ASSERT_TRUE(*dc[0] == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_Prepend_edge) {
    int array [] {1,2};
    dc[2]->Prepend(2);
    dc[2]->Prepend(1);
    ASSERT_TRUE(*dc[2] == LinkedList<int>(array, 2));
}
TEST_F(LinkedListTests, LinkedList_Append_Prepend) {
    int array [] {-1,0,1,-1};
    dc[1]->Prepend(0);
    dc[1]->Append(-1);
    dc[1]->Prepend(-1);
    ASSERT_TRUE(*dc[1] == LinkedList<int>(array, 4));
}



TEST_F(LinkedListTests, LinkedList_Set_123) {
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < dc[k]->GetLength(); ++i) {
            dc[k]->Set(i, i);
        }
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < dc[k]->GetLength(); ++i) {
            ASSERT_EQ(dc[k]->Get(i), i);
        }
    }
}

TEST_F(LinkedListTests, LinkedList_Set_edgeCase1) {
    string str;
    try {
        dc[2]->Set(0, 1);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(LinkedListTests, LinkedList_Set_edgeCase2) {
    string str;
    try {dc[0]->Set(-1, 0);}
    catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}

TEST_F(LinkedListTests, LinkedList_SetLast_1) {
    for (int k = 0; k < 2; ++k) {
        dc[k]->Set(dc[k]->GetLength()-1, 100);
        ASSERT_EQ(dc[k]->GetLast(), 100);
    }
}
TEST_F(LinkedListTests, LinkedList_GetSubList_1) {
    int array [] {2,3};
    unique_ptr<LinkedList<int>> d(dc[0]->GetSubList(1, 3));
    ASSERT_TRUE(*d == LinkedList<int>(array, 2));
}
TEST_F(LinkedListTests, LinkedList_GetSubList_2) {
    int array [] {1};
    unique_ptr<LinkedList<int>> d(dc[1]->GetSubList(0, 1));
    ASSERT_TRUE(*d == LinkedList<int>(array, 1));
}
TEST_F(LinkedListTests, LinkedList_GetSubList_3) {
    int array [] {1};
    unique_ptr<LinkedList<int>> d(dc2->GetSubList(2, 2));
    ASSERT_TRUE(*d == LinkedList<int>());
}
TEST_F(LinkedListTests, LinkedList_GetSubList_4) {
    int array [] {3, 5, 4};
    unique_ptr<LinkedList<int>> d(dc2->GetSubList(2, 5));
    ASSERT_TRUE(*d == LinkedList<int>(array, 3));
}
TEST_F(LinkedListTests, LinkedList_GetSubList_edgeCase1) {
    string str;
    try {
        dc[2]->GetSubList(0, 1);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(LinkedListTests, LinkedList_GetSubList_edgeCase2) {
    string str;
    try {
        dc[0]->GetSubList(-1, 1);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(LinkedListTests, LinkedList_GetSubList_edgeCase3) {
    string str;
    try {
        dc[0]->GetSubList(1, 6);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(LinkedListTests, LinkedList_GetSubList_edgeCase4) {
    string str;
    try {
        dc[0]->GetSubList(-1, 15);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(LinkedListTests, LinkedList_Concat_1) {
    int array [] {1,2,3,4,5,1,2,3,5,4};
    shared_ptr<LinkedList<int>> d(dc[0]->Concat(dc2));
    ASSERT_TRUE(*d == LinkedList<int>(array, 10));
}
TEST_F(LinkedListTests, LinkedList_Concat_2) {
    int array [] {1,2,3,4,5,1};
    unique_ptr<LinkedList<int>> d(dc[0]->Concat(dc[1]));
    ASSERT_TRUE(*d == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_Concat_3) {
    int array [] {1,1,2,3,4,5};
    unique_ptr<LinkedList<int>> d(dc[1]->Concat(dc[0]));
    ASSERT_TRUE(*d == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_Concat_4) {
    int array [] {1,2,3,4,5};
    unique_ptr<LinkedList<int>> d(dc[0]->Concat(dc[2]));
    ASSERT_TRUE(*d == LinkedList<int>(array, 5));
}
TEST_F(LinkedListTests, LinkedList_Concat_5) {
    int array [] {1,2,3,4,5};
    unique_ptr<LinkedList<int>> d(dc[2]->Concat(dc[0]));
    ASSERT_TRUE(*d == LinkedList<int>(array, 5));
}

TEST_F(LinkedListTests, LinkedList_InsertAt_1) {
    int array [] {1,2,-1,3,4,5};
    dc[0]->InsertAt(-1, 2);
    ASSERT_TRUE(*dc[0] == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_InsertAt_2) {
    int array [] {-1,1,2,3,4,5};
    dc[0]->InsertAt(-1, 0);
    ASSERT_TRUE(*dc[0] == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_InsertAt_3) {
    int array [] {1,2,3,4,5,-1};
    dc[0]->InsertAt(-1, 5);
    ASSERT_TRUE(*dc[0] == LinkedList<int>(array, 6));
}
TEST_F(LinkedListTests, LinkedList_InsertAt_5) {
    int array [] {-1};
    dc[2]->InsertAt(-1, 0);
    ASSERT_TRUE(*dc[2] == LinkedList<int>(array, 1));
}
TEST_F(LinkedListTests, LinkedList_InsertAt_edgeCase_1) {
    string str;
    try {
        dc[0]->InsertAt(-1, 6);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(LinkedListTests, LinkedList_InsertAt_edgeCase_2) {
    string str;
    try {
        dc[0]->InsertAt(-1, -1);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
TEST_F(LinkedListTests, LinkedList_InsertAt_edgeCase_3) {
    string str;
    try {
        dc[2]->InsertAt(-1, 2);
    } catch(exception& e) {
        str = e.what();
    }
    ASSERT_STREQ(str.c_str(), "IndexOutOfRange");
}
