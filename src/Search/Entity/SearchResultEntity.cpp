#include "SearchResultEntity.h"

PositiveNumber *SearchResultEntity::getMatches() const {
    return matches;
}

void SearchResultEntity::setMatches(PositiveNumber *matches) {
    SearchResultEntity::matches = matches;
}
