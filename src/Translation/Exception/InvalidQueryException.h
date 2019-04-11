#ifndef FILESEARCHENGINE_INVALIDQUERYEXCEPTION_H
#define FILESEARCHENGINE_INVALIDQUERYEXCEPTION_H

#include <exception>

using namespace std;

/**
 * @brief Exception thrown if no search query is invalid.
 * @struct InvalidQueryException
 */
struct InvalidQueryException : public exception {
    const char *what() const noexcept override {
        return "Search query is invalid!";
    }
};

#endif
