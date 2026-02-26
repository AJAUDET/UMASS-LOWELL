// Copyright (c) 2026 AJ Audet

#include "Sokoban.hpp"

#include <fstream>

namespace SB {
Sokoban::Sokoban() {}

Sokoban::Sokoban(const std::string& levelFile) {
  std::ifstream in(levelFile);
  if (!in) {
    throw std::runtime_error("Sokoban: Unable to open level file");
  }
  in >> *this;
}

sf::Vector2u Sokoban::windowSize() const {
  return {lvlWidth_ * TILE_SIZE, lvlHeight_ * TILE_SIZE};
}

sf::Vector2u Sokoban::playerLoc() const { return playerPos_; }

void Sokoban::movePlayer(Direction) {
  // UNDEFINED FOR PART A
}

bool Sokoban::isWon() const {
  return false;  // stub for checks
}

void Sokoban::draw(sf::RenderTarget& target, sf::RenderStates states) const {
for (unsigned int y = 0; y < lvlHeight_; ++y) {
    for (unsigned int x = 0; x < lvlWidth_; ++x) {
      char tile = grid_[index(x, y)];

      size_t tileIndex;
      switch (tile) {
        case '#':  // wall
          tileIndex = 85;
          break;
        case '.':  // floor
          tileIndex = 90;
          break;
        case 'A':  // box
          tileIndex = 2;
          break;
        case 'a':  // storage
          tileIndex = 103;
          break;
        case '1':  // box in storage
          tileIndex = 41;
          break;
        default:
          tileIndex = 1;
          break;
      }

      auto view = (*spriteSheet_)[tileIndex];
      sf::Sprite spr = view.toSprite();

      spr.setPosition({static_cast<float>(x * TILE_SIZE),
                       static_cast<float>(y * TILE_SIZE)});
      target.draw(spr, states);
    }
  }
  auto p = (*spriteSheet_)[71];
  sf::Sprite player = p.toSprite();
  player.setPosition({static_cast<float>(playerPos_.x * TILE_SIZE),
                      static_cast<float>(playerPos_.y * TILE_SIZE)});
  target.draw(player, states);
}

std::istream& operator>>(std::istream& in, Sokoban& s) {
  in >> s.lvlHeight_ >> s.lvlWidth_;
  if (!in) {
    throw std::runtime_error("Sokoban: Error finding level dimensions");
  }
  std::string level;
  std::getline(in, level);

  s.grid_.clear();
  s.grid_.resize(s.lvlWidth_ * s.lvlHeight_);
  for (unsigned int y = 0; y < s.lvlHeight_; ++y) {
    std::getline(in, level);
    if (level.size() != s.lvlWidth_) {
      std::runtime_error("Sokoban: Level width does not match");
    }
    for (unsigned int x = 0; x < s.lvlWidth_; ++x) {
      char tile = '.';
      if (x < level.size()) tile = level[x];
      if (tile == '@') {
        s.playerPos_ = {x, y};
        s.grid_[s.index(x, y)] = '.';
      } else {
        s.grid_[s.index(x, y)] = tile;
      }
    }
  }
  s.origGrid_ = s.grid_;

  sf::Image image;
  if (!image.loadFromFile("assets/sokoban_tilesheet.png"))
    throw std::runtime_error("Sokoban: Failed to load tilesheet");

  s.spriteSheet_ = std::make_unique<sb::SpriteSheet>(
      image, sf::Vector2u{Sokoban::TILE_SIZE, Sokoban::TILE_SIZE});
  return in;
}

std::ostream& operator<<(std::ostream& out, const Sokoban& s) {
  out << s.lvlHeight_ << " " << s.lvlWidth_ << std::endl;
  for (unsigned int y = 0; y < s.lvlHeight_; ++y) {
    for (unsigned int x = 0; x < s.lvlWidth_; ++x) {
      if (s.playerPos_ == sf::Vector2u{x, y}) {
        out << '@';
      } else {
        out << s.grid_[s.index(x, y)];
      }
    }
    out << '\n';
  }
  return out;
}
}  // namespace SB
