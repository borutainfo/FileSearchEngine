#ifndef FILESEARCHENGINE_COMMANDNOTEXISTSEXCEPTION_H
#define FILESEARCHENGINE_COMMANDNOTEXISTSEXCEPTION_H

#include <exception>

using namespace std;

/**
 * @brief Exception thrown if no command match to command name.
 * @struct CommandNotExistsException
 */
struct CommandNotExistsException : public exception {
    const char *what() const noexcept override {
        return "Command not exists!";
    }
};

#endif
