#ifndef FILESEARCHENGINE_COMMANDFACTORY_H
#define FILESEARCHENGINE_COMMANDFACTORY_H

#include <string>
#include <vector>
#include <algorithm>
#include "File/Entity/FileEntity.h"
#include "Terminal/Command/ICommand.h"
#include "Terminal/Command/HelpCommand.h"
#include "Terminal/Exception/CommandNotExistsException.h"
#include "Terminal/Exception/ExitException.h"
#include "File/Command/AddFileCommand.h"

using namespace std;

class CommandFactory {
public:
    explicit CommandFactory(vector<FileEntity> *fileEntityCollection);

    ICommand *create(string commandName);

protected:
    vector<FileEntity> *fileEntityCollection;

};

#endif
