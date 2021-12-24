#include <iostream>
#include "Object.hpp"

int main();
void play(); // Actual running of the game, outpus board and calls functions for processing
void move(); // Moves the player in the world
int get_all_xp(); // Returns the players total xp
int get_distance(); // Returns the players total distance travelled 
void menu(); // Acts as the main menu, leads to instructions, play, or highscores
void highscores(); // Saves highscores for xp in a file, and outputs them
void instructions(); // Instructions page
void goodbye(); // Goodbye page
int * searchAnimal(Object*); // Finds coords of the Animal on screen
int * searchResource(Object*); // Finds coords of the resource on screen
void printBoard(Object*, std::size_t, std::size_t);
void assignBoard(Object*&, std::size_t, std::size_t);
void updateBoard(Object*&, std::size_t, std::size_t, Object*);
char * generateLine(char);

//Getters and Setters
char Object::get_symbol() const{ return this->symbol; }
std::string Object::get_name() const{ return this->name; }
int Object::get_xp() const{ return this->xp; }
int Object::get_strength() const{ return this->strength; }

void Object::set_symbol(char newSymbol) { this->symbol = newSymbol; }
void Object::set_name(std::string newName) { this->name = newName; }
void Object::set_xp(int newXP) { this->xp = newXP; }
void Object::set_strength(int newStrength) { this->strength = newStrength; }


int main(){
    play();
    std::cout << "done" << std::endl;
    return 0;
}

void play(){
    std::size_t xdim = 50;
    std::size_t ydim = 20;
    Object* gameBoard{new Object [xdim*ydim]};
    Object* lion = new Object(100, 100, 'L', "Lion");
    //Resource * gold = new Resource(100, 100, 'G', "Gold");

    assignBoard(gameBoard, xdim, ydim);
    printBoard(gameBoard, xdim, ydim);
}

void move(){

}

void printBoard(Object * board, std::size_t xdim, std::size_t ydim){

    for (int y = 0 ; y < ydim ; y++){

        for (int x = 0 ; x < xdim ; x++){

            if (x == xdim - 1){
                std::cout << board[x + y*xdim].get_symbol() << std::endl;
            }
            else{
                std::cout << board[x + y*xdim].get_symbol();
            }
        }
    }
}

void assignBoard(Object * & board, std::size_t xdim, std::size_t ydim){

    for (int y = 0 ; y < ydim ; y++){

        for (int x = 0 ; x < xdim ; x++){

            board[x + y*xdim].set_symbol('.');
        }
    }

    //random function to place animals and resources randomly
}

void updateBoard(Object * & board, std::size_t xdim, std::size_t ydim, Object * newLine){
    board[(xdim * ydim)/2].set_symbol('O'); //Head

}

char * generateLine(char orientation){
    char* line = new char [20];
    return line;
}

void highscores(){

}

void instructions(){

}

void goodbye(){

}

int get_all_xp(){
    return 0;
}

int get_distance(){
    return 0;
}

int * searchAnimal(Object * animal){
    int * coordinates{new int [2]};
    return coordinates;
}

int * searchResource(Object * resource){
    int * coordinates{new int [2]};
    return coordinates;
}

Object::Object():
    symbol{0}{
}

Object::Object(int xpValue, int strengthValue, char objectSymbol, std::string objectName):
    xp{xpValue},
    strength{strengthValue},
    symbol{objectSymbol},
    name{objectName}{

    //Stuff
}

Object::~Object(){
    //Stuff
}

