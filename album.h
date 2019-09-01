#include <string>
#include "printable.h"

class Album : public Printable {
    private:
    int artistId;
        int id;
        std::string name;
        int year;

    public:
        Album();
        Album(int artistID, int ID, std::string nm, int yr);
        std::string toString();
        int getArtistId();
        std::string getName();
        int getAlbumId();
        void setAlbumId(int newId);
        int getYear();

};