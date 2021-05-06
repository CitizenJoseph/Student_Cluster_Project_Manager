#ifndef ERROR_H
#define ERROR_H

#include "Project_List.h"
#include <iostream>

using namespace std;

class Error
{
public: //static functions to help with error-validation
    static void system_check(int);
    static void list_check(int& num);
};

#endif