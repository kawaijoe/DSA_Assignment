//
// Created by Joe Kawai on 10/12/17.
//
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue() {
    frontNode = nullptr;
    backNode = nullptr;
}

template <class T>
Queue<T>::~Queue() {
    Node *temp;
    while(frontNode) {
        temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}

template <class T>
bool Queue<T>::enqueue(T item) {
    Node *newNode = new Node;
    newNode->item = item;
    newNode->next = nullptr;

    if(isEmpty()) {
        frontNode = newNode;
        backNode = newNode;
    } else {
        backNode->next = newNode;
        backNode = newNode;
    }
    return true;
}

template <class T>
bool Queue<T>::dequeue() {
    if(!isEmpty()) {
        Node *temp = frontNode;
        frontNode = temp->next;
        delete temp;
        return true;
    }
    return false;
}

template <class T>
T Queue<T>::getFront() {
    if(!isEmpty())
        return frontNode->item;
}

template <class T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

template <class T>
void Queue<T>::displayItems() {
    int count = 0;
    Node *temp = frontNode;
    while(temp) {
        cout << ++count << " - " << temp->item << endl;
        temp = temp->next;
    }
    cout << "---------------" << endl;
}

template <class T>
class Queue<T>::Node *Queue<T>::getBackNode() const {
    return backNode;
}

template <class T>
int Queue<T>::getNoOfElements() {
    int count = 0;
    Node *temp = frontNode;
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}
