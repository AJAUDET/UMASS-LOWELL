// Copyright (c) 2026 AJ Audet

#pragma once
#ifndef SOKOBAN_HPP
#define SOKOBAN_HPP

#include <SFML/Graphics.hpp>

#include "SpriteBuilder.hpp"

namespace sb {
enum class Directions { Up, Down, Left, Right };  // sb::Directions

class Sokoban : public sf::Drawable {
 public:
  static const int SIZE = 64;
  Sokoban();
  explicit Sokoban(const std::string&);

  sf::Vector2u size() const { return {width(), height()}; };
  unsigned int width() const;
  unsigned int height() const;
  sf::Vector2u windowSize();

  sf::Vector2u playerLoc() const;
  void movePlayer(Directions dir);
  bool isWon();

  void reset();

 protected:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
};  // sb::Sokoban
std::ostream& operator<<(std::ostream& out, const Sokoban& s);
std::istream& operator>>(std::istream& in, Sokoban& s);
}  // namespace sb

#endif
