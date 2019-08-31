#include<string>

class Validator {
    public:
        static bool isEmpty(std::string);
        static bool isNumber(std::string);
        static bool isAlpha(std::string);
        static bool isFloat(std::string str);

        static std::string toLower(std::string);
};