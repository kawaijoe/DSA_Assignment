//
// Created by David on 19/01/2018.
//

#include "ACommand.h"

class DisplayItemsInOrderCommand : ACommand{
protected:

    BST tree;
public:
    explicit DisplayItemsInOrderCommand(BST &aTree) : ACommand() {
        tree = aTree;
    }

    int Execute() override {
        tree.inorder();
    }
};
