// Copyright (c) 2026 AJ Audet

#include <fstream>
#include <stdexcept>
#include <random>
#include <chrono>

#include "SpriteBuilder.hpp"
#include "SpriteSheet.hpp"

namespace sb {

SpriteBuilder::SpriteBuilder(const std::string& textureFile)
: SpriteBuilder(textureFile, std::chrono::system_clock::now().time_since_epoch().count()) {}

SpriteBuilder::SpriteBuilder(const std::string& textureFile, unsigned int seed)
: rng_(seed) {
    std::ifstream file(textureFile);
    if (!file) throw std::runtime_error("SpriteBuilder: failed to open file");

    unsigned int tileWidth, tileHeight, margin;
    if (!(file >> tileWidth >> tileHeight >> margin))
        throw std::runtime_error("SpriteBuilder: failed to read tile dimensions");

    std::string imageFile;
    while (file >> imageFile) {
        sf::Image image;
        if (!image.loadFromFile(imageFile))
            throw std::runtime_error("SpriteBuilder: failed to load image");

        sf::Vector2u imgSize = image.getSize();
        sf::Vector2u gridSize{
            (imgSize.x + margin) / (tileWidth + margin),
            (imgSize.y + margin) / (tileHeight + margin)
        };

        if (gridSize.x == 0 || gridSize.y == 0)
            throw std::runtime_error("SpriteBuilder: tile size + margin too big for image");

        SpriteSheet sheet(image, {tileWidth, tileHeight}, gridSize, margin);

        std::vector<TextureView> tiles;
        tiles.reserve(sheet.length());
        for (size_t i = 0; i < sheet.length(); ++i) {
            tiles.push_back(sheet[i]);
        }

        tileSheets_.push_back(std::move(tiles));
    }
    randomize();
}

void SpriteBuilder::randomize() {
    selection_.clear();
    for (const auto& sheetTiles : tileSheets_) {
        std::uniform_int_distribution<size_t> dist(0, sheetTiles.size() - 1);
        selection_.push_back(dist(rng_));
    }
}

void SpriteBuilder::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (size_t i = 0; i < tileSheets_.size(); ++i) {
        sf::Sprite sprite = tileSheets_[i][selection_[i]].toSprite();
        target.draw(sprite, states);
    }
}

sf::Vector2u SpriteBuilder::windowSize() const {
    if (tileSheets_.empty()) return {0, 0};
    const auto& firstSheet = tileSheets_[0];
    if (firstSheet.empty()) return {0, 0};
    return firstSheet[0].getSize();
}

void SpriteBuilder::save(const std::string& filename) const {
    sf::Vector2u size = windowSize();
    sf::RenderTexture rt(size);
    rt.clear(sf::Color::Transparent);
    rt.draw(*this);
    rt.display();

    if (!rt.getTexture().copyToImage().saveToFile(filename)) {
        throw std::runtime_error("SpriteBuilder: failed to save image");
    }
}

}  // namespace sb
