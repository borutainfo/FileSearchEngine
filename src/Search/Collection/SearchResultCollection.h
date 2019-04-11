#ifndef FILESEARCHENGINE_SEARCHRESULTCOLLECTION_H
#define FILESEARCHENGINE_SEARCHRESULTCOLLECTION_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Template for storing and displaying search results.
 * @class SearchResultCollection
 * @tparam T object storing single search result
 */
template<class T>
class SearchResultCollection {
public:
    /**
    * @brief Method to add object to result collection.
    * @param T singleResult
    */
    void add(T singleResult);

    /**
    * @brief Method to display all search results.
    */
    void display();

private:
    vector<T> data;
};

#endif
