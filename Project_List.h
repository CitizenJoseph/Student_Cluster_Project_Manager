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
    //static vector<Project> list;
    static string editor;
    void write();
    Project_List& operator+=(Project&);
    friend void change(string project_name, Project_List& list);
};
#endif 