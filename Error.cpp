#include "Error.h"


void Error::system_check(int com) {
    if (com != 0)
        throw invalid_argument("Directory does not exist. Change the directory to one that does.");
}


void Error::list_check(int& num) {
    if (num <= 0 || num > Project_List::project_count) {
        cout << "Project number is not in the list. Choose a number that is.\n";
        do {
            cout << "Enter the number of the project you would like to enter : ";
            cin >> num;
        } while (num <= 0 || num > Project_List::project_count);
    }
}
