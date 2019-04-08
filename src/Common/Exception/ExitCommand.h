#ifndef FILESEARCHENGINE_EXITEXCEPTION_H
#define FILESEARCHENGINE_EXITEXCEPTION_H

#include <exception>

using namespace std;

/**
 * @brief Exception thrown if exit command has been executed. Used to exit the program.
 * @struct ExitCommand
 */
struct ExitCommand : public exception {
};

#endif
