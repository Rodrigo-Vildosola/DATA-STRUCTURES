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
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, DequeueEmptyQueue) {                           \
        STRUCTS::QueueType queue;                                        \
        EXPECT_THROW(queue.dequeue(), std::out_of_range);                \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, FrontEmptyQueue) {                             \
        STRUCTS::QueueType queue;                                        \
        EXPECT_THROW(queue.front(), std::out_of_range);                  \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, LargeEnqueueDequeue) {                         \
        STRUCTS::QueueType queue;                                        \
        for (int i = 0; i < 1000; ++i) {                                 \
            queue.enqueue(i);                                            \
        }                                                                \
        EXPECT_EQ(queue.getSize(), 1000);                                \
        for (int i = 0; i < 1000; ++i) {                                 \
            EXPECT_EQ(queue.front(), i);                                 \
            queue.dequeue();                                             \
        }                                                                \
        EXPECT_TRUE(queue.isEmpty());                                    \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, CopyConstructor) {                             \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        STRUCTS::QueueType queueCopy(queue);                             \
        EXPECT_EQ(queueCopy.front(), 1);                                 \
        queueCopy.dequeue();                                             \
        EXPECT_EQ(queueCopy.front(), 2);                                 \
        queueCopy.dequeue();                                             \
        EXPECT_TRUE(queueCopy.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, CopyAssignment) {                              \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        STRUCTS::QueueType queueCopy;                                    \
        queueCopy = queue;                                               \
        EXPECT_EQ(queueCopy.front(), 1);                                 \
        queueCopy.dequeue();                                             \
        EXPECT_EQ(queueCopy.front(), 2);                                 \
        queueCopy.dequeue();                                             \
        EXPECT_TRUE(queueCopy.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, MoveConstructor) {                             \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        STRUCTS::QueueType queueMove(std::move(queue));                  \
        EXPECT_EQ(queueMove.front(), 1);                                 \
        queueMove.dequeue();                                             \
        EXPECT_EQ(queueMove.front(), 2);                                 \
        queueMove.dequeue();                                             \
        EXPECT_TRUE(queueMove.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, MoveAssignment) {                              \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        STRUCTS::QueueType queueMove;                                    \
        queueMove = std::move(queue);                                    \
        EXPECT_EQ(queueMove.front(), 1);                                 \
        queueMove.dequeue();                                             \
        EXPECT_EQ(queueMove.front(), 2);                                 \
        queueMove.dequeue();                                             \
        EXPECT_TRUE(queueMove.isEmpty());                                \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, EqualityOperator) {                            \
        STRUCTS::QueueType queue1;                                       \
        STRUCTS::QueueType queue2;                                       \
        queue1.enqueue(1);                                               \
        queue1.enqueue(2);                                               \
        queue2.enqueue(1);                                               \
        queue2.enqueue(2);                                               \
        EXPECT_TRUE(queue1 == queue2);                                   \
        queue2.enqueue(3);                                               \
        EXPECT_FALSE(queue1 == queue2);                                  \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, InequalityOperator) {                          \
        STRUCTS::QueueType queue1;                                       \
        STRUCTS::QueueType queue2;                                       \
        queue1.enqueue(1);                                               \
        queue1.enqueue(2);                                               \
        queue2.enqueue(1);                                               \
        queue2.enqueue(2);                                               \
        EXPECT_FALSE(queue1 != queue2);                                  \
        queue2.enqueue(3);                                               \
        EXPECT_TRUE(queue1 != queue2);                                   \
    }                                                                    \
                                                                         \
    TEST(QueueType##Test, StreamInsertionOperator) {                     \
        STRUCTS::QueueType queue;                                        \
        queue.enqueue(1);                                                \
        queue.enqueue(2);                                                \
        queue.enqueue(3);                                                \
        std::stringstream ss;                                            \
        ss << queue;                                                     \
        EXPECT_EQ(ss.str(), "1 2 3 ");                                   \
    }

QUEUE_TESTS(ArrayQueue)
QUEUE_TESTS(LinkedListQueue)
