#ifndef FILESEARCHENGINE_COMMANDHELPER_H
#define FILESEARCHENGINE_COMMANDHELPER_H

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief Helper for command execution.
 * @class CommandHelper
 */
class CommandHelper {
public:
    /**
    * @brief Method returns command name (first argument of user input).
    * @param vector<string> userInput
    */
    static string getCommandName(vector<string> userInput);

    /**
    * @brief Method returns command arguments (input arguments omitting the command name).
    * @param vector<string> userInput
    */
    static vector<string> getCommandArguments(vector<string> userInput);
};

#endif
