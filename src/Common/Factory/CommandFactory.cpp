#include "CommandFactory.h"

ICommand *CommandFactory::create(string commandName) {
    if (commandName == CommandConstant::EXIT) {
        throw ExitCommand();
    } else if (commandName == CommandConstant::HELP) {
        return new HelpCommand();
    } else if (commandName == CommandConstant::ADD_FILE) {
        return new AddFileCommand(this->fileEntityCollection);
    } else if (commandName == CommandConstant::SEARCH) {
        return new SearchCommand(this->fileEntityCollection);
    } else if (commandName == CommandConstant::ABOUT) {
        return new AboutCommand();
    } else if (commandName == CommandConstant::DELETE) {
        return new DeleteFileCommand(this->fileEntityCollection);
    }

    throw CommandNotExistsException();
}

CommandFactory::CommandFactory(vector<FileEntity> *fileEntityCollection) : fileEntityCollection(fileEntityCollection) {}
