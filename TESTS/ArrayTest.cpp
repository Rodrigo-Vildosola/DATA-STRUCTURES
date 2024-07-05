#include <gtest/gtest.h>
#include <Structs.h>
#include <iostream>

TEST(ArrayTest, AppendAndGetSize) {
    STRUCTS::Array array;
    EXPECT_EQ(array.getSize(), 0);
    array.append(1);
    EXPECT_EQ(array.getSize(), 1);
    array.append(2);
    EXPECT_EQ(array.getSize(), 2);
}

TEST(ArrayTest, InsertAndGet) {
    STRUCTS::Array array;
    array.append(1);
    array.append(3);
    array.insert(1, 2);
    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 2);
    EXPECT_EQ(array.get(2), 3);
}

TEST(ArrayTest, Update) {
    STRUCTS::Array array;
    array.append(1);
    array.append(2);
    array.update(1, 3);
    EXPECT_EQ(array.get(1), 3);
}

TEST(ArrayTest, Remove) {
    STRUCTS::Array array;
    array.append(1);
    array.append(2);
    array.append(3);
    array.remove(1);
    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 3);
    EXPECT_EQ(array.getSize(), 2);
}

TEST(ArrayTest, IsEmpty) {
    STRUCTS::Array array;
    EXPECT_TRUE(array.isEmpty());
    array.append(1);
    EXPECT_FALSE(array.isEmpty());
}

TEST(ArrayTest, Search) {
    STRUCTS::Array array;
    array.append(1);
    array.append(2);
    array.append(3);
    EXPECT_TRUE(array.search(2));
    EXPECT_FALSE(array.search(4));
}

TEST(ArrayTest, CopyConstructor) {
    STRUCTS::Array array1;
    array1.append(1);
    array1.append(2);
    STRUCTS::Array array2 = array1;
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2.get(0), 1);
    EXPECT_EQ(array2.get(1), 2);
    EXPECT_TRUE(array2 == array1);
}

TEST(ArrayTest, MoveConstructor) {
    STRUCTS::Array array1;
    array1.append(1);
    array1.append(2);
    STRUCTS::Array array2 = std::move(array1);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2.get(0), 1);
    EXPECT_EQ(array2.get(1), 2);
}

TEST(ArrayTest, CopyAssignmentOperator) {
    STRUCTS::Array array1;
    array1.append(1);
    array1.append(2);
    STRUCTS::Array array2;
    array2 = array1;
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2.get(0), 1);
    EXPECT_EQ(array2.get(1), 2);
    EXPECT_TRUE(array2 == array1);
}

TEST(ArrayTest, MoveAssignmentOperator) {
    STRUCTS::Array array1;
    array1.append(1);
    array1.append(2);
    STRUCTS::Array array2;
    array2 = std::move(array1);
    EXPECT_EQ(array2.getSize(), 2);
    EXPECT_EQ(array2.get(0), 1);
    EXPECT_EQ(array2.get(1), 2);
    EXPECT_EQ(array1.getSize(), 0);  // array1 should be empty after move
}

TEST(ArrayTest, IndexOperator) {
    STRUCTS::Array array;
    array.append(1);
    array.append(2);
    EXPECT_EQ(array[0], 1);
    EXPECT_EQ(array[1], 2);
    array[1] = 3;
    EXPECT_EQ(array[1], 3);
}

TEST(ArrayTest, EqualityOperators) {
    STRUCTS::Array array1;
    array1.append(1);
    array1.append(2);
    STRUCTS::Array array2;
    array2.append(1);
    array2.append(2);
    EXPECT_TRUE(array1 == array2);
    array2.append(3);
    EXPECT_FALSE(array1 == array2);
    EXPECT_TRUE(array1 != array2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
