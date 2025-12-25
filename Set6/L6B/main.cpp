/* CSCI 200: Lab 6B: L6B - SFML Starcraft
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // www.sfml-dev.org/documentation/2.5.1/
 *     // 
 *
 * This program draws stars based off of their positions in a given data file.
 */

#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Star.h"
using namespace std;

int main() {
    // create a window
    int WIDTH = 640;
    int HEIGHT = 640;
    RenderWindow window( VideoMode(WIDTH, HEIGHT), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    std::vector<Star> Stars;

    ifstream fileIn("data/stars.txt");
    double discard, xStar, yStar, brightness;
    int xPixel, yPixel;
    if (!fileIn) {
        cerr << "Error opening input file" << endl;
        return -1;
    }
    while (!fileIn.eof()) {
        fileIn >> xStar >> yStar >> discard >> brightness >> discard >> discard;
        Star starObject(xStar, yStar, brightness);
        if (brightness >= 0.0 && brightness <= 8.0) { // ensure object is in the proper range
            Stars.push_back(starObject); // send object to list
        }
    }
    fileIn.close();
    cout << "Size: " << Stars.size() << endl;
    cout << "X coordinate: " << Stars[0].getXcoor() << std::endl;
    cout << "X coordinate transformed: " << Stars[0].getTransformedX(WIDTH) << std::endl;
    cout << "Y coordinate: " << Stars[0].getYcoor() << std::endl;
    cout << "X coordinate transformed: " << Stars[0].getTransformedY(HEIGHT) << std::endl;
    cout << "Brightness: " << Stars[0].getBrightness() << std::endl;

    // find brightest star
    double BRIGHTEST_STAR = 0.0;
    for (unsigned int i = 0; i < Stars.size(); i++) {
        if (Stars[i].getBrightness() > BRIGHTEST_STAR) {
            BRIGHTEST_STAR = Stars[i].getBrightness();
        }
    }
    cout << BRIGHTEST_STAR << endl;

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        for (unsigned int i = 0; i < Stars.size(); i++) {
            xPixel = Stars[i].getTransformedX(WIDTH);
            yPixel = Stars[i].getTransformedY(HEIGHT);
            CircleShape starShape;
            starShape.setPosition(Vector2f(xPixel, yPixel));
            starShape.setRadius(2);
            starShape.setFillColor(Stars[i].getGrayscaleColor(BRIGHTEST_STAR));
            window.draw(starShape);
        }
        
        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}