//
// Created by David on 19/01/2018.
//

#include "ACommand.h"
#include "../Queue.h"

class DisplayItemsInTreeCommand : ACommand{
protected:
    BST tree;

public:
    explicit DisplayItemsInTreeCommand(BST &aTree) : ACommand() {
        tree = aTree;
    }

    int Execute() override {

    }

    void printLevelOrder(BinaryNode *root)
    {
        // Base Case
        if (root == nullptr)
            return;

        // Create an empty queue for level order tarversal
        Queue queue;

        // Enqueue Root and initialize height
        queue.enqueue(root);

        while (!queue.isEmpty())
        {
            // Print front of queue and remove it from queue
            BinaryNode *node;
            queue.getFront(node);
            cout << node->item<< " ";
            queue.dequeue();

            /* Enqueue left child */
            if (node->left != nullptr)
                queue.enqueue(node->left);

            /*Enqueue right child */
            if (node->right != nullptr)
                queue.enqueue(node->right);
        }
    }
};
