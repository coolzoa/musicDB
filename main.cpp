#include <iostream>
#include <string>
#include "song.h"
#include "validator.h"
#include "album.h"
#include "artist.h"
#include "message.h"
#include "main.h"

using namespace std;

const int MAX = 200;

int numberSongs = 0;
int numberAlbums = 0;
int numberArtists = 0;

int artistId = 1;
int albumId = 1;

Song* songs = NULL;
Album* albums = NULL;
Artist* artists = NULL;



////////////Array functions


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




void showArtistMenu() {
    cout << "=====Artists=====" << endl;
    cout << "1. Add New Artist" << endl;
    cout << "2. Search for Artist" << endl;
    cout << "3. Show Artists" << endl;
    cout << "4. Return to main menu" << endl;
    
    std::string option;
    cout << "Press the option number: ";
    getline(std::cin, option);
    
    handleArtistMenuOption(option);
}



void handleArtistMenuOption(std::string option) {
    if (option.compare("1") == 0) {
        askArtistInfo(1);
    } else if (option.compare("2") == 0) {
        askArtistInfo(2);
    } else if (option.compare("3") == 0) {
        showArtists();
    } else if (option.compare("4") == 0) {
        showMainMenu();
    } else {
        cout << Message::invalidOption << endl;
    }
    showArtistMenu();
}


void askArtistInfo(int option) {
    std::string name;
    cout << "Insert the Artist name: ";
    getline(std::cin, name);
    name = Validator::toLower(name);
    name[0] = toupper(name[0]);

    if (validArtistInfo(name)) {
        switch (option) {
            case 1:
                addNewArtist(name);
                break;
            case 2:
                findArtist(name);
                break;
        }
    } else {

    }
}



bool validArtistInfo(std::string name) {
    bool valid = true;

    if (Validator::isEmpty(name)) {
        cout << Message::errorEmpty(string("Artist name")) << endl;
        valid = false;

    } else if (Validator::isNumber(name)) {
        cout << Message::errorFormat(string("Artist name"), string("only numbers")) << endl;
        valid = false;

    } else if (numberArtists == MAX) {
        cout <<Message::maxCapacity(string("Artist")) << endl;
        valid = false;
    }
    return valid;
}

bool existArtist(std::string name) {
    bool found = false;

    int i  = 0;
    while (artists[i].getName().compare("") != 0) {
        if (artists[i].getName().compare(name) == 0) {
            found = true;
            break;
        } else {
            i++;
        }
    }
    return found;
}



void addNewArtist(std::string name) {
    if (!existArtist(name)) {
        artists[numberArtists] = Artist(artistId, name);
        artists[numberArtists].setName(name);

        cout << Message::newObjectAdded(string("Artist")) << endl;
        numberArtists++;
        artistId++;
    } else {
        cout << Message::foundMatch("Artst ") << endl;
    }
    
    showArtistMenu();
}



void findArtist(std::string name) {
    
    if (existArtist(name)) {
        cout << name << " is in the database" << endl;
    } else {
        cout << Message::errorMatch(string("Artist name")) << endl;
    }
    showArtistMenu();
}



void showArtists() {
    cout << "===== Artists =====" << endl;
    cout << "|\tid\t|\tname\t|" << endl;
    cout << "=================================" << endl;

    int i;
    for (i = 0; i < numberArtists; i++) {
        cout << artists[i].toString() << endl;
    }
    showArtistMenu();
}



////////////Main menu functions
void showMainMenu() {
    clearScreen();
    cout << "=====Music Database=====" << endl;
    cout << "1. Artist menu" << endl;
    cout << "2. Album menu" << endl;
    cout << "3. Song menu" << endl;
    cout << "4. Read a file" << endl;
    cout << "5. Save database to a file" << endl;
    cout << "6. Exit" << endl << endl;
    
    std::string option;
    cout << "Press the option number: ";
    getline(std::cin, option);
    handleMainMenuOption(option);
}


void handleMainMenuOption(std::string option) {
    if (option.compare("1") == 0) {
        showArtistMenu();

    }else if (option.compare("2") == 0) {
        cout << "Now we should show album menu" << endl;
    } else if (option.compare("3") == 0) {
        cout << "Now we should show song menu" << endl;
    } else if (option.compare("4") == 0) {
        cout << "Now we should read a file" << endl;
    } else if (option.compare("5") == 0) {
        cout << "Now we should save the database" << endl;
    } else if (option.compare("6") == 0) {
        cout << "Goodbye." << endl;
        exit(0);
    } else {
        cout << Message::invalidOption<< endl;
        showMainMenu();
    }
}







////////////Main

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

int main() {
    cout << "\the\tllo";
    intitializeArrays();
    showMainMenu();


    
    // songs[0] = new Song(1, 1, "Hello", 4.5);
    // songs[1] = Song(2, 2, "It's Me", 3.3);


    
    cout << Validator::isAlpha("abd123") << " A" << endl;
    cout << Validator::isNumber("12") <<" N" << endl;
    cout << Validator::isEmpty("") <<" I" << endl;

    cout << Validator::toLower("HEEY boii it'sa me") << endl;
    deleteArrays();

    return 0;
}