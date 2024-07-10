### Basic Binary Trees
1. **Binary Tree**:
   - A tree data structure in which each node has at most two children, referred to as the left child and the right child.

### Self-Balancing Binary Search Trees
2. **AVL Tree**:
   - A self-balancing binary search tree where the difference in heights between left and right subtrees is at most one for all nodes.
   - Provides O(log n) time complexity for search, insert, and delete operations.

3. **Red-Black Tree**:
   - A self-balancing binary search tree where each node contains an extra bit for denoting the color of the node, either red or black.
   - Ensures the tree remains balanced with fewer rotations compared to AVL trees.
   - Commonly used in implementations of associative containers like maps and sets.

### Heaps
4. **Binary Heap**:
   - A complete binary tree which satisfies the heap property.
   - Two types: Min-Heap (parent nodes are smaller than their children) and Max-Heap (parent nodes are larger than their children).
   - Primarily used to implement priority queues.

5. **Binomial Heap**:
   - A collection of binomial trees that are linked together.
   - Allows efficient merging of two heaps.
   - Used in implementing priority queues.

6. **Fibonacci Heap**:
   - A collection of trees that are not necessarily binomial trees.
   - Allows more efficient amortized operations compared to binary heaps and binomial heaps.

### Trie
7. **Trie (Prefix Tree)**:
   - A tree-like data structure that stores a dynamic set of strings, where keys are usually strings.
   - Each node represents a common prefix of some strings.
   - Used in applications like auto-completion and spell-checking.

### Specialized Binary Trees
8. **Splay Tree**:
   - A self-adjusting binary search tree where recently accessed elements are moved to the root.
   - Useful for sequences of operations where the same elements are frequently accessed.

9. **Treap**:
   - A combination of a binary search tree and a heap.
   - Each node has a priority, and the tree maintains both the binary search tree property and the heap property.

10. **Tango Tree**:
    - A type of binary search tree that is designed to perform well on access sequences with locality of reference.
    - It achieves O(log log n) competitive ratio for searches.

### Segment and Interval Trees
11. **Segment Tree**:
    - A binary tree used for storing intervals or segments.
    - Allows querying which of the stored segments overlap with a given point or interval efficiently.

12. **Interval Tree**:
    - A type of binary search tree used to hold intervals and allows efficient querying of all intervals that overlap with a given interval or point.

### Cartesian Tree
13. **Cartesian Tree**:
    - A binary tree derived from a sequence of numbers, where the tree is a heap with respect to the values and an in-order traversal gives the original sequence.
    - Used in range-minimum queries.

### K-D Tree
14. **k-d Tree (k-dimensional tree)**:
    - A space-partitioning data structure for organizing points in a k-dimensional space.
    - Used in applications such as range searches and nearest neighbor searches.

### Binary Indexed Tree
15. **Binary Indexed Tree (Fenwick Tree)**:
    - A data structure that provides efficient methods for calculation and manipulation of the prefix sums of a table of values.
    - Used in applications like cumulative frequency tables.

### Order Statistic Tree
16. **Order Statistic Tree**:
    - A binary search tree that supports order statistics operations, such as finding the k-th smallest element.
    - Commonly implemented as an augmented Red-Black Tree.

