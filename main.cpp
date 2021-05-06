/*
*
* Author: Joseph Cittadino
* Purpose: To create a simplified user-interface for students working on coding projects in the student cluster. 
* 
*/


#include "Main_Menu.h"
#include "Project_Menu.h"
#include "Error.h"

int main() {
    Project_Menu p; //Project_Menu object
    Main_Menu m; //Main_Menu object
    char command = 0;
    char locCommand = 0;
    //string answer;

    m.read(); //reads in contents from project_list.txt
    m.show_title(); //prints title of program


    do {
        m.show_projects();
        m.show_commands();
        cout << "Command: ";
        cin >> command;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (tolower(command)) {
        case 'c': //change project name or filepath
            int proj_number;
            cout << "Enter the number of the project you would like to enter: ";
            cin >> proj_number;
            Error::list_check(proj_number);
            change(proj_number, m.get_list());
            break;
        case 't': //change user-preferred text-editor
            m.change_edit();
            break;
        case 'e': //enters project
            cout << "Enter the number of the project you would like to enter: ";
            cin >> proj_number;
            Error::list_check(proj_number); //checks if project number is in-range for the project list
            if (p.show_contents(proj_number, m.get_list()) == false) { //checks if project is accessible (i.e if the project has a good filepath) and prints directory of project
                break;
            }
            //p.show_commands(); //inherited from Main_Menu
            do {
                p.show_commands();
                cout << "Command: ";
                cin >> locCommand;

	            switch (tolower(locCommand)) {
                case 't':
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    p.change_edit(); //inherited from Main_Menu
                    break;
	            case 'e':
                    p.enter_file(proj_number, m.get_list()); //enters file 
                    break;
                case 'r':
                    p.remove_file(proj_number, m.get_list()); //removes file from project
                    break;
                case 'x': //exits project menu
		            break;
                }

                p.show_contents(proj_number, m.get_list());
                //p.show_commands();

            } while (locCommand != 'x');
            break;
        case 'a': //adds project from project list
	        m.add_project();
            break;
        case 'r': //removes project from project list
            //int proj_number;
            cout << "Enter the number of the project you would like to remove: ";
            cin >> proj_number;
            Error::list_check(proj_number);
            m.remove_project(proj_number);
            break;
        case 'x': //exits program
            break;
        default: //error-validation for all responses not commands
            cout << "Invalid command. Try again.\n";
            continue;
        }
        cout << "\n";
    } while (command != 'x');

    m.get_list().write(); //writes chnages made to the program

    return 0;
}
