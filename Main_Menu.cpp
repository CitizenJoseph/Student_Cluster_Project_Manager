#include "Main_Menu.h"


Project_List& Main_Menu::get_list() { //returns private Project_List in Main_Menu class
    return obj_list;
}


void Main_Menu::show_title() { //prints title of program
    cout << "Student Cluster Project Manager\n\n";
}

void Main_Menu::show_projects() { //range-based for loop to display projects
    int i = 1;
    for (Project proj : obj_list.get_list()) {
        cout << i << ". " << proj << "\n";
        i++;
    }
    cout << "\n";
}

void Main_Menu::show_commands() { //prints commands
    cout << "COMMANDS:\n\n"
    << "C - Change the name or filepath of a selected project.\n"
    << "T - Change the text-editor used to edit files.\n"
    << "E - Enter a project.\n"
    << "A - Add a project.\n"
    << "R - Remove a project.\n"
    << "X - Exit the program.\n\n";
}

void Main_Menu::add_project() { //adds project to list by creating Project object and by using += operator

    string project_name, file_path;
    cout << "Enter the name of the project (No spaces. Use underscores): ";
    cin >> project_name;
    cout << "Enter the absolute file directory of " + project_name + ": ";
    cin >> file_path;
    Project proj(project_name, file_path);
    obj_list += proj; //+= operator

}

void Main_Menu::remove_project(int i) { //removes project from list using -= opertor
    obj_list -= (i - 1); //-= operator
}

void Main_Menu::read() {
    ifstream input_file;
    string name, filepath;
    input_file.open("project_list.txt"); //opens project_list.txt
    getline(input_file, name); //grabs text-editor
    Project_List::editor = name;
    while(!input_file.eof()) {
        input_file >> name >> filepath; //grabs proj_name and proj_filepath (proj_name must be one word or spaces must be replaced with underscores)
        Project proj(name, filepath);
        obj_list += proj;
    }
    --obj_list; //--operator
    input_file.close();
}

ostream& operator<<(ostream& out, const Project& project) { //<< operator for formatting project
    out << "NAME: "<< project.name << "\n\tPATH: " << project.filepath;
    return out;
}

void Main_Menu::change_edit() { 
    string answer;

    cout << "What is your preferred text-editor?: ";
    getline(cin, answer);
    Project_List::editor = answer;
}

void change(int project_num, Project_List& list) { //changes name or filepath of a selected project (friend function)
    int temp = project_num - 1;

    char answer;
    string changed;
    do {
        cout << "Enter N to change the name of a project or F to change it's filepath: ";
        cin >> answer;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (tolower(answer)) {
        case 'n':
            cout << "What will the new name be?: ";
            getline(cin, changed);
            list.proj_list[temp].set_name(changed);
            break;
        case 'f':
            cout << "What will the new filepath be?: ";
            getline(cin, changed);
            list.proj_list[temp].set_filepath(changed);
            break;
        default:
            break;
        }
    } while (tolower(answer) != 'n' && tolower(answer) != 'f');
}
