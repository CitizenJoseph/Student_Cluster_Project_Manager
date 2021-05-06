#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <ostream>

using namespace std;

class Project
{
    string name, filepath; //private data members of Project
public:
    Project(string name, string filepath); //constructor for project
    void set_name(string); //setters and getters for name and filepath
    string get_name();
    void set_filepath(string);
    string get_filepath();
    friend ostream& operator<<(ostream& out, const Project& project); //operator<< for formatting each project to cout
};
#endif


//this is a test.
