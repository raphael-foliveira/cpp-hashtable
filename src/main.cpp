#include <iostream>
#include <string>
#include "../include/node.hpp"
#include "../include/hash_table.hpp"

int main() {
    HashTable hashTable = HashTable();
    hashTable.put("foo", 12);
    hashTable.put("fii", 65);
    hashTable.put("bar", 15);
    int foo;
    int fii;
    int bar;

    bool result = hashTable.remove("foo");
    std::cout << result << "\n";
    if (hashTable.get("foo", foo)) {
        std::cout << foo << "\n";
    }
    if (hashTable.get("fii", fii)) {
        std::cout << fii << "\n";
    }
    if (hashTable.get("bar", bar)) {
        std::cout << bar << "\n";
    }

    return 0;
}