#ifndef PRINTABLE_H
#define PRINTABLE_H
#include <iostream>

class Printable {
    public:
        virtual std::string toString() = 0;
};

#endif