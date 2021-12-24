#include <string>
//#include "Object.hpp"

class Resource{
    public:
        Resource();

        ~Resource();

        void place(int x, int y);

    private:
        Resource * p_next;
};