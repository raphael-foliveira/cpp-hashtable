#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    const char* key;
    int value;
    Node* next;

public:
    Node(const char* key, int value);

    ~Node();

    Node(const Node& other);

    Node& operator=(const Node& rhs);

    const char* getKey();

    void setKey(const char* newKey);

    int getValue();

    void setValue(int newValue);

    Node* getNext();

    void setNext(Node* newNext);
};

#endif