#include "../include/hash_table.hpp"
#include "../include/node.hpp"
#include <iostream>
#include "string.h"

int TABLE_SIZE = 10;

HashTable::HashTable() : arr(new Node* [TABLE_SIZE]), length(TABLE_SIZE) {}

HashTable::~HashTable() {
    delete[] arr;
}

HashTable::HashTable(const HashTable& other) {
    for (int i = 0; i < other.length; i++) {
        arr[i] = other.arr[i];
    }
}

int HashTable::hash(const char* key) {
    int sum = 0;
    while (strcmp(key, "\0") != 0) {
        sum += *key++;
    }
    return sum % TABLE_SIZE;
}

bool HashTable::exists(const char* key) {
    int hashKey = hash(key);
    Node* node = arr[hashKey];
    while (node != nullptr) {
        if (node->getKey() == key) {
            return true;
        }
        node = node->getNext();
    }
    return false;
}

bool HashTable::checkConflict(int hashKey) {
    Node* node = arr[hashKey];
    return node != nullptr;
}

bool HashTable::get(const char* key, int& target) {
    int hashKey = hash(key);
    Node* node = arr[hashKey];
    while (node != nullptr) {
        if (node->getKey() == key) {
            target = node->getValue();
            return true;
        }
        node = node->getNext();
    }
    return false;
}

void HashTable::put(const char* key, int value) {
    Node* node = new Node(key, value);
    int hashKey = hash(key);
    if (!checkConflict(hashKey)) {
        arr[hashKey] = node;
        return;
    }
    Node* current = arr[hashKey];
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }
    current->setNext(node);
}

