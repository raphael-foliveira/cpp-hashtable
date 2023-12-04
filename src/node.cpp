#include "../include/node.hpp"

Node::Node(const char* key, int val) : key(key), value(val), next(nullptr) {}

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