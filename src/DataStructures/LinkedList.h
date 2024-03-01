
#include "Node.h"
#include "../Buses.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T> *Head;

public:


    LinkedList() {
        Head = nullptr;
    }


    ~LinkedList() {
        DeleteAll();
    }

    void insert( T &data) {
        Node<T> *newNode = new Node<T>(data,0);
        if (!Head) {
            Head = newNode;
        } else {
            Node<T> *current = Head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    void DeleteAll() {
        Node<T> *P = Head;
        while (Head) {
            P = Head->getNext();
            delete Head;
            Head = P;
        }
    }

    Node<T>* getHead() const {
        return Head;

    }



};