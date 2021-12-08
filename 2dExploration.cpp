#include <iostream>
#include "Animal.hpp"
#include "Resource.hpp"

int main();
void play(); // Actual running of the game, outpus board and calls functions for processing
void move(); // Moves the player in the world
int get_xp(); // Returns the players total xp
int get_distance(); // Returns the players total distance travelled 
void menu(); // Acts as the main menu, leads to instructions, play, or highscores
void highscores(); // Saves highscores for xp in a file, and outputs them
void instructions(); // Instructions page
void goodbye(); // Goodbye page
int * searchAnimal(Animal*); // Finds coords of the Animal on screen
int * searchResource(Resource*); // Finds coords of the resource on screen
void printBoard(char*, std::size_t, std::size_t);
void assignBoard(char*&, std::size_t, std::size_t);

int main(){
    play();
    std::cout << "done" << std::endl;
    return 0;
}

void play(){
    std::size_t xdim = 50;
    std::size_t ydim = 20;
    char* gameBoard{new char [xdim*ydim]};
    Animal * lion = new Animal(100, 100, 'L', "Lion");
    Resource * gold = new Resource(100, 'G', "Gold");

    assignBoard(gameBoard, xdim, ydim);
    printBoard(gameBoard, xdim, ydim);
}

void move(){

}

void printBoard(char * board, std::size_t xdim, std::size_t ydim){

    for (int y = 0 ; y < ydim ; y++){

        for (int x = 0 ; x < xdim ; x++){

            if (x == xdim - 1){
                std::cout << board[x + y*xdim] << std::endl;
            }
            else{
                std::cout << board[x + y*xdim];
            }
        }
    }
}

void assignBoard(char * & board, std::size_t xdim, std::size_t ydim){

    for (int y = 0 ; y < ydim ; y++){

        for (int x = 0 ; x < xdim ; x++){

            board[x + y*xdim] = '.';
        }
    }

    //random function to place animals and resources randomly
}

void highscores(){

}

void instructions(){

}

void goodbye(){

}

int get_xp(){
    return 0;
}

int get_distance(){
    return 0;
}

int * searchAnimal(Animal * animal){
    int * coordinates{new int [2]};
    return coordinates;
}

int * searchResource(Resource * resource){
    int * coordinates{new int [2]};
    return coordinates;
}

Animal::Animal(int xpValue, int strengthValue, char animalSymbol, std::string animalName):
    xp{xpValue},
    strength{strengthValue},
    symbol{animalSymbol},
    name{animalName}{
    
    //Stuff
}

Animal::~Animal(){

}

Resource::Resource(int xpValue, char resourceSymbol, std::string resourceName):
    xp{xpValue},
    symbol{resourceSymbol},
    name{resourceName}{

    //Stuff
}

Resource::~Resource(){

}

