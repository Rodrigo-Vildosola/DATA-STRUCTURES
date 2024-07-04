#include <gtest/gtest.h>
#include <Structs.h>

TEST(HashTableTest, InsertAndSearch) {
    STRUCTS::HashTable ht(10);

    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    EXPECT_EQ(ht.search(1), 10);
    EXPECT_EQ(ht.search(2), 20);
    EXPECT_EQ(ht.search(3), 30);
}

TEST(HashTableTest, InsertAndUpdate) {
    STRUCTS::HashTable ht(10);

    ht.insert(1, 10);
    ht.insert(1, 100);

    EXPECT_EQ(ht.search(1), 100);
}

TEST(HashTableTest, Remove) {
    STRUCTS::HashTable ht(10);

    ht.insert(1, 10);
    ht.remove(1);

    EXPECT_THROW(ht.search(1), std::runtime_error);
}

TEST(HashTableTest, Contains) {
    STRUCTS::HashTable ht(10);

    ht.insert(1, 10);
    ht.insert(2, 20);

    EXPECT_TRUE(ht.contains(1));
    EXPECT_TRUE(ht.contains(2));
    EXPECT_FALSE(ht.contains(3));
}

TEST(HashTableTest, Resize) {
    STRUCTS::HashTable ht(2);

    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    EXPECT_EQ(ht.search(1), 10);
    EXPECT_EQ(ht.search(2), 20);
    EXPECT_EQ(ht.search(3), 30);
}

TEST(HashTableTest, OperatorSubscriptInsertAndUpdate) {
    STRUCTS::HashTable ht(10);

    ht[1] = 10;
    ht[2] = 20;
    ht[1] = 100;

    EXPECT_EQ(ht.search(1), 100);
    EXPECT_EQ(ht.search(2), 20);
}

TEST(HashTableTest, OperatorSubscriptAccess) {
    STRUCTS::HashTable ht(10);

    ht.insert(1, 10);
    ht.insert(2, 20);

    EXPECT_EQ(ht[1], 10);
    EXPECT_EQ(ht[2], 20);
}

TEST(HashTableTest, EqualityOperator) {
    STRUCTS::HashTable ht1(10);
    STRUCTS::HashTable ht2(10);

    ht1.insert(1, 10);
    ht1.insert(2, 20);

    ht2.insert(1, 10);
    ht2.insert(2, 20);

    EXPECT_TRUE(ht1 == ht2);
}

TEST(HashTableTest, InequalityOperator) {
    STRUCTS::HashTable ht1(10);
    STRUCTS::HashTable ht2(10);

    ht1.insert(1, 10);
    ht1.insert(2, 20);

    ht2.insert(1, 10);
    ht2.insert(3, 30);

    EXPECT_TRUE(ht1 != ht2);
}

TEST(HashTableTest, SubscriptOperatorForNonExistingKey) {
    STRUCTS::HashTable ht(10);

    EXPECT_EQ(ht[1], 0); // Default value should be 0 for non-existing key
    ht[1] = 10;
    EXPECT_EQ(ht[1], 10);
}
