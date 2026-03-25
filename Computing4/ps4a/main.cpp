// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "AniPlayer.hpp"

int main(int argc, char* argv[]) {
    AP::AniPlayer player(argv[1]);

    sf::RenderWindow window(
    sf::VideoMode(player.windowSize()), "AniPlayer");

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
        }
        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
