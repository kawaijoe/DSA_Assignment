//
// Created by Joe Kawai on 10/12/17.
//

#ifndef DSA_ASSIGNMENT_QUEUE_H
#define DSA_ASSIGNMENT_QUEUE_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Queue {
private:
    struct Node {
        T item;
        Node *next;
    };

    Node *frontNode;
    Node *backNode;

public:
    Queue();

    ~Queue();

    bool isEmpty() const;

    bool enqueue(T item);

    bool dequeue();

    T getFront();

    void displayItems();

    int getNoOfElements();

    Node *getBackNode() const;
};

// Template workaround (Removed BST.cpp from CMakeLists.txt's add_executable())
#include "Queue.cpp"

#endif //DSA_ASSIGNMENT_QUEUE_H
