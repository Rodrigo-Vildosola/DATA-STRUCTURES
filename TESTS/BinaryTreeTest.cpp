#include <gtest/gtest.h>
#include <Structs.h>

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
    std::stringstream ss;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    // std::cout << "Inorder Traversal: ";
    // bt.inorder();
    // std::cout << "Preorder Traversal: ";
    // bt.preorder();
    // std::cout << "Postorder Traversal: ";
    // bt.postorder();

    // Test inorder traversal
    testing::internal::CaptureStdout();
    bt.inorder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 10 20 \n");

    // Test preorder traversal
    testing::internal::CaptureStdout();
    bt.preorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 5 20 \n");

    // Test postorder traversal
    testing::internal::CaptureStdout();
    bt.postorder();
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 20 10 \n");
}

TEST(BinaryTreeTest, Traverse) {
    STRUCTS::BinaryTree bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    // Multiply each node's value by 2
    bt.traverse([](int& value) { value *= 2; });

    EXPECT_TRUE(bt.search(20));  // Original 10
    EXPECT_TRUE(bt.search(40));  // Original 20
    EXPECT_TRUE(bt.search(10));  // Original 5
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

