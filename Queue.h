//
// Created by David on 19/01/2018.
//

#ifndef DSA_ASSIGNMENT_QUEUE_H
#define DSA_ASSIGNMENT_QUEUE_H


#include "BinaryNode.h"

typedef BinaryNode* QItemType;
/** ADT queue - Pointer-based implementation. */
class Queue {
protected:
    /** A node on the queue. */
    struct Node {
        /** A data item on the queue. */
        QItemType item;
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

    bool enqueue(BinaryNode *item);

    bool dequeue();

    bool dequeue(QItemType &item);

    void getFront(QItemType &item);

    void displayItems();
};
#endif //DSA_ASSIGNMENT_QUEUE_H
