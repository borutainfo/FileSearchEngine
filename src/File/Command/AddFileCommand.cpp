#include "AddFileCommand.h"

AddFileCommand::AddFileCommand(vector<FileEntity> *fileEntityCollection) {
    this->fileEntityCollection = fileEntityCollection;
}

void AddFileCommand::execute(vector<string> arguments) {
    int successfullyAdded = 0;
    for (const auto &argument: arguments) {
        if (this->executeForSingleFile(argument)) {
            successfullyAdded++;
        }
    }

    if (successfullyAdded > 0) {
        cout << "Successfully added " << successfullyAdded << " files." << endl;
    } else {
        cout << "Failure when adding files!" << endl;
    }
}

bool AddFileCommand::executeForSingleFile(string argument) {
    if (!FileHelper::fileExists(argument)) {
        cout << "File '" << argument << "' not exists!" << endl;
        return false;
    }

    FileEntity fileEntity = {};
    fileEntity.setFileName(new FileName(argument));
    fileEntity.setFileContent(new FileContent(FileHelper::getFileContent(argument)));

    for (const auto &existingFileEntity: *this->fileEntityCollection) {
        if (existingFileEntity.getFileName()->value() == fileEntity.getFileName()->value()) {
            cout << "File '" << argument << "' already exists in collection!" << endl;
            return false;
        }
    }

    this->fileEntityCollection->push_back(fileEntity);

    cout << "File '" << argument << "' successfully added!" << endl;
    return true;
}
