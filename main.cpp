#include "Main_Menu.h"
#include "Project_Menu.h"
#include "Error.h"
#include <ctype.h>
#include <limits>

int main() {

    Project_Menu p;
    Main_Menu m;
    char command = 0;
    char locCommand = 0;
    string answer;

    m.read();
    m.show_title();
    m.show_projects();
    m.show_commands();


    do {
        cout << "Command: ";
        cin >> command;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (tolower(command)) {
        case 'c':
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the project name: ";
            getline(cin, answer);
            change(answer, m.get_list());
            break;
        case 'e':
            int proj_number;
            cout << "Enter the number of the project you would like to enter: ";
            cin >> proj_number;
            p.show_contents(proj_number, m.get_list());
            p.show_commands();
            do {
               cout << "Command: ";
               cin >> locCommand;

	       switch (tolower(locCommand)) {
	          case 'e':
                      p.enter_file(proj_number, m.get_list());
                      break;
                  case 'x':
		      break;
               }
               
            } while (locCommand != 'x');
            break;
        case 'a':
	    m.add_project();
            break;
        case 'r':
            m.remove_project();
            break;
        case 'x':
            break;
        default:
            cout << "Invalid command. Try again.\n";
            continue;
        }
        cout << "\n";
        m.show_projects();
        m.show_commands();
    } while (command != 'x');

    m.get_list().write();



    return 0;
}
