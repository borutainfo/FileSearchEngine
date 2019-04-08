#include "FileName.h"

FileName::FileName(string value) {
    if (!this->validate(value)) {
        throw InvalidFileNameException();
    }

    this->privateValue = value;
}

bool FileName::validate(string value) {
    char deniedCharacters[] = {'!', '@', '%', '^', '*', '~', '|'};

    for (char deniedCharacter: deniedCharacters) {
        if (strchr(value.c_str(), deniedCharacter) != nullptr) {
            return false;
        }
    }

    return !value.empty();
}

const string &FileName::value() const {
    return this->privateValue;
}
