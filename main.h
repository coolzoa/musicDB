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
void findArtist(std::string name); 
void showArtists();




