#include "FileEntity.h"

FileName *FileEntity::getFileName() const {
    return fileName;
}

void FileEntity::setFileName(FileName *fileName) {
    FileEntity::fileName = fileName;
}

FileContent *FileEntity::getFileContent() const {
    return fileContent;
}

void FileEntity::setFileContent(FileContent *fileContent) {
    FileEntity::fileContent = fileContent;
}
