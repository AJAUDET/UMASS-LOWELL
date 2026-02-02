// Copyright 2026 AJ Audet

#include <iostream>
#include <memory>
#include <string>
#include "SpriteSheet.hpp"
#include <SFML/Graphics.hpp>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SpriteSheetTests
#include <boost/test/included/unit_test.hpp>

using sb::TextureView;
using sb::SpriteSheet;

using sf::Image;
using sf::Vector2u;
using sf::Vector2i;
using sf::Sprite;
using sf::IntRect;

namespace sf {
std::ostream& operator<<(std::ostream& os, const sf::Vector2u& v) {
    os << "<" << v.x << "," << v.y << ">";
    return os;
}
}

BOOST_AUTO_TEST_CASE(TestInstructorTileSize) {
    Image img("images/playingCards.png");
    SpriteSheet sheet(img, {140, 190});
    BOOST_REQUIRE_EQUAL(sheet.getTileSize(), Vector2u(140, 190));
}

BOOST_AUTO_TEST_CASE(TestDimensions) {
    Image img(Vector2u(200, 150));
    Vector2u tileSize(50, 50);
    SpriteSheet sheet(img, tileSize, 0);

    BOOST_CHECK_EQUAL(sheet.width(), 4u);
    BOOST_CHECK_EQUAL(sheet.height(), 3u);
    BOOST_CHECK_EQUAL(sheet.length(), 12u);

    TextureView tv = sheet[0];
    Vector2u size = tv.getSize();

    BOOST_CHECK_EQUAL(size.x, 50u);
    BOOST_CHECK_EQUAL(size.y, 50u);
}

BOOST_AUTO_TEST_CASE(TestPosition) {
    Image img(Vector2u(200, 200));
    SpriteSheet sheet(img, Vector2u(50, 50));
    TextureView tv = sheet[Vector2u(1, 1)];
    Sprite sprite = tv.toSprite();

    BOOST_CHECK_EQUAL(sprite.getTextureRect().position.x, 50);
    BOOST_CHECK_EQUAL(sprite.getTextureRect().position.y, 50);
}

BOOST_AUTO_TEST_CASE(TestColumn) {
    Image img(Vector2u(100, 100));
    SpriteSheet sheet(img, Vector2u(50, 50));
    TextureView tv = sheet[1];
    Sprite sprite = tv.toSprite();

    BOOST_CHECK_EQUAL(sprite.getTextureRect().position.x, 50);
    BOOST_CHECK_EQUAL(sprite.getTextureRect().position.y, 0);
}

BOOST_AUTO_TEST_CASE(TestBadCrop) {
    Image img(Vector2u(100, 100));
    SpriteSheet sheet(img, Vector2u(50, 50), 0);
    TextureView tv = sheet[0];

    IntRect temp(Vector2i(0, 0), Vector2i(50, 50));
    BOOST_CHECK_NO_THROW(tv.crop(temp));

    IntRect onePixelDiff(Vector2i(1, 0), Vector2i(50, 50));
    BOOST_CHECK_THROW(tv.crop(onePixelDiff), std::out_of_range);

    IntRect negativePos(Vector2i(-1, 0), Vector2i(50, 50));
    BOOST_CHECK_THROW(tv.crop(negativePos), std::out_of_range);

    IntRect tooTall(Vector2i(0, 0), Vector2i(50, 51));
    BOOST_CHECK_THROW(tv.crop(tooTall), std::out_of_range);

    IntRect tooWide(Vector2i(0, 0), Vector2i(51, 50));
    BOOST_CHECK_THROW(tv.crop(tooWide), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(TestCrop) {
    Image img(Vector2u(100, 100));
    SpriteSheet sheet(img, Vector2u(50, 50));
    TextureView tv = sheet[0];
    IntRect cropArea(Vector2i(10, 10), Vector2i(20, 20));
    TextureView cropped = tv.crop(cropArea);

    BOOST_CHECK_EQUAL(cropped.getSize().x, 20u);
    BOOST_CHECK_EQUAL(cropped.getSize().y, 20u);

    Sprite s = cropped.toSprite();
    BOOST_CHECK_EQUAL(s.getTextureRect().position.x, 10);
    BOOST_CHECK_EQUAL(s.getTextureRect().position.y, 10);
}

BOOST_AUTO_TEST_CASE(TestThrow) {
    Image img(Vector2u(100, 100));
    BOOST_CHECK_NO_THROW({
        SpriteSheet sheet(img, Vector2u(50, 50));
        TextureView tv = sheet[0];
        Sprite s = tv.toSprite(); });
}

BOOST_AUTO_TEST_CASE(TestMargin) {
    Image img(Vector2u(200, 200));
    Vector2u tileSize(50, 50);

    int margin = 10;
    SpriteSheet sheet(img, tileSize, margin);
    TextureView tv = sheet[1];
    Sprite sprite = tv.toSprite();

    int x = sprite.getTextureRect().position.x;

    BOOST_CHECK_EQUAL(x, 60);
}
