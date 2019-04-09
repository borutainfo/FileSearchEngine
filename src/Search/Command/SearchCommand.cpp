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
    string pattern = translationService->translateQueryToRegex(searchQuery);

    regex regex(pattern);

    for (const auto &fileEntity: *this->fileEntityCollection) {
        string content = fileEntity.getFileContent()->value();
        ptrdiff_t matches = distance(std::sregex_iterator(content.begin(), content.end(), regex), sregex_iterator());
    }

    cout << endl << "NOT FOUND" << endl;
}
