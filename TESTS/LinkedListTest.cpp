#include <gtest/gtest.h>
#include <Structs.h>
#include <vector>
#include <string>

struct Person {
    std::string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << " (" << person.age << ")";
    return os;
}

TEST(LinkedListTest, InsertAtBeginning) {
    STRUCTS::LinkedList<int> list;
    list.insertAtBeginning(1);
    list.insertAtBeginning(2);

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 2);
    EXPECT_EQ(values[1], 1);
}

TEST(LinkedListTest, InsertAtEnd) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
}

TEST(LinkedListTest, InsertAtPosition) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtPosition(1, 2);

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
    EXPECT_EQ(values[2], 3);
}

TEST(LinkedListTest, DeleteFromBeginning) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.deleteFromBeginning();

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 1);
    EXPECT_EQ(values[0], 2);
}

TEST(LinkedListTest, DeleteFromEnd) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.deleteFromEnd();

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 1);
    EXPECT_EQ(values[0], 1);
}

TEST(LinkedListTest, DeleteFromPosition) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.deleteFromPosition(1);

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 3);
}

TEST(LinkedListTest, Traverse) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 2);
}

TEST(LinkedListTest, Map) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    list.map([](int value) { return value + 1; });

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 3);
    EXPECT_EQ(values[0], 2);
    EXPECT_EQ(values[1], 3);
    EXPECT_EQ(values[2], 4);
}

TEST(LinkedListTest, Search) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    EXPECT_TRUE(list.search(1));
    EXPECT_TRUE(list.search(2));
    EXPECT_FALSE(list.search(3));
}

TEST(LinkedListTest, Update) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.update(1, 3);

    std::vector<int> values;
    list.traverse([&values](const int& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 3);
}

TEST(LinkedListTest, GetSize) {
    STRUCTS::LinkedList<int> list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);

    EXPECT_EQ(list.getSize(), 2);
}

TEST(LinkedListTest, IsEmpty) {
    STRUCTS::LinkedList<int> list;
    EXPECT_TRUE(list.isEmpty());

    list.insertAtEnd(1);
    EXPECT_FALSE(list.isEmpty());
}

TEST(LinkedListTest, InsertAtBeginningString) {
    STRUCTS::LinkedList<std::string> list;
    list.insertAtBeginning("Hello");
    list.insertAtBeginning("World");

    std::vector<std::string> values;
    list.traverse([&values](const std::string& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], "World");
    EXPECT_EQ(values[1], "Hello");
}

TEST(LinkedListTest, MapString) {
    STRUCTS::LinkedList<std::string> list;
    list.insertAtEnd("Hello");
    list.insertAtEnd("World");

    list.map([](std::string value) { return value + "!!!"; });

    std::vector<std::string> values;
    list.traverse([&values](const std::string& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    EXPECT_EQ(values[0], "Hello!!!");
    EXPECT_EQ(values[1], "World!!!");
}

TEST(LinkedListTest, InsertAtEndPerson) {
    STRUCTS::LinkedList<Person> list;
    list.insertAtEnd(Person{"Alice", 30});
    list.insertAtEnd(Person{"Bob", 25});

    std::vector<Person> values;
    list.traverse([&values](const Person& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    bool isEqualFirst = values[0] == Person{"Alice", 30};
    bool isEqualSecond = values[1] == Person{"Bob", 25};

    EXPECT_EQ(isEqualFirst, true);
    EXPECT_EQ(isEqualSecond, true);
}

TEST(LinkedListTest, MapPerson) {
    STRUCTS::LinkedList<Person> list;
    list.insertAtEnd(Person{"Alice", 30});
    list.insertAtEnd(Person{"Bob", 25});

    list.map([](Person person) { person.age += 1; return person; });

    std::vector<Person> values;
    list.traverse([&values](const Person& value) {
        values.push_back(value);
    });

    ASSERT_EQ(values.size(), 2);
    bool isEqualFirst = values[0] == Person{"Alice", 31};
    bool isEqualSecond = values[1] == Person{"Bob", 26};

    EXPECT_EQ(isEqualFirst, true);
    EXPECT_EQ(isEqualSecond, true);
}
