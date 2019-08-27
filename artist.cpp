#include <iostream>
#include "artist.h"

Artist::Artist(){}

Artist::Artist(int ID, std::string nm) {
    id = ID;
    name = name;
}


std::string Artist::toString() {
    return std::to_string(id) + " " + \
     + " " + name;
}