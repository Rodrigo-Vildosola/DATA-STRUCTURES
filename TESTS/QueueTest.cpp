#include <gtest/gtest.h>
#include <Structs.h>
#include <DTypes.h>
#include <sstream>
#include <string>
#include <iostream>

typedef std::string StringAlias;

// Helper macro to define queue tests for both implementations
#define QUEUE_TESTS_TEMPLATE(QueueType, T, enqueueValue, expectedOutput) \
    TEST(QueueType##_##T##_Test, EnqueueAndFront) {                      \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        EXPECT_EQ(queue.front(), enqueueValue(1));                       \
        queue.enqueue(enqueueValue(3));                                  \
        EXPECT_EQ(queue.front(), enqueueValue(1));                       \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, Dequeue) {                              \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        queue.dequeue();                                                 \
        EXPECT_EQ(queue.front(), enqueueValue(2));                       \
        queue.dequeue();                                                 \
        EXPECT_TRUE(queue.isEmpty());                                    \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, IsEmpty) {                              \
        STRUCTS::QueueType<T> queue;                                     \
        EXPECT_TRUE(queue.isEmpty());                                    \
        queue.enqueue(enqueueValue(1));                                  \
        EXPECT_FALSE(queue.isEmpty());                                   \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, GetSize) {                              \
        STRUCTS::QueueType<T> queue;                                     \
        EXPECT_EQ(queue.getSize(), 0);                                   \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        EXPECT_EQ(queue.getSize(), 2);                                   \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, DequeueEmptyQueue) {                    \
        STRUCTS::QueueType<T> queue;                                     \
        EXPECT_THROW(queue.dequeue(), std::out_of_range);                \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, FrontEmptyQueue) {                      \
        STRUCTS::QueueType<T> queue;                                     \
        EXPECT_THROW(queue.front(), std::out_of_range);                  \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, CopyConstructor) {                      \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        STRUCTS::QueueType<T> queueCopy(queue);                          \
        EXPECT_EQ(queueCopy.front(), enqueueValue(1));                   \
        queueCopy.dequeue();                                             \
        EXPECT_EQ(queueCopy.front(), enqueueValue(2));                   \
        queueCopy.dequeue();                                             \
        EXPECT_TRUE(queueCopy.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, CopyAssignment) {                       \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        STRUCTS::QueueType<T> queueCopy;                                 \
        queueCopy = queue;                                               \
        EXPECT_EQ(queueCopy.front(), enqueueValue(1));                   \
        queueCopy.dequeue();                                             \
        EXPECT_EQ(queueCopy.front(), enqueueValue(2));                   \
        queueCopy.dequeue();                                             \
        EXPECT_TRUE(queueCopy.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, MoveConstructor) {                      \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        STRUCTS::QueueType<T> queueMove(std::move(queue));               \
        EXPECT_EQ(queueMove.front(), enqueueValue(1));                   \
        queueMove.dequeue();                                             \
        EXPECT_EQ(queueMove.front(), enqueueValue(2));                   \
        queueMove.dequeue();                                             \
        EXPECT_TRUE(queueMove.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, MoveAssignment) {                       \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        STRUCTS::QueueType<T> queueMove;                                 \
        queueMove = std::move(queue);                                    \
        EXPECT_EQ(queueMove.front(), enqueueValue(1));                   \
        queueMove.dequeue();                                             \
        EXPECT_EQ(queueMove.front(), enqueueValue(2));                   \
        queueMove.dequeue();                                             \
        EXPECT_TRUE(queueMove.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, EqualityOperator) {                     \
        STRUCTS::QueueType<T> queue1;                                    \
        STRUCTS::QueueType<T> queue2;                                    \
        queue1.enqueue(enqueueValue(1));                                 \
        queue1.enqueue(enqueueValue(2));                                 \
        queue2.enqueue(enqueueValue(1));                                 \
        queue2.enqueue(enqueueValue(2));                                 \
        EXPECT_TRUE(queue1 == queue2);                                   \
        queue2.enqueue(enqueueValue(3));                                 \
        EXPECT_FALSE(queue1 == queue2);                                  \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, InequalityOperator) {                   \
        STRUCTS::QueueType<T> queue1;                                    \
        STRUCTS::QueueType<T> queue2;                                    \
        queue1.enqueue(enqueueValue(1));                                 \
        queue1.enqueue(enqueueValue(2));                                 \
        queue2.enqueue(enqueueValue(1));                                 \
        queue2.enqueue(enqueueValue(2));                                 \
        EXPECT_FALSE(queue1 != queue2);                                  \
        queue2.enqueue(enqueueValue(3));                                 \
        EXPECT_TRUE(queue1 != queue2);                                   \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, StreamInsertionOperator) {              \
        STRUCTS::QueueType<T> queue;                                     \
        queue.enqueue(enqueueValue(1));                                  \
        queue.enqueue(enqueueValue(2));                                  \
        queue.enqueue(enqueueValue(3));                                  \
        std::stringstream ss;                                            \
        ss << queue;                                                     \
        EXPECT_EQ(ss.str(), expectedOutput);                             \
    }                                                                    \
                                                                         \
    TEST(QueueType##_##T##_Test, LargeEnqueueDequeue) {                  \
        STRUCTS::QueueType<T> queue;                                     \
        for (int i = 0; i < 1000; ++i) {                                 \
            queue.enqueue(enqueueValue(i));                              \
        }                                                                \
        EXPECT_EQ(queue.getSize(), 1000);                                \
        for (int i = 0; i < 1000; ++i) {                                 \
            EXPECT_EQ(queue.front(), enqueueValue(i));                   \
            queue.dequeue();                                             \
        }                                                                \
        EXPECT_TRUE(queue.isEmpty());                                    \
    }

QUEUE_TESTS_TEMPLATE(ArrayQueue, int, [](int value) { return value; }, "1 2 3 ")
QUEUE_TESTS_TEMPLATE(LinkedListQueue, int, [](int value) { return value; }, "1 2 3 ")

QUEUE_TESTS_TEMPLATE(ArrayQueue, StringAlias, [](int value) { return std::to_string(value); }, "1 2 3 ")
QUEUE_TESTS_TEMPLATE(LinkedListQueue, StringAlias, [](int value) { return std::to_string(value); }, "1 2 3 ")

QUEUE_TESTS_TEMPLATE(ArrayQueue, Person, [](int value) { return Person("Person" + std::to_string(value), value); }, "Person1 (1) Person2 (2) Person3 (3) ")
QUEUE_TESTS_TEMPLATE(LinkedListQueue, Person, [](int value) { return Person("Person" + std::to_string(value), value); }, "Person1 (1) Person2 (2) Person3 (3) ")
