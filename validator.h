#include<string>

class Validator {
    public:
        static bool isEmpty(std::string);
        static bool isNumber(std::string);
        static bool isAlpha(std::string);

        static std::string toLower(std::string);
};