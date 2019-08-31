#include <iostream>
#include "printable.h"

class Artist : public Printable{
    private:
        int id;
        std::string name;

    public:
        Artist();
        Artist(int ID, std::string nm);
        std::string toString();
        std::string getName();
        int getId();
};