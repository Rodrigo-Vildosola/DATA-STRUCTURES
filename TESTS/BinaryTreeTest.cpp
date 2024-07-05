#include <gtest/gtest.h>
#include <Structs.h>
#include <sstream>

TEST(BinaryTreeTest, InsertAndSearch) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    EXPECT_TRUE(bt.search(10));
    EXPECT_TRUE(bt.search(20));
    EXPECT_TRUE(bt.search(5));
    EXPECT_FALSE(bt.search(15));
}

TEST(BinaryTreeTest, Remove) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.remove(10);

    EXPECT_FALSE(bt.search(10));
    EXPECT_TRUE(bt.search(20));
    EXPECT_TRUE(bt.search(5));
}

TEST(BinaryTreeTest, FindMinMax) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    EXPECT_EQ(bt.findMin(), 5);
    EXPECT_EQ(bt.findMax(), 20);
}

TEST(BinaryTreeTest, Height) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(4);
    bt.insert(6);

    EXPECT_EQ(bt.height(), 2);
}

TEST(BinaryTreeTest, Traversal) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    // Test inorder traversal
    testing::internal::CaptureStdout();
    bt.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 10 20 ");

    // Test preorder traversal
    testing::internal::CaptureStdout();
    bt.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Preorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 5 20 ");

    // Test postorder traversal
    testing::internal::CaptureStdout();
    bt.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Postorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 20 10 ");
}

TEST(BinaryTreeTest, Map) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    // Multiply each node's value by 2
    bt.map([](int value) { return value * 2; });

    // Test inorder traversal after mapping
    testing::internal::CaptureStdout();
    bt.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 40 ");

    EXPECT_TRUE(bt.search(20));  // Original 10 -> 20
    EXPECT_TRUE(bt.search(40));  // Original 20 -> 40
    EXPECT_TRUE(bt.search(10));  // Original 5 -> 10
}

TEST(BinaryTreeTest, SizeAndHeightAfterOperations) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(4);
    bt.insert(6);

    EXPECT_EQ(bt.size(), 5);
    EXPECT_EQ(bt.height(), 2);

    bt.remove(20);
    bt.remove(10);

    EXPECT_EQ(bt.size(), 3);
    EXPECT_EQ(bt.height(), 1);
}

TEST(BinaryTreeTest, MinMaxAfterOperations) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(4);
    bt.insert(6);

    EXPECT_EQ(bt.findMin(), 4);
    EXPECT_EQ(bt.findMax(), 20);

    bt.remove(20);
    bt.remove(4);

    EXPECT_EQ(bt.findMin(), 5);
    EXPECT_EQ(bt.findMax(), 10);
}
