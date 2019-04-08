#include "BasicCommunicationService.h"

void BasicCommunicationService::beginNotice() {
    cout << "FileSearchEngine v1.0 by Boruta" << endl;
    cout << "----------------------------------------------------" << endl << endl;
}

vector<string> BasicCommunicationService::getUserInput() {
    cout << "Available commands: " << endl;
    cout << "addfile $filename" << endl;

    cout << endl << "FileSearchEngine:~$ ";

    string option;
    getline(cin, option);

    stringstream str_strm(option);
    string tmp;
    vector<string> words;
    char delim = ' ';

    while (getline(str_strm, tmp, delim)) {
        words.push_back(tmp);
    }

    return words;
}

void BasicCommunicationService::endNotice() {
    cout << "bye" << endl;
}
