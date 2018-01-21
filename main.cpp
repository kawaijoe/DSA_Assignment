#include <cstdio>
#include <cmath>
#include <iostream>
#include "BST.h"

string displayMenu();
void initBST();
int validateIntData(const string &query);
bool isDigit(const std::string &str);

BST<int> bst;

int main() {
    int option = -1;

    initBST();

    while(option != 0) {
        option = validateIntData(displayMenu());
        switch(option) {
            // Exit
            case 0:
                cout << "Thank you for using Binary Search Tree Demo." << endl;
                break;

            // Search for an item
            case 1:
                cout << (bst.search(validateIntData("Please enter value for search: ")) != nullptr
                         ? "Found" : "Not Found") << endl;
                break;

            // Add a new item
            case 2:
                bst.insert(validateIntData("Please enter value to add: "));
                break;

            // Delete an item
            case 3:
                bst.remove(validateIntData("Please enter value to remove: "));
                break;

            // Display values in ascending order
            case 4:
                bst.inorder();
                break;

            // Display level-by-level traversal
            case 5:
                bst.printLevelOrder();
                break;

            // Display tree
            case 6:
                bst.printTree(3);
                break;

            // Any other number
            default:
                option = -1;
                cout << "Invalid data entered. Please try again." << endl;
                break;
        }
    }


    return 0;
}

string displayMenu() {
    return "\nBinary Search Tree Demo \n"
            "--------------------------------\n"
            "1 Search for an item\n"
            "2 Add a new item \n"
            "3 Delete an item \n"
            "4 Display values in ascending order \n"
            "5 Display level-by-level traversal \n"
            "6 Display tree \n"
            "0 Exit \n"
            "--------------------------------\n"
            "Enter option: ";
}

void initBST() {
    cout << "Binary Search Tree Initializer" << endl;
    int value = validateIntData("Enter value: ");
    cout << "Initializing Binary Search Tree..." << endl;

    int total = 0;
    int i = 0;
    while(total < value) {
        total += ++i;
        cout << "\nInserting " << i << "..." << endl;
        bst.insert(i);
    }
}

int validateIntData(const string &query) {
    string data;
    while(true) {
        cout << query;
        cout.flush();
        getline(cin, data);

        if(!isDigit(data) || data.empty())
            cout << "Invalid data entered. Please try again." << endl;
        else
            return stoi(data);
    }
}

bool isDigit(const std::string &str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}