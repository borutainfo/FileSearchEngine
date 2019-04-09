#ifndef FILESEARCHENGINE_POSITIVENUMBER_H
#define FILESEARCHENGINE_POSITIVENUMBER_H

#include <string>
#include "Common/Exception/InvalidPositiveNumberException.h"

using namespace std;

/**
 * @brief ValueObject for positive number.
 * @class PositiveNumber
 */
class PositiveNumber {
public:
    /**
    * @brief ValueObject constructor gets positive number as integer.
    * @param integer value
    * @throw InvalidPositiveNumberException throw exception on invalid value
    */
    explicit PositiveNumber(int value);

    /**
    * @brief Method returns positive number as a integer.
    * @return int
    */
    const int &value() const;

protected:
    /**
    * @brief This method validate positive number.
    * @param int value
    * @return bool
    */
    bool validate(int value);

private:
    int privateValue;
};

#endif
