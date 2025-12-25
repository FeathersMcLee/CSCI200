/* CSCI 200: Lab 6B: L6B - SFML Starcraft
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // www.sfml-dev.org/documentation/2.5.1/
 *     // 
 *
 * This program creates the stars class
 */

#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Star {
    public:
        Star(); // default constructor
        Star(double x, double y, double brightness); // perameterized constructor
        double getXcoor();
        double getYcoor();
        double getBrightness();
        float getTransformedX(const int WIDTH);
        float getTransformedY(const int HEIGHT);
        Color getGrayscaleColor(const double BRIGHTEST_STAR);

    private:
        double Xcoor;
        double Ycoor;
        double brightness;

};

#endif