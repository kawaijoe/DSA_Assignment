//
// Created by David on 19/01/2018.
//

#ifndef DSA_ASSIGNMENT_ACOMMAND_H
#define DSA_ASSIGNMENT_ACOMMAND_H

#include "../BST.h"

class ACommand
{
public:

    ACommand() = default;

    virtual int Execute() = 0;
};
#endif //DSA_ASSIGNMENT_ACOMMAND_H
