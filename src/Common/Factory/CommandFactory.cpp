#include "CommandFactory.h"

ICommand *CommandFactory::create(string commandName) {
    if (commandName == "exit") {
        throw ExitCommand();
    } else if (commandName == "help") {
        return new HelpCommand();
    } else if (commandName == "addfile") {
        return new AddFileCommand(this->fileEntityCollection);
    }

    throw CommandNotExistsException();
}

CommandFactory::CommandFactory(vector<FileEntity> *fileEntityCollection) : fileEntityCollection(fileEntityCollection) {}
