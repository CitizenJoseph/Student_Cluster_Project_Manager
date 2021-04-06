#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <limits>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Project_List.h"

class Main_Menu
{
    Project_List list;
public:
    Project_List& get_list();
    void show_title();
    void show_projects();
    virtual void show_commands();
    void enter_project();
    void read();
};

#endif