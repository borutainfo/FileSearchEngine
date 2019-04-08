#ifndef FILESEARCHENGINE_FILECONTENT_H
#define FILESEARCHENGINE_FILECONTENT_H

#include <string>
#include "File/Exception/InvalidFileContentException.h"

using namespace std;

/**
 * @brief ValueObject for file content.
 * @class FileContent
 */
class FileContent {
public:
    /**
    * @brief ValueObject constructor gets file content as a string.
    * @param string value
    * @throw InvalidFileContentException throw exception on invalid value
    */
    explicit FileContent(string value);

    /**
    * @brief Method returns file content as a string.
    * @return string
    */
    const string &value() const;

protected:
    /**
    * @brief This method validate file content.
    * @param string value
    * @return bool
    */
    bool validate(string value);

private:
    string privateValue;
};

#endif
