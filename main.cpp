#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
using namespace std;

int main()
{

    cout << " Hello!!" << endl;

    // create the window
    RenderWindow window(sf::VideoMode(800, 600), "Minha Janela");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(Color::Black);

        sf::Texture texture;
        if (!texture.loadFromFile("img.jpg"))
        {
            // error...
        }

        sf::Sprite sprite;
        sprite.setTexture(texture);

        //sprite.setTextureRect(sf::IntRect(50, 50, 500, 300)); 
        //sprite.setColor(sf::Color(255, 255, 255, 128)); Transparente
        //sprite.setPosition(sf::Vector2f(150.f, 80.f));

        // draw everything here...
        window.draw(sprite);

        Font font;
        if (!font.loadFromFile("OpenSans-Bold.ttf"))
        {
            // error...
        }

        //window.clear(Color::Black);

        sf::Text text;

        // select the font
        text.setFont(font); // font is a sf::Font

        // set the string to display
        text.setString("Ola coisa linda, como voce esta?");

        // set the character size
        text.setCharacterSize(24); // in pixels, not points!

        // set the color
        text.setFillColor(sf::Color(255,111,156));

        // set the text style
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        text.setPosition(Vector2f(150.f, 420.f));

        // inside the main loop, between window.clear() and window.display()
        window.draw(text);



        // end the current frame
        window.display();
    }

    return 0;
}
