#ifndef FILESEARCHENGINE_SEARCHRESULTENTITY_H
#define FILESEARCHENGINE_SEARCHRESULTENTITY_H

#include "File/Entity/FileEntity.h"
#include "Common/ValueObject/PositiveNumber.h"

/**
 * @brief Entity for search result.
 * @struct SearchResultEntity
 */
class SearchResultEntity : public FileEntity {
protected:
    PositiveNumber *matches = nullptr;

public:
    /**
    * @brief Method returns PositiveNumber VO (number of search matches).
    * @return PositiveNumber
    */
    PositiveNumber *getMatches() const;

    /**
     * @brief Method sets PositiveNumber VO in entity.
     * @param PositiveNumber *matches
     */
    void setMatches(PositiveNumber *matches);
};

#endif
