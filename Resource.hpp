#include <string>

class Resource{
    public:

    Resource(int xpValue, char resourceSymbol, std::string resourceName);

    ~Resource();

    void place(int x, int y);

    private:

    int xp;

    char symbol;

    std::string name;

    Resource * p_next;
};