#ifndef ERROR_H
#define ERROR_H

#include "Project_List.h"
#include <iostream>

class Error
{
public:
    static void system_check(int);
    static void list_check(int& num);
    static void bad_input(char command);
    static void bad_command();
};

#endif
