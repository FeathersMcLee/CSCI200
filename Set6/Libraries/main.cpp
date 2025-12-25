#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
using namespace sf;

int main() {

    // Variables for dealing with sprite
    double spriteX = 40, spriteY = 40;
    Clock programClock;
    Time lastTime = programClock.getElapsedTime();
    const int THRESHOLD = 500; // move every half second on line 85
    srand(time(0));
    rand();

    // TODO #1
    RenderWindow window( VideoMode( 640, 640 ), "SFML Example" );
    
    // TODO #3
    while( window.isOpen() ) {
        window.clear( sf::Color(128,128,128,128) );

        // TODO #6
        CircleShape face;
	        face.setPosition( 15, 15 );
        	face.setRadius(300);
            face.setFillColor( Color::Yellow );
	        window.draw( face );

        // TODO #7-8
        RectangleShape rect;
        rect.setSize( Vector2f( 45, 150 ) );
        rect.setPosition( 200, 150 );
        rect.setFillColor( Color(120, 0, 120) );
        window.draw(rect);

        RectangleShape rect2;
        rect2.setSize( Vector2f( 45, 150) );
        rect2.setPosition( 400, 150 );
        rect2.setFillColor( Color(0, 0, 255) );
        window.draw(rect2);

        // TODO #9
        for( float i = 0; i <= 3.14; i += 3.14/512.0f ) {
            ConvexShape convexShape( 4 );
            convexShape.setPoint( 0, Vector2f( cos( i )*150+320,   sin(i)*150+320 ) );
            convexShape.setPoint( 1, Vector2f( cos( i )*150+320+15, sin(i)*150+320 ) );
            convexShape.setPoint( 2, Vector2f( cos( i )*150+320+15, sin(i)*150+320+15 ) );
            convexShape.setPoint( 3, Vector2f( cos( i )*150+320,   sin(i)*150+320+15 ) );
            convexShape.setFillColor( Color( 0, 128, 0 ) );
            window.draw( convexShape );
        }

        // TODO #10
        Font myFont;
        if( !myFont.loadFromFile( "data/arial.ttf" ) )
            return -1;
        Text label;
        label.setFont( myFont );
        label.setString( "Hello World!" );
        label.setPosition( 250, 520 );
        label.setFillColor( Color::Black );
        window.draw( label );

        // Add a texture for a sprite
        Texture myTexture;
        if( !myTexture.loadFromFile( "data/bubble.png" ) ) {
            cerr << "Could not load image" << endl;
            return -2;
        }

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

        // TODO #2:
        window.display();

        // TODO #5
        Event event; // sets input events
		while (window.pollEvent(event)) {
            if (event.type == Event::MouseButtonPressed) { // if the event is a mouse button press
                spriteX = event.mouseButton.x;
                spriteY = event.mouseButton.y;
            }
			if (event.type == Event::Closed) { // if event is close button pressed
				window.close();
			}
		}
       
    // TODO #4
    }

    return EXIT_SUCCESS;
}
