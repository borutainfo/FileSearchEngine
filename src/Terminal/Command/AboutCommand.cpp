#include "AboutCommand.h"

void AboutCommand::execute(vector<string> arguments) {
    cout << "About application:" << endl << endl;

    cout << "Application has been created as part of a student project" << endl;
    cout << "in the subject \"Advanced C++\" at the Warsaw University of Technology."<< endl << endl;
    cout << "Author: Sebastian Boruta" << endl;
    cout << "Contact: sebastian@boruta.info" << endl << endl;
    cout << "https://boruta.info/" << endl;
}
