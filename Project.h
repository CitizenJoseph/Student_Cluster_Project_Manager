#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <ostream>

using namespace std;

class Project
{
private:
    string name, filepath;
public:
    Project(string name, string filepath);
    void set_name(string);
    string get_name();
    void set_filepath(string);
    string get_filepath();
    friend ostream& operator<<(ostream& out, const Project& project); 
};
#endif


//this is a test.
