// Copyright (c) 2026 AJ Audet

#include <iostream>
#include <string>
#include <chrono>
#include <random>

#include "SpriteSheet.hpp"
#include "SpriteBuilder.hpp"

#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
    std::string dataFile;
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned int scale = 16;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg.rfind("--file=", 0) == 0) {
            dataFile = arg.substr(7);
        } else if (arg.rfind("--scale=", 0) == 0) {
            scale = static_cast<unsigned int>(std::stoul(arg.substr(8)));
        } else if (arg.rfind("--seed=", 0) == 0) {
            seed = static_cast<unsigned int>(std::stoul(arg.substr(7)));
        } else {
            std::cerr << "Unknown argument: " << arg << "\n";
            return 1;
        }
    }

    sb::SpriteBuilder builder(dataFile, seed);

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                builder.save("output_" + std::to_string(seed) + ".png");
        }

        window.clear(sf::Color::Transparent);
        window.draw(builder, states);
        window.display();
    }

    return 0;
}
