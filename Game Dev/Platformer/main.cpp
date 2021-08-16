#include <SFML/Graphics.hpp>

using namespace sf;

int windowWidth = 400;
int windowHeight = 300;

int main()
{
    // Create the main window
    RenderWindow app(VideoMode(windowWidth, windowHeight), "Platformer");

    // variables
    bool up, down, left, right = false;

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

        // Clear screen
        app.clear();

        // Draw the sprite

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
