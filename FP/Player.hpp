/* CSCI 200: Final Project
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // StackOverflow
 *     // Cplusplus.com
 *     //
 *
 * Player.hpp creates the player class and defines any functions or actions the player might perform during gameplay
 */
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include "global.hpp"

class Player {
    public:
        Player();
        void draw(sf::RenderWindow& window);
        void update();
        int getLocationX();
        int getLocationY();
        bool getDead();

    private:
        int location;
        double x, y;
        int health;
        bool dead;
        sf::Texture texture;
        sf::Sprite sprite;
};

/************ Player Functions *************/

Player::Player() {
    texture.loadFromFile("data/PlayerShip.png");
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.075, 0.075));
    x = WINDOW_WIDTH / 2 - sprite.getGlobalBounds().width / 2;
    y = WINDOW_HEIGHT - sprite.getGlobalBounds().height;
    sprite.setPosition(sf::Vector2f(x, y));
}

void Player::draw(sf::RenderWindow& window) {
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

void Player::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // Move the player to the left when A is pressed
        x -= PLAYER_SPEED; // Adjust the value as needed for your game
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // Move the player to the right when D is pressed
        x += PLAYER_SPEED; // Adjust the value as needed for your game
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { // Move the player forward when W is pressed
        y -= PLAYER_SPEED*0.7; // Adjust the value as needed for your game
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { // Move the player backward when S is pressed
        y += PLAYER_SPEED*0.7; // Adjust the value as needed for your game
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { // shoot a laser when space is pressed
        //cout << "fire!" << endl;
    }

    // Ensure that the player stays within the screen bounds
    if (x < 0) {
        x = 0;
    }
    if (x > WINDOW_WIDTH - sprite.getGlobalBounds().width) {
        x = WINDOW_WIDTH - sprite.getGlobalBounds().width;
    }
    if (y < 0) {
        y = 0;
    }
    if (y > WINDOW_HEIGHT - sprite.getGlobalBounds().height) {
        y = WINDOW_HEIGHT - sprite.getGlobalBounds().height;
    }

    // Update the sprite's position
    sprite.setPosition(sf::Vector2f(int(x), int(y)));
}

int Player::getLocationX() {
    return int(x);
}

int Player::getLocationY() {
    return int(y);
}

bool Player::getDead() {
    return 0;
}

#endif