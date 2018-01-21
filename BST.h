//
// Created by David on 14/01/2018.
//

#ifndef DSA_ASSIGNMENT_BST_H
#define DSA_ASSIGNMENT_BST_H

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

#include "BinaryNode.h"

template <class T>
class BST {
private:
    // root of the BST
    BinaryNode<T> *root;

    // balance() helper
    int getHeightDiff(BinaryNode<T> *temp);

    BinaryNode<T> *rr_rotation(BinaryNode<T> *parent);

    BinaryNode<T> *ll_rotation(BinaryNode<T> *parent);

    BinaryNode<T> *lr_rotation(BinaryNode<T> *parent);

    BinaryNode<T> *rl_rotation(BinaryNode<T> *parent);

public:
    // Constructor
    BST();

    // Destructor
    ~BST();

    // search an item in the binary search tree
    BinaryNode<T> *search(T target);

    BinaryNode<T> *search(BinaryNode<T> *t, T target);

    // add an item to the binary search tree
    void insert(T item);

    void insert(BinaryNode<T> *&t, T item);

    // delete an item from the binary search tree
    void remove(T item);

    BinaryNode<T> *remove(BinaryNode<T> *&t, T item);

    // traverse the binary search tree in inOrder(smallest to biggest)
    void inorder();

    void inorder(BinaryNode<T> *t);

    // traverse the binary search tree in preOrder(Parent to child)
    void preorder();

    void preorder(BinaryNode<T> *t);

    // traverse the binary search tree in postOrder(child to parent)
    void postorder();

    void postorder(BinaryNode<T> *t);

    // compute the height of the binary search tree
    int getHeight();

    int getHeight(BinaryNode<T> *t);

    // count the number of nodes in the binary search tree
    int countNodes();

    int countNodes(BinaryNode<T> *t);

    // check if the binary search tree is empty
    bool isEmpty();

    // Check if the binary search tree is balanced
    bool isBalanced();

    bool isBalanced(BinaryNode<T> *t);

    // Balance tree
    BinaryNode<T> *balance(BinaryNode<T> *temp);

    // Display level-by-level traversal
    void printLevelOrder();

    void printTree(BinaryNode<T> *root, int space);

    void printTree(int space);

    void printLevelOrder(BinaryNode<T> *root);

};

// Template workaround (Removed BST.cpp from CMakeLists.txt's add_executable())
#include "BST.cpp"

#endif //DSA_ASSIGNMENT_BST_H
