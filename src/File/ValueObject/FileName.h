#ifndef FILESEARCHENGINE_FILENAME_H
#define FILESEARCHENGINE_FILENAME_H

#include <string>
#include <cstring>

using namespace std;

/**
 * @brief ValueObject for file name.
 * @class FileName
 */
class FileName {
public:
    /**
    * @brief ValueObject constructor gets file name as a string.
    * @param string value
    */
    explicit FileName(string value);

    /**
    * @brief Method returns file name as a string.
    * @return string
    */
    const string &value() const;

protected:
    /**
    * @brief This method validate file name.
    * @param string value
    * @return bool
    */
    bool validate(string value);

private:
    string privateValue;
};

#endif
