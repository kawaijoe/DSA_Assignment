cmake_minimum_required(VERSION 3.9)
project(DSA_Assignment)

set(CMAKE_CXX_STANDARD 11)

# Template workaround: BST.cpp & Queue.cpp have been removed from add_executable()
add_executable(DSA_Assignment main.cpp BST.h BinaryNode.h Queue.h)

#command/ACommand.h command/DisplayItemsInOrderCommand.cpp command/SearchCommand.cpp "command/AddItemCommand .cpp" command/RemoveItemCommand.cpp command/DisplayItemsInTreeCommand.cpp