#include<iostream>
#include <string>
#include "song.h"

Song::Song() { }


Song::Song(int albumID, int tNumber, std::string nm, double dur) {
    albumId = albumID;
    trackNumber = tNumber;
    name = nm;
    duration = dur;
}


std::string Song::toString() {

    return "\t" + std::to_string(trackNumber) + "\t|\t" + name + "\t|\t" + std::to_string(duration) + "\t|";
}

int Song::getAlbumId() {
    return albumId;
}

std::string Song::getName() {
    return name;
}

int Song::getTrackNumber() {
    return trackNumber;
}

void Song::setTrackNumber(int newTrack) {
    trackNumber = newTrack;
}

double Song::getDuration() {
    return duration;
}





