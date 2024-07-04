#include <gtest/gtest.h>
#include <Structs.h>

// Helper macro to define stack tests for both implementations
#define STACK_TESTS(StackType)                                          \
    TEST(StackType##Test, PushAndTop) {                                 \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        EXPECT_EQ(stack.top(), 2);                                      \
        stack.push(3);                                                  \
        EXPECT_EQ(stack.top(), 3);                                      \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, Pop) {                                        \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        stack.pop();                                                    \
        EXPECT_EQ(stack.top(), 1);                                      \
        stack.pop();                                                    \
        EXPECT_TRUE(stack.isEmpty());                                   \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, IsEmpty) {                                    \
        STRUCTS::StackType stack;                                       \
        EXPECT_TRUE(stack.isEmpty());                                   \
        stack.push(1);                                                  \
        EXPECT_FALSE(stack.isEmpty());                                  \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, GetSize) {                                    \
        STRUCTS::StackType stack;                                       \
        EXPECT_EQ(stack.getSize(), 0);                                  \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        EXPECT_EQ(stack.getSize(), 2);                                  \
    }

STACK_TESTS(ArrayStack)
STACK_TESTS(LinkedListStack)
