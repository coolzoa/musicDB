#include "validator.h"
#include <string>
#include <algorithm>


bool Validator::isEmpty(std::string str) {
    return str.size() == 0;
}

bool Validator::isNumber(std::string str) {
    int length = str.size();
    int i = 0;
    while (i < length) {
        if (!isdigit(str[i])) {
            return false;
        } else {
            i = i + 1;
        }
    }
    return true;
}

bool Validator::isAlpha(std::string str) {
    int length = str.size();
    int i = 0;
    while (i < length) {
        if (!isalpha(str[i])) {
            return false;
        } else {
            i = i + 1;
        }
    }
    return true;
}
// adapted from https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
std::string Validator::toLower(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
