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
    string pattern = translationService->translateQueryToRegex(searchQuery);

    cout << "Regex query: " << pattern << endl << endl;

    regex regex(pattern);
    vector<SearchResultEntity> resultCollection;

    for (const auto &fileEntity: *this->fileEntityCollection) {
        string content = fileEntity.getFileContent()->value();
        smatch matches;

        while (regex_search(content, matches, regex)) {
            for (auto x:matches)
                cout << x << " ";
            cout << endl;
            content = matches.suffix().str();
        }

//        if (matches > 0) {
//            SearchResultEntity searchResultEntity = SearchResultEntityFactory::createFromFileEntity(fileEntity);
//            resultCollection.push_back(searchResultEntity);
//        }
    }

    this->displayResults(&resultCollection);
}

void SearchCommand::displayResults(vector<SearchResultEntity> *resultCollection) {
    if (resultCollection->empty()) {
        cout << "No results!" << endl;
        return;
    }

    for (const auto &resultEntity: *resultCollection) {
        cout << resultEntity.getFileName()->value() << " - number of results : ";
        cout << resultEntity.getMatches()->value() << endl;
    }
}
