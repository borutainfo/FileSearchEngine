#ifndef FILESEARCHENGINE_SEARCHCOMMAND_H
#define FILESEARCHENGINE_SEARCHCOMMAND_H

#include <iostream>
#include <vector>
#include "Common/Command/ICommand.h"
#include "File/Entity/FileEntity.h"
#include "Translation/Service/TranslationService.h"

/**
 * @brief Command used to search text in files from collection.
 * @class SearchCommand
 */
class SearchCommand : public ICommand {
public:
    /**
    * @brief SearchCommand constructor gets FileEntity collection (vector).
    * @param vector<FileEntity> *fileEntityCollection
    */
    explicit SearchCommand(vector<FileEntity> *fileEntityCollection);

    /**
    * @brief Method to execute task of searching text in files from collection.
    * @param vector<string> arguments
    */
    void execute(vector<string> arguments) override;

private:
    vector<FileEntity> *fileEntityCollection;
};

#endif
