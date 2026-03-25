// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// AniPlayer.cpp

#include <fstream>
#include <stdexcept>
#include "AniPlayer.hpp"

namespace AP {
    AniPlayer::AniPlayer(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("AniPlayer::AniPlayer, Could not open file: " + filename);
        }
        Json data;
        file >> data;
        width_ = data.value("width", 0);
        height_ = data.value("height", 0);
        scene_ = Component::fromJson(data["scene"]);
    }

    void AniPlayer::tween(sf::Time time) {
        // Part B
    }

    sf::Vector2u AniPlayer::windowSize() const {
        return sf::Vector2u{width_, height_};
    }

    void AniPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(*scene_, states);
    }
}
