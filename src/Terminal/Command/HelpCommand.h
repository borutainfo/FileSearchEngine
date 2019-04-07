#ifndef FILESEARCHENGINE_HELPCOMMAND_H
#define FILESEARCHENGINE_HELPCOMMAND_H

#include <iostream>
#include <vector>
#include "ICommand.h"

using namespace std;

using namespace std;

class HelpCommand : public ICommand {
public:
    void execute(vector<string> arguments) override;
};


#endif
