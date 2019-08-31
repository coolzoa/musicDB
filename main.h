#include <string>

////////////Main functions
void initializeArray();
void deleteArrays();
void clearScreen();

void showMainMenu();
void handleMainMenuOption(std::string option);

////////////Artist functions
void showArtistMenu();
void handleArtistMenuOption(std::string option);
void askArtistInfo(int option);
bool validArtistInfo(std::string name);
bool existArtist(std::string name);

void addNewArtist(std::string name);
Artist getArtistByName(std::string name);
Artist getArtist(int id);
void searchArtist(std::string name); 
void showArtists();


////////////Album functions
void showAlbumMenu();
void handleAlbumMenuOption(std::string option);
void askAlbumInfo(int option);
bool validAlbumInput(std::string artistName, std::string albumName, std::string year);
bool validAlbumInput(std::string albumName);
bool existAlbum(std::string albumName, std::string artistName);
bool existAlbum(std::string albumName);

void addNewAlbum(std::string artistName, std::string albumName, std::string year);
Album getAlbumByName(std::string albumName, std::string artistName);
void searchAlbum(std::string albumName);
void showAlbums();

////////////Song functions
void showSongMenu();
void handleSongMenuOption(std::string option);
void askSongInfo(int option);
bool validSongInput(std::string artistName, std::string albumName, std::string songName, std::string songDuration);
bool validSongInput(std::string songName);
bool existSong(std::string songName, std::string albumName, std::string artistName);
bool existSong(std::string songName);
int getMaxTrackNumberFromAlbum(std::string albumName, std::string artistName);

void addNewSong(std::string artistName, std::string albumName, std::string songName, std::string songDuration);
void searchSong(std::string songName);
void showSongs();







