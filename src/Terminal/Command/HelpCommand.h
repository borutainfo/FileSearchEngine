#ifndef FILESEARCHENGINE_HELPCOMMAND_H
#define FILESEARCHENGINE_HELPCOMMAND_H

#include <iostream>
#include <vector>
#include "Common/Command/ICommand.h"

using namespace std;

/**
 * @brief Command used to display help information.
 * @class HelpCommand
 */
class HelpCommand : public ICommand {
public:
    /**
    * @brief Method to execute task of displaying help information.
    * @param vector<string> arguments
    */
    void execute(vector<string> arguments) override;
};

#endif
