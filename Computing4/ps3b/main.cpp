// Copyright (c) 2026 AJ Audet

#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>

#include "Sokoban.hpp"

using SB::Direction;
using SB::Sokoban;

using sf::Color;
using sf::Event;
using sf::FloatRect;
using sf::RenderWindow;
using sf::VideoMode;
using sf::Keyboard::Key;

using std::cerr;
using std::cout;
using std::exception;
using std::optional;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./Sokoban <level_name>.lvl\n";
    return 1;
  }

  try {
    Sokoban game(argv[1]);

    cout << "Loaded level:\n";
    cout << game << std::endl;

    RenderWindow window(VideoMode(game.windowSize()), "Sokoban");

    while (window.isOpen()) {
      while (const optional event = window.pollEvent()) {
        if (event->is<Event::Closed>()) window.close();

        if (event->is<Event::KeyPressed>()) {
          const auto& key = event->getIf<Event::KeyPressed>()->code;

          if (key == Key::Escape) window.close();
          if (key == Key::R) {
            game.reset();
            cout << "Level reset.\n";
          }

          if (key == Key::Up) game.movePlayer(Direction::Up);
          if (key == Key::Down) game.movePlayer(Direction::Down);
          if (key == Key::Left) game.movePlayer(Direction::Left);
          if (key == Key::Right) game.movePlayer(Direction::Right);
        }
      }

      window.clear();
      window.draw(game);
      window.display();
    }
  } catch (const exception& e) {
    cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
