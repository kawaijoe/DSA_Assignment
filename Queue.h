//
// Created by David on 19/01/2018.
//

#ifndef DSA_ASSIGNMENT_QUEUE_H
#define DSA_ASSIGNMENT_QUEUE_H


#include "BinaryNode.h"

/** ADT queue - Pointer-based implementation. */
class Queue {
private:
    /** A node on the queue. */
    struct Node {
        /** A data item on the queue. */
        ItemType item;
        /** Pointer to next node.     */
        Node *next;
    }; // end Node

    /** Pointer to front node in the queue. */
    Node *frontNode;
    /** Pointer to back node in the queue. */
    Node *backNode;

public:

    /** Default constructor. */
    Queue();

    /** Destructor. */
    ~Queue();

    // Queue operations:
    bool isEmpty();

    bool enqueue(ItemType item);

    bool dequeue();

    bool dequeue(ItemType &item);

    void getFront(ItemType &item);

    void displayItems();
};
#endif //DSA_ASSIGNMENT_QUEUE_H
