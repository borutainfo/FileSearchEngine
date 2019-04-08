#ifndef FILESEARCHENGINE_ICOMMAND_H
#define FILESEARCHENGINE_ICOMMAND_H

#include <vector>

using namespace std;

/**
 * @brief Command interface.
 * @class ICommand
 */
class ICommand {
public:
    /**
    * @brief Method to execute command overwritten by child class.
    * @param vector<string> arguments
    */
    virtual void execute(vector<string> arguments) = 0;
};

#endif
