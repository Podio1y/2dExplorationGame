#include <iostream>
#include <ctime>
#include <conio.h>
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
void updateBoard(Object*&, std::size_t, std::size_t, Object*, char);
Object * generateLine(char);

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
    char input;
    while (input != 'x'){
        printBoard(gameBoard, xdim, ydim);
        input = getch();
        if (input == 'w'){
            updateBoard(gameBoard, xdim, ydim, generateLine('1'), 'U');
        }
        else if (input == 'a'){
            updateBoard(gameBoard, xdim, ydim, generateLine('2'), 'L');
        }
        else if (input == 's'){
            updateBoard(gameBoard, xdim, ydim, generateLine('1'), 'D');
        }   
        else if (input == 'd'){
            updateBoard(gameBoard, xdim, ydim, generateLine('2'), 'R');
        }
        //_sleep(100);
    }

    // assignBoard(gameBoard, xdim, ydim);
    // printBoard(gameBoard, xdim, ydim);

    // std::cout << "break" << std::endl;
    // updateBoard(gameBoard, xdim, ydim, generateLine('1'), 'L');
    // updateBoard(gameBoard, xdim, ydim, generateLine('1'), 'D');
    // //updateBoard(gameBoard, xdim, ydim, generateLine('1'), 'L');
    // printBoard(gameBoard, xdim, ydim);
}

void move(){
    
}

void printBoard(Object * board, std::size_t xdim, std::size_t ydim){
    system("cls");
    for (int y = 0 ; y < ydim ; y++){

        for (int x = 0 ; x < xdim ; x++){
            if ((x + y*xdim) == ( ((xdim * ydim)/2) + (xdim/2) )){
                std::cout << "O";
            }
            else if((x + y*xdim) == ( ((xdim * ydim)/2) + (xdim/2) + xdim )){
                std::cout << "|";
            }
            else if((x + y*xdim) == ( ((xdim * ydim)/2) + (xdim/2) + xdim + 1 )){
                std::cout << "-";
            }
            else if((x + y*xdim) == ( ((xdim * ydim)/2) + (xdim/2) + xdim - 1 )){
                std::cout << "-";
            }
            else if((x + y*xdim) == ( ((xdim * ydim)/2) + (xdim/2) + 2*xdim - 1 )){
                std::cout << "/";
            }
            else if((x + y*xdim) == ( ((xdim * ydim)/2) + (xdim/2) + 2*xdim + 1 )){
                std::cout << "\\";
            }
            else if (x == xdim - 1){
                std::cout << board[x + y*xdim].get_symbol() << std::endl;
            }
            else{
                std::cout << board[x + y*xdim].get_symbol();
            }
        }
    }
}

void assignBoard(Object * & board, std::size_t xdim, std::size_t ydim){
    // srand(time(0));
    for (int y = 0 ; y < ydim ; y++){

        for (int x = 0 ; x < xdim ; x++){

            board[x + y*xdim].set_symbol('.');//(rand() % 10) + 65);
        }
    }

    //random function to place animals and resources randomly
}

void updateBoard(Object * & board, std::size_t xdim, std::size_t ydim, Object * newLine, char direction){
    
    // board[((xdim * ydim)/2) + (xdim/2)].set_symbol('.'); //Head
    // board[((xdim * ydim)/2) + (xdim/2) + xdim].set_symbol('.');
    // board[((xdim * ydim)/2) + (xdim/2) + xdim - 1].set_symbol('.');
    // board[((xdim * ydim)/2) + (xdim/2) + xdim + 1].set_symbol('.');
    // board[((xdim * ydim)/2) + (xdim/2) + xdim - 2].set_symbol('.');
    // board[((xdim * ydim)/2) + (xdim/2) + xdim + 2].set_symbol('.');
    // board[((xdim * ydim)/2) + (xdim/2) + 2*xdim - 1].set_symbol('.');
    // board[((xdim * ydim)/2) + (xdim/2) + 2*xdim + 1].set_symbol('.');

    // std::cout << std::endl; // For testing
    // printBoard(board, xdim, ydim);
    // std::cout << std::endl;

    // Movement
    if (direction == 'L'){
        // Left side
        for (int j = xdim ; j > 1; j--){
            for (int i = 0 ; i < ydim ; i++){
                board[(j-1) + i*(xdim-1)] = board[(j-2) + i*(xdim-1)];
            }
        }

        for (int i = 0 ; i < ydim ; i++){
            board [xdim*i] = newLine[i];
        }
    }
    else if (direction == 'R'){
        // Right side
        for (int j = 0 ; j < xdim - 1; j++){
            for (int i = 0 ; i < ydim ; i++){
                board[j + i*xdim] = board[j + 1 + i*xdim];
            }
        }

        for (int i = 0 ; i < ydim ; i++){
            board [(xdim-1) + xdim*i] = newLine[i];
        }
    }
    else if (direction == 'D'){
        // Bottom
        for (int j = 0 ; j < ydim - 1; j++){
            for (int i = 0 ; i < xdim ; i++){
                board[j*xdim + i] = board[(j+1)*xdim + i];
            }
        }

        for (int i = 0 ; i < xdim ; i++){
            board [xdim*(ydim-1) + i] = newLine[i];
        }
    }
    else if (direction == 'U'){
        // Top 
        for (int j = ydim - 1 ; j > 1; j--){
            for (int i = 0 ; i < xdim ; i++){
                board[(j-1)*xdim + i] = board[(j-2)*xdim + i];
            }
        }

        for (int i = 0 ; i < xdim ; i++){
            board [i] = newLine[i];
        }
    }

    //board[((xdim * ydim)/2) + (xdim/2)].set_symbol('O'); //Head
    //board[((xdim * ydim)/2) + (xdim/2) + xdim].set_symbol('|');
    //board[((xdim * ydim)/2) + (xdim/2) + xdim - 1].set_symbol('-');
    //board[((xdim * ydim)/2) + (xdim/2) + xdim + 1].set_symbol('-');
    //board[((xdim * ydim)/2) + (xdim/2) + xdim - 2].set_symbol('-');
    //board[((xdim * ydim)/2) + (xdim/2) + xdim + 2].set_symbol('-');
    //board[((xdim * ydim)/2) + (xdim/2) + 2*xdim - 1].set_symbol('/');
    //board[((xdim * ydim)/2) + (xdim/2) + 2*xdim + 1].set_symbol('\\');

}

Object * generateLine(char orientation){
    //srand(time(0));
    std::string names[6]{"Li", "BI", "AI", "GI", "DI", "FI"}; // testing
    char symbols[6]{'L', 'B', 'A', 'G', 'D', 'F'};
    int r = 0; // stores random number
    
    Object* line = new Object [50];

    for (int i = 0 ; i < 50 ; i++){

        r = rand() % 6;

        line[i].set_symbol('.');
        if ((rand() % 30) == 1){

            line[i].set_symbol( symbols[r]);
            line[i].set_name(names[r]);
        }
    }
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

