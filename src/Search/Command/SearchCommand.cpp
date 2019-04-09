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
    vector<SearchResultEntity> resultCollection;

    for (const auto &fileEntity: *this->fileEntityCollection) {
        string content = fileEntity.getFileContent()->value();
        ptrdiff_t matches = distance(std::sregex_iterator(content.begin(), content.end(), regex), sregex_iterator());

        if (matches > 0) {
            SearchResultEntity searchResultEntity = SearchResultEntityFactory::createFromFileEntity(fileEntity);
            searchResultEntity.setMatches(new PositiveNumber(matches));
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

    for (const auto &resultEntity: *resultCollection) {
        cout << resultEntity.getFileName()->value() << " - number of results : ";
        cout << resultEntity.getMatches()->value() << endl;
    }
}
