//
// Created by David on 19/01/2018.
//

#include "ACommand.h"
#include "../Queue.h"

class RemoveItemCommand : ACommand{
protected:
    BST tree;
    Queue queue;
public:
    RemoveItemCommand(BST &aTree,Queue &aQueue) : ACommand(){
        tree = aTree;
        queue = aQueue;
    }

    int Execute() override {
        int n;
        cout << "Enter a number to delete : ";
        cin >> n;
        tree.remove(n);

    }

};