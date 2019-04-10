#include "FileHelper.h"

bool FileHelper::fileExists(string fileName) {
    std::ifstream inputFile(fileName);
    return inputFile.good();
}

string FileHelper::getFileContent(string fileName) {
    ifstream inputFile(fileName);
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    replace(fileContent.begin(), fileContent.end(), '\n', ' ');
    return fileContent;
}
