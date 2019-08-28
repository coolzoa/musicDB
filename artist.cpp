#include <iostream>
#include "artist.h"

Artist::Artist(){}

Artist::Artist(int ID, std::string nm) {
    id = ID;
    name = name;
}


std::string Artist::toString() {
    return "|\t" + std::to_string(id) + "\t|" + "\t" + name + "\t|";
}

std::string Artist::getName() {
    return name;
}

void Artist::setName(std::string nm) {
    name = nm;
}

int Artist::getId() {
    return id;
}