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


class BST {
private:
    // root of the BST
    BinaryNode* root;

    // isBalance() helper
    void checkNode(set<int> &heightSet, BinaryNode *node, int height);

    // balance() helper
    int getHeightDiff(BinaryNode* temp);
    BinaryNode* rr_rotation(BinaryNode* parent);
    BinaryNode* ll_rotation(BinaryNode* parent);
    BinaryNode* lr_rotation(BinaryNode* parent);
    BinaryNode* rl_rotation(BinaryNode* parent);

public:
    // Constructor
    BST();

    // Destructor
    ~BST();

    // search an item in the binary search tree
    BinaryNode* search(ItemType target);
    BinaryNode* search(BinaryNode* t, ItemType target);

    // add an item to the binary search tree
    void insert(ItemType item);
    void insert(BinaryNode* &t, ItemType item);

    // delete an item from the binary search tree
    void remove(ItemType item);
    void remove(BinaryNode* &t, ItemType item);

    // traverse the binary search tree in inOrder(smallest to biggest)
    void inorder();
    void inorder(BinaryNode* t);

    // traverse the binary search tree in preOrder(Parent to child)
    void preorder();
    void preorder(BinaryNode* t);

    // traverse the binary search tree in postOrder(child to parent)
    void postorder();
    void postorder(BinaryNode* t);

    // compute the height of the binary search tree
    int getHeight();
    int getHeight(BinaryNode* t);

    // count the number of nodes in the binary search tree
    int countNodes();
    int countNodes(BinaryNode* t);

    // check if the binary search tree is empty
    bool isEmpty();
    bool isEmpty(BinaryNode* t);

    // Check if the binary search tree is balanced
    bool isBalanced();
    bool isBalanced(BinaryNode* t);

    // Balance tree
    BinaryNode* balance();
    BinaryNode* balance(BinaryNode* temp);

};

#endif //DSA_ASSIGNMENT_BST_H
