// Copyright (c) 2026 AJ Audet

#include <SFML/Graphics.hpp>
#include <iostream>

#include "SpriteSheet.hpp"
#include "SpriteBuilder.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
            std::cerr << "Usage: " << argv[0]
                    << " <datafile> [scale]\n";
            return 1;
        }

    std::string dataFile = argv[1];
    unsigned scale = (argc >= 3)
        ? static_cast<unsigned>(std::stoul(argv[2])): 1;

    sb::SpriteBuilder builder(dataFile);

    sf::Vector2u size = builder.windowSize();
    sf::RenderWindow window(
        sf::VideoMode({size.x * scale, size.y * scale}),
        "SpriteBuilder Test");

    sf::RenderStates states;
    states.transform.scale(
        {static_cast<float>(scale),
         static_cast<float>(scale)});

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
                builder.randomize();
        }

        window.clear(sf::Color::Transparent);
        window.draw(builder, states);
        window.display();
    }

    return 0;
}
