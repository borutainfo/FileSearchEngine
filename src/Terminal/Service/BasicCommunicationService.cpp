#include "BasicCommunicationService.h"

void BasicCommunicationService::beginNotice() {
    cout << "FileSearchEngine v1.0 by Boruta" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "type 'help' to get more informations" << endl;
}

vector<string> BasicCommunicationService::getUserInput() {
    cout << endl << "FileSearchEngine:~$ ";

    string option;
    getline(cin, option);

    stringstream str_strm(option);
    string tmp;
    vector<string> words;
    while (getline(str_strm, tmp, ' ')) {
        words.push_back(tmp);
    }

    return words;
}

void BasicCommunicationService::endNotice() {
    cout << endl << "Thank you, bye!" << endl;
}
