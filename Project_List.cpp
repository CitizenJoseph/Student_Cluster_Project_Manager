#include "Project_List.h"

string Project_List::editor = "vi"; //sets default text-editor to vi
int Project_List::project_count = 0;

vector<Project> Project_List::get_list() {
    return proj_list;
}

void Project_List::write() {
    ofstream output_file;
    output_file.open("project_list.txt");
    output_file << Project_List::editor << "\n";
    for (Project proj : proj_list) {
        output_file << proj.get_name() << "\t" << proj.get_filepath() << "\n";
    }
    output_file.close();
}

Project_List& Project_List::operator+= (Project& proj) {
    proj_list.push_back(proj);
    project_count++;
    return *this;
}

Project_List& Project_List::operator-- (){
    proj_list.pop_back();
    project_count--;
    return *this;
}

Project_List& Project_List::operator-=(int i) {
    proj_list.erase(proj_list.begin() + i);
    project_count--;
    return *this;
}
