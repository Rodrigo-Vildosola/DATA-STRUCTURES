#include <gtest/gtest.h>
#include <Structs.h>

// Helper macro to define queue tests for both implementations
#define QUEUE_TESTS(QueueType)                                           \
    TEST(QueueType##Test, EnqueueAndFront) {                             \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        EXPECT_EQ(queue.front(), 1);                                     \
        queue.enqueue(3);                                                \
        EXPECT_EQ(queue.front(), 1);                                     \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, Dequeue) {                                     \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        queue.dequeue();                                                 \
        EXPECT_EQ(queue.front(), 2);                                     \
        queue.dequeue();                                                 \
        EXPECT_TRUE(queue.isEmpty());                                    \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, IsEmpty) {                                     \
        STRUCTS::QueueType queue;                                        \
        EXPECT_TRUE(queue.isEmpty());                                    \
        queue.enqueue(1);                                                \
        EXPECT_FALSE(queue.isEmpty());                                   \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, GetSize) {                                     \
        STRUCTS::QueueType queue;                                        \
        EXPECT_EQ(queue.getSize(), 0);                                   \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        EXPECT_EQ(queue.getSize(), 2);                                   \
    }

QUEUE_TESTS(ArrayQueue)
QUEUE_TESTS(LinkedListQueue)
