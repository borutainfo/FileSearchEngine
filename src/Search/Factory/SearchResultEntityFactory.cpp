#include "SearchResultEntityFactory.h"

SearchResultEntity SearchResultEntityFactory::createFromFileEntity(FileEntity fileEntity) {
    SearchResultEntity searchResultEntity = {};
    searchResultEntity.setFileName(fileEntity.getFileName());
    searchResultEntity.setFileContent(fileEntity.getFileContent());
    return searchResultEntity;
}
