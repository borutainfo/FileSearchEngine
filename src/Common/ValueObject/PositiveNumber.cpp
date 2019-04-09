#include "PositiveNumber.h"

PositiveNumber::PositiveNumber(int value) {
    if (!this->validate(value)) {
        throw InvalidPositiveNumberException();
    }

    this->privateValue = value;
}

bool PositiveNumber::validate(int value) {
    return value > 0;
}

const int &PositiveNumber::value() const {
    return this->privateValue;
}
