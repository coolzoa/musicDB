#include <iostream>
#include <string>
#include "song.h"
#include "validator.h"
#include "album.h"
#include "artist.h"
#include "message.h"
#include "main.h"

//link to simpleJSON parser library used: https://github.com/MJPA/SimpleJSON

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



////////////Artist functions
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
                searchArtist(name);
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
    if (numberArtists == MAX) {
        cout << Message::maxCapacity("Artist");
    } else if (!existArtist(name)) {
        artists[numberArtists] = Artist(artistId, name);

        cout << Message::newObjectAdded(string("Artist")) << endl;
        numberArtists++;
        artistId++;
    } else {
        cout << Message::foundMatch("Artist ") << endl;
    }    
}

Artist getArtistByName(std::string name) {
    int i;
    for (i = 0; i < numberArtists; i++) {
        if (artists[i].getName().compare(name) == 0) {
            return artists[i];
        } else {}
    }
}

Artist getArtist(int id) {
    int i;
    for (i = 0; i < numberArtists; i++) {
        if (artists[i].getId() == id) {
            return artists[i];
        } else {}
    }
}



void searchArtist(std::string name) {
    
    if (existArtist(name)) {
        cout << "Here's what we found: " << endl;
        cout << "|\tid\t|\tname\t|" << endl;
        cout << "=================================" << endl;
        cout << getArtistByName(name).toString() << endl;
    } else {
        cout << Message::errorMatch(string("Artist name")) << endl;
    }
}



void showArtists() {
    cout << "===== Artists =====" << endl;
    cout << "|\tid\t|\tname\t|" << endl;
    cout << "=================================" << endl;

    int i;
    for (i = 0; i < numberArtists; i++) {
        cout << artists[i].toString() << endl;
    }
}




///////////Album functions
void showAlbumMenu() {
    cout << "=====Albums=====" << endl;
    cout << "1. Add New Album" << endl;
    cout << "2. Search for Album" << endl;
    cout << "3. Show Albums" << endl;
    cout << "4. Return to main menu" << endl;
    
    std::string option;
    cout << "Press the option number: ";
    getline(std::cin, option);
    handleAlbumMenuOption(option);
}



void handleAlbumMenuOption(std::string option) {
    if (option.compare("1") == 0) {
        askAlbumInfo(1);
    } else if (option.compare("2") == 0) {
        askAlbumInfo(2);
    } else if (option.compare("3") == 0) {
        showAlbums();
    } else if (option.compare("4") == 0) {
        showMainMenu();
    } else {
        cout << Message::invalidOption << endl;
    }
    showAlbumMenu();
}



void askAlbumInfo(int option) {
    std::string artistName;
    std::string albumName;
    std::string year;

        //option 1 = register new album
    if (option == 1) {
        cout << "Insert the Artist name: ";
        getline(std::cin, artistName);
        artistName = Validator::toLower(artistName);
        artistName[0] = toupper(artistName[0]);

        cout << "Insert the Album name: ";
        getline(std::cin, albumName);
        albumName = Validator::toLower(albumName);
        albumName[0] = toupper(albumName[0]);

        cout << "Insert the Album year: ";
        getline(std::cin, year);

        if (validAlbumInput(artistName, albumName, year)) {
            addNewAlbum(artistName, albumName, year);
        } else {

        }
        //option = 2 search for album
    } else {
        cout << endl;
        cout << "Insert the Album name: ";
        getline(std::cin, albumName);
        albumName = Validator::toLower(albumName);
        albumName[0] = toupper(albumName[0]);
        if (validAlbumInput(albumName)) {
            searchAlbum(albumName);
        } else {

        }
    }
}




bool validAlbumInput(std::string artistName, std::string albumName, std::string year) {
    bool valid = true;
    if (Validator::isEmpty(artistName)) {
        cout << Message::errorEmpty(string("Artist name")) << endl;
        valid = false;
    } else if (Validator::isNumber(artistName)) {
        cout << Message::errorFormat(string("Artist name"), string("only numbers")) << endl;
        valid = false;
    } else if (Validator::isEmpty(albumName)) {
        cout << Message::errorEmpty(string("Album name")) << endl;
        valid = false;
    } else if (Validator::isEmpty(year)) {
        cout << Message::errorEmpty(string("Album year")) << endl;
        valid = false;
    } else if (!Validator::isNumber(year)) {
        cout << Message::errorFormat("Album year", " something other than numbers") << endl;
        valid = false;
    }
    return valid;
}

bool validAlbumInput(std::string albumName) {
    bool valid = true;
    if (Validator::isEmpty(albumName)) {
        cout << Message::errorEmpty(string("Album name")) << endl;
        valid = false;
    }
    return valid;
}

bool existAlbum(std::string albumName, std::string artistName) {
    bool exist = false;
    if (!existArtist(artistName)) {
        return exist;
    } else {
        int artistId = getArtistByName(artistName).getId();

        int i;
        for (i = 0; i < numberAlbums; i++) {
            if (albums[i].getArtistId() == artistId) {
                if (albums[i].getName().compare(albumName) == 0) {
                    exist = true;
                    break;
                } else {
                    
                }
            } else {

            }
        }
    }
    return exist;
}



bool existAlbum(std::string albumName) {
    int i;
    for (i = 0; i < numberAlbums; i++) {
        if (albums[i].getName().compare(albumName) == 0) {
            return true;
        } else {

        }
    }
    return false;
}


void addNewAlbum(std::string artistName, std::string albumName, std::string year) {
    if (numberAlbums == MAX) {
        cout << Message::maxCapacity(string("Album")) << endl;
    } else if (existAlbum(albumName, artistName)) {
        cout << Message::foundMatch(string("Album")) << endl;
    } else {

        int yr = atoi(year.c_str());
 
        if (!existArtist(artistName)) {
            addNewArtist(artistName);
        }

        int artistId = getArtistByName(artistName).getId();
        albums[numberAlbums] = Album(artistId, albumId, albumName, yr);
        cout << Message::newObjectAdded(string("Album")) << endl;
        numberAlbums++;
        albumId++;
    }
}


Album getAlbumByName(std::string albumName,std::string artistName) {
    int i, j;
    for (i = 0; i < numberArtists; i++) {
        for (j = 0; j < numberAlbums; j++) {
            if (albums[j].getArtistId() == artists[i].getId()) {
                if (albums[j].getName().compare(albumName) == 0) {
                    return albums[j];
                } else {

                }
            } else {

            }
        }
    }
}





void searchAlbum(std::string albumName) {
    if (existAlbum(albumName)) {
        cout << "Here's what we found: " << endl;
        cout << "|\tArtist_id\t|\tArtist_name\t|\tAlbum_id\t|\tAlbum_name\t|\tyear\t|" << endl;
        cout << "======================================================================================================" << endl;
        int i, j;
        for (i = 0; i < numberArtists; i++) {
            for (j = 0; j < numberAlbums; j++) {
                if (existAlbum(albums[j].getName(), artists[i].getName())) {
                    if ((albums[j].getArtistId() == artists[i].getId())
                        && (albums[i].getName().compare(albumName) == 0)
                    ) {
                        cout << artists[i].toString() + albums[j].toString() << endl;

                    }
                }
            }
        }       
    } else {
        cout << Message::errorMatch(string("Album name")) << endl;
    }
}



void showAlbums() {
    cout << "===== Albums =====" << endl;
    cout << "|\tArtist_id\t|\tArtist_name\t|\tAlbum_id\t|\tAlbum_name\t|\tyear\t|" << endl;
    cout << "=========================================================================================================" << endl;
    int i, j;
    for (i = 0; i < numberArtists; i++) {
        for (j = 0; j < numberAlbums; j++) {
            if (existAlbum(albums[j].getName(), artists[i].getName())) {
                if (albums[j].getArtistId() == artists[i].getId()) {
                    cout << artists[i].toString() + albums[j].toString() << endl;
                }
            }
        }
    }
}




////////////Song menu functions
void showSongMenu() {
    cout << "=====Songs=====" << endl;
    cout << "1. Add New Song" << endl;
    cout << "2. Search for Song" << endl;
    cout << "3. Show Songs" << endl;
    cout << "4. Return to main menu" << endl;
    
    std::string option;
    cout << "Press the option number: ";
    getline(std::cin, option);
    handleSongMenuOption(option);
}

void handleSongMenuOption(std::string option) {
    if (option.compare("1") == 0) {
        askSongInfo(1);
    } else if (option.compare("2") == 0) {
        askSongInfo(2);
    } else if (option.compare("3") == 0) {
        showSongs();
    } else if (option.compare("4") == 0) {
        showMainMenu();
    } else {
        cout << Message::invalidOption << endl;
    }
    showSongMenu();
}


void askSongInfo(int option) {
    std::string artistName;
    std::string albumName;

    std::string songName;
    std::string songDuration;

    
       //option 1 = register new Song
    if (option == 1) {
        cout << "Insert the Artist name: ";
        getline(std::cin, artistName);
        artistName = Validator::toLower(artistName);
        artistName[0] = toupper(artistName[0]);

        cout << "Insert the Album name: ";
        getline(std::cin, albumName);
        albumName = Validator::toLower(albumName);
        albumName[0] = toupper(albumName[0]);

        cout << "Insert the Song name: ";
        getline(std::cin, songName);
        songName = Validator::toLower(songName);
        songName[0] = toupper(songName[0]);

        cout << "Insert the track duration: ";
        getline(std::cin, songDuration);

        if (validSongInput(artistName, albumName, songName, songDuration)) {
            addNewSong(artistName, albumName, songName, songDuration);
        } else {

        }


        //option = 2 search for song
    } else {
        cout << endl;
        cout << "Insert the Song name: ";
        getline(std::cin, songName);
        songName = Validator::toLower(songName);
        songName[0] = toupper(songName[0]);
        if (validSongInput(songName)) {
            //searchSong(trackName);
        } else {

        }
    }
}


bool validSongInput(std::string artistName, std::string albumName, std::string songName, std::string songDuration) {
    bool valid = true;
    if (Validator::isEmpty(artistName)) {
        cout << Message::errorEmpty(string("Artist name")) << endl;
        valid = false;
    } else if (Validator::isNumber(artistName)) {
        cout << Message::errorFormat(string("Artist name"), string("only numbers")) << endl;
        valid = false;
    } else if (Validator::isEmpty(albumName)) {
        cout << Message::errorEmpty(string("Album name")) << endl;
        valid = false;
    } else if (Validator::isEmpty(songName)) {
        cout << Message::errorEmpty(string("Song name")) << endl;
        valid = false;
    } else if (Validator::isEmpty(songDuration)) {
        cout << Message::errorEmpty(string("Song duration")) << endl;
        valid = false;
    } else if (!Validator::isFloat(songDuration)) {
        cout << Message::errorFormat(string("Song duration"), string("a format different than a decimal value")) << endl;
        valid = false;
    }
    return valid;
}

bool validSongInput(std::string songName) {
    if (Validator::isEmpty(songName)) {
        cout << Message::errorEmpty(string("Song name")) << endl;
        return false;
    } else {
        return true;
    }
}

bool existSong(std::string songName, std::string albumName, std::string artistName) {
     bool exist = false;
    if (!existArtist(artistName)) {
        return exist;
    } else if (!existAlbum(albumName, artistName)) {
        return exist;
    } else {
        int artistId = getArtistByName(artistName).getId();
        int i;
        for (i = 0; i < numberAlbums; i++) {
            if (exist) {
                break;
            } else if (albums[i].getArtistId() == artistId) {
                if (albums[i].getName().compare(albumName) == 0) {
                    int albumId = albums[i].getAlbumId();
                    int j;
                    for (j = 0; j < numberSongs; j++) {
                        if (songs[j].getAlbumId() == albumId) {
                            if (songs[j].getName().compare(songName) == 0) {
                                exist = true;
                                break;
                            }
                        }
                    }
                }  
            }
        }
    }
    return exist;
}



bool existSong(std::string songName) {
    bool exist = false;
    int i;
    for (i = 0; i < numberSongs; i++) {
        if (songs[i].getName().compare(songName) == 0) {
            exist = true;
            break;
        }
    }
    return exist;
}

