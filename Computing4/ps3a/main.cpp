// Copyright (c) 2026 AJ Audet

#include "Sokoban.hpp"

using sf::Color;
using sf::Event;
using sf::FloatRect;
using sf::RenderWindow;
using sf::VideoMode;

int main() {
  sf::CircleShape circle(100.f);
  circle.setFillColor(Color::Blue);

  RenderWindow window{VideoMode({800, 800}), "Sokoban"};

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<Event::Closed>()) {
        window.close();
      }
    }
    window.clear(Color::Black);
    window.draw(circle);
    window.display();
  }

  return 0;
}