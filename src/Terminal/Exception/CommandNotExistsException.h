#ifndef FILESEARCHENGINE_COMMANDNOTEXISTSEXCEPTION_H
#define FILESEARCHENGINE_COMMANDNOTEXISTSEXCEPTION_H

struct CommandNotExistsException : public exception {
    const char *what() const noexcept override {
        return "Command not exists!";
    }
};

#endif
