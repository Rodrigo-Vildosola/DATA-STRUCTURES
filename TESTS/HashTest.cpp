#include <gtest/gtest.h>
#include <Structs.h>
#include <string>

// Custom data type
struct Person {
    std::string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Hash specialization for custom data type
namespace std {
    template <>
    struct hash<Person> {
        std::size_t operator()(const Person& p) const {
            return hash<std::string>()(p.name) ^ hash<int>()(p.age);
        }
    };
}

TEST(HashTableTest, InsertAndSearchInt) {
    STRUCTS::HashTable<int, int> ht(10);

    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    EXPECT_EQ(ht.search(1), 10);
    EXPECT_EQ(ht.search(2), 20);
    EXPECT_EQ(ht.search(3), 30);
}

TEST(HashTableTest, InsertAndUpdateInt) {
    STRUCTS::HashTable<int, int> ht(10);

    ht.insert(1, 10);
    ht.insert(1, 100);

    EXPECT_EQ(ht.search(1), 100);
}

TEST(HashTableTest, RemoveInt) {
    STRUCTS::HashTable<int, int> ht(10);

    ht.insert(1, 10);
    ht.remove(1);

    EXPECT_THROW(ht.search(1), std::runtime_error);
}

TEST(HashTableTest, ContainsInt) {
    STRUCTS::HashTable<int, int> ht(10);

    ht.insert(1, 10);
    ht.insert(2, 20);

    EXPECT_TRUE(ht.contains(1));
    EXPECT_TRUE(ht.contains(2));
    EXPECT_FALSE(ht.contains(3));
}

TEST(HashTableTest, ResizeInt) {
    STRUCTS::HashTable<int, int> ht(2);

    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    EXPECT_EQ(ht.search(1), 10);
    EXPECT_EQ(ht.search(2), 20);
    EXPECT_EQ(ht.search(3), 30);
}

TEST(HashTableTest, OperatorSubscriptInsertAndUpdateInt) {
    STRUCTS::HashTable<int, int> ht(10);

    ht[1] = 10;
    ht[2] = 20;
    ht[1] = 100;

    EXPECT_EQ(ht.search(1), 100);
    EXPECT_EQ(ht.search(2), 20);
}

TEST(HashTableTest, OperatorSubscriptAccessInt) {
    STRUCTS::HashTable<int, int> ht(10);

    ht.insert(1, 10);
    ht.insert(2, 20);

    EXPECT_EQ(ht[1], 10);
    EXPECT_EQ(ht[2], 20);
}

TEST(HashTableTest, EqualityOperatorInt) {
    STRUCTS::HashTable<int, int> ht1(10);
    STRUCTS::HashTable<int, int> ht2(10);

    ht1.insert(1, 10);
    ht1.insert(2, 20);

    ht2.insert(1, 10);
    ht2.insert(2, 20);

    EXPECT_TRUE(ht1 == ht2);
}

TEST(HashTableTest, InequalityOperatorInt) {
    STRUCTS::HashTable<int, int> ht1(10);
    STRUCTS::HashTable<int, int> ht2(10);

    ht1.insert(1, 10);
    ht1.insert(2, 20);

    ht2.insert(1, 10);
    ht2.insert(3, 30);

    EXPECT_TRUE(ht1 != ht2);
}

TEST(HashTableTest, SubscriptOperatorForNonExistingKeyInt) {
    STRUCTS::HashTable<int, int> ht(10);

    EXPECT_EQ(ht[1], 0); // Default value should be 0 for non-existing key
    ht[1] = 10;
    EXPECT_EQ(ht[1], 10);
}

TEST(HashTableTest, InsertAndSearchString) {
    STRUCTS::HashTable<std::string, int> ht(10);

    ht.insert("one", 10);
    ht.insert("two", 20);
    ht.insert("three", 30);

    EXPECT_EQ(ht.search("one"), 10);
    EXPECT_EQ(ht.search("two"), 20);
    EXPECT_EQ(ht.search("three"), 30);
}

TEST(HashTableTest, InsertAndUpdateString) {
    STRUCTS::HashTable<std::string, int> ht(10);

    ht.insert("one", 10);
    ht.insert("one", 100);

    EXPECT_EQ(ht.search("one"), 100);
}

TEST(HashTableTest, RemoveString) {
    STRUCTS::HashTable<std::string, int> ht(10);

    ht.insert("one", 10);
    ht.remove("one");

    EXPECT_THROW(ht.search("one"), std::runtime_error);
}

TEST(HashTableTest, ContainsString) {
    STRUCTS::HashTable<std::string, int> ht(10);

    ht.insert("one", 10);
    ht.insert("two", 20);

    EXPECT_TRUE(ht.contains("one"));
    EXPECT_TRUE(ht.contains("two"));
    EXPECT_FALSE(ht.contains("three"));
}

TEST(HashTableTest, InsertAndSearchPerson) {
    STRUCTS::HashTable<Person, int> ht(10);

    Person p1{"Alice", 30};
    Person p2{"Bob", 25};
    Person p3{"Charlie", 35};

    ht.insert(p1, 100);
    ht.insert(p2, 200);
    ht.insert(p3, 300);

    EXPECT_EQ(ht.search(p1), 100);
    EXPECT_EQ(ht.search(p2), 200);
    EXPECT_EQ(ht.search(p3), 300);
}

TEST(HashTableTest, InsertAndUpdatePerson) {
    STRUCTS::HashTable<Person, int> ht(10);

    Person p{"Alice", 30};
    ht.insert(p, 100);
    ht.insert(p, 200);

    EXPECT_EQ(ht.search(p), 200);
}

TEST(HashTableTest, RemovePerson) {
    STRUCTS::HashTable<Person, int> ht(10);

    Person p{"Alice", 30};
    ht.insert(p, 100);
    ht.remove(p);

    EXPECT_THROW(ht.search(p), std::runtime_error);
}

TEST(HashTableTest, ContainsPerson) {
    STRUCTS::HashTable<Person, int> ht(10);

    Person p1{"Alice", 30};
    Person p2{"Bob", 25};

    ht.insert(p1, 100);
    ht.insert(p2, 200);

    EXPECT_TRUE(ht.contains(p1));
    EXPECT_TRUE(ht.contains(p2));
    EXPECT_FALSE(ht.contains(Person{"Charlie", 35}));
}
