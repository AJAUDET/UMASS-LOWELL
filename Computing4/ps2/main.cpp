// Copyright (c) 2026 AJ Audet

#include <iostream>
#include <string>

#include "PTree.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using std::cerr;
using std::string;

using sf::Color;
using sf::Event;
using sf::FloatRect;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Keyboard::isKeyPressed;
using sf::Keyboard::Key;

int main(int argc, char* argv[]) {
    double length = 100.0;
    int depth = 1;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg.rfind("--length=", 0) == 0) {
            length = static_cast<double>(std::stoul(arg.substr(9)));
        } else if (arg.rfind("--depth=", 0) == 0) {
            depth = static_cast<int>(std::stoul(arg.substr(8)));
        } else {
            cerr << "Unknown argument: " << arg << "\n";
            return 1;
        }
    }

    PTree tree(length, depth);

    FloatRect bounds = tree.getBounds();

    unsigned width = static_cast<unsigned>(bounds.size.x);
    unsigned height = static_cast<unsigned>(bounds.size.y);

    RenderWindow window{
        VideoMode({width, height}), "Pythagorean Tree"
    };

    tree.move({-bounds.position.x, -bounds.position.y});

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
        }
        if (isKeyPressed(Key::Escape)) {
            window.close();
        }
        window.clear(Color::Transparent);
        window.draw(tree);
        window.display();
    }

    return 0;
}
