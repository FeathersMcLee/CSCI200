/* CSCI 200: Assignment 6: A6 - SFML: Triangle Land
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // stackoverflow, how to create a class hierarchy
 *     // got help from mines grad student for debugging the equilateraltriangle.hpp
 *
 * This is the parrent .hpp file that creates protected varibles that will be used in the child classes. This file also creates, destroys, and draws each triangle.
 */
#ifndef LIST_HPP
#define LIST_HPP

#include <SFML/Graphics.hpp>

class Triangle {
    public:
        Triangle(); // default constructor
        ~Triangle(); // destructor
        void setColor(const sf::Color& color); // sets the private color data member
        void draw(sf::RenderTarget& window); // creates a ConvexShape, sets the points for each coordinate, sets the fill color, draws it to the provided
        virtual bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) = 0;
    protected:
        int verts; // the number of vertices making up the triangle as an integer
        std::vector<sf::Vector2f> coordinates; // a list of (x, y) coordinates
    private:
        sf::Color fillColor; // the color of the triangle as an SFML Color object
};

// default constructor - sets the color to white, specifies the number of vertices as 3, allocates the list to have three elements (if necessary)
Triangle::Triangle() {
    fillColor = sf::Color::White;
    verts = 3;
}

//deallocates the list (if necessary)
Triangle::~Triangle() {
    if (coordinates.size() > 0) {
        coordinates.clear();
    }
}

// sets the private color data member
void Triangle::setColor(const sf::Color& color) {
    fillColor = color;
}

// creates a ConvexShape, sets the points for each coordinate, sets the fill color, draws it to the provided
void Triangle::draw(sf::RenderTarget& window) {
    sf::ConvexShape tri;
    tri.setPointCount(verts); 
    for (int i = 0; i < verts; ++i) {
        tri.setPoint(i, coordinates[i]);
    }
    tri.setFillColor(sf::Color(fillColor)); 
    window.draw(tri);

}

#endif