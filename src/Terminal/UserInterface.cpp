#include "UserInterface.h"

void UserInterface::initMessage() {
    cout << "FileSearchEngine v1.0 by Boruta" << endl;
    cout << "----------------------------------------------------" << endl << endl;
}

vector<string> UserInterface::getUserInput() {
    cout << "Available commands: " << endl;
    cout << "addfile $filename" << endl;

    cout << endl << "FileSearchEngine:~$ ";

    string option;
    cin >> option;
    regex regex{R"([\s]+)"};
    sregex_token_iterator it{option.begin(), option.end(), regex, -1};
    vector<string> result{it, {}};
    return result;
}

void UserInterface::exitMessage() {
    cout << "bye" << endl;
}
