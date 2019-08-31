#include <string>
#include "message.h"

const std::string Message::invalidOption = "Whoops, it seems that is an invalid option.";

std::string Message::errorEmpty(std::string input) {
    return "Whoops, " + input + " cannot be empty";
}

std::string Message::errorFormat(std::string input, std::string format) {
    return "Whoops, " + input + " cannot contain " + format;
}

std::string Message::maxCapacity(std::string className) {
    return "Whoops, we have run out of space for more " + className;
}

std::string Message::errorMatch(std::string property) {
    return "An instance of that " + property + " does not exist";
}

std::string Message::foundMatch(std::string className) {
    return "That " + className + " exists in the database";
}

std::string Message::newObjectAdded(std::string className) {
    return "New " + className + " added";
}