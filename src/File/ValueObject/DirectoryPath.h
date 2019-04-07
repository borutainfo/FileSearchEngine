#ifndef FILESEARCHENGINE_DIRECTORYPATH_H
#define FILESEARCHENGINE_DIRECTORYPATH_H

#include <string>

using namespace std;

/**
 * @brief ValueObject for directory path.
 * @class DirectoryPath
 */
class DirectoryPath {
public:
    /**
    * @brief ValueObject constructor gets directory path as a string.
    * @param string value
    */
    explicit DirectoryPath(string value);

    /**
    * @brief Method returns directory path as a string.
    * @return string
    */
    const string &value() const;

protected:
    /**
    * @brief This method validate directory path.
    * @param string value
    * @return bool
    */
    bool validate(string value);

private:
    string privateValue;
};


#endif
