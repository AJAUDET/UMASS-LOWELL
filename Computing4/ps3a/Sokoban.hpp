// Copyright (c) 2026 AJ Audet

#pragma once
#ifndef SOKOBAN_HPP
#define SOKOBAN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

#include "SpriteBuilder.hpp"
#include "SpriteSheet.hpp"

namespace SB {
enum class Direction { Up, Down, Left, Right };  // SB::Direction

class Sokoban : public sf::Drawable {
 public:
  static const int TILE_SIZE = 64;
  Sokoban();
  explicit Sokoban(const std::string& levelFile);

  sf::Vector2u size() const { return {width(), height()}; }
  unsigned int width() const { return lvlWidth_; }
  unsigned int height() const { return lvlHeight_; }
  sf::Vector2u windowSize() const;

  sf::Vector2u playerLoc() const;
  void movePlayer(Direction dir);
  bool isWon() const;

  void reset() { grid_ = origGrid_; }
  friend std::ostream& operator<<(std::ostream& out, const Sokoban& s);
  friend std::istream& operator>>(std::istream& in, Sokoban& s);

 protected:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  unsigned int lvlWidth_;
  unsigned int lvlHeight_;

  std::vector<char> grid_;
  std::vector<char> origGrid_;

  sf::Vector2u playerPos_{0, 0};
  sf::Texture tiles_;
  std::unique_ptr<sb::SpriteSheet> spriteSheet_;

  size_t index(unsigned int x, unsigned int y) const {
    return x + y * lvlWidth_;
  }
};  // SB::Sokoban

std::ostream& operator<<(std::ostream& out, const Sokoban& s);
std::istream& operator>>(std::istream& in, Sokoban& s);
}  // namespace SB

#endif
