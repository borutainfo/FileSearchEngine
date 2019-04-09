#ifndef FILESEARCHENGINE_SEARCHRESULTENTITYFACTORY_H
#define FILESEARCHENGINE_SEARCHRESULTENTITYFACTORY_H

#include "Search/Entity/SearchResultEntity.h"

using namespace std;

/**
 * @brief Factory for creating SearchResultEntity from FileEntity.
 * @class SearchResultEntityFactory
 */
class SearchResultEntityFactory {
public:
    /**
    * @brief Method returns SearchResultEntity based on given FileEntity.
    * @param FileEntity fileEntity
    * @return SearchResultEntity
    */
    static SearchResultEntity createFromFileEntity(FileEntity fileEntity);
};

#endif
