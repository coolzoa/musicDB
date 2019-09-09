#include "album.h"
#include <iostream>
#include <string>

Album::Album() {}

Album::Album(int artistID, int ID, std::string nm, int yr) {
    artistId = artistID;
    id = ID;
    name = nm;
    year = yr;
}

std::string Album::toString() {
    return "\t" + std::to_string(id) + "\t|\t" + name + "\t|\t" + std::to_string(year) + "\t|";
}

int Album::getArtistId() {
    return artistId;
}

std::string Album::getName() {
    return name;
}

int Album::getAlbumId() {
    return id;
}

void Album::setAlbumId(int newId) {
    id = newId;
}

int Album::getYear() {
    return year;
}