#include <iostream>
#include <Structs.h>

namespace STRUCTS {

}

void testHashTableInsert() {
    std::cout << "Testing HashTable Insert..." << std::endl;

    STRUCTS::HashTable hashTable(10);

    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    std::cout << "Inserted key-value pairs: (1, 10), (2, 20), (3, 30)" << std::endl;
}

void testHashTableSearch() {
    std::cout << "Testing HashTable Search..." << std::endl;

    STRUCTS::HashTable hashTable(10);

    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    std::cout << "Value for key 1: " << hashTable.search(1) << std::endl;
    std::cout << "Value for key 2: " << hashTable.search(2) << std::endl;
    std::cout << "Value for key 3: " << hashTable.search(3) << std::endl;

    try {
        hashTable.search(4);
    } catch (const std::runtime_error& e) {
        std::cout << "Search for key 4: " << e.what() << std::endl;
    }
}

void testHashTableRemove() {
    std::cout << "Testing HashTable Remove..." << std::endl;

    STRUCTS::HashTable hashTable(10);

    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);

    hashTable.remove(2);

    std::cout << "Removed key 2. Searching for key 2 should throw an error." << std::endl;

    try {
        hashTable.search(2);
    } catch (const std::runtime_error& e) {
        std::cout << "Search for key 2: " << e.what() << std::endl;
    }
}

void testHashTableContains() {
    std::cout << "Testing HashTable Contains..." << std::endl;

    STRUCTS::HashTable hashTable(10);

    hashTable.insert(1, 10);
    hashTable.insert(2, 20);

    std::cout << "HashTable contains key 1: " << (hashTable.contains(1) ? "Yes" : "No") << std::endl;
    std::cout << "HashTable contains key 2: " << (hashTable.contains(2) ? "Yes" : "No") << std::endl;
    std::cout << "HashTable contains key 3: " << (hashTable.contains(3) ? "Yes" : "No") << std::endl;
}

void testHashTableResize() {
    std::cout << "Testing HashTable Resize..." << std::endl;

    STRUCTS::HashTable hashTable(2);

    for (int i = 0; i < 10; ++i) {
        std::cout << "Size: " << hashTable.getSize() << " Capacity: " << hashTable.getCapacity() << std::endl;
        hashTable.insert(i, i * 10);
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << "Key: " << i << ", Value: " << hashTable.search(i) << std::endl;
    }
}

void testHashTableOperators() {
    std::cout << "Testing HashTable Operators..." << std::endl;

    STRUCTS::HashTable hashTable1(10);
    STRUCTS::HashTable hashTable2(10);

    hashTable1.insert(1, 10);
    hashTable1.insert(2, 20);
    hashTable2.insert(1, 10);
    hashTable2.insert(2, 20);

    std::cout << "HashTable1 == HashTable2: " << (hashTable1 == hashTable2 ? "True" : "False") << std::endl;

    hashTable2.insert(3, 30);

    std::cout << "HashTable1 == HashTable2 after modification: " << (hashTable1 == hashTable2 ? "True" : "False") << std::endl;

    hashTable1[3] = 30;
    // hashTable1[4] = 40;

    std::cout << "HashTable1[4]: " << hashTable1[4] << std::endl;
    std::cout << "HashTable1 == HashTable2 after using subscript operator: " << (hashTable1 == hashTable2 ? "True" : "False") << std::endl;
}

int main() {
    testHashTableInsert();
    std::cout << std::endl;

    testHashTableSearch();
    std::cout << std::endl;

    testHashTableRemove();
    std::cout << std::endl;

    testHashTableContains();
    std::cout << std::endl;

    testHashTableResize();
    std::cout << std::endl;

    testHashTableOperators();

    return 0;
}
