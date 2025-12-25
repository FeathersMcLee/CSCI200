/* CSCI 200: Lab 6A: L6A - SFML Bob Ross
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // www.sfml-dev.org/documentation/2.5.1/
 *     // pngtree.com/element/down?id=NDE3MDE4Ng==&type=1&time=1690768171&token=OWI2Zjc3MGFkZjFjNjIyZGZmZDU4MzNjMDk1YTZkYmQ=&t=0 // this website is kinda sketch
 *
 * “In coding, you have unlimited power. You have the ability to move mountains. You can bend rivers. But when I get home, the only thing I have power over is the garbage.” - Bob Ross (updated to 2023 standards)
 */

#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;

#include <iostream>
using namespace std;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    double spriteX = 40, spriteY = 40;
    Clock programClock;
    Time lastTime = programClock.getElapsedTime();
    const int THRESHOLD = 500; // move every half second on line 85
    srand(time(0));
    rand();

    Texture myTexture;
        if( !myTexture.loadFromFile( "data/flying eagle.png" ) ) {
            cerr << "Could not load image" << endl;
            return -2;
        }

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
        ConvexShape mountain;
        mountain.setPointCount(3); 
        mountain.setPoint(0, Vector2f(100, 440)); // Bottom-left corner
        mountain.setPoint(1, Vector2f(420, 100)); // Top corner
        mountain.setPoint(2, Vector2f(740, 440)); // Bottom-right corner
        mountain.setFillColor(Color(128, 128, 128)); 
        window.draw(mountain);

        // place any draw commands here to display in the window
        // Draw two trees
        for (int i = 0; i < 2; i++) {
            int x = 250*i; int y = 20*i;
            // Draw a rectangle object called trunk
            RectangleShape trunk;
            trunk.setSize( Vector2f( 45, 150 ) );
            trunk.setPosition( 200+x, 300+y );
            trunk.setFillColor( Color(150, 75, 0));
            window.draw( trunk );

            // Draw leaves for a happy little tree
            CircleShape treeTop;
            treeTop.setPosition( 125+x, 130+y );
            treeTop.setRadius( 100 );
            treeTop.setFillColor( Color::Green );
            window.draw( treeTop );
        }

        // draw a lake
        CircleShape lake(100, 50); // Radius = 100, Number of points = 50 (higher = smoother)
        lake.setPosition(270, 400); // Center the oval in the window
        lake.setFillColor(Color::Blue); // Fill color of the oval
        lake.setOutlineColor(Color(150, 75, 0)); // Outline color of the oval
        lake.setOutlineThickness(5);
        window.draw(lake);

        // Display sprite
        Sprite mySprite;
        mySprite.setTexture( myTexture );
        mySprite.setScale(0.10,0.10);
        mySprite.setPosition( spriteX, spriteY );            
        window.draw( mySprite ); 

        // Have sprite move 
        Time currTime = programClock.getElapsedTime();
        if( (currTime - lastTime).asMilliseconds() > THRESHOLD ) { // if time threshold is met execute movement
            spriteX += rand()%10 - 5;
            spriteY += rand()%10 - 5;
            lastTime = currTime;
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
            if (event.type == Event::MouseButtonPressed) { // if the event is a mouse button press
                spriteX = event.mouseButton.x;
                spriteY = event.mouseButton.y;
            }
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}