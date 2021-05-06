#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include "Main_Menu.h"

class Project_Menu : public Main_Menu //inherits public members of Main_Menu 
{
    int working_proj = 0; //private member to keep track of working project in list
public:
    bool show_contents(int project, Project_List list);
    void show_commands(); //overrides show_commands from Main_Menu
    void enter_file(int project, Project_List list);
    void remove_file(int project, Project_List list);
};

#endif
