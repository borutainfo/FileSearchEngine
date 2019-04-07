#include <iostream>
#include <vector>
#include "Terminal/UserInterface.h"
#include "File/Entity/FileEntity.h"
#include "Terminal/Factory/CommandFactory.h"
#include "Terminal/Helper/CommandHelper.h"

using namespace std;

int main() {
    vector<FileEntity> fileEntityCollection;

    auto *userInterface = new UserInterface;
    auto *commandFactory = new CommandFactory(&fileEntityCollection);

    userInterface->initMessage();

    while (true) {
        try {
            vector<string> userInput = userInterface->getUserInput();

            ICommand *command = nullptr;
            command = commandFactory->create(CommandHelper::getCommandName(userInput));
            command->execute(CommandHelper::getCommandArguments(userInput));
        } catch (ExitException &e) {
            break;
        } catch (...) {
            break;
        }
    };

    userInterface->exitMessage();

    return 0;
}
