#include <string>

class Animal{
    public:

    Animal(int xpValue, int strengthValue, char animalSymbol, std::string animalName);

    ~Animal();

    void place (int x, int y);

    private:

    int xp;

    int strength;

    char symbol;

    std::string name;

};