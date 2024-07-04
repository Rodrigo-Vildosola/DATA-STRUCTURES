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

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    std::cout << "Inorder Traversal: ";
    bt.inorder();
    std::cout << "Preorder Traversal: ";
    bt.preorder();
    std::cout << "Postorder Traversal: ";
    bt.postorder();
}

