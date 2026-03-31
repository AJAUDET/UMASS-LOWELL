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

    sf::RenderWindow window(sf::VideoMode(player.windowSize()), "AniPlayer");

    sf::Clock clock;
    sf::Time pauseOffset = sf::Time::Zero;
    bool paused = false;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->code == sf::Keyboard::Key::R) {
                    clock.restart();
                    pauseOffset = sf::Time::Zero;
                    paused = false;
                    player.restart();
                } else if (key->code == sf::Keyboard::Key::P ||
                           key->code == sf::Keyboard::Key::Space) {
                    if (paused) {
                        paused = false;
                        player.unpause();
                    } else {
                        pauseOffset += clock.getElapsedTime();
                        paused = true;
                        player.pause();
                    }
                }
            }
        }

        if (paused) {
            player.tween(pauseOffset);
        } else {
            player.tween(pauseOffset + clock.getElapsedTime());
        }
        window.clear();
        window.draw(player);
        window.display();
    }
    return 0;
}
