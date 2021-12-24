#include <string>
//#include "Object.hpp"

class Animal{
    public:
        Animal(int xpValue, int strenthValue, char animalSymbol, std::string animalName);

        ~Animal();

    private:
        Animal * p_next;

    protected:

};