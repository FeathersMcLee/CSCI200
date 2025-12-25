/* CSCI 200: Final Project
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // StackOverflow
 *     // Cplusplus.com
 *     //
 *
 * Enemy.hpp creates the enemy class and sets up any functions for enemy actions during gameplay
 */
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include <iostream>
#include "global.hpp"

class Enemy {
    public:
        Enemy();
        void draw(sf::RenderWindow& window);
        void update();
        int getLocationX();
        int getLocationY();
        bool getDead();
    private:
        double x, y;
        int enemyLocation;
        bool enemyStatus;

        sf::Texture texture;
        sf::Sprite sprite;

};

/************ Player Functions *************/

Enemy::Enemy() {
    texture.loadFromFile("data/EnemyRock.png");
    x = (int(rand()) % int((WINDOW_WIDTH  - sprite.getGlobalBounds().width + 1)));
    //x = WINDOW_WIDTH-random; /// 2 - sprite.getGlobalBounds().width / 2;
    y = (-int(rand()) % int((WINDOW_HEIGHT )));
    sprite.setPosition(sf::Vector2f(x, y));
}

void Enemy::draw(sf::RenderWindow& window) {
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.2, 0.2));
    sprite.setPosition(sf::Vector2f(x, y));
    window.draw(sprite);
}

void Enemy::update() {
    // Ensure that the enemy stays within the screen bounds
    if (y > WINDOW_HEIGHT - sprite.getGlobalBounds().height + 100) {
        y -= WINDOW_HEIGHT+100+(int(rand()) % int((WINDOW_HEIGHT)));
        x = (int(rand()) % int((WINDOW_WIDTH  - sprite.getGlobalBounds().width + 1)));
        return;
    }
    y += ENEMY_SPEED;
    // Update the sprite's position
    sprite.setPosition(sf::Vector2f(int(x), int(y)));
}

int Enemy::getLocationX() {
    return int(x);
}

int Enemy::getLocationY() {
    return int(y);
}

bool Enemy::getDead() {
    return 0;
}

#endif