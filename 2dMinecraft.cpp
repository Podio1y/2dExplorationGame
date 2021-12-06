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

int main(){

}

void play(){
    
}

void move(){

}

void highscores(){

}

void instructions(){

}

void goodbye(){

}

int get_xp(){

}

int get_distance(){

}

int * searchAnimal(Animal * animal){

}

int * searchResource(Resource * resource){

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

