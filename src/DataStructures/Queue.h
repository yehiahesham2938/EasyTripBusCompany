//
// Created by yehia on 12/8/2023.
//

#ifndef EASYTRIPBUSCOMPANY_QUEUE_H
#define EASYTRIPBUSCOMPANY_QUEUE_H
#include "Node.h"
#include <iostream>

using namespace std;
class NormalPassenger;
class SpecialCategoriesPassengers;
class WheelchairPassengers;

template <typename T>
class Queue
        {
private:
    Node<T>* front;
    int count;

public:
    class Passenger;

    Queue() : front(nullptr) {}

    bool isEmpty()
    {
        return front == nullptr;
    }

    Node<T>* getFront()
    {
        return front;
    }

    void enqueue(T& data)
    {
        Node<T>* newNode = new Node<T>(data, 0);
        newNode->data = data;
        if (front == nullptr)
        {
            front = newNode;
        }
        else
        {
            Node<T>* temp = front;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        count++;
    }

    void dequeue()
    {
        if ( front == nullptr)
        {
            return;
        }
        else
        {
            Node<T> *temp;
            temp = front;
            front = front->next;
            delete temp;
        }
        count = count-1;
    }

    int getCount()
    {
        return count;
    }

    void display() {
        Node<T> *curr;
        curr = front;
        while (curr != nullptr) {
            cout << curr->data.getpassengerOnOffTime() << " ";
            cout << curr->data.getPassengerStartStation() << " ";
            cout << curr->data.getPassengerEndStation() << endl;
            curr = curr->next;
        }
    }



};

#endif //EASYTRIPBUSCOMPANY_QUEUE_H
