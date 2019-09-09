#include <string>

////////////Main functions
void initializeArray();
void deleteArrays();
void clearScreen();

void showMainMenu();
void handleMainMenuOption(std::string option);

void readFile(std::string fileName);

////////////Artist functions
void showArtistMenu();
void handleArtistMenuOption(std::string option);
void askArtistInfo(int option);
bool validArtistInfo(std::string name);
bool existArtist(std::string name);
bool existArtistById(int id);

bool addNewArtist(std::string name);
Artist getArtistByName(std::string name);
Artist getArtist(int id);
void searchArtist(std::string name); 
void showArtists();

void addNewArtistFromFile(std::string name, int id);
void validateFileArtist(std::string id, std::string name);
int getMaxArtistId();


////////////Album functions
void showAlbumMenu();
void handleAlbumMenuOption(std::string option);
void askAlbumInfo(int option);
bool validAlbumInput(std::string artistName, std::string albumName, std::string year);
bool validAlbumInput(std::string albumName);


bool existAlbum(std::string albumName, std::string artistName);
bool existAlbum(std::string albumName);
bool existAlbumById(int albumId, int artistId);
bool existAlbum(int albumId);

bool addNewAlbum(std::string artistName, std::string albumName, std::string year);
Album getAlbum(int id);
Album getAlbumByName(std::string albumName, std::string artistName);
void searchAlbum(std::string albumName);
void showAlbums();

void validateFileSongOrAlbum(std::string artistIdOrAlbumId, std::string albumIdOrTrackNumber, \
    std::string name, std::string yearOrDuration);
void addNewAlbumFromFile(int artistId, int albumId, std::string name, std::string year);
int getMaxAlbumId();

////////////Song functions
void showSongMenu();
void handleSongMenuOption(std::string option);
void askSongInfo(int option);
bool validSongInput(std::string artistName, std::string albumName, std::string songName, \
    std::string songDuration);
bool validSongInput(std::string songName);
bool existSong(std::string songName, std::string albumName, std::string artistName);
bool existSong(std::string songName);
bool existSongById(int albumId, int trackNumber);
int getMaxTrackNumberFromAlbum(std::string albumName, std::string artistName);

bool addNewSong(std::string artistName, std::string albumName, std::string songName, std::string songDuration);
void searchSong(std::string songName);
void addNewSongFromFile(int albumId, std::string trackNumber, std::string name, std::string duration);
void showSongs();

void askFileName();

void saveDB();

void showDB();







