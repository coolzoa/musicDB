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
};