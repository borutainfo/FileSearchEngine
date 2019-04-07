#ifndef FILESEARCHENGINE_FILEHELPER_H
#define FILESEARCHENGINE_FILEHELPER_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <streambuf>

using namespace std;

class FileHelper {
public:
    static bool fileExists(string fileName);
    static string getFileContent(string fileName);
};

#endif
