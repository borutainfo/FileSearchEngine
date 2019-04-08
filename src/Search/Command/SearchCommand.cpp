#include "SearchCommand.h"

SearchCommand::SearchCommand(vector<FileEntity> *fileEntityCollection) {
    this->fileEntityCollection = fileEntityCollection;
}

void SearchCommand::execute(vector<string> arguments) {
    if (arguments.empty()) {
        cout << "Invalid search query!" << endl;
        return;
    }

    string searchQuery = arguments.front();

    auto *translationService = new TranslationService;
    string regex = translationService->translateQueryToRegex(searchQuery);

    for (const auto &fileEntity: *this->fileEntityCollection) {
        fileEntity.getFileContent()->value().find(regex);
    }

    cout << endl << "NOT FOUND" << endl;
}
