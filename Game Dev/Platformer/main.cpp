#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int windowWidth = 400;
int windowHeight = 300;

class playerClass {
    public:
        playerClass()
        {

        }
};

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(windowWidth, windowHeight), "Platformer");

    // variables
    bool up, down, left, right = false;
    playerClass player;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                app.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Right)) right = true;
        else if(Keyboard::isKeyPressed(Keyboard::Left)) left = true;
        else if(Keyboard::isKeyPressed(Keyboard::Up)) up = true;
        else if(Keyboard::isKeyPressed(Keyboard::Down)) down = true;
        else {
            up = false;
            down = false;
            left = false;
            right = false;
        }

        cout << down << endl;

        // Clear screen
        app.clear();

        // Draw the sprite

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
