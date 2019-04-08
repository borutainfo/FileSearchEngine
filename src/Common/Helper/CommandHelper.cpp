#include "CommandHelper.h"

string CommandHelper::getCommandName(vector<string> userInput) {
    string command = userInput.front();
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    return command;
}

vector<string> CommandHelper::getCommandArguments(vector<string> userInput) {
    if (userInput.size() > 1) {
        userInput.erase(userInput.begin());
    } else {
        userInput = vector<string>();
    }
    return userInput;
}
