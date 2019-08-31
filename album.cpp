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
    return "\t" + std::to_string(id) + "\t|" + \
     name + "|\t" + std::to_string(year) + "\t|";
}

int Album::getArtistId() {
    return artistId;
}

std::string Album::getName() {
    return name;
}