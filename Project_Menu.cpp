#include "Project_Menu.h"
#include "Error.h"
#include <limits>

bool Project_Menu::show_contents(int project, Project_List list) {
    working_proj = project - 1;
    string command =  "ls -l " + list.get_list()[working_proj].get_filepath();
    //system(command.c_str());
    try {
        //system(command.c_str())
        Error::system_check(system(command.c_str()));
    }
    catch (const invalid_argument& e) {
        cout << e.what() << "\n\n";
        return false;
    }
    return true;
}

void Project_Menu::show_commands() {
    cout << "COMMANDS:\n\n"
    << "E - Enter a file.\n"
    << "X - Exit the program.\n\n";
}

void Project_Menu::enter_file(int project, Project_List list) {
    char temp;
    working_proj = project - 1;
    string file_name;
    string command;

    cout << "Enter the name of the file you would like to enter: ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, file_name);
    command = Project_List::editor + " " + list.get_list()[working_proj].get_filepath() + "/"  + file_name;
    system(command.c_str());
    //cout << "\n";
    //cin >> ;

}

