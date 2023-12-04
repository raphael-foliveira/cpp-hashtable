#include "../include/node.hpp"

Node::Node(const char* key, int val) : key(key), value(val), next(nullptr) {}

Node::~Node() {
    if (next != nullptr) {
        delete next;
    }
    delete key;
}

Node::Node(const Node& other) {}

const char* Node::getKey() {
    return key;
}

void Node::setKey(const char* newKey) {
    key = newKey;
}

int Node::getValue() {
    return value;
}

void Node::setValue(int newValue) {
    value = newValue;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* newNext) {
    next = newNext;
}