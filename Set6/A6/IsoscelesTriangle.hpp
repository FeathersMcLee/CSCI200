/* CSCI 200: Assignment 6: A6 - SFML: Triangle Land
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // stackoverflow, how to create a class hierarchy
 *     // got help from mines grad student for debugging the equilateraltriangle.hpp
 *
 * This code checks that the given coordinates actualy create an isosceles trinagle.
 */
#ifndef ISOSCELESTRIANGLE_HPP
#define ISOSCELESTRIANGLE_HPP

#include "Triangle.hpp"
#include <iostream>
#include <cmath>

using namespace std;

class IsoscelesTriangle : public Triangle {
    public:
        IsoscelesTriangle(); // default constructor
        ~IsoscelesTriangle(); // destructor
        //void setColor(const Color color); // sets the private color data member
        //void draw(RenderTarget& window); // creates a ConvexShape, sets the points for each coordinate, sets the fill color, draws it to the provided
        virtual bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) override; // If the sides do not form a triangle, return false.
};

// default constructor - sets the size to zero
IsoscelesTriangle::IsoscelesTriangle() {
    
}

// If the sides do not form a triangle, return false.
bool IsoscelesTriangle::setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
    double d12, d23, d13;
    d12 = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    d23 = std::sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    d13 = std::sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    //cout << " d12: " << d12 << " d23: " << d23 << " d13: " << d13 << endl; // used for debuging
    if ((d12 != 0 && d12 != 0 && d23 != 0 && d12 + d23 > d13 && d12 + d13 > d23 && d23 + d13 > d12) && (d12 == d23 || d12 == d13 || d23 == d13)) {
        coordinates.push_back(sf::Vector2f(x1, y1));
        coordinates.push_back(sf::Vector2f(x2, y2));
        coordinates.push_back(sf::Vector2f(x3, y3));
        return true;
    }
    return false;
}

#endif