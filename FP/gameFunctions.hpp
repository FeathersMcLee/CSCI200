/* CSCI 200: Final Project
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // StackOverflow
 *     // Cplusplus.com
 *     // learn.microsoft.com/en-us/windows/win32/api/winbase/
 *     // cplusplus.com/forum/beginner/54360/  there are links in this forum to useful information about changing the color of text
 *     // cplusplus.com/forum/beginner/190309/  how to use chrono
 *
 * This file houses all the functions to run main.cpp
 */

#ifndef GAMEFUNCTIONS_HPP
#define GAMEFUNCTIONS_HPP
#include "Player.hpp"
#include "Enemy.hpp"
#include "global.hpp"

#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <random>
#include <thread>
#include <SFML/Graphics.hpp>

using namespace std;

// function to play game
void playGame(int& score) {
    cout << "Playing game" << endl;
    double activeScore = 0;
    
    int game_over = 0;

    // get font from files
    sf::Font font;
    if (!font.loadFromFile("data/SpaceCrusaders-x3DP0.ttf")) {
        cerr << "Error loading font" << endl;
        return;
    }

    // set time
    //std::chrono::steady_clock::time_point previous_time;
    //previous_time = std::chrono::steady_clock::now();
    srand(static_cast<unsigned int>(time(0)));

    // create a window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid Survival");

    // create an event object once to store future events
    sf::Event event;

    Player player;

    // Create a vector to store enemies
    std::vector<Enemy> enemies;
    for (int i = 0; i < 5; ++i) {
        enemies.push_back(Enemy()); // Add enemies to the vector
    }
    int hitBox = 65;

    while( window.isOpen() && game_over == 0 ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        player.draw(window);
        player.update();
        for (Enemy& enemy : enemies) { // move all enemies on screen
            enemy.update();
        }
        for (Enemy& enemy : enemies) { // draw all enmies on screen
            enemy.draw(window);
        }
        activeScore += 0.01;
        score = int(activeScore); // Update score value as game runs
        sf::Text gameScoreText("Score: " + std::to_string(score), font, 35);
        gameScoreText.setPosition(WINDOW_WIDTH - gameScoreText.getGlobalBounds().width - 10.0f, 10.0f);
        window.draw(gameScoreText);

        //  END  DRAWING HERE
        /////////////////////////////////////

        // check if collision occurs
        for (Enemy& enemy : enemies) {
            int enemyX = enemy.getLocationX();
            int enemyY = enemy.getLocationY();
            int playerX = player.getLocationX();
            int playerY = player.getLocationY();

            if (abs(enemyX - playerX) <= hitBox && abs(enemyY - playerY) <= hitBox) {
                game_over = 1;
                break; // exit the loop if collision detected
            }
        }

        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == sf::Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
            
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////

        // set time and lag speed

    }

    // perform game ending actions
    if (game_over) {

        // print ending text
        sf::Text gameOverText("Game Over", font, 60);
        gameOverText.setPosition(WINDOW_WIDTH / 2 - gameOverText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - gameOverText.getGlobalBounds().height / 2);
        sf::Text scoreText("Score: " + std::to_string(score), font, 35);
        scoreText.setPosition(WINDOW_WIDTH / 2 - scoreText.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 + gameOverText.getGlobalBounds().height);

        // wait for user to exit game
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            //window.clear();
            window.draw(gameOverText);
            window.draw(scoreText);
            window.display();
        }
    }
}

// clear screen command
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to read saved scores from the scores file and update the high score and top player
void findTopPlayer(int& highScore, string& topPlayer, vector<string>& users, vector<int>& scores) {
    int topPlayerIndex, score;
    string username, discard;
    for (unsigned int i = 0; i < scores.size(); i++) {
        if (scores[i] > highScore) {
            highScore = scores[i];
            topPlayerIndex = i;
        }
    }
    topPlayer = users[topPlayerIndex];
    users.clear();
    scores.clear();
}

// Function that retrieves save data from a game scores file
void getScores(const string fileName, vector<string>& users, vector<int>& scores) {
    ifstream fileIn(fileName);
    string username, discard;
    int score;
    if (!fileIn) {
        cerr << "Error opening input file" << endl;
        return;
    }
    while (!fileIn.eof()) {
        fileIn >> username >> discard >> score;
        users.push_back(username);
        scores.push_back(score);
    }
    fileIn.close();
}

// Function to display title screen
void displayTitle(const string topPlayer, const int highScore) {
    cout << "     Welcome to Space Invaders!      " << endl; 
    cout << "Beat " << topPlayer << "'s high score of " << highScore << " points." << endl; 
    cout << "            How to play:             " << endl;
    //cout << "     Press \"space\" to fire         " << endl; 
    cout << "     Press \"A\" to move Left        " << endl;
    cout << "     Press \"D\" to move Left        " << endl; 
    cout << "-------------------------------------" << endl; 
    cout << "Press \"S\" to start or \"Q\" to quit" << endl; 
    cout << "-------------------------------------" << endl; 
}

// Function that writes new username and scores after a game is played to save score data
void writeScores(const string fileName, const string username, const int score) {
    ofstream fileOut(fileName, ios::app); // Open the file in append mode
    if (!fileOut) {
        cerr << "Error opening output file" << endl;
        return;
    }
    fileOut << endl << username << " Score: " << score; // Write the new line to the file
    cout << endl << username << " Score: " << score << endl;
    fileOut.close();
}

#endif