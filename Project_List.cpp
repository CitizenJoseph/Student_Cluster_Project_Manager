#include "Project_List.h"

string Project_List::editor = "vim";
int Project_List::project_count = 0;

vector<Project> Project_List::get_list() {
    return list;
}

void Project_List::write() {
    ofstream output_file;
    output_file.open("project_list.txt");
    output_file << Project_List::editor << "\n";
    for (Project proj : list) {
        output_file << proj.get_name() << "\t" << proj.get_filepath() << "\n";
    }
    output_file.close();
}

Project_List& Project_List::operator+= (Project& proj) {
    list.push_back(proj);
    project_count++;
    return *this;
}

Project_List& Project_List::operator-- (){
    list.pop_back();
    project_count--;
    return *this;
}

Project_List& Project_List::operator-=(int i) {
    list.erase(list.begin() + i);
    return *this;
}
