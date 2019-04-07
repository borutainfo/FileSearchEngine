#ifndef FILESEARCHENGINE_USERINTERFACE_H
#define FILESEARCHENGINE_USERINTERFACE_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class UserInterface {
public:
    void initMessage();

    vector<string> getUserInput();

    void exitMessage();
};

#endif
