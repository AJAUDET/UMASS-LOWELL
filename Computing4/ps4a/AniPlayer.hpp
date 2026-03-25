// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// AniPlayer.hpp
#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Component.hpp"

namespace AP {
class AniPlayer: public sf::Drawable {
 public:
    /**
     * Loads an AniPlayer containing the data from the given video
     * @param filename A .json file that contains data describing the video
     */
    explicit AniPlayer(const std::string& filename);

    /**
     * Advance the AniPlayer to the given time
     * @param time A given instance in time
     */
    void tween(sf::Time time);  // For part B

    /**
     * Gets the viewport dimensions for this Drawable
     * @return The size (in pixels)
     */
    sf::Vector2u windowSize() const;

 protected:
    void draw(sf::RenderTarget& target,
      sf::RenderStates states) const override;  // From sf::Drawable

 private:
    std::unique_ptr<Component> scene_;
    unsigned int width_;
    unsigned int height_;
};  // Class AniPlayer
}  // namespace AP
