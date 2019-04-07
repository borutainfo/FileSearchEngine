#include "DirectoryPath.h"

/**
 * @brief Exception throws when given string is not correct directory path.
 * @struct InvalidDirectoryPathException
 */
struct InvalidDirectoryPathException : public exception {
    const char *what() const noexcept override {
        return "This is not valid directory path!";
    }
};

DirectoryPath::DirectoryPath(string value) {
    if (!this->validate(value)) {
        throw InvalidDirectoryPathException();
    }

    this->privateValue = value;
}

bool DirectoryPath::validate(string value) {
    return true; // todo validation
}

const string &DirectoryPath::value() const {
    return this->privateValue;
}
