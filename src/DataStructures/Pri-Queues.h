//
// Created by yehia on 12/8/2023.
//

#ifndef EASYTRIPBUSCOMPANY_PRI_QUEUES_H
#define EASYTRIPBUSCOMPANY_PRI_QUEUES_H

#include "Node.h"
template <typename T>

class priorityQueue
{
private:
    Node<T>* front;
    int count;
public:
    priorityQueue():front(nullptr){}
    Node<T>* getFront()
    {
        return front;
    }

    void enqueue(T data , int priority)
    {
        Node<T>* newNode = new Node<T>(data, priority);
        if (front == nullptr || priority > front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node<T> *temp;
            temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        count++;

    }
    void dequeue()
    {
        if (front == nullptr)
        {
            return;
        }
        else if (front != nullptr)
        {
            Node<T>* temp;
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

};

#endif //EASYTRIPBUSCOMPANY_PRI_QUEUES_H
