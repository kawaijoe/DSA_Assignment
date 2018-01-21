//
// Created by David on 14/01/2018.
//

#include <cstdlib>
#include "BST.h"
#include "Queue.h"

using namespace std;

#define max(x, y) (((x) > (y)) ? (x) : (y))

// -------- Constructor --------------
template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
BST<T>::~BST() = default;


// -------- Search an item in the binary search Tree --------------------------------
template <class T>
BinaryNode<T> *BST<T>::search(T target) {
    return search(root, target);
}

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

//----------- insert an item into the binary search tree --------------------------------------------------------------
template <class T>
void BST<T>::insert(T item) {
    if(search(item) == nullptr) {
        insert(root, item);
    } else {
        cout << "Unable to insert, item exist." << endl;
    }
}

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

// ----------------- delete an item from the binary search tree ----------------------------------------------------
template <class T>
void BST<T>::remove(T item) {
    if(search(item) != nullptr) {
        remove(root, item);
    } else {
        cout << "Unable to delete, item does not exist." << endl;
    }

}

// delete an item from the binary search tree
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
        // if found and have two parents
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
        // if found and is leave

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
        free(temp);
    }

    if(t == nullptr) return t;

    //balancing
    t = balance(t);
}

// -------------- traverse the tree in "inOrder" process (smallest to biggest)-------------------
template <class T>
void BST<T>::inorder() {
    if(isEmpty()) {
        cout << "BST does not exist." << endl;
    } else {
        inorder(root);
    }
}

template <class T>
void BST<T>::inorder(BinaryNode<T> *t) {
    if(t) {
        inorder(t->left);
        cout << t->item << endl;
        inorder(t->right);
    }
}

// ----------------- traverse the tree in "PreOrder" process (Parent first then Child) -----------------
template <class T>
void BST<T>::preorder() {
    if(isEmpty()) {
        cout << "No items found." << endl;
    } else {
        preorder(root);
    }
}

template <class T>
void BST<T>::preorder(BinaryNode<T> *t) {
    if(t) {
        cout << t->item << endl;
        preorder(t->left);
        preorder(t->right);
    }
}

// ------------------- traverse the tree in "PostOrder" process (Children first then parent) ---------------------
template <class T>
void BST<T>::postorder() {
    if(isEmpty()) {
        cout << "No items found" << endl;
    } else {
        postorder(root);
    }
}

template <class T>
void BST<T>::postorder(BinaryNode<T> *t) {
    if(t) {
        postorder(t->left);
        postorder(t->right);
        cout << t->item << endl;
    }
}

// ----------------------- compute the height of the binary search tree ---------------------
template <class T>
int BST<T>::getHeight() {
    return getHeight(root);
}

template <class T>
int BST<T>::getHeight(BinaryNode<T> *t) {
    if(t) return 1+max(getHeight(t->left), getHeight(t->right));
    return 0;
}

// ---------------------- count the number of the Nodes in the Tree ------------------------------
template <class T>
int BST<T>::countNodes() {
    return countNodes(root);
}

template <class T>
int BST<T>::countNodes(BinaryNode<T> *t) {
    if(t) return 1+countNodes(t->left)+countNodes(t->right);
    return 0;
}

// check if the binary search tree is balanced
template <class T>
bool BST<T>::isBalanced() {
    return isBalanced(root);
}

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

template <class T>
void BST<T>::printLevelOrder() {
    printLevelOrder(root);
}

template <class T>
void BST<T>::printLevelOrder(BinaryNode<T> *root) {
    // Base case
    if(root == nullptr)
        return;

    // Create an empty queue for level order tarversal
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

template <class T>
void BST<T>::printTree(int space) {
    printTree(root, space);
}

template <class T>
void BST<T>::printTree(BinaryNode<T> *root, int space) {
    // Base case
    if(root == NULL)
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

// --------------------- Check if the binary search tree is empty -------------------------------
template <class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

// Height Difference
template <class T>
int BST<T>::getHeightDiff(BinaryNode<T> *temp) {
    return getHeight(temp->left)-getHeight(temp->right);
}

// Right- Right Rotation
template <class T>
BinaryNode<T> *BST<T>::rr_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation
template <class T>
BinaryNode<T> *BST<T>::ll_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// Left - Right Rotation
template <class T>
BinaryNode<T> *BST<T>::lr_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

// Right- Left Rotation
template <class T>
BinaryNode<T> *BST<T>::rl_rotation(BinaryNode<T> *parent) {
    BinaryNode<T> *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

// Balancing AVL Tree
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