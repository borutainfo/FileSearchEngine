#include "FileContent.h"

/**
 * @brief Exception throws when given string is not correct file content.
 * @struct InvalidFileContentException
 */
struct InvalidFileContentException : public exception {
    const char *what() const noexcept override {
        return "This is not valid file content!";
    }
};

FileContent::FileContent(string value) {
    if (!this->validate(value)) {
        throw InvalidFileContentException();
    }

    this->privateValue = value;
}

bool FileContent::validate(string value) {
    return true; // todo validation
}

const string &FileContent::value() const {
    return this->privateValue;
}
