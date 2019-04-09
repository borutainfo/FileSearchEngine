#ifndef FILESEARCHENGINE_FILEHELPER_H
#define FILESEARCHENGINE_FILEHELPER_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <streambuf>

using namespace std;

/**
 * @brief Helper for file handling.
 * @class FileHelper
 */
class FileHelper {
public:
    /**
    * @brief Method returns true if file exists, false otherwise.
    * @param string fileName
    * @return bool
    */
    static bool fileExists(string fileName);

    /**
    * @brief Method returns file content as string.
    * @param string fileName
    * @return string
    */
    static string getFileContent(string fileName);
};

#endif
