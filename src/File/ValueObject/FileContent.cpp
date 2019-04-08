#include "FileContent.h"

FileContent::FileContent(string value) {
    if (!this->validate(value)) {
        throw InvalidFileContentException();
    }

    this->privateValue = value;
}

bool FileContent::validate(string value) {
    return !value.empty();
}

const string &FileContent::value() const {
    return this->privateValue;
}
