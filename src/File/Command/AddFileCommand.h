#ifndef FILESEARCHENGINE_ADDFILECOMMAND_H
#define FILESEARCHENGINE_ADDFILECOMMAND_H

#include <iostream>
#include <string>
#include <vector>
#include "File/Entity/FileEntity.h"
#include "Terminal/Command/ICommand.h"
#include "File/Helper/FileHelper.h"

using namespace std;

class AddFileCommand : public ICommand {
public:
    explicit AddFileCommand(vector<FileEntity> *fileEntityCollection);

    void execute(vector<string> arguments) override;

protected:
    vector<FileEntity> *fileEntityCollection;

    bool executeForSingleFile(string argument);
};

#endif
