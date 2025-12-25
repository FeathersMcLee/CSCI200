/* CSCI 200: Lab 6B: L6B - SFML Starcraft
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // www.sfml-dev.org/documentation/2.5.1/
 *     // 
 *
 * This program impliments all the functions for the star class
 */

#include "Star.h"
#include <SFML/Graphics.hpp>
using namespace sf;

// Star::Star() : Xcoor(0), Ycoor(0), brightness(0) {}
Star::Star() { // set all data to 0 by default
    Xcoor = 0; 
    Ycoor = 0;
    brightness = 0;
}

Star::Star(double x, double y, double brightness) : Xcoor(x), Ycoor(y), brightness(brightness) {}

double Star::getXcoor() {
    return Xcoor;
}

double Star::getYcoor() {
    return Ycoor;
}

double Star::getBrightness() {
    return brightness;
}

float Star::getTransformedX(const int WIDTH) {
    float xPixel = (Xcoor + 1) * WIDTH / 2;
    return xPixel;
}

float Star::getTransformedY(const int HEIGHT) {
    float yPixel = (-Ycoor + 1) * HEIGHT / 2;
    return yPixel;
}

Color Star::getGrayscaleColor(const double BRIGHTEST_STAR) {
    int invertedBrightness = BRIGHTEST_STAR - brightness;
    int shadeOfGray = (int)((255.0 * invertedBrightness) / BRIGHTEST_STAR);
    return Color(shadeOfGray, shadeOfGray, shadeOfGray);
}