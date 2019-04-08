#ifndef FILESEARCHENGINE_COMMANDFACTORY_H
#define FILESEARCHENGINE_COMMANDFACTORY_H

#include <string>
#include <vector>
#include "Common/Command/ICommand.h"
#include "File/Entity/FileEntity.h"
#include "File/Command/AddFileCommand.h"
#include "Terminal/Command/HelpCommand.h"
#include "Common/Exception/CommandNotExistsException.h"
#include "Common/Exception/ExitCommand.h"

using namespace std;

/**
 * @brief Factory for ICommand.
 * @class CommandFactory
 */
class CommandFactory {
public:
    /**
    * @brief CommandFactory constructor gets FileEntity collection (vector).
    * @param vector<FileEntity> *fileEntityCollection
    */
    explicit CommandFactory(vector<FileEntity> *fileEntityCollection);

    /**
    * @brief Method create ICommand object according to received command name.
    * @param string commandName
    * @return ICommand child class object
    */
    ICommand *create(string commandName);

private:
    vector<FileEntity> *fileEntityCollection;
};

#endif
