#ifndef ERROR_H
#define ERROR_H

#include "Project_List.h"

class Error
{
public:
    static void check_file();
    static void bad_input(char command);
    static void bad_command();
};

#endif
