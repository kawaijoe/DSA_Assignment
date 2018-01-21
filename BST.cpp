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
 *  Adelson-Velsky and Landis(AVL) Binary Tree
 *  Template
 *  Printing of full tree
 *
 */

#include <cstdlib>
#include "BST.h"
#include "Queue.h"

using namespace std;

#define max(x, y) (((x) > (y)) ? (x) : (y))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * BST()
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
BST<T>::BST() {
    root = nullptr;
}

/*
 * ~BST()
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
BST<T>::~BST() = default;


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * search(T target)
 *
 * Description:
 *  search(BinaryNode<T> *t, T target) wrapper; automatically searching the entire root.
 *
 * Input Parameter:
 *  T target
 *
 * Return Value:
 *  BinaryNode<T>
 */
template <class T>
BinaryNode<T> *BST<T>::search(T target) {
    return search(root, target);
}

/*
 * search(BinaryNode<T> *t, T target)
 *
 * Description:
 *  Search for a particular target value. Returns value if found.
 *  It will also print root if the target is the root node. While transversing, the method will print 'L' and 'R'
 *  depending on the direction taken.
 *
 * Input Parameter:
 *  BinaryNode<T> *t
 *  T target
 *
 * Return Value:
 *  BinaryNode<T>
 */
template <class T>
BinaryNode<T> *BST<T>::search(BinaryNode<T> *t, T target) {
    if(!t) {
        // item Not Found
        return nullptr;
    } else {
        if(t->item == target) {
            if(root == t) cout << "root" << endl;
            return t;
        } else {
            if(t->item > target) {
                // search left subtree
                cout << "L" << endl;
                return search(t->left, target);
            } else {
                // search right subtree
                cout << "R" << endl;
                return search(t->right, target);
            }
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * insert(T item)
 *
 * Description:
 *  insert(BinaryNode<T> *&t, T item) wrapper; automatically adding value to the entire root tree.
 *
 * Input Parameter:
 *  T item
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::insert(T item) {
    if(search(item) == nullptr) {
        insert(root, item);
    } else {
        cout << "Unable to insert, item exist." << endl;
    }
}

/*
 * insert(BinaryNode<T> *&t, T item)
 *
 * Description:
 *  Insert an item into a binary tree.
 *
 * Input Parameter:
 *  BinaryNode<T> *&t
 *  T item
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::insert(BinaryNode<T> *&t, T item) {
    if(!t) {
        auto *newNode = new BinaryNode<T>;
        newNode->item = item;
        newNode->left = nullptr;
        newNode->right = nullptr;
        t = newNode;
    } else {
        if(item < t->item) {
            // item is less than centre
            insert(t->left, item);
        } else {
            // item is more than centre
            insert(t->right, item);
        }
        t = balance(t);
    }

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * remove(T item)
 *
 * Description:
 *  remove(BinaryNode<T> *&t, T item) wrapper; automatically searching the item in the root to be deleted.
 *
 * Input Parameter:
 *  T item
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::remove(T item) {
    if(search(item) != nullptr) {
        remove(root, item);
    } else {
        cout << "Unable to delete, item does not exist." << endl;
    }

}

/*
 * remove(BinaryNode<T> *&t, T item)
 *
 * Description:
 *  Delete an item from the binary search tree.
 *
 * Input Parameter:
 *  BinaryNode<T> *&t
 *  T item
 *
 * Return Value:
 *  BinaryNode<T>*
 */
template <class T>
BinaryNode<T> *BST<T>::remove(BinaryNode<T> *&t, T item) {
    if(root == nullptr) {
        // if there is the root of null
        return root;
    } else if(item < t->item) {
        // search for the node to be deleted in left subtree
        remove(t->left, item);
    } else if(item > t->item) {
        // search for the node to be deleted in right subtree
        remove(t->right, item);
    } else if(t->left && t->right) {
        // if found and have two children
        BinaryNode<T> *successor = t->left;
        while(successor->right != nullptr)
            successor = successor->right;

        // replace the node’s item with that of the successor
        T n = successor->item;

        // delete the successor (either case 1 or case 2)
        remove(t->left, n);

        // replace the node’s item with that of the successor
        t->item = n;
    } else {
        // if found and is leaf
        // set temp to be the node that is the child
        BinaryNode<T> *temp = t->left ? t->left : t->right;

        // No child case
        if(temp == nullptr) {
            temp = t;
            t = nullptr;
        } else {
            // One child case
            // Copy the contents of non-empty child to t
            *t = *temp;
        }
        // delete the node
        delete temp;
    }

    if(t == nullptr) return t;

    //balancing
    t = balance(t);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * inorder()
 *
 * Description:
 *  inorder(BinaryNode<T> *t) wrapper; automatically printing the item from the root node.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::inorder() {
    if(isEmpty()) {
        cout << "BST does not exist." << endl;
    } else {
        inorder(root);
    }
}

/*
 * inorder(BinaryNode<T> *t)
 *
 * Description:
 *  Traverse the tree in "inOrder" process (smallest to biggest).
 *
 * Input Parameter:
 *  BinaryNode<T> *t
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::inorder(BinaryNode<T> *t) {
    if(t) {
        inorder(t->left);
        cout << t->item << endl;
        inorder(t->right);
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * getHeight()
 *
 * Description:
 *  getHeight(BinaryNode<T> *t) wrapper; automatically getting height from the root node.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  int
 */
template <class T>
int BST<T>::getHeight() {
    return getHeight(root);
}

/*
 * getHeight(BinaryNode<T> *t)
 *
 * Description:
 *  Compute the height of the binary search tree.
 *
 * Input Parameter:
 *  BinaryNode<T> *t
 *
 * Return Value:
 *  int
 */
template <class T>
int BST<T>::getHeight(BinaryNode<T> *t) {
    if(t) return 1+max(getHeight(t->left), getHeight(t->right));
    return 0;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * isBalanced()
 *
 * Description:
 *  isBalanced(BinaryNode<T> *t) wrapper; automatically checking if the entire tree is balanced.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  bool
 */
template <class T>
bool BST<T>::isBalanced() {
    return isBalanced(root);
}

/*
 * isBalanced(BinaryNode<T> *t)
 *
 * Description:
 *  Check if the binary search tree is balanced.
 *
 * Input Parameter:
 *  BinaryNode<T> *t
 *
 * Return Value:
 *  bool
 */
template <class T>
bool BST<T>::isBalanced(BinaryNode<T> *t) {
    if(t) {
        int leftHeight = getHeight(t->left);
        int rightHeight = getHeight(t->right);
        bool isBalancedNode = ( abs(leftHeight-rightHeight) <= 1 );
        return ( isBalancedNode && isBalanced(t->left) && isBalanced(t->right));
    } else {
        return true;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * printLevelOrder()
 *
 * Description:
 *  printLevelOrder(BinaryNode<T> *root) wrapper; automatically print values from root node.
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::printLevelOrder() {
    printLevelOrder(root);
}

/*
 * printLevelOrder(BinaryNode<T> *root)
 *
 * Description:
 *  Print level-by-level traversal of items.
 *
 * Input Parameter:
 *  BinaryNode<T> *root
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::printLevelOrder(BinaryNode<T> *root) {
    // Base case
    if(root == nullptr)
        return;

    // Create an empty queue for level order transversal
    Queue<BinaryNode<T>> queue;

    // Enqueue root and initialize height
    queue.enqueue(*root);

    BinaryNode<T> node;
    while(!queue.isEmpty()) {
        // Print front of queue and remove it from queue
        node = queue.getFront();
        cout << node.item << endl;

        /* Enqueue left child */
        if(node.left != nullptr)
            queue.enqueue(*(node.left));

        /*Enqueue right child */
        if(node.right != nullptr)
            queue.enqueue(*(node.right));

        queue.dequeue();
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * printTree(int space)
 *
 * Description:
 *  printTree(BinaryNode<T> *root, int space) wrapper; automatically print values from root node.
 *
 * Input Parameter:
 *  int space
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::printTree(int space) {
    printTree(root, space);
}

/*
 * printTree(BinaryNode<T> *root, int space)
 *
 * Description:
 *  Print the entire tree in a human readable form.
 *
 * Input Parameter:
 *  BinaryNode<T> *root
 *  int space
 *
 * Return Value:
 *  void
 */
template <class T>
void BST<T>::printTree(BinaryNode<T> *root, int space) {
    // Base case
    if(root == nullptr)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for(int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->item);

    // Process left child
    printTree(root->left, space);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * isEmpty()
 *
 * Description:
 *  Check if the binary search tree is empty
 *
 * Input Parameter:
 *  NIL
 *
 * Return Value:
 *  bool
 */
template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * getHeightDiff(BinaryNode<T> *temp)
 *
 * Description:
 *  Calculate height difference between left and right node.
 *
 * Input Parameter:
 *  BinaryNode<T> *temp
 *
 * Return Value:
 *  int
 */
template <class T>
int BST<T>::getHeightDiff(BinaryNode<T> *temp) {
    return getHeight(temp->left)-getHeight(temp->right);
}

/*
 * rr_rotation(BinaryNode<T> *parent)
 *
 * Description:
 *  Right- Right Rotation.
 *
 * Input Parameter:
 *  BinaryNode<T> *parent
 *
 * Return Value:
 *  BinaryNode<T>*
 */
template <class T>
BinaryNode<T> *BST<T>::rr_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

/*
 * ll_rotation(BinaryNode<T> *parent)
 *
 * Description:
 *  Left- Left Rotation.
 *
 * Input Parameter:
 *  BinaryNode<T> *parent
 *
 * Return Value:
 *  BinaryNode<T>*
 */
template <class T>
BinaryNode<T> *BST<T>::ll_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

/*
 * lr_rotation(BinaryNode<T> *parent)
 *
 * Description:
 *  Left - Right Rotation.
 *
 * Input Parameter:
 *  BinaryNode<T> *parent
 *
 * Return Value:
 *  BinaryNode<T>*
 */
template <class T>
BinaryNode<T> *BST<T>::lr_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

/*
 * rl_rotation(BinaryNode<T> *parent)
 *
 * Description:
 *  Right - Left Rotation.
 *
 * Input Parameter:
 *  BinaryNode<T> *parent
 *
 * Return Value:
 *  BinaryNode<T>*
 */
template <class T>
BinaryNode<T> *BST<T>::rl_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

/*
 * balance(BinaryNode<T> *temp)
 *
 * Description:
 *  Balancing AVL Tree. This method analyses and decides if a particular pivot needs a rotation.
 *
 * Input Parameter:
 *  BinaryNode<T> *temp
 *
 * Return Value:
 *  BinaryNode<T>*
 */
template <class T>
BinaryNode<T> *BST<T>::balance(BinaryNode<T> *temp) {
    int bal_factor = getHeightDiff(temp);
    if(bal_factor > 1) {
        if(getHeightDiff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    } else if(bal_factor < -1) {
        if(getHeightDiff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}