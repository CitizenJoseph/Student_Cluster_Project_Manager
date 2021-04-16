#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include "Main_Menu.h"

class Project_Menu : public Main_Menu
{
    int working_proj = 0;
public:
    bool show_contents(int project, Project_List list);
    void show_commands();
    void enter_file(int project, Project_List list);
};

#endif
