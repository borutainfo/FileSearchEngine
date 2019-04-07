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
    char deniedCharacters[] = {'!', '@', '%', '^', '*', '~', '|'};

    for (char deniedCharacter: deniedCharacters) {
        if (strchr(value.c_str(), deniedCharacter) != nullptr) {
            return false;
        }
    }

    return !value.empty();
}

const string &FileName::value() const
{
    return this->privateValue;
}
