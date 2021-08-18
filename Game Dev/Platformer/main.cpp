#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int windowWidth = 400;
int windowHeight = 300;

class playerClass {
    public:
        float x_vel;
        float y_vel;

        bool flipSprite;

        playerClass()
        {
            flipSprite = true;
            x_vel = 0;
            y_vel = 0;
        }

        void Update(bool playerUp, bool playerDown, bool playerLeft, bool playerRight)
        {
            if (playerRight)
            {
                flipSprite = true;
                x_vel = 5;
            }

            else if (playerLeft)
            {
                flipSprite = false;
                x_vel = -5;
            }
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

        player.Update(up, down, left, right);

        // Clear screen
        app.clear();

        // Draw the sprite

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
