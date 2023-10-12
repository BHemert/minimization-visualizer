#include <SFML/Graphics.hpp>
#include "algorithms/gradient_descent.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gradient Descent Visualization");
    window.setFramerateLimit(60);

    GradientDescent gd(-10.0f, 0.01f);

    // Drawing the function f(x) = x^2
    sf::VertexArray function(sf::LinesStrip, 800); // Assuming each x has a unique pixel on screen

    for (int i = 0; i < 800; i++)
    {
        float x = (i - 400) / 40.0f; // -10 <= x <= 10, if the screen width is 800
        function[i].position = sf::Vector2f(i, 300 - x * x * 4);
        function[i].color = sf::Color::Blue;
    }

    // Circle representing our x value
    sf::CircleShape point(5);
    point.setFillColor(sf::Color::Red);
    point.setPosition((-10 + 10) * 40, 300 - (-10) * (-10) * 4);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float x = gd.step();
        point.setPosition((x + 10) * 40, 300 - x * x * 4);

        window.clear(sf::Color::White);
        window.draw(function);
        window.draw(point);
        window.display();
    }

    return 0;
}
