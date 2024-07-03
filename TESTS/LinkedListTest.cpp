#include <gtest/gtest.h>
#include <Structs.h>

TEST(LinkedListTest, InsertAtBeginning) {
    STRUCTS::LinkedList list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 2);
    EXPECT_EQ(values[1], 1);
}

TEST(LinkedListTest, InsertAtEnd) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
}

TEST(LinkedListTest, InsertAtPosition) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtPosition(1, 2);

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
    EXPECT_EQ(values[2], 3);
}

TEST(LinkedListTest, DeleteFromBeginning) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.deleteFromBeginning();

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 1);
    EXPECT_EQ(values[0], 2);
}

TEST(LinkedListTest, DeleteFromEnd) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.deleteFromEnd();

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 1);
    EXPECT_EQ(values[0], 1);
}

TEST(LinkedListTest, DeleteFromPosition) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.deleteFromPosition(1);

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 3);
}

TEST(LinkedListTest, Traverse) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
}

TEST(LinkedListTest, Search) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    EXPECT_TRUE(list.search(1));
    EXPECT_TRUE(list.search(2));
    EXPECT_FALSE(list.search(3));
}

TEST(LinkedListTest, Update) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.update(1, 3);

    std::vector<int> values;
    list.traverse([&values](int value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 3);
}

TEST(LinkedListTest, GetSize) {
    STRUCTS::LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(LinkedListTest, IsEmpty) {
    STRUCTS::LinkedList list;
    EXPECT_TRUE(list.isEmpty());

    list.insertAtEnd(1);
    EXPECT_FALSE(list.isEmpty());
}
