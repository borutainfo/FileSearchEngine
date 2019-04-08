#ifndef FILESEARCHENGINE_INVALIDFILENAMEEXCEPTION_H
#define FILESEARCHENGINE_INVALIDFILENAMEEXCEPTION_H

#include <exception>

using namespace std;

/**
 * @brief Exception thrown when given string is not correct file name.
 * @struct InvalidFileNameException
 */
struct InvalidFileNameException : public exception {
    const char *what() const noexcept override {
        return "This is not valid file name!";
    }
};

#endif
