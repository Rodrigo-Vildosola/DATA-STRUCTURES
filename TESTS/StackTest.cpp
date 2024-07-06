#include <gtest/gtest.h>
#include <Structs.h>
#include <sstream>
#include <string>
#include <iostream>


class Person {
public:
    std::string name;
    int age;

    Person() : name(""), age(0) {}
    Person(std::string name, int age) : name(name), age(age) {}

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " (" << person.age << ")";
        return os;
    }
};


typedef std::string StringAlias;  // Add this line to create an alias for std::string

// Helper macro to define stack tests for both implementations
#define STACK_TESTS_TEMPLATE(StackType, T, pushValue, expectedOutput)   \
    TEST(StackType##_##T##_Test, PushAndTop) {                          \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        EXPECT_EQ(stack.top(), pushValue(2));                           \
        stack.push(pushValue(3));                                       \
        EXPECT_EQ(stack.top(), pushValue(3));                           \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, Pop) {                                 \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        stack.pop();                                                    \
        EXPECT_EQ(stack.top(), pushValue(1));                           \
        stack.pop();                                                    \
        EXPECT_TRUE(stack.isEmpty());                                   \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, IsEmpty) {                             \
        STRUCTS::StackType<T> stack;                                    \
        EXPECT_TRUE(stack.isEmpty());                                   \
        stack.push(pushValue(1));                                       \
        EXPECT_FALSE(stack.isEmpty());                                  \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, GetSize) {                             \
        STRUCTS::StackType<T> stack;                                    \
        EXPECT_EQ(stack.getSize(), 0);                                  \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        EXPECT_EQ(stack.getSize(), 2);                                  \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, PopEmptyStack) {                       \
        STRUCTS::StackType<T> stack;                                    \
        EXPECT_THROW(stack.pop(), std::out_of_range);                   \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, TopEmptyStack) {                       \
        STRUCTS::StackType<T> stack;                                    \
        EXPECT_THROW(stack.top(), std::out_of_range);                   \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, CopyConstructor) {                     \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        STRUCTS::StackType<T> stackCopy(stack);                         \
        EXPECT_EQ(stackCopy.top(), pushValue(2));                       \
        stackCopy.pop();                                                \
        EXPECT_EQ(stackCopy.top(), pushValue(1));                       \
        stackCopy.pop();                                                \
        EXPECT_TRUE(stackCopy.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, CopyAssignment) {                      \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        STRUCTS::StackType<T> stackCopy;                                \
        stackCopy = stack;                                              \
        EXPECT_EQ(stackCopy.top(), pushValue(2));                       \
        stackCopy.pop();                                                \
        EXPECT_EQ(stackCopy.top(), pushValue(1));                       \
        stackCopy.pop();                                                \
        EXPECT_TRUE(stackCopy.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, MoveConstructor) {                     \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        STRUCTS::StackType<T> stackMove(std::move(stack));              \
        EXPECT_EQ(stackMove.top(), pushValue(2));                       \
        stackMove.pop();                                                \
        EXPECT_EQ(stackMove.top(), pushValue(1));                       \
        stackMove.pop();                                                \
        EXPECT_TRUE(stackMove.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, MoveAssignment) {                      \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        STRUCTS::StackType<T> stackMove;                                \
        stackMove = std::move(stack);                                   \
        EXPECT_EQ(stackMove.top(), pushValue(2));                       \
        stackMove.pop();                                                \
        EXPECT_EQ(stackMove.top(), pushValue(1));                       \
        stackMove.pop();                                                \
        EXPECT_TRUE(stackMove.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, EqualityOperator) {                    \
        STRUCTS::StackType<T> stack1;                                   \
        STRUCTS::StackType<T> stack2;                                   \
        stack1.push(pushValue(1));                                      \
        stack1.push(pushValue(2));                                      \
        stack2.push(pushValue(1));                                      \
        stack2.push(pushValue(2));                                      \
        EXPECT_TRUE(stack1 == stack2);                                  \
        stack2.push(pushValue(3));                                      \
        EXPECT_FALSE(stack1 == stack2);                                 \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, InequalityOperator) {                  \
        STRUCTS::StackType<T> stack1;                                   \
        STRUCTS::StackType<T> stack2;                                   \
        stack1.push(pushValue(1));                                      \
        stack1.push(pushValue(2));                                      \
        stack2.push(pushValue(1));                                      \
        stack2.push(pushValue(2));                                      \
        EXPECT_FALSE(stack1 != stack2);                                 \
        stack2.push(pushValue(3));                                      \
        EXPECT_TRUE(stack1 != stack2);                                  \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, StreamInsertionOperator) {             \
        STRUCTS::StackType<T> stack;                                    \
        stack.push(pushValue(1));                                       \
        stack.push(pushValue(2));                                       \
        stack.push(pushValue(3));                                       \
        std::stringstream ss;                                           \
        ss << stack;                                                    \
        EXPECT_EQ(ss.str(), expectedOutput);                            \
    }                                                                   \
                                                                        \
    TEST(StackType##_##T##_Test, LargePushPop) {                        \
        STRUCTS::StackType<T> stack;                                    \
        for (int i = 0; i < 1000; ++i) {                                \
            stack.push(pushValue(i));                                   \
        }                                                               \
        EXPECT_EQ(stack.getSize(), 1000);                               \
        for (int i = 999; i >= 0; --i) {                                \
            EXPECT_EQ(stack.top(), pushValue(i));                       \
            stack.pop();                                                \
        }                                                               \
        EXPECT_TRUE(stack.isEmpty());                                   \
    }

STACK_TESTS_TEMPLATE(ArrayStack, int, [](int value) { return value; }, "3 2 1 ")
STACK_TESTS_TEMPLATE(LinkedListStack, int, [](int value) { return value; }, "3 2 1 ")

STACK_TESTS_TEMPLATE(ArrayStack, StringAlias, [](int value) { return std::to_string(value); }, "3 2 1 ")
STACK_TESTS_TEMPLATE(LinkedListStack, StringAlias, [](int value) { return std::to_string(value); }, "3 2 1 ")

STACK_TESTS_TEMPLATE(ArrayStack, Person, [](int value) { return Person("Person" + std::to_string(value), value); }, "Person3 (3) Person2 (2) Person1 (1) ")
STACK_TESTS_TEMPLATE(LinkedListStack, Person, [](int value) { return Person("Person" + std::to_string(value), value); }, "Person3 (3) Person2 (2) Person1 (1) ")

