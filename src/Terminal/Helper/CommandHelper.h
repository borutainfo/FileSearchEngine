#ifndef FILESEARCHENGINE_COMMANDHELPER_H
#define FILESEARCHENGINE_COMMANDHELPER_H

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class CommandHelper {
public:
    static string getCommandName(vector<string> userInput);
    static vector<string> getCommandArguments(vector<string> userInput);
};

#endif
