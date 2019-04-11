#ifndef FILESEARCHENGINE_ABOUTCOMMAND_H
#define FILESEARCHENGINE_ABOUTCOMMAND_H

#include <iostream>
#include <vector>
#include "Common/Command/ICommand.h"

using namespace std;

/**
 * @brief Command used to display information about application.
 * @class AboutCommand
 */
class AboutCommand : public ICommand {
    /**
    * @brief Method to execute task of displaying information about application.
    * @param vector<string> arguments
    */
    void execute(vector<string> arguments) override;
};

#endif
