/* CSCI 200: Assignment 2: A2 - Watch the Wumpus
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // Stack Overflow
 *     // ZYbooks
 *     // A mines student in the robotics department helped me with a file reading issue I had/
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * This code provides the neccessary functions to complete the game Watch the Wumpus. In its current state it runs perfectly on my setup providing game results and a log file of every action taken. 
 * The code also ends the game when a win condition is made. 
 * 
 *      For some reason this code only works if you add "cout << endl;" to line 44 of the int main() file provided. I have no idea why.
 */

#include "wumpus_functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string enter_wumpus_file() {
    cout << "Enter a file:" << endl;
    string direct = "input/";
    string file;
    cin >> file;
    cout << flush;
    return direct + file;
}

string enter_game_log_file() {
    cout << "Enter a log file:" << endl;
    string direct = "output/";
    string file;
    cin >> file;
    cout << flush;
    return direct + file;
}

bool open_files(ifstream& wumpusFileIn, ofstream& gameLogOut, string WUMPUS_FILE_NAME, string GAME_LOG_FILE_NAME) {
    //Open files
    wumpusFileIn.open(WUMPUS_FILE_NAME);
    gameLogOut.open(GAME_LOG_FILE_NAME);

    // Validate files
    if ( !wumpusFileIn ) {
        cerr << "Error opening input file" << endl;
        return false;
    }
    if ( !gameLogOut ) {
        cerr << "Error opening output file" << endl;
        return false;
    }
    cout << flush;
    return true;
}

int read_world_header(ifstream& wumpusFileIn, int& caveWidth, int& caveHeight) {
    wumpusFileIn >> caveWidth >> caveHeight;
    cout << flush;
    return 0;
}

bool read_object_header(ifstream& wumpusFileIn, int& wumpusX, int& wumpusY, int& heroX, int& heroY, int& pitX, int& pitY){
    string line;
    bool Wstate = false; bool Hstate = false; bool Pstate = false;
    while (getline(wumpusFileIn, line)) {
        stringstream stream(line);
        char waste;
        if(line.size() == 5 && line[0] == 'W') {
            stream >> waste;
            stream >> wumpusX;
            stream >> wumpusY;
            Wstate = true;
        }
        else if(line.size() == 5 && line[0] == 'H') {
            stream >> waste;
            stream >> heroX;
            stream >> heroY;
            Hstate = true;
        }
        else if(line.size() == 5 && line[0] == 'P') {
            stream >> waste;
            stream >> pitX;
            stream >> pitY;
            Pstate = true;
        }
        if (Wstate && Hstate && Pstate) {break;}
    }
    cout << flush;
    return Wstate && Hstate && Pstate;
}

void read_number_moves(ifstream& wumpusFileIn, int& numMoves) {
    string line;
    getline(wumpusFileIn, line);
    stringstream stream(line);
    stream>>numMoves;
    cout << flush;
}

bool choose_player() {
    string input;
    while (true) {
        cout << "Who do you wish to play as?" << endl << "   H - Hero" << endl << "   W - Wumpus" << endl << "Character: " << endl;
        cin >> input;
        if (input == "H") {
            cout << "You chose to play as the hero!" << endl;
            return true;
            }
        else if (input == "W") {
            cout << "You chose to play as the wumpus!" << endl;
            return false;
            }
        else {
            cerr << "Invalid choice, please select again." << endl;
        }
    }
    cout << flush;
    return false;
}

void play_game(ifstream& wumpusFileIn, ofstream& gameLogOut, int& caveWidth, int& caveHeight, int& numMoves, int& wumpusX, int& wumpusY, int& heroX, int& heroY, int& pitX, int& pitY, bool PLAY_AS_HERO) {
    string line;
    char movement;
    char waste;
    bool gameEnd;
    bool heroVictory;

    //Move characters -> check for move viability -> check for player/pit colison, if collision occurs break loop.
    while (getline(wumpusFileIn, line)) {
        stringstream stream(line);
        //Move Wumpus
        if(line.size() == 3 && line[0] == 'W') {
            stream >> waste;
            stream >> movement;
            if ((movement == 'N') && (wumpusY < caveHeight)) {wumpusY+=1;} //&& (wumpusY < caveHeight)
            else if (movement == 'S' && (wumpusY > 0)) {wumpusY-=1;} 
            else if (movement == 'E' && (wumpusX < caveWidth)) {wumpusX+=1;} 
            else if (movement == 'W' && (wumpusY > 0)) {wumpusX-=1;} 
            else {cout<<"You cannot move "<<movement<<"."<<endl;}
            //Check if move is posible, if move is not posible
            //if ((wumpusY > caveHeight) && (movement == 'N'))
        }
        //Move Hero
        else if(line.size() == 3 && line[0] == 'H') {
            stream >> waste;
            stream >> movement;
            if ((movement == 'N') && (heroY < caveHeight)) {heroY+=1;} //&& (wumpusY < caveHeight)
            else if (movement == 'S' && (heroY > 0)) {heroY-=1;} 
            else if (movement == 'E' && (heroX < caveWidth)) {heroX+=1;} 
            else if (movement == 'W' && (heroY > 0)) {heroX-=1;} 
            else {cout<<"You cannot move "<<movement<<"."<<endl;}
        }
        else {stream >> waste >> waste;}

        //Print character locations to gameLogOut
        cout << "The Hero is at (" << heroX << ", " << heroY << ")" << endl;
        gameLogOut << "The Hero is at (" << heroX << ", " << heroY << ")" << endl;
        cout << "The Wumpus is at (" << wumpusX << ", " << wumpusY << ")" << endl;
        gameLogOut << "The Wumpus is at (" << wumpusX << ", " << wumpusY << ")" << endl;
        if (PLAY_AS_HERO == true) {cout << "You are at (" << heroX << ", " << heroY << ")" << endl;}
        else {
            cout << "You are at (" << wumpusX << ", " << wumpusY << ")" << endl;
            gameLogOut<< "You are at (" << wumpusX << ", " << wumpusY << ")" << endl;
        }

        //Check for colision and print results
        if ((heroX == pitX) && (heroY == pitY)) { //Hero falls in pit and looses
            if(PLAY_AS_HERO==true) {
                cout << "You have fallen in the pit.  You lose!" << endl;
                gameLogOut << "You have fallen in the pit.  You lose!"<< endl;
            }
            else{
                cout << "The Hero has fallen in the pit.  You win!"<< endl;
                gameLogOut << "The Hero has fallen in the pit.  You win!"<< endl;
            }
            gameEnd = true; heroVictory = false;
            break;
        }
        else if ((wumpusX == pitX) && (wumpusY == pitY)) { //Wumpus falls in pit and looses
            if(PLAY_AS_HERO==true) {
                cout << "The Wumpus has fallen in the pit.  You win!"<< endl;
                gameLogOut << "The Wumpus has fallen in the pit.  You win!"<< endl;
            }
            else{
                cout << "You have fallen in the pit.  You lose!"<< endl;
                gameLogOut << "You have fallen in the pit.  You lose!"<< endl;
            }
            gameEnd = true; heroVictory = true;
            break;
        }
        else if ((heroX == wumpusX) && (heroY == wumpusY)) { //Hero finds wumpus and wins
            if(PLAY_AS_HERO==true) {
                cout << "You have killed the Wumpus. You win!"<< endl;
                gameLogOut << "You have killed the Wumpus. You win!"<< endl;
            }
            else{
                cout << "You have been killed by the Hero.  You lose."<< endl;
                gameLogOut << "You have been killed by the Hero.  You lose."<< endl;
            }
            gameEnd = true; heroVictory = true;
            break;
        }
    }
    if (!gameEnd) { //Game has reached end of file and nothing happened
        heroVictory = false;
        //Respond to player as hero or wumpus
        if(PLAY_AS_HERO==true) {
            cout << "The Wumpus has evaded you. You lose."<< endl;
            gameLogOut << "The Wumpus has evaded you. You lose."<< endl;
        }
        else{
            cout << "You have evaded the Hero. You win!"<< endl;
            gameLogOut << "You have evaded the Hero. You win!"<< endl;
        }
    }
    cout << flush;
    wumpusFileIn.close();
    gameLogOut.close();
}