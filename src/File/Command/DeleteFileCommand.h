#ifndef FILESEARCHENGINE_DELETEFILECOMMAND_H
#define FILESEARCHENGINE_DELETEFILECOMMAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Common/Command/ICommand.h"
#include "File/Entity/FileEntity.h"

using namespace std;

/**
 * @brief Command used to delete a file from collection.
 * @class DeleteFileCommand
 */
class DeleteFileCommand : public ICommand {
public:
    /**
    * @brief DeleteFileCommand constructor gets FileEntity collection (vector).
    * @param vector<FileEntity> *fileEntityCollection
    */
    explicit DeleteFileCommand(vector<FileEntity> *fileEntityCollection);

    /**
    * @brief Method to execute task of deleting multiple files from collection.
    * @param vector<string> arguments
    */
    void execute(vector<string> arguments) override;

protected:
    /**
    * @brief Internal method to execute task of deleting single file from collection.
    * @param string argument
    * @return bool
    */
    bool executeForSingleFile(string argument);

private:
    vector<FileEntity> *fileEntityCollection;
};

#endif
