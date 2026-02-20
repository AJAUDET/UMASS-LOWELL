#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

namespace SB {
enum class Direction {
    Up, Down, Left, Right
};

class Sokoban : public sf::Drawable {
 public:
    static const int TILE_SIZE = 64;

    Sokoban();
    explicit Sokoban(const std::string&);  // Optional

    sf::Vector2u size() const { return {width(), height()}; }
    unsigned int height() const;
    unsigned int width() const;

    sf::Vector2u windowSize() const;  // Optional

    sf::Vector2u playerLoc() const;

    bool isWon() const;

    void movePlayer(Direction dir);
    void reset();

    void undo(); // Optional XC
    void redo(); // Optional  X

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 private:
    // Any fields you need go here.
};

std::ostream& operator<<(std::ostream& out, const Sokoban& s);
std::istream& operator>>(std::istream& in, Sokoban& s);
}  // namespace SB
