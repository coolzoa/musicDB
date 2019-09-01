
#include <string>
#include "printable.h"

class Song : public Printable {
    private:
        int albumId;
        int trackNumber;
        std::string name;
        double duration;
    
    public:
        Song();
        Song(int albumID, int tNumber, std::string nm, double dur);
        std::string toString();

        int getAlbumId();
        std::string getName();
        int getTrackNumber();
        void setTrackNumber(int trackNumber);
        double getDuration();
};

