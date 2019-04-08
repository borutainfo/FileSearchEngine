#ifndef FILESEARCHENGINE_USERINTERFACE_H
#define FILESEARCHENGINE_USERINTERFACE_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @brief Service for transmission of low level messages.
 * @class BasicCommunicationService
 */
class BasicCommunicationService {
public:
    /**
    * @brief Display welcome message.
    */
    void beginNotice();

    /**
    * @brief Method returns input data from the user.
    * @return vector<string>
    */
    vector<string> getUserInput();

    /**
    * @brief Display farewell message.
    */
    void endNotice();
};

#endif
