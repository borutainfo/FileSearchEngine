#include "AddFileCommand.h"

AddFileCommand::AddFileCommand(vector<FileEntity> *fileEntityCollection) {
    this->fileEntityCollection = fileEntityCollection;
}

void AddFileCommand::execute(vector<string> arguments) {
    cout << endl << "AddFile";
}
