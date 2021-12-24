#include <string>

class Object{
    public:
        Object();

        Object(int xpValue, int strenthValue, char objectSymbol, std::string objectName);

        ~Object();

        void place (int x, int y);

        char get_symbol() const;

        std::string get_name() const;

        int get_xp() const;

        int get_strength() const;

        void set_symbol(char);

        void set_name(std::string);

        void set_xp(int);

        void set_strength(int);

    private:

    protected:
    
        int xp;

        int strength;

        char symbol;

        std::string name;

        Object * p_next;
};