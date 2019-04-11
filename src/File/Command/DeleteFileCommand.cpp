#include "DeleteFileCommand.h"

DeleteFileCommand::DeleteFileCommand(vector<FileEntity> *fileEntityCollection) {
    this->fileEntityCollection = fileEntityCollection;
}

void DeleteFileCommand::execute(vector<string> arguments) {
    if (this->fileEntityCollection->empty()) {
        cout << "Collection is empty!" << endl;
        return;
    }

    int successfullyDeleted = 0;

    for (const auto &argument: arguments) {
        if (this->executeForSingleFile(argument)) {
            successfullyDeleted++;
        }
    }

    if (successfullyDeleted > 0) {
        cout << "Successfully deleted " << successfullyDeleted << " files." << endl;
    } else {
        cout << "Failure when deleting files!" << endl;
    }
}

bool DeleteFileCommand::executeForSingleFile(string argument) {
    FileName *fileName = new FileName(argument);

    int counter = 0;
    for (const auto &existingFileEntity: *this->fileEntityCollection) {
        if (existingFileEntity.getFileName()->value() == fileName->value()) {
            this->fileEntityCollection->erase(this->fileEntityCollection->begin() + counter);

            cout << "File '" << argument << "' successfully deleted!" << endl;
            return true;
        }
        counter++;
    }

    return false;
}
