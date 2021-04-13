#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

#include <vector>
#include <fstream>
#include "Project.h"

class Project_List
{
    vector<Project> list;
public:
    vector<Project> get_list();
    static int project_count;
    static string editor;
    void write();
    Project_List& operator+=(Project&);
    Project_List& operator--();
    Project_List& operator-=(int);
    friend void change(string project_name, Project_List& list);
};
#endif 
