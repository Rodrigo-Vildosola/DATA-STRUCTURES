#include <gtest/gtest.h>
#include <Structs.h>
#include <sstream>
#include <climits>

TEST(BinaryTreeTest, InsertAndSearch) {
    STRUCTS::BinaryTree<int> bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);

    EXPECT_TRUE(bt.search(10));
    EXPECT_TRUE(bt.search(20));
    EXPECT_TRUE(bt.search(5));
    EXPECT_FALSE(bt.search(15));
}

TEST(BinaryTreeTest, Remove) {
    STRUCTS::BinaryTree<int> bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.remove(10);

    EXPECT_FALSE(bt.search(10));
    EXPECT_TRUE(bt.search(20));
    EXPECT_TRUE(bt.search(5));
}

TEST(BinaryTreeTest, Height) {
    STRUCTS::BinaryTree<int> bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(4);
    bt.insert(6);

    EXPECT_EQ(bt.height(), 2);
}

TEST(BinaryTreeTest, Traversal) {
    STRUCTS::BinaryTree<int> bt;

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
    STRUCTS::BinaryTree<int> bt;

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
    STRUCTS::BinaryTree<int> bt;

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
    STRUCTS::BinaryTree<int> bt;

    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(4);
    bt.insert(6);

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    // Traverse to find min and max
    bt.traverse([&minValue, &maxValue](const int& value) {
        if (value < minValue) minValue = value;
        if (value > maxValue) maxValue = value;
    });

    EXPECT_EQ(minValue, 4);
    EXPECT_EQ(maxValue, 20);

    bt.remove(20);
    bt.remove(4);

    minValue = INT_MAX;
    maxValue = INT_MIN;

    bt.traverse([&minValue, &maxValue](const int& value) {
        if (value < minValue) minValue = value;
        if (value > maxValue) maxValue = value;
    });

    EXPECT_EQ(minValue, 5);
    EXPECT_EQ(maxValue, 10);
}

TEST(BinaryTreeTest, StringBinaryTree) {
    STRUCTS::BinaryTree<std::string> bt;

    bt.insert("banana");
    bt.insert("apple");
    bt.insert("cherry");

    EXPECT_TRUE(bt.search("apple"));
    EXPECT_TRUE(bt.search("banana"));
    EXPECT_TRUE(bt.search("cherry"));
    EXPECT_FALSE(bt.search("date"));

    // Test inorder traversal
    testing::internal::CaptureStdout();
    bt.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple banana cherry ");

    // Test preorder traversal
    testing::internal::CaptureStdout();
    bt.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Preorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "banana apple cherry ");

    // Test postorder traversal
    testing::internal::CaptureStdout();
    bt.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Postorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple cherry banana ");
}

TEST(BinaryTreeTest, MapStringBinaryTree) {
    STRUCTS::BinaryTree<std::string> bt;

    bt.insert("banana");
    bt.insert("apple");
    bt.insert("cherry");

    // Append " fruit" to each string
    bt.map([](std::string value) { return value + " fruit"; });

    // Test inorder traversal after mapping
    testing::internal::CaptureStdout();
    bt.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple fruit banana fruit cherry fruit ");

    EXPECT_TRUE(bt.search("apple fruit"));
    EXPECT_TRUE(bt.search("banana fruit"));
    EXPECT_TRUE(bt.search("cherry fruit"));
    EXPECT_FALSE(bt.search("date"));
}