int getMaxTrackNumberFromAlbum(std::string albumName, std::string artistName) {
    int albumId = getAlbumByName(albumName, artistName).getAlbumId();
    int i;
    int last = 0;
    for (i = 0; i < numberSongs; i++) {
        if (songs[i].getAlbumId() == albumId) {
            if (last < songs[i].getTrackNumber()) {
                last = songs[i].getTrackNumber();
            }
        }
    }
    return ++last;

}

void addNewSong(std::string artistName, std::string albumName, std::string songName, std::string songDuration) {
    if (numberSongs == MAX) {
        cout << Message::maxCapacity(string("Song")) << endl;
    } else if (existSong(songName, albumName, artistName)) {
        cout << Message::foundMatch(string("Album")) << endl;
    } else {

        if (!existArtist(artistName) || !existAlbum(albumName, artistName)) {
            cout << Message::errorMatch(string("Artist and Album combination")) << endl;
        } else {
            double duration = atof(songDuration.c_str());
            int albumId = getAlbumByName(albumName, artistName).getAlbumId();
            int trackNumber = getMaxTrackNumberFromAlbum(albumName, artistName);
            songs[numberSongs] = Song(albumId, trackNumber, songName, duration);
            cout << Message::newObjectAdded(string("Song")) << endl;
            numberSongs++;
        }
    }
}

void searchSong(std::string songName) {
    if (!existSong(songName)) {
        cout << Message::errorMatch(string("Song")) << endl;
    } else {
        cout << "Here;s what we found: " << endl;
        cout << "|\tArtist_id\t|\tArtist_name\t|\tAlbum_id\t|\tAlbum_name\t|\tAlbum_year\t|" << endl;

        cout << "|\tArtist_id\t|\tArtist_name\t|\tAlbum_id\t|\tAlbum_name\t|\tAlbum_year\t|" <<
            "\tTrack_number\t|\tSong_name\t|\tSong_duration\t|"<< endl;
        cout << "======================================================================================================" << endl;

        int i, j, k;
        for (i = 0; i < numberArtists; i++) {
            for (j = 0; j < numberAlbums; j++) {
                if (existAlbum(albums[j].getName(), artists[i].getName())) {
                    if ((albums[j].getArtistId() == artists[i].getId())) {
                        for (k = 0; k < numberSongs; k++) {
                            if ((existSong(songName, albums[j].getName(), artists[i].getName())
                                && (songs[k].getName().compare(songName) == 0))
                            ) {
                                cout << artists[i].toString() + albums[j].toString() + songs[k].toString() << endl;
                            }
                        }
                    }
                }
            }
        }       
    }
}

void showSongs() {
    cout << "Here;s what we found: " << endl;

    cout << "|\tArtist_id\t|\tArtist_name\t|\tAlbum_id\t|\tAlbum_name\t|\tAlbum_year\t|" <<
        "\tTrack_number\t|\tSong_name\t|\tSong_duration\t|"<< endl;
    cout << "======================================================================================================" << endl;

    int i, j, k;
    for (i = 0; i < numberArtists; i++) {
        for (j = 0; j < numberAlbums; j++) {
            if (existAlbum(albums[j].getName(), artists[i].getName())) {
                if ((albums[j].getArtistId() == artists[i].getId())) {
                    for (k = 0; k < numberSongs; k++) {
                        if (existSong(songs[k].getName(), albums[j].getName(), artists[i].getName())) {
                            cout << artists[i].toString() + albums[j].toString() + songs[k].toString() << endl;
                        }
                    }
                }
            }
        }
    }      
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
        showAlbumMenu();
    } else if (option.compare("3") == 0) {
        showSongMenu();
    } else if (option.compare("4") == 0) {
        cout << "Now we should read a file" << endl;
    } else if (option.compare("5") == 0) {
        cout << "Now we should save the database" << endl;
    } else if (option.compare("6") == 0) {
        cout << "Goodbye." << endl;
        deleteArrays();
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
    intitializeArrays();
    //showMainMenu();




    
    // songs[0] = new Song(1, 1, "Hello", 4.5);
    // songs[1] = Song(2, 2, "It's Me", 3.3);

    deleteArrays();

    return 0;
}