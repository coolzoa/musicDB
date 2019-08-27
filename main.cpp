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

Song* songs = NULL;
Album* albums = NULL;
Artist* artists = NULL;

void intitializeArrays() {
    songs = new Song[MAX];
    albums = new Album[MAX];
    artists = new Artist[MAX];
}

void deleteArrays() {
    delete [] songs;
    delete [] albums;
    delete [] artists;
}




void showMainMenu() {
    cout << "=====Music Database=====" << endl;
    cout << "1. Add New Artist" << endl;
    cout << "2. Add New Album" << endl;
    cout << "3. Add New Song" << endl;
    cout << "4. Read a file" << endl;
    cout << "5. Save database to a file" << endl;
    cout << "6. Exit" << endl << endl;
    
    std::string option;
    cout << "Press the option number: ";
    getline(std::cin, option);
    cout << "You pressed: " << option << " now we do something";

}


int main() {
    intitializeArrays();
    cout << songs[0].toString();



    
    // songs[0] = new Song(1, 1, "Hello", 4.5);
    // songs[1] = Song(2, 2, "It's Me", 3.3);


    showMainMenu();
    cout << Validator::isAlpha("abd123") << " A" << endl;
    cout << Validator::isNumber("12") <<" N" << endl;
    cout << Validator::isEmpty("") <<" I" << endl;

    cout << Validator::toLower("HEEY boii it'sa me") << endl;
    deleteArrays();

    return 0;
}