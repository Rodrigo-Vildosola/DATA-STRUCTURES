#include <gtest/gtest.h>
#include <Structs.h>
#include <sstream>
#include <climits>

TEST(BSTTest, InsertAndSearch) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);

    EXPECT_TRUE(bst.search(10));
    EXPECT_TRUE(bst.search(20));
    EXPECT_TRUE(bst.search(5));
    EXPECT_FALSE(bst.search(15));
}

TEST(BSTTest, Remove) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.remove(10);

    EXPECT_FALSE(bst.search(10));
    EXPECT_TRUE(bst.search(20));
    EXPECT_TRUE(bst.search(5));
}

TEST(BSTTest, Height) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);

    EXPECT_EQ(bst.getHeight(), 2);
}

TEST(BSTTest, Traversal) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);

    // Test inorder traversal
    testing::internal::CaptureStdout();
    bst.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 10 20 ");

    // Test preorder traversal
    testing::internal::CaptureStdout();
    bst.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Preorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 5 20 ");

    // Test postorder traversal
    testing::internal::CaptureStdout();
    bst.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Postorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "5 20 10 ");
}

TEST(BSTTest, Map) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);

    // Multiply each node's value by 2
    bst.map([](int value) { return value * 2; });

    // Test inorder traversal after mapping
    testing::internal::CaptureStdout();
    bst.traverse([](const int& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "10 20 40 ");

    EXPECT_TRUE(bst.search(20));  // Original 10 -> 20
    EXPECT_TRUE(bst.search(40));  // Original 20 -> 40
    EXPECT_TRUE(bst.search(10));  // Original 5 -> 10
}

TEST(BSTTest, SizeAndHeightAfterOperations) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);

    EXPECT_EQ(bst.getSize(), 5);
    EXPECT_EQ(bst.getHeight(), 2);

    bst.remove(20);
    bst.remove(10);

    EXPECT_EQ(bst.getSize(), 3);
    EXPECT_EQ(bst.getHeight(), 1);
}

TEST(BSTTest, MinMaxAfterOperations) {
    STRUCTS::BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);

    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    // Traverse to find min and max
    bst.traverse([&minValue, &maxValue](const int& value) {
        if (value < minValue) minValue = value;
        if (value > maxValue) maxValue = value;
    });

    EXPECT_EQ(minValue, 4);
    EXPECT_EQ(maxValue, 20);

    bst.remove(20);
    bst.remove(4);

    minValue = INT_MAX;
    maxValue = INT_MIN;

    bst.traverse([&minValue, &maxValue](const int& value) {
        if (value < minValue) minValue = value;
        if (value > maxValue) maxValue = value;
    });

    EXPECT_EQ(minValue, 5);
    EXPECT_EQ(maxValue, 10);
}

TEST(BSTTest, StringBinarySearchTree) {
    STRUCTS::BinarySearchTree<std::string> bst;

    bst.insert("banana");
    bst.insert("apple");
    bst.insert("cherry");

    EXPECT_TRUE(bst.search("apple"));
    EXPECT_TRUE(bst.search("banana"));
    EXPECT_TRUE(bst.search("cherry"));
    EXPECT_FALSE(bst.search("date"));

    // Test inorder traversal
    testing::internal::CaptureStdout();
    bst.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple banana cherry ");

    // Test preorder traversal
    testing::internal::CaptureStdout();
    bst.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Preorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "banana apple cherry ");

    // Test postorder traversal
    testing::internal::CaptureStdout();
    bst.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Postorder);
    output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple cherry banana ");
}

TEST(BSTTest, MapStringBinarySearchTree) {
    STRUCTS::BinarySearchTree<std::string> bst;

    bst.insert("banana");
    bst.insert("apple");
    bst.insert("cherry");

    // Append " fruit" to each string
    bst.map([](const std::string& value) { return value + " fruit"; });

    // Test inorder traversal after mapping
    testing::internal::CaptureStdout();
    bst.traverse([](const std::string& value) { std::cout << value << " "; }, STRUCTS::TraversalType::Inorder);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "apple fruit banana fruit cherry fruit ");

    EXPECT_TRUE(bst.search("apple fruit"));
    EXPECT_TRUE(bst.search("banana fruit"));
    EXPECT_TRUE(bst.search("cherry fruit"));
    EXPECT_FALSE(bst.search("date"));
}
