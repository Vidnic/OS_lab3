#include <gtest/gtest.h>
#include "../marker.h"

TEST(SimpleTest, ArrayInit) {
    int size = 5;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        ASSERT_EQ(arr[i], 0);
    }

    delete[] arr;
}

TEST(SimpleTest, ThreadDataInit) {
    ThreadData data{};
    data.id = 1;

    ASSERT_EQ(data.id, 1);
}