#include <cstdio>
#include <cmath>
#include <iostream>
#include "BST.h"


bool isInteger(double num);
void displayMenu();
bool is_digits(const std::string &str);

int main() {

    BST bst;

    int dataArray[10] = {55, 28, 87, 32, 90, 16, 45, 79, 66, 30};

    for(int i : dataArray) {
        bst.insert(i);
    }


    int option = 0;

    while(option != 8) {
        displayMenu();
        cout << "Enter option : ";
        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if(option == 1)    // display items
            bst.inorder();
        else if(option == 2) {      // search Item
            cout << "Enter a number to search : ";
            cin >> target;

            while(cin.fail() || !isInteger(target)) {   // checks if input is integer
                cout << "Please enter a number..." << endl;
                cout << "Enter a number to search: ";
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> target;
            }

            BinaryNode *p = bst.search(target);
            if(p != nullptr)
                cout << "Found" << endl;
            else
                cout << "Not found" << endl;

        } else if(option == 3) {        // add item
            int n;
            cout << "Enter a number to add : ";
            cin >> n;
            bst.insert(n);
        } else if(option == 4) {    // delete item
            int n;
            cout << "Enter a number to delete : ";
            cin >> n;
            bst.remove(n);
        } else if(option == 5) {    // display number of items
            cout << "total Number of items: " << bst.countNodes() << endl;
        } else if(option == 6) {  // display height
            cout << "Height of Binary Tree: " << bst.getHeight() << endl;
        } else if(option == 7) { // check if tree is balanced
            if(bst.isBalanced()) {
                cout << "Binary Search tree is balanced" << endl;
            } else {
                cout << "Binary Search tree is not balanced" << endl;
            }
        } else if(option == 8)
            cout << "Bye! \n";
        else
            cout << " Sorry. You have entered an invalid option."<<endl;
    }
    return 0;
}

void displayMenu() {
    cout << "\nBinary Search Tree Demo \n";
    cout << "--------------------------------\n";
    cout << "1 Display all the items in order\n";
    cout << "2 Search for an item \n";
    cout << "3 Add a new item \n";
    cout << "4 Delete an item \n";
    cout << "5 Display total number of items \n";
    cout << "6 Display the height \n";
    cout << "7 Check if tree is balanced \n";
    cout << "8 Exit \n";
    cout << "--------------------------------\n";
    cout.flush();
}

bool isInteger(double num){         // checks if input is integer
    return num == ceil(num);
}

bool is_digits(const std::string &str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}
