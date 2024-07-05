#include <gtest/gtest.h>
#include <Structs.h>
#include <sstream>

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
    }                                                                   \
                                                                        \
    TEST(StackType##Test, PopEmptyStack) {                              \
        STRUCTS::StackType stack;                                       \
        EXPECT_THROW(stack.pop(), std::out_of_range);                   \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, TopEmptyStack) {                              \
        STRUCTS::StackType stack;                                       \
        EXPECT_THROW(stack.top(), std::out_of_range);                   \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, CopyConstructor) {                            \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        STRUCTS::StackType stackCopy(stack);                            \
        EXPECT_EQ(stackCopy.top(), 2);                                  \
        stackCopy.pop();                                                \
        EXPECT_EQ(stackCopy.top(), 1);                                  \
        stackCopy.pop();                                                \
        EXPECT_TRUE(stackCopy.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, CopyAssignment) {                             \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        STRUCTS::StackType stackCopy;                                   \
        stackCopy = stack;                                              \
        EXPECT_EQ(stackCopy.top(), 2);                                  \
        stackCopy.pop();                                                \
        EXPECT_EQ(stackCopy.top(), 1);                                  \
        stackCopy.pop();                                                \
        EXPECT_TRUE(stackCopy.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, MoveConstructor) {                            \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        STRUCTS::StackType stackMove(std::move(stack));                 \
        EXPECT_EQ(stackMove.top(), 2);                                  \
        stackMove.pop();                                                \
        EXPECT_EQ(stackMove.top(), 1);                                  \
        stackMove.pop();                                                \
        EXPECT_TRUE(stackMove.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, MoveAssignment) {                             \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        STRUCTS::StackType stackMove;                                   \
        stackMove = std::move(stack);                                   \
        EXPECT_EQ(stackMove.top(), 2);                                  \
        stackMove.pop();                                                \
        EXPECT_EQ(stackMove.top(), 1);                                  \
        stackMove.pop();                                                \
        EXPECT_TRUE(stackMove.isEmpty());                               \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, EqualityOperator) {                           \
        STRUCTS::StackType stack1;                                      \
        STRUCTS::StackType stack2;                                      \
        stack1.push(1);                                                 \
        stack1.push(2);                                                 \
        stack2.push(1);                                                 \
        stack2.push(2);                                                 \
        EXPECT_TRUE(stack1 == stack2);                                  \
        stack2.push(3);                                                 \
        EXPECT_FALSE(stack1 == stack2);                                 \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, InequalityOperator) {                         \
        STRUCTS::StackType stack1;                                      \
        STRUCTS::StackType stack2;                                      \
        stack1.push(1);                                                 \
        stack1.push(2);                                                 \
        stack2.push(1);                                                 \
        stack2.push(2);                                                 \
        EXPECT_FALSE(stack1 != stack2);                                 \
        stack2.push(3);                                                 \
        EXPECT_TRUE(stack1 != stack2);                                  \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, StreamInsertionOperator) {                    \
        STRUCTS::StackType stack;                                       \
        stack.push(1);                                                  \
        stack.push(2);                                                  \
        stack.push(3);                                                  \
        std::stringstream ss;                                           \
        ss << stack;                                                    \
        EXPECT_EQ(ss.str(), "3 2 1 ");                                  \
    }                                                                   \
                                                                        \
    TEST(StackType##Test, LargePushPop) {                               \
        STRUCTS::StackType stack;                                       \
        for (int i = 0; i < 1000; ++i) {                                \
            stack.push(i);                                              \
        }                                                               \
        EXPECT_EQ(stack.getSize(), 1000);                               \
        for (int i = 999; i >= 0; --i) {                                \
            EXPECT_EQ(stack.top(), i);                                  \
            stack.pop();                                                \
        }                                                               \
        EXPECT_TRUE(stack.isEmpty());                                   \
    }

STACK_TESTS(ArrayStack)
STACK_TESTS(LinkedListStack)

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
