#include "HelpCommand.h"

void HelpCommand::execute(vector<string> arguments) {
    cout << "Available commands:" << endl << endl;

    cout << "about" << endl << endl << "  ";
    cout << "Show information about the project and the author." << endl << endl;

    cout << "add $filename1 [$filename2 ...]" << endl << endl << "  ";
    cout << "Add a file to the collection in which you will search for data." << endl << "  ";
    cout << "You can add one file or several at a time." << endl << endl;

    cout << "delete $filename1 [$filename2 ...]" << endl << endl << "  ";
    cout << "Delete file from collection in which you will search for data." << endl << "  ";
    cout << "You can delete one file or several at a time." << endl << endl;

    cout << "exit" << endl << endl << "  ";
    cout << "Close the application." << endl << endl;

    cout << "help" << endl << endl << "  ";
    cout << "Get information about how to use this application." << endl << endl;

    cout << "search $searchQuery" << endl << endl << "  ";
    cout << "Search for text in files added to the collection using the given expression." << endl << "  ";
    cout << "You can use brackets \"(\", \")\", and following operators \"AND\", \"OR\", \"NOT\"." << endl << "  ";
    cout << "The size of the characters matters - for operators, you must use capital letters." << endl << "  ";
    cout << "The operator must be separated by a space from the search text." << endl << "  ";
    cout << "You can use any characters. If you use spaces between two words" << endl << "  ";
    cout << "the engine will search for the entire expression (including spaces)." << endl << "  ";
    cout << "If you want to search for a bracket, you must precede it with a slash." << endl << endl << "   ";
    cout << "Some examples - good:" << endl << endl << "      ";
    cout << " search Sebastian AND Boruta" << endl << "      ";
    cout << " search Sebastian OR Boruta AND NOT Kowalski" << endl << "      ";
    cout << " search (Sebastian Boruta OR Mickiewicz) AND NOT Kowalski" << endl << "      ";
    cout << " search (NOT (Sebastian OR Boruta) AND Kowalski) OR Nowak" << endl << endl << "    ";
    cout << "BAD (not working properly):" << endl << endl << "      ";
    cout << " search SebastianANDBoruta" << endl << "      ";
    cout << " search SebastianOR Boruta AND NOTKowalski" << endl << "      ";
    cout << " search Sebastian OR Boruta) AND NOT Kowalski" << endl << "      ";
    cout << " search (NOT (Sebastian OR Boruta) AND Kowalski)OR((Nowak" << endl << "      ";
}
