//
// Created by David on 19/01/2018.
//
#include <iostream>

using namespace std;

#include "Queue.h"

Queue::Queue() = default;;


Queue::~Queue() = default;;

bool Queue::enqueue(QItemType item) {

    auto * newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if (isEmpty()) {
        frontNode = newNode;
        backNode = newNode;
    }
    else {
        backNode->next = newNode;
        backNode = newNode;
    }
    return true;
}

bool Queue::dequeue() {
    auto * temp = new Node;
    temp = frontNode;
    frontNode = frontNode->next;

    delete temp;
    return true;

}

bool Queue::dequeue(QItemType& item) {
    auto * temp = new Node;
    temp = frontNode;
    item = temp->item;
    frontNode = frontNode->next;

    delete temp;
    return true;
}

bool Queue::isEmpty() { return frontNode == nullptr && backNode == nullptr; }

void Queue::getFront(QItemType& item) { item = frontNode->item; }

void Queue::displayItems() {
    Node* temp = frontNode;
    while (temp != nullptr) {
        cout << temp->item << endl;
        temp = temp->next;
    }
}



