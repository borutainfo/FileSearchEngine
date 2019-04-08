#include <iostream>
#include <vector>
#include "Terminal/Service/BasicCommunicationService.h"
#include "File/Entity/FileEntity.h"
#include "Common/Factory/CommandFactory.h"
#include "Common/Helper/CommandHelper.h"

using namespace std;

int main() {
    vector<FileEntity> fileEntityCollection;

    auto *basicCommunicationService = new BasicCommunicationService;
    auto *commandFactory = new CommandFactory(&fileEntityCollection);

    basicCommunicationService->beginNotice();

    while (true) {
        try {
            vector<string> userInput = basicCommunicationService->getUserInput();

            ICommand *command = commandFactory->create(CommandHelper::getCommandName(userInput));
            command->execute(CommandHelper::getCommandArguments(userInput));
        } catch (ExitCommand &e) {
            break;
        } catch (...) {
            return -1;
        }
    };

    basicCommunicationService->endNotice();

    return 0;
}
