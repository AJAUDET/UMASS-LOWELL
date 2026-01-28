// Copyright 2026 AJ Audet
#include <optional>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "PS0 - SFML Events");
    sf::CircleShape shape(100.f);
    sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return -1;

    sf::Sprite pebble(texture);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            pebble.move({0.f, -0.1f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            pebble.move({0.f, 0.1f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            pebble.move({-0.1f, 0.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            pebble.move({0.1f, 0.f});

        sf::Vector2u windowSize = window.getSize();
        sf::FloatRect bounds = pebble.getGlobalBounds();
        sf::Vector2f pos = pebble.getPosition();

        pos.x = std::clamp(pos.x, 0.f, windowSize.x - bounds.size.x);
        pos.y = std::clamp(pos.y, 0.f, windowSize.y - bounds.size.y);

        pebble.setPosition(pos);

        window.clear();
        window.draw(pebble);
        window.draw(shape);
        window.display();
    }
}
