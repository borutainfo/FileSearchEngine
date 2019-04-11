#include <utility>

#include "TranslationService.h"

string TranslationService::translateQueryToRegex(string query) {
    string regexPattern = move(query);

    // verify number of brackets
    unsigned int openBracket = 0, closeBracket = 0;
    for (char &character : regexPattern) {
        if(character == '(') {
            openBracket++;
        } else if (character == ')') {
            closeBracket++;
        }
    }
    if (openBracket != closeBracket) {
        throw InvalidQueryException();
    }

    // remove multiple spaces
    regexPattern = regex_replace(regexPattern, regex("[ ]{2,}"), " ");

    // sanitize all characters used by regular expressions (except brackets)
    regex specialChars{R"([-[\]{}*+?.,\^$|#\s])"};
    regexPattern = regex_replace(regexPattern, specialChars, R"(\$&)");

    // handle "AND" operator
    size_t position;
    while ((position = regexPattern.find(R"(\ AND\ )")) != string::npos) {
        unsigned int lastPosition = regexPattern.size();

        // left border
        unsigned int currentPosition = position;
        openBracket = closeBracket = 0;
        while (currentPosition > 0) {
            // break by OR
            if (currentPosition > 6 && regexPattern.substr(currentPosition - 6, 6) == R"(\ OR\ )") {
                if (openBracket == closeBracket) {
                    break;
                }
            }
            // break by AND
            if (currentPosition > 7 && regexPattern.substr(currentPosition - 7, 7) == R"(\ AND\ )") {
                if (openBracket == closeBracket) {
                    break;
                }
            }
            // break by bracket
            if (currentPosition > 0 && regexPattern.substr(currentPosition - 1, 1) == R"(()") {
                if (++openBracket > closeBracket) {
                    break;
                } else if (openBracket == closeBracket) {
                    currentPosition--;
                    break;
                }
            }
            if (currentPosition > 0 && regexPattern.substr(currentPosition - 1, 1) == R"())") {
                closeBracket++;
            }
            currentPosition--;
        }
        unsigned int leftBorder = currentPosition;

        // right border
        currentPosition = position + 7;
        openBracket = closeBracket = 0;
        while (currentPosition < lastPosition) {
            // break by OR
            if (currentPosition < lastPosition - 6 && regexPattern.substr(currentPosition, 6) == R"(\ OR\ )") {
                if (closeBracket == openBracket) {
                    break;
                }
            }
            // break by AND
            if (currentPosition < lastPosition - 7 && regexPattern.substr(currentPosition, 7) == R"(\ AND\ )") {
                if (closeBracket == openBracket) {
                    break;
                }
            }
            // break by bracket
            if (currentPosition < lastPosition && regexPattern.substr(currentPosition, 1) == R"())") {
                if (++closeBracket > openBracket) {
                    break;
                } else if (closeBracket == openBracket) {
                    currentPosition++;
                    break;
                }
            }
            if (currentPosition < lastPosition && regexPattern.substr(currentPosition, 1) == R"(()") {
                openBracket++;
            }
            currentPosition++;
        }
        unsigned int rightBorder = currentPosition;

        string subRegexPatern = regexPattern.substr(leftBorder, rightBorder - leftBorder);
        subRegexPatern = regex_replace(subRegexPatern, regex(R"((.+)\\ AND\\ (.+))"), R"((?=.*$1)(?=.*$2))");
        regexPattern = regexPattern.substr(0, leftBorder) + subRegexPatern + regexPattern.substr(rightBorder);
    }

    // handle "OR" operator
    regexPattern = regex_replace(regexPattern, regex(R"(\\ OR\\ )"), "|");

    // handle "NOT" operator
    regexPattern = regex_replace(regexPattern, regex(R"(NOT\\ )"), "?!");

    return "^.*(" + regexPattern + ").*$";
}
