#ifndef FILESEARCHENGINE_INVALIDPOSITIVENUMBEREXCEPTION_H
#define FILESEARCHENGINE_INVALIDPOSITIVENUMBEREXCEPTION_H

#include <exception>

using namespace std;

/**
 * @brief Exception thrown when given number is not correct positive number.
 * @struct InvalidPositiveNumberException
 */
struct InvalidPositiveNumberException : public exception {
    const char *what() const noexcept override {
        return "This is not valid positive number!";
    }
};

#endif
