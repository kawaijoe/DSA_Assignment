//
// Created by David on 14/01/2018.
//

#include "BST.h"

using namespace std;

#define max(x, y) (((x) > (y)) ? (x) : (y))

class List;

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
    insert(root, item);
    root = balance();
}

void BST::insert(BinaryNode *&t, ItemType item) {
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
    remove(root, item);
    root = balance();
}

void BST::remove(BinaryNode *&t, ItemType target) {
    BinaryNode *current = t;
    BinaryNode *parent = nullptr;
    bool isLeftChild = false;
    bool found = false;

    while(!found && current != nullptr) {
        if(target == current->item) {
            found = true;
        } else {
            parent = current;
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
                    parent->left = nullptr;
                } else {
                    // Check if node is a right child, then change the parent right node to null
                    parent->right = nullptr;
                }
            }
        } else if(current->left == nullptr) {

            // ------------------------ case 2: node has 1 child --------------------------------
            if(current == t) {
                t = current->right;
            } else if(isLeftChild) {
                parent->left = current->right;
            } else {
                parent->right = current->right;
            }

        } else if(current->right == nullptr) {
            if(current == t) {
                t = current->left;
            } else if(isLeftChild) {
                parent->left = current->left;
            } else {
                parent->right = current->left;
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
        cout << "BST does not Exist" << endl;
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
    if(t) return 1 + max(getHeight(t->left), getHeight(t->right));
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

// check if the binary search tree is balanced
bool BST::isBalanced()
{
    return isBalanced(root);
}

bool BST::isBalanced(BinaryNode *t)
{
    if (t)
    {
        int leftHeight = getHeight(t->left);	// height of left sub-tree
        int rightHeight = getHeight(t->right);	// height of right sub-tree
        bool isBalancedNode = (abs(leftHeight - rightHeight) <= 1);
        return (isBalancedNode && isBalanced(t->left) && isBalanced(t->right));
    }
    else
        return true;
}

void BST::checkNode(set<int> &heightSet, BinaryNode *node, int height) {
    height++;

    if(!node->right || !node->left) heightSet.insert(height);
    if(node->right) checkNode(heightSet, node->right, height);
    if(node->left) checkNode(heightSet, node->left, height);
}

// --------------------- Check if the binary search tree is empty -------------------------------
bool BST::isEmpty() {
    return root == nullptr;
}

// Height Difference
int BST::getHeightDiff(BinaryNode *temp) {
    return getHeight(temp->left) - getHeight(temp->right);
}

// Right- Right Rotation
BinaryNode* BST::rr_rotation(BinaryNode *parent) {
    BinaryNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation
BinaryNode* BST::ll_rotation(BinaryNode *parent) {
    BinaryNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// Left - Right Rotation
BinaryNode* BST::lr_rotation(BinaryNode *parent) {
    BinaryNode *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

// Right- Left Rotation
BinaryNode* BST::rl_rotation(BinaryNode *parent) {
    BinaryNode *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

// Balancing AVL Tree
BinaryNode* BST::balance() {
    return balance(root);
}

BinaryNode* BST::balance(BinaryNode *temp) {
    int bal_factor = getHeightDiff(temp);
    cout << bal_factor <<endl;
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