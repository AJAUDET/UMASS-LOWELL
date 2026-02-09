// Copyright (c) 2026 AJ Audet

#pragma once
#ifndef SPRITEBUILDER_HPP
#define SPRITEBUILDER_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "SpriteSheet.hpp"

namespace sb {
class SpriteBuilder: public sf::Drawable {
 public:
  SpriteBuilder(const std::string& textureFile);
  SpriteBuilder(const std::string& textureFile, const unsigned int seed);

  sf::Vector2u windowSize() const;

  void randomize();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
  std::vector<std::vector<sb::TextureView>> tileSheets_;
  std::vector<size_t> selection_;
  std::minstd_rand0 rng_;
 };
}  // namespace sb

#endif  // SPRITEBUILDER_HPP
