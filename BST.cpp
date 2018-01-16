//
// Created by David on 14/01/2018.
//

#include "BST.h"

using namespace std;

#define max(x, y) (((x) > (y)) ? (x) : (y))


// -------- Constructor --------------
BST::BST() {
    root = nullptr;
}

BST::~BST() = default;


// -------- Search an item in the binary search Tree --------------------------------
BinaryNode *BST::search(ItemType target) {
    return search(root, target);
}

BinaryNode *BST::search(BinaryNode *t, ItemType target) {
    if(!t) {
        // item Not Found
        return nullptr;
    } else {
        if(t->item == target) {
            // item found
            return t;
        } else {
            if(t->item > target) {
                // search left subtree
                return search(t->left, target);
            } else {
                // search right subtree
                return search(t->right, target);
            }
        }
    }
}


//----------- insert an item into the binary search tree ---------------------------------------------------------------------

void BST::insert(ItemType item) {
    return insert(root, item);
}

void BST::insert(BinaryNode *&t, ItemType item) {

    // base case, if the tree is empty
    if(!t) {
        auto *newNode = new BinaryNode;
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
    }

}

// ----------------- delete an item from the binary search tree ----------------------------------------------------
void BST::remove(ItemType item) {
    return remove(root, item);
}

void BST::remove(BinaryNode *&t, ItemType target) {

    BinaryNode *current = nullptr;
    BinaryNode *root = t;
    bool isLeftChild = false;
    bool found = false;

    while(!found && root != nullptr) {
        if(target == current->item) {
            found = true;
        } else {
            current = root;
            if(target < current->item) {
                // go down the left subtree
                current = current->left;
                isLeftChild = true;
            } else {
                // go down the right subtree
                current = current->right;
                isLeftChild = false;
            }
        }
    }

    if(found) {
        if(current->left == nullptr && current->right == nullptr) {

            // ----------------------- case 1 : node is a leaf ---------------------------------
            if(current == t) {
                t = nullptr;
            } else {
                if(isLeftChild) {
                    // Check if node is a left child, then change the parent left node to null
                    root->left = nullptr;
                } else {
                    // Check if node is a right child, then change the parent right node to null
                    root->right = nullptr;
                }
            }
        } else if(current->left == nullptr) {

            // ------------------------ case 2: node has 1 child --------------------------------
            if(current->left == nullptr) {
                t = current->right;
            } else if(isLeftChild) {
                root->left = current->right;
            } else {
                root->right = current->right;
            }
        } else if(current->right == nullptr) {
            if(current == t) {
                t = current->left;
            } else if(isLeftChild) {
                root->left = current->left;
            } else {
                root->right = current->left;
            }
        } else {

            // ---------------------- Case 3: node has 2 children ------------------------------
            // find the successor (rightmost child in the node's Left subtree)
            BinaryNode *successor = current->left;
            while(successor->right != nullptr) {
                successor = successor->right;
            }

            int n = successor->item;

            // delete the Successor (either case 1 or case 2 above)
            remove(t, n);

            // replace the Node's item with that of the successor using n
            current->item = n;
        }
    }
}

// -------------- traverse the tree in "inOrder" process (smallest to biggest)-------------------
void BST::inorder() {
    if(isEmpty()) {
        cout << "No item found" << endl;
    } else {
        inorder(root);
    }
}

void BST::inorder(BinaryNode *t) {
    if(t) {
        inorder(t->left);
        cout << t->item << endl;
        inorder(t->right);
    }
}

// ----------------- traverse the tree in "PreOrder" process (Parent first then Child) -----------------
void BST::preorder() {
    if(isEmpty()) {
        cout << "No items found" << endl;
    } else {
        preorder(root);
    }
}

void BST::preorder(BinaryNode *t) {
    if(t) {
        cout << t->item << endl;
        preorder(t->left);
        preorder(t->right);
    }
}

// ------------------- traverse the tree in "PostOrder" process (Children first then parent) ---------------------
void BST::postorder() {
    if(isEmpty()) {
        cout << "No items found" << endl;
    } else {
        postorder(root);
    }
}

void BST::postorder(BinaryNode *t) {
    if(t) {
        postorder(t->left);
        postorder(t->right);
        cout << t->item << endl;
    }
}

// ----------------------- compute the height of the binary search tree ---------------------
int BST::getHeight() {
    return getHeight(root);
}

int BST::getHeight(BinaryNode *t) {
    if (t) return 1 + max(getHeight(t->left), getHeight(t->right));
    return 0;
}

// ---------------------- count the number of the Nodes in the Tree ------------------------------
int BST::countNodes() {
    return countNodes(root);
}

int BST::countNodes(BinaryNode *t) {
    if(t) return 1 + countNodes(t->left) + countNodes(t->right);
    return 0;
}

// ------------------------ check if the binary search tree is balanced ------------------------------
bool BST::isBalanced() {
    return isBalanced(root);
}

bool BST::isBalanced(BinaryNode *t) {
    if(!t) {
        if(getHeight(t) < 4) {
            int leftHeight = getHeight(t->left);
            int rightHeight = getHeight(t->right);

            return abs(leftHeight-rightHeight) <= 1;
        } else {
            return isBalanced(t->left) && isBalanced(t->right);
        }
    } else {
        return true;
    }
}


// --------------------- Check if the binary search tree is empty -------------------------------
bool BST::isEmpty() {
    return root == nullptr;
}