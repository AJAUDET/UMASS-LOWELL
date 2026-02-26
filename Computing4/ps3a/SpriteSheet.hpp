// Copyright 2026 AJ Audet

#pragma once
#ifndef SPRITESHEET_HPP
#define SPRITESHEET_HPP

#include <memory>
#include <SFML/Graphics.hpp>

namespace sb {
class TextureView {
 public:
  explicit TextureView(std::shared_ptr<sf::Texture> texture);
  TextureView(std::shared_ptr<sf::Texture> texture, const sf::IntRect &rect);

  TextureView crop(const sf::IntRect &rect) const;
  sf::Image toImage() const;
  sf::Sprite toSprite() const;
  sf::Vector2u getSize() const;

 private:
  std::shared_ptr<sf::Texture> texture_;
  sf::IntRect rect_;
};

class SpriteSheet {
 public:
  SpriteSheet(std::shared_ptr<sf::Texture> texture,
    sf::Vector2u tileSize,
    sf::Vector2u gridSize,
    unsigned margin = 0);

  SpriteSheet(const sf::Image &image,
    sf::Vector2u tileSize,
    sf::Vector2u gridSize,
    unsigned margin = 0);

  SpriteSheet(const sf::Image &image, sf::Vector2u tileSize);
  SpriteSheet(const sf::Image &image, sf::Vector2u tileSize, unsigned margin);

  unsigned width() const;
  unsigned height() const;
  sf::Vector2u size() const;
  size_t length() const;
  sf::Vector2u getTileSize() const;

  TextureView operator[](sf::Vector2u pos) const;
  TextureView operator[](size_t index) const;

 private:
  std::shared_ptr<sf::Texture> texture_;
  sf::Vector2u tileSize_;
  sf::Vector2u gridSize_;
  unsigned margin_;
};

}  // namespace sb

#endif
