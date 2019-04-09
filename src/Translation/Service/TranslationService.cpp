#include <utility>

#include "TranslationService.h"

string TranslationService::translateQueryToRegex(string query) {
//    return query;

    string regexPattern = std::move(query);

    // remove multiple spaces
    regexPattern = regex_replace(regexPattern, regex("[ ]{2,}"), " ");

    // remove spaces connected with a parenthesis
//    regexPattern = regex_replace(regexPattern, regex("( \\()"), "(");
//    regexPattern = regex_replace(regexPattern, regex("(\\( )"), "(");
//    regexPattern = regex_replace(regexPattern, regex("( \\))"), ")");
//    regexPattern = regex_replace(regexPattern, regex("(\\) )"), ")");

    // sanitize all characters used by regular expressions (except parenthesis)
    regex specialChars{R"([-[\]{}*+?.,\^$|#\s])"};
    regexPattern = regex_replace(regexPattern, specialChars, R"(\$&)");

    // handle "AND" operator
//    regexPattern = regex_replace(regexPattern, regex(R"((.*)\\ OR\\ (.+)\\ AND\\ (.+)\\ OR\\ (.*))"), R"($1(?=.*\b$2\b)(?=.*\b$3\b)$4)");
    
    regexPattern = regex_replace(regexPattern, regex(R"((.*)\((.+)\\ AND\\ (.+)\)(.*))"), R"($1(?=.*\b$2\b)(?=.*\b$3\b)$4)");
    regexPattern = regex_replace(regexPattern, regex(R"((.+)\\ AND\\ (.+))"), R"((?=.*\b$1\b)(?=.*\b$2\b))");

    // handle "OR" operator
    regexPattern = regex_replace(regexPattern, regex(R"(\\ OR\\ )"), "|");

    return "^.*(" + regexPattern + ").*";
}


//^(?=.*\bhas\b)(?=.*\bsubmarine\b).*$