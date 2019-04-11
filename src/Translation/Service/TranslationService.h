#ifndef FILESEARCHENGINE_TRANSLATIONSERVICE_H
#define FILESEARCHENGINE_TRANSLATIONSERVICE_H

#include <string>
#include <regex>
#include <iostream>
#include "Translation/Exception/InvalidQueryException.h"

using namespace std;

/**
 * @brief Service used to translate input search query to regular expression.
 * @class TranslationService
 */
class TranslationService {
public:
    /**
    * @brief Method returns regular expression created from input search query.
    * @param string query
    * @return string
    * @throw InvalidQueryException when given query is incorrect
    */
    string translateQueryToRegex(string query);
};

#endif
