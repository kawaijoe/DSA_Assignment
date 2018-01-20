//
// Created by David on 19/01/2018.
//

#include "ACommand.h"
using namespace std;


class SearchCommand : public ACommand{
protected:

    BST tree;
public:
    explicit SearchCommand(BST &aTree) : ACommand(){
        tree = aTree;
    }

    int Execute() override {
        int target;
        cout << "Enter a number to search : ";
        cin >> target;


        BinaryNode *p = tree.search(target);
        if(p != nullptr)
            cout << "Found" << endl;
        else
            cout << "Not found" << endl;
    };

};
