#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

#include <vector>
#include <fstream>
#include "Project.h"

class Project_List
{
    vector<Project> proj_list; //Project_List vector container
public:
    vector<Project> get_list();
    static int project_count; //static count of projects in project list for easy access 
    static string editor; //static string of user text-editor for easy access. 
    void write();
    Project_List& operator+=(Project&); //operator+= to add project to list
    Project_List& operator--(); //operator-- to remove last project from list
    Project_List& operator-=(int); //operator-= to remove project from specified index 
    friend void change(int project_num, Project_List& list); //friend function to access private list 
};
#endif 
