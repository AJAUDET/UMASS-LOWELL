#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "PS0 - SFML Events");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            shape.move({0.f, -0.1f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            shape.move({0.f, 0.1f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            shape.move({-0.1f, 0.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            shape.move({0.1f, 0.f});

        window.clear();
        window.draw(shape);
        window.display();
    }
}