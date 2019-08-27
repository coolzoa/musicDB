#include <iostream>
#include <string>
#include "song.h"
#include "validator.h"
#include "album.h"
#include "artist.h"

using namespace std;

const int MAX = 200;

int numberSongs = 0;
int numberAlbums = 0;
int numberArtists = 0;

int artistId = 0;
int albumId = 0;

Song songs[MAX];
Album albums[MAX];
Artist artists[MAX];



void showMainMenu() {
    cout << "=====Music Database=====" << endl;
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << songs[0].toString() << endl;
}


int main() {

    
    songs[0] = Song(1, 1, "Hello", 4.5);
    songs[1] = Song(2, 2, "It's Me", 3.3);


    showMainMenu();
    cout << Validator::isAlpha("abd123") << " A" << endl;
    cout << Validator::isNumber("12") <<" N" << endl;
    cout << Validator::isEmpty("") <<" I" << endl;
    return 0;
}