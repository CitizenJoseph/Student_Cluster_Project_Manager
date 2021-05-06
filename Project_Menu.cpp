#include "Project_Menu.h"
#include "Error.h"

bool Project_Menu::show_contents(int project, Project_List list) {
    working_proj = project - 1;
    string command =  "ls -l " + list.get_list()[working_proj].get_filepath();
    try { //try-catch using system_check()
        Error::system_check(system(command.c_str()));
    }
    catch (const invalid_argument& e) { //if caught, will return false
        cout << e.what() << "\n\n";
        return false;
    }
    return true; //else return true
}

void Project_Menu::show_commands() {
    cout << "COMMANDS:\n\n"
         << "T - Change the text-editor used to edit files.\n" //inherits change_edit from Main_Menu
         << "E - Enter a file.\n"
         << "R - Remove a file.\n"
         << "X - Exit the project.\n\n";
}

void Project_Menu::enter_file(int project, Project_List list) { //enters file with text editor using system() to execute command
    string temp;
    working_proj = project - 1;
    string file_name;
    string command;

    cout << "Enter the name of the file you would like to enter: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, file_name);
    command = Project_List::editor + " " + list.get_list()[working_proj].get_filepath() + "/"  + file_name;
    system(command.c_str());
    cout << "\n";
}

void Project_Menu::remove_file(int project, Project_List list) { //removes file with rm
    working_proj = project - 1;
    
    string file_name;
    string command;

    cout << "Enter the name of the file to remove: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, file_name);
    command = "rm " + list.get_list()[working_proj].get_filepath() + "/" + file_name;
    system(command.c_str());
    cout << "\n";
}
