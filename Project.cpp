#include "Project.h"

Project::Project(string name, string filepath) {
    set_name(name);
    set_filepath(filepath);
}

void Project::set_name(string name) {
    this->name = name;
}
string Project::get_name() {
    return this->name;
}
void Project::set_filepath(string filepath) {
    this->filepath = filepath;
}
string Project::get_filepath() {
    return this->filepath;
}