#include "Error.h"

void Error::system_check(int com) { //throws invalid_argument exception if system() returns # != 0
    if (com != 0)
        throw invalid_argument("Directory does not exist. Change the directory to one that does.");
}

void Error::list_check(int& num) { //checks if project number from user is within range
    if (num <= 0 || num > Project_List::project_count) {
        cout << "Project number is not in the list. Choose a number that is.\n";
        do { //will ask for a project number until a number is in range
            cout << "Enter the number of a project in the list: ";
            cin >> num;
        } while (num <= 0 || num > Project_List::project_count);
    }
}
