#ifndef FILESEARCHENGINE_ADDFILECOMMAND_H
#define FILESEARCHENGINE_ADDFILECOMMAND_H

#include <iostream>
#include <vector>
#include "Common/Command/ICommand.h"
#include "File/Entity/FileEntity.h"
#include "File/Helper/FileHelper.h"

using namespace std;

/**
 * @brief Command used to adding a file to collection.
 * @class AddFileCommand
 */
class AddFileCommand : public ICommand {
public:
    /**
    * @brief AddFileCommand constructor gets FileEntity collection (vector).
    * @param vector<FileEntity> *fileEntityCollection
    */
    explicit AddFileCommand(vector<FileEntity> *fileEntityCollection);

    /**
    * @brief Method to execute task of adding multiple files to collection.
    * @param vector<string> arguments
    */
    void execute(vector<string> arguments) override;

protected:
    /**
    * @brief Internal method to execute task of adding single file to collection.
    * @param string argument
    * @return bool
    */
    bool executeForSingleFile(string argument);

private:
    vector<FileEntity> *fileEntityCollection;
};

#endif
