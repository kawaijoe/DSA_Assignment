/*
 *  ____       _____       _____
 * /\  _`\    /|  _ \     /\___ \
 * \ \ \/\ \  |/\   |     \/__/\ \
 *  \ \ \ \ \  \// __`\/\    _\ \ \
 *   \ \ \_\ \ /|  \L>  <_  /\ \_\ \
 *    \ \____/ | \_____/\/  \ \____/
 *     \/___/   \/____/\/    \/___/
 *
 * Team Member:
 *  David Chew En-Lai   -   S10173143G
 *  Joe Kawai           -   S10166858B
 *
 * Features:
 *  Template
 *  Destructor Implemented
 *
 */

#include "Queue.h"

using namespace std;

/*
 * Queue()
 *
 * Description:
 *  Constructor
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  NIL
 */
template <class T>
Queue<T>::Queue() {
    frontNode = nullptr;
    backNode = nullptr;
}

/*
 * ~Queue()
 *
 * Description:
 *  Destructor
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  NIL
 */
template <class T>
Queue<T>::~Queue() {
    Node *temp;
    while(frontNode) {
        temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}

/*
 * enqueue(T item)
 *
 * Description:
 *  Enqueue a new item to the queue. Return true upon success.
 *
 * Input Parameter:
 *  T item
 *
 * Return Value:
 *  bool
 */
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

/*
 * dequeue()
 *
 * Description:
 *  Dequeue an item from the queue. Return true upon success.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  bool
 */
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

/*
 * getFront()
 *
 * Description:
 *  Get the front node's item if the queue is not empty.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  T
 */
template <class T>
T Queue<T>::getFront() {
    if(!isEmpty())
        return frontNode->item;
}

/*
 * isEmpty()
 *
 * Description:
 *  Checks if the queue is empty. Returns true if there are no nodes in queue.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  bool
 */
template <class T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

/*
 * Queue()
 *
 * Description:
 *  Display all items current in queue from the oldest to the newest added item.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  void
 */
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

/*
 * Queue()
 *
 * Description:
 *  Returns the back node.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  Node
 */
template <class T>
class Queue<T>::Node *Queue<T>::getBackNode() const {
    return backNode;
}

/*
 * getNoOfElements()
 *
 * Description:
 *  Returns the total number of elements currently stored in a queue
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  int
 */
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
