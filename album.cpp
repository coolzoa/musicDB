#include "album.h"
#include <string>

Album::Album() {}

Album::Album(int artistID, int ID, std::string nm, int yr) {
    artistId = artistID;
    id = ID;
    name = nm;
    year = yr;
}

std::string Album::toString() {
    return std::to_string(id) + " " + \
     + " " + name + " " + std::to_string(year);
}