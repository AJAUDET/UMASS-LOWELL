// Copyright 2026 AJ Audet
#include <stdexcept>
#include <memory>
#include <utility>
#include "SpriteSheet.hpp"

namespace sb {

TextureView::TextureView(std::shared_ptr<sf::Texture> texture)
: texture_(std::move(texture)) {
    if (!texture_) {
        throw std::invalid_argument("TextureView: null texture");
    }

    sf::Vector2u size = texture_->getSize();
    rect_ = sf::IntRect({0, 0},
        {static_cast<int>(size.x), static_cast<int>(size.y)});
}

TextureView::TextureView(std::shared_ptr<sf::Texture> texture,
const sf::IntRect& rect): texture_(std::move(texture)), rect_(rect) {
    if (!texture_) {
        throw std::invalid_argument("TextureView: null texture");
    }

    sf::Vector2u size = texture_->getSize();

    if (rect.position.x < 0 || rect.position.y < 0 ||
        rect.size.x <= 0 || rect.size.y <= 0 ||
        rect.position.x + rect.size.x > static_cast<int>(size.x) ||
        rect.position.y + rect.size.y > static_cast<int>(size.y)) {
        throw std::out_of_range("TextureView: rectangle out of bounds");
    }
}

TextureView TextureView::crop(const sf::IntRect& rect) const {
    if (rect.position.x < 0 || rect.position.y < 0 ||
        rect.size.x <= 0 || rect.size.y <= 0 ||
        rect.position.x + rect.size.x > rect_.size.x ||
        rect.position.y + rect.size.y > rect_.size.y) {
        throw std::out_of_range("TextureView::crop out of bounds");
    }

    sf::IntRect child(
        {rect_.position.x + rect.position.x,
            rect_.position.y + rect.position.y},
        {rect.size.x, rect.size.y});

    return TextureView(texture_, child);
}

sf::Sprite TextureView::toSprite() const {
    sf::Sprite sprite(*texture_);
    sprite.setTextureRect(rect_);
    return sprite;
}

sf::Image TextureView::toImage() const {
    sf::Image full = texture_->copyToImage();
    sf::Image view(sf::Vector2u(static_cast<unsigned>(rect_.size.x),
        static_cast<unsigned>(rect_.size.y)), sf::Color::Transparent);

    for (unsigned y = 0; y < static_cast<unsigned>(rect_.size.y); ++y) {
        for (unsigned x = 0; x < static_cast<unsigned>(rect_.size.x); ++x) {
            view.setPixel({x, y}, full.getPixel({
                static_cast<unsigned>(rect_.position.x + x),
                static_cast<unsigned>(rect_.position.y + y)}));
        }
    }

    return view;
}

sf::Vector2u TextureView::getSize() const {
    return {static_cast<unsigned>(rect_.size.x),
        static_cast<unsigned>(rect_.size.y)};
}

SpriteSheet::SpriteSheet(std::shared_ptr<sf::Texture> texture,
sf::Vector2u tileSize, sf::Vector2u gridSize, unsigned margin)
: texture_(std::move(texture)), tileSize_(tileSize),
gridSize_(gridSize), margin_(margin) {
    if (!texture_) throw std::invalid_argument("SpriteSheet: null texture");
    if (tileSize_.x == 0 || tileSize_.y == 0 ||
        gridSize_.x == 0 || gridSize_.y == 0)
        throw std::invalid_argument("SpriteSheet: zero dimensions");

    sf::Vector2u texSize = texture_->getSize();
    unsigned requiredWidth  = gridSize_.x *
        tileSize_.x + (gridSize_.x - 1) * margin_;
    unsigned requiredHeight = gridSize_.y *
        tileSize_.y + (gridSize_.y - 1) * margin_;

    if (requiredWidth > texSize.x || requiredHeight > texSize.y)
        throw std::out_of_range("SpriteSheet: texture too small");
}

SpriteSheet::SpriteSheet(const sf::Image& image,
sf::Vector2u tileSize, sf::Vector2u gridSize, unsigned margin)
: tileSize_(tileSize), gridSize_(gridSize), margin_(margin) {
    if (tileSize_.x == 0 || tileSize_.y == 0 ||
        gridSize_.x == 0 || gridSize_.y == 0)
        throw std::invalid_argument("SpriteSheet: zero dimensions");

    texture_ = std::make_shared<sf::Texture>();
    if (!texture_->loadFromImage(image))
        throw std::runtime_error("SpriteSheet: failed to load texture");

    sf::Vector2u texSize = texture_->getSize();
    unsigned requiredWidth  = gridSize_.x *
        tileSize_.x + (gridSize_.x - 1) * margin_;
    unsigned requiredHeight = gridSize_.y *
        tileSize_.y + (gridSize_.y - 1) * margin_;

    if (requiredWidth > texSize.x || requiredHeight > texSize.y)
        throw std::out_of_range("SpriteSheet: texture too small");
}

SpriteSheet::SpriteSheet(const sf::Image& image, sf::Vector2u tileSize) {
    sf::Vector2u imgSize = image.getSize();
    if (tileSize.x == 0 || tileSize.y == 0)
        throw std::invalid_argument("Tile size can't be zero");

    sf::Vector2u gridSize{ imgSize.x / tileSize.x, imgSize.y / tileSize.y };
    if (gridSize.x == 0 || gridSize.y == 0)
        throw std::invalid_argument("Tile size too big for image");

    *this = SpriteSheet(image, tileSize, gridSize, 0);
}

SpriteSheet::SpriteSheet(const sf::Image& image,
sf::Vector2u tileSize, unsigned margin) {
    sf::Vector2u imgSize = image.getSize();
    if (tileSize.x == 0 || tileSize.y == 0)
        throw std::invalid_argument("Tile size can't be zero");

    sf::Vector2u gridSize{
        (imgSize.x + margin) / (tileSize.x + margin),
        (imgSize.y + margin) / (tileSize.y + margin)
    };
    if (gridSize.x == 0 || gridSize.y == 0)
        throw std::invalid_argument("Tile size + margin too big for image");

    *this = SpriteSheet(image, tileSize, gridSize, margin);
}


unsigned SpriteSheet::width() const {
    return gridSize_.x;
}
unsigned SpriteSheet::height() const {
    return gridSize_.y;
}

sf::Vector2u SpriteSheet::size() const {
    return gridSize_;
}

size_t SpriteSheet::length() const {
    return static_cast<size_t>(gridSize_.x) * static_cast<size_t>(gridSize_.y);
}
sf::Vector2u SpriteSheet::getTileSize() const { return tileSize_; }

TextureView SpriteSheet::operator[](sf::Vector2u pos) const {
    if (pos.x >= gridSize_.x || pos.y >= gridSize_.y)
        throw std::out_of_range("SpriteSheet: index out of range");

    unsigned left = pos.x * (tileSize_.x + margin_);
    unsigned top  = pos.y * (tileSize_.y + margin_);

    sf::IntRect rect({static_cast<int>(left), static_cast<int>(top)},
                     {static_cast<int>(tileSize_.x),
                        static_cast<int>(tileSize_.y)});
    return TextureView(texture_, rect);
}

TextureView SpriteSheet::operator[](size_t index) const {
    if (index >= length())
        throw std::out_of_range("SpriteSheet: index out of range");

    unsigned x = static_cast<unsigned>(index % gridSize_.x);
    unsigned y = static_cast<unsigned>(index / gridSize_.x);
    return (*this)[sf::Vector2u{x, y}];
}

}  // namespace sb
