#include "SearchCommand.h"

SearchCommand::SearchCommand(vector<FileEntity> *fileEntityCollection) {
    this->fileEntityCollection = fileEntityCollection;
}

void SearchCommand::execute(vector<string> arguments) {
    if (arguments.empty()) {
        cout << "Invalid search query!" << endl;
        return;
    }

    string searchQuery;
    for (const auto &argument: arguments) {
        searchQuery += argument + " ";
    }
    searchQuery = searchQuery.substr(0, searchQuery.size() - 1);

    auto *translationService = new TranslationService;
    string pattern;
    try {
        pattern = translationService->translateQueryToRegex(searchQuery);
    } catch (InvalidQueryException &e) {
        cout << e.what() << endl;
        return;
    }

    cout << "Regex query: " << pattern << endl << endl;

    regex regex;
    try {
        regex.assign(pattern);
    } catch (...) {
        cout << "Invalid search query!" << endl;
        return;
    }

    vector<SearchResultEntity> resultCollection;

    for (const auto &fileEntity: *this->fileEntityCollection) {
        string content = fileEntity.getFileContent()->value();

        if (regex_search(content.begin(), min(content.end(), content.begin() + (1024 * 4)), regex)) {
            SearchResultEntity searchResultEntity = SearchResultEntityFactory::createFromFileEntity(fileEntity);
            searchResultEntity.setMatches(new PositiveNumber(1));
            resultCollection.push_back(searchResultEntity);
        }
    }

    this->displayResults(&resultCollection);
}

void SearchCommand::displayResults(vector<SearchResultEntity> *resultCollection) {
    if (resultCollection->empty()) {
        cout << "No results!" << endl;
        return;
    }

    cout << "Files that matches to requested search query:" << endl;
    for (const auto &resultEntity: *resultCollection) {
        cout << "- " << resultEntity.getFileName()->value() << endl;
    }
}
