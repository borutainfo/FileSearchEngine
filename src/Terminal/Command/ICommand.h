#ifndef FILESEARCHENGINE_ICOMMAND_H
#define FILESEARCHENGINE_ICOMMAND_H

#include <vector>

using namespace std;

class ICommand {
public:
    virtual void execute(vector<string> arguments) = 0;
};

#endif
