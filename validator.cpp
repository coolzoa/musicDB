#include "validator.h"
#include <string>
#include <algorithm> //transform()
#include <stdlib.h> //atof()


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

bool Validator::isFloat(std::string str) {
    if (atof(str.c_str()) == 0) {
        return false;
    } else {
        return true;
    }
}


// adapted from https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case
std::string Validator::toLower(std::string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    str[0] = toupper(str[0]);
    return str;
}


