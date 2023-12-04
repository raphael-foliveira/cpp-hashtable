#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include "./node.hpp"

class HashTable {
private:
    Node** arr;

    int length;

    int hash(const char* key);

    bool checkConflict(int hashKey);

public:
    HashTable();

    ~HashTable();

    HashTable(const HashTable& other);

    void put(const char* key, int value);

    bool get(const char* key, int& target);

    bool exists(const char* key);
};


#endif