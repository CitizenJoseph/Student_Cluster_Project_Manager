#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <ctype.h>
#include <limits>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Project_List.h"

class Main_Menu
{
    Project_List obj_list; //main_menus private list
public:
    Project_List& get_list(); //returns reference to Main_Menu list
    void show_title();
    void show_projects();
    void change_edit();
    virtual void show_commands(); //virtual function to show commands between menus
    void add_project();
    void remove_project(int);
    void read();
};

#endif
