/* CSCI 200: Assignment 6: A6 - SFML: Triangle Land
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // stackoverflow, how to create a class hierarchy
 *     // got help from mines grad student for debugging the equilateraltriangle.hpp
 *
 * This is the main function that retrives file info and mangaes the window as well as the logic to diturmine what kind of triangle is being put in.
 */
#include "Triangle.hpp"
#include "ScaleneTriangle.hpp"
#include "IsoscelesTriangle.hpp"
#include "EquilateralTriangle.hpp"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
//using namespace sf;

using namespace std;

int main() {
    // input triangel data from file

    sf::RenderWindow window( sf::VideoMode(640, 640), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    ifstream fileIn("triangles.dat");
    if ( !fileIn ) {
        cerr << "Error opening input file" << endl;
        return -1;
    }

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    sf::Event event;
    std::vector<Triangle*> triangleList;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        // while triangle data from file still exists run functions to draw triangles
        double x1, y1, x2, y2, x3, y3;
        int r, g, b;
        char triType;
        while ( !fileIn.eof()) {
            fileIn >> triType >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
            Triangle* newTriangle = nullptr;
            switch (triType) {
            case 'S':
                //cout << "ScaleneTriangle" << endl; // used for debuging
                newTriangle = new ScaleneTriangle;
                if (newTriangle->setCoordinates(x1, y1, x2, y2, x3, y3)) { // check that triangle is scalene.
                    newTriangle->setColor(sf::Color(r, g, b));
                    triangleList.push_back(newTriangle);
                }
                break;
            case 'I':
                //cout << "IsoscelesTriangle" << endl; // used for debuging
                newTriangle = new IsoscelesTriangle;
                if (newTriangle->setCoordinates(x1, y1, x2, y2, x3, y3)) { // check that triangle is isosceles.
                    newTriangle->setColor(sf::Color(r, g, b));
                    triangleList.push_back(newTriangle);
                }
                break;
            case 'E':
                //cout << "EquilateralTriangle" << endl; // used for debuging
                newTriangle = new EquilateralTriangle;
                if (newTriangle->setCoordinates(x1, y1, x2, y2, x3, y3)) { // check that triangle is equalateral.
                    newTriangle->setColor(sf::Color(r, g, b));
                    triangleList.push_back(newTriangle);
                }
                break;
            default:
                //cout << "Triangle type not valid." << endl; // used for debuging
                break;
            }
        }

        for (Triangle* triangle : triangleList) {
            triangle->draw(window);
        }

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == sf::Event::Closed) {
                // tell the window to close
                window.close();
            }
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////

        window.display();
    }

    // close files and clean up memory when done
    triangleList.clear();
    fileIn.close();

    return 0;
}