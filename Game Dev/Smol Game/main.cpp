#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int windowWidth = 512;
int windowHeight = 512;

int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Smol Game", Style::Close | Style::Titlebar);

    while(window.isOpen())
    {
        Event listener;
        while (window.pollEvent(listener))
        {
            switch (listener.type)
            {
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    cout << "New Window Width: " << listener.size.width << "New Window Height: " << listener.size.height << endl;
                    break;
                case Event::TextEntered:
                    if (listener.text.unicode < 128)
                    {
                        printf("%c", listener.text.unicode);
                    }

            }
        }
    }

    return 0;
}
