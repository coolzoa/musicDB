#include<string>

class Message {
    public:
        static const std::string invalidOption;


        static std::string errorEmpty(std::string input);

        static std::string errorFormat(std::string input, std::string format);

        static std::string maxCapacity(std::string className);

        static std::string errorMatch(std::string property);

        static std::string foundMatch(std::string obj);

        static std::string newObjectAdded(std::string className);
};