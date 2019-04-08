#ifndef FILESEARCHENGINE_INVALIDFILECONTENTEXCEPTION_H
#define FILESEARCHENGINE_INVALIDFILECONTENTEXCEPTION_H

#include <exception>

using namespace std;

/**
 * @brief Exception thrown when given string is not correct file content.
 * @struct InvalidFileContentException
 */
struct InvalidFileContentException : public exception {
    const char *what() const noexcept override {
        return "This is not valid file content!";
    }
};

#endif
