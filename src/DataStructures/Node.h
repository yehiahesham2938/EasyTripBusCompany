#ifndef EASYTRIPBUSCOMPANY_NODE_H
#define EASYTRIPBUSCOMPANY_NODE_H

template <typename T>
class Node {
public:
    T data;
    int priority;
    Node* next;

    Node(T& data, int priority) : data(data), priority(priority), next(nullptr) {}

    Node<T>* getNext() const {
        return next;
    }

    void setNext(Node<T>* Next) {
        next = Next;
    }

    T getData() const {
        return data;
    }
};

#endif //EASYTRIPBUSCOMPANY_NODE_H
