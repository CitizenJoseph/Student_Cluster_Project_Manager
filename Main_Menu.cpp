#include "Main_Menu.h"


Project_List& Main_Menu::get_list() {
    return list;
}


void Main_Menu::show_title() {
    cout << "Student Cluster Project Manager\n\n";
}

void Main_Menu::show_projects() {
    int i = 1;
    for (Project proj : list.get_list()) {
        cout << i << ". " << proj << "\n";
        i++;
    }
    cout << "\n";
}

void Main_Menu::show_commands() {
    cout << "COMMANDS:\n\n"
    << "C - Change the name or filepath of a selected project.\n"
    << "T - Change the text-editor used to edit files.\n"
    << "E - Enter a project.\n"
    << "A - Add a project.\n"
    << "R - Remove a project.\n"
    << "X - Exit the program.\n\n";
}

/*void Main_Menu::enter_project() {
    int proj_number;
    cout << "Enter the number of the project you would like to enter: ";
    cin >> proj_number;

}*/

void Main_Menu::add_project() {

    string project_name, file_path;
    cout << "Enter the name of the project (One or no spaces): ";
    cin >> project_name;
    cout << "Enter the absolute file directory of " + project_name + ": ";
    cin >> file_path;
    Project proj(project_name, file_path);
    list += proj;

}

void Main_Menu::remove_project() {
    string project_name;
    
    cout << "Enter the name of the project to remove: ";
    cin >> project_name;

    for (int i = 0; i < Project_List::project_count; i++) {
        if (list.get_list()[i].get_name() == project_name)
            list -= (i);
    }

}

void Main_Menu::read() {
    ifstream input_file;
    string name, filepath;
    input_file.open("project_list.txt");
    getline(input_file, name);
    Project_List::editor = name;
    while(!input_file.eof()) {
        input_file >> name >> filepath;
        Project proj(name, filepath);
        list += proj;
    }
    --list;
    input_file.close();
}

ostream& operator<<(ostream& out, const Project& project) {
    out << project.name << "\t" << project.filepath;
    return out;
}




void change(string project_name, Project_List& list) {

    int temp = 0;

    for (int i = 0; i < Project_List::project_count; i++) {
        if (list.get_list()[i].get_name() == project_name) {
            temp = i;
            break;
        }

    }

    char answer;
    string changed;
    cout << "Enter N to change the name of a project or F to change it's filepath: ";
    cin >> answer;
    if (tolower(answer) == 'n') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "What will the new name be?: ";
        getline(cin, changed);
        list.list[temp].set_name(changed);
    }
    if (tolower(answer) == 'f') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "What will the new filepath be?: ";
        getline(cin, changed);
        list.list[temp].set_filepath(changed);
    }
    /*if (tolower(answer) == 't') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "What is your preferred text-editor?: ";
        getline(cin, changed);
        Project_List::editor = changed;
    }*/
}
