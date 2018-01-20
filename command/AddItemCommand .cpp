//
// Created by David on 19/01/2018.
//

#include "ACommand.h"

class AddItemCommand : ACommand{
protected:
    BST tree;
public:
    explicit AddItemCommand(BST &aTree) : ACommand(){
        tree = aTree;
    }

    int Execute() override {
        string line;
        cout << "Enter a number to add : ";
        getline(cin, line);
        if(true){
            int n = strtol(line.c_str());
            tree.insert(n);
        }else{
            cout << "Please enter an Integer" << endl;
        }


    }

};