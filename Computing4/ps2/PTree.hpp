// Copyright (c) 2026 AJ Audet

#pragma once
#ifndef PTREE_HPP
#define PTREE_HPP

#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>

class PTree : public sf::Drawable {
 public:
  PTree(double length, int depth);

  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void pTree(sf::Vector2f position, float size, float angle, int depth);
  sf::FloatRect getBounds() const;
  void move(sf::Vector2f position);

 private:
  std::vector<sf::RectangleShape> branches_;
  int depth_;
};  // class PTree

#endif  // PTREE_HPP
