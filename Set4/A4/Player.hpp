#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Node.hpp"

class Player {
    public:
        Player();
        int returnID();
        int returnNumChips();
        void givePlayerChip(int roll);
        void giveCenterChip(int roll, Player* center);

        Player* prevPlayer;
        Player* nextPlayer;

        int playerID;
        int numChips;

};

/************ Player Functions *************/

Player::Player() {
    playerID = 0; // Set a default ID if needed
    numChips = 3; // Set a default number of chips if needed
}

int Player::returnID() {
    return playerID;
}

int Player::returnNumChips() {
    return numChips;
}

void Player::givePlayerChip(int roll) {
    if (roll == 3) {
        numChips -= 1;
        nextPlayer->numChips += 1;
    } else if (roll == 4) {
        numChips -= 1;
        prevPlayer->numChips += 1;
    }
    return;
}

void Player::giveCenterChip(int roll, Player* center) {
    if (roll == 5) {
        numChips -= 1;
        center->numChips += 1;
    }
    return;
}

#endif