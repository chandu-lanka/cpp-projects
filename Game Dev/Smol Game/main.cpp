#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int windowWidth = 600;
int windowHeight = 400;

float x = 0;
float y = 0;
float momentum = 0.f;
float width = 50.f;
float height = 50.f;
bool movingRight = false;
bool movingLeft = false;

int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Smol Game", Style::Close | Style::Titlebar);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Right)
                    {
                        movingRight = true;
                    }
                    else if (event.key.code == Keyboard::Left)
                    {
                        movingLeft = true;
                    }
                    break;
                case Event::KeyReleased:
                    if (event.key.code == Keyboard::Right)
                    {
                        movingRight = false;
                    }
                    else if (event.key.code == Keyboard::Left)
                    {
                        movingLeft = false;
                    }
                    break;
            }
        }

        // bouncing feature
        if (y > windowHeight - height)
        {
            momentum = -momentum;
        }
        else {
            momentum += 0.2;
        }
        y += momentum;

        // movement
        if (movingRight)
        {
            x += 5;
        }
        if (movingLeft)
        {
            x -= 5;
        }

        // clear window
        window.clear(Color::Black);

        // draw entities here

        RectangleShape rect(Vector2f(width, height));
        rect.setFillColor(Color::Red);
        rect.setPosition(x, y);
        window.draw(rect);

        // display stuff on the screen
        window.display();

        // fps
        window.setFramerateLimit(60);
    }
}
