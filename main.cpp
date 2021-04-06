#include "Main_Menu.h"
#include "Project_Menu.h"
#include "Error.h"
#include <limits>

int main() {

    Project_Menu p;
    Main_Menu m;
    char command = NULL;
    char locCommand = NULL;
    string answer;

    m.read();
    m.show_title();
    m.show_projects();
    m.show_commands();


    do {
        cout << "Command: ";
        cin >> command;
        switch (command) {
        case 'C':
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter the project name: ";
            getline(cin, answer);
            change(answer, m.get_list());
            break;
        case 'E':
            int proj_number;
            cout << "Enter the number of the project you would like to enter: ";
            cin >> proj_number;
            p.show_contents(proj_number, m.get_list());
            p.show_commands();
            /*do {

            } while (locCommand != 'x');*/
            break;
        case 'A':
            break;
        case 'R':
            break;
        }
        m.show_projects();
        m.show_commands();
    } while (command != 'x');

    m.get_list().write();



    return 0;
}