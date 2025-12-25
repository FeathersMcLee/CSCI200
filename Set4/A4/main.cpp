/* CSCI 200: Assignment 4: A4 - Wild Left-Center-Right Simulation
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // Stackoverflow
 *     // Zybooks
 *
 * Methods and functions to run the game Wild Left-Center-Right.
 */

#include "Player.hpp"
#include "Game.hpp"
#include "Node.hpp"

#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

void playGame(Player*& currentPlayer, Player* center, bool &reverse, int &skips);

int rollDie();

bool checkForWin(Player* Player1);

void moveToNext(int skips, Player*& currentPlayer, bool reverse);

int main() {
    srand(time(0));
    // Ask for number of players
    int numPlayers;
    cout << "How many players are playing: ";
    cin >> numPlayers;
    cout << endl;
    if (numPlayers < 2) { // check if there are enough players to start
        cout << "Not enough players." << endl; return 0;
    }

    // create pointers
    Player* Player1 = nullptr;
    Player* prev_Player = nullptr;

    // create cicular doubly linked list for players
    for (int i = 1; i <= numPlayers; i++) {
        Player* cur_Player = new Player();
        cur_Player->playerID = i;
        if (prev_Player != nullptr) {
            prev_Player->nextPlayer = cur_Player;
            cur_Player->prevPlayer = prev_Player;
        } else {
            Player1 = cur_Player;
            cur_Player->prevPlayer = nullptr; // set the first player's prevPlayer to nullptr
        }
        prev_Player = cur_Player;
    }
    if (Player1 != nullptr && prev_Player != nullptr) {
        Player1->prevPlayer = prev_Player;
        prev_Player->nextPlayer = Player1;
    }

    // create center player with 0 chips
    Player* center = new Player();
    center->numChips = 0;

    // play rounds of the game
    int skips = 0;
    bool reverse = false;
    int numTurns;
    while(checkForWin(Player1) == 0) {
        if (Player1->returnNumChips() != 0) {
            playGame(Player1, center, reverse, skips);
        }
        moveToNext(skips, Player1, reverse);
        numTurns++;
    }

    // when game ends print winning player
    Player* winningPlayer = nullptr;
    Player* currentPlayer = Player1;
    do {
        if (currentPlayer->returnNumChips() > 0) {
            winningPlayer = currentPlayer;
            break;
        }
        currentPlayer = currentPlayer->nextPlayer;
    } while (currentPlayer != Player1);
    if (winningPlayer != nullptr) {
        cout << "Player #" << winningPlayer->returnID() << " wins with " << winningPlayer->returnNumChips() << " after " << numTurns << " turns" << endl;
    }

    return 0;
}

// play one round of the game
void playGame(Player*& currentPlayer, Player* center, bool &reverse, int &skips) {
    skips = 0;
    Player* cur_Player = currentPlayer;
    int numChips = cur_Player->returnNumChips();
    cout << "Player #" << cur_Player->returnID() << " has " << numChips << " chips left" << endl;

    // roll die according to number of chips held
    int rolls, roll;
    if (numChips <= 3) {
        rolls = numChips;
    } else {
        rolls = 3;
    }
    cout << "   Rolling " << rolls << " dice" << endl;

    // create list of rolled values
    vector<int> rollValues;
    for (int i = 0; i < rolls; i++) {
        roll = rollDie();
        rollValues.push_back(roll);
    }

    // perform actions based off of rolls
    for (int i = 0; i < rolls; i++) {
        roll = rollValues[i];
        cout << "   Rolled a " << roll;
        if (roll == 0 || roll == 1 || roll == 2) { // if die roll is 0 or 1 or 2, player keeps chips and nothing happens
            cout << " - keep!" << endl;
        } else if (roll == 3) { // if die rill is 3, give a chip to nextPlayer
            cur_Player->givePlayerChip(roll);
            cout << " - give next - Player #" << cur_Player->nextPlayer->returnID() << " has " << cur_Player->nextPlayer->returnNumChips() << " chips - Player #" << cur_Player->returnID() << " has " << cur_Player->returnNumChips() << " chips" << endl;
        } else if (roll == 4) { // if die roll is 4, give a chip to prevPlayer
            cur_Player->givePlayerChip(roll);
            cout << " - give prev - Player #" << cur_Player->prevPlayer->returnID() << " has " << cur_Player->prevPlayer->returnNumChips() << " chips - Player #" << cur_Player->returnID() << " has " << cur_Player->returnNumChips() << " chips" << endl;
        } else if (roll == 5) { // if die roll is 5, give a chip to the center
            cur_Player->giveCenterChip(roll, center);
            cout << " - give center - Center has " << center->returnNumChips() << " chips - Player #" << cur_Player->returnID() << " has " << cur_Player->returnNumChips() << " chips" << endl;
        } else if (roll == 6) { // if die roll is 6, revrse game turn order
            reverse = !reverse;
            cout << " - reverse!" << endl;
        } else { // if die roll is 7 skip next player
            skips++;
            cout << " - skip! skipping "<< skips << " players" << endl;
        }
    }
}

bool checkForWin(Player* Player1) {
    int playersWithChips = 0;
    Player* currentPlayer = Player1;

    // Count the number of players with more than 0 chips
    do {
        if (currentPlayer->returnNumChips() > 0) {
            playersWithChips++;
        }
        currentPlayer = currentPlayer->nextPlayer;
    } while (currentPlayer != Player1);

    // Return true if only one player has more than 0 chips
    return playersWithChips == 1;
}

void moveToNext(int skips, Player*& Player1, bool reverse) {
    for (int j = 0; j <= skips; j++) {
        if (reverse) {
            Player1 = Player1->prevPlayer;
        } else {
            Player1 = Player1->nextPlayer;
        }
    }
}

// rolls one die with possible numbers between 0 and 7
int rollDie() {
    int Random = (rand() % (8));
    return Random;
}
