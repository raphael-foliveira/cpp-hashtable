#include "../include/hash_table.hpp"
#include "../include/node.hpp"
#include "string.h"

int TABLE_SIZE = 10;

HashTable::HashTable() : arr(new Node* [TABLE_SIZE]), length(TABLE_SIZE) {}

HashTable::~HashTable() {
    delete[] arr;
}

HashTable::HashTable(const HashTable& other) {
    for (int i = 0; i < other.length; i++) {
        if (other.arr[i] != nullptr) {
            arr[i] = new Node(*other.arr[i]);
        }
    }
}

HashTable& HashTable::operator=(const HashTable& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < rhs.length; i++) {
            if (rhs.arr[i] != nullptr) {
                arr[i] = new Node(*rhs.arr[i]);
            }
        }
    }
    return *this;
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
    if (arr[hashKey] == nullptr) {
        arr[hashKey] = node;
        return;
    }
    Node* current = arr[hashKey];
    while (current->getNext() != nullptr) {
        current = current->getNext();
    }
    current->setNext(node);
}

bool HashTable::remove(const char* key) {
    int hashKey = hash(key);
    Node* node = arr[hashKey];
    if (node == nullptr) {
        return false;
    }
    if (node->getKey() == key) {
        arr[hashKey] = node->getNext();
        return true;
    }
    while (node->getNext() != nullptr) {
        if (node->getNext()->getKey() == key) {
            Node* temp = node->getNext();
            node->setNext(temp->getNext());
            delete temp;
            return true;
        }
        node = node->getNext();
    }
    return false;
}