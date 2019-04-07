#include "FileName.h"

/**
 * @brief Exception throws when given string is not correct file name.
 * @struct InvalidFileNameException
 */
struct InvalidFileNameException : public exception {
    const char *what() const noexcept override {
        return "This is not valid file name!";
    }
};

FileName::FileName(string value)
{
    if (!this->validate(value)) {
        throw InvalidFileNameException();
    }

    this->privateValue = value;
}

bool FileName::validate(string value)
{
    return true; // todo validation
}

const string &FileName::value() const
{
    return this->privateValue;
}
