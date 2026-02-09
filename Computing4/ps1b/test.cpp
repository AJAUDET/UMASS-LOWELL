// Copyright 2026 AJ Audet

#include <iostream>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "SpriteSheet.hpp"
#include "SpriteBuilder.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SpriteBuilderTests
#include <boost/test/included/unit_test.hpp>

using sb::TextureView;
using sb::SpriteSheet;
using sb::SpriteBuilder;

using sf::Image;
using sf::Vector2u;
using sf::Vector2i;
using sf::Sprite;
using sf::IntRect;
using sf::RenderTexture;
using sf::RenderStates;

using std::string;

// ostream operator for Vector2u so we can compare equality easily
namespace sf {
std::ostream& operator<<(std::ostream& os, const sf::Vector2u& v) {
    os << "<" << v.x << "," << v.y << ">";
    return os;
}
}

bool checkImagesIdentical(const Image& img1, const Image& img2) {
    if (img1.getSize() != img2.getSize()) return false;
    Vector2u size = img1.getSize();
    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            if (img1.getPixel({x, y}) != img2.getPixel({x, y})) return false;
        }
    }
    return true;
}

BOOST_AUTO_TEST_CASE(TestFixedSeedConsistency) {
    SpriteBuilder b1("rogue.txt", 444);
    SpriteBuilder b2("rogue.txt", 444);

    Vector2u s = b1.windowSize();
    RenderTexture rt1(s);
    RenderTexture rt2(s);

    rt1.clear();
    rt1.draw(b1);
    rt1.display();

    rt2.clear();
    rt2.draw(b2);
    rt2.display();

    BOOST_CHECK(checkImagesIdentical(
        rt1.getTexture().copyToImage(),
        rt2.getTexture().copyToImage()));

    for (int i = 0; i < 5; ++i) {
        b1.randomize();
        b2.randomize();

        RenderTexture r1(b1.windowSize());
        RenderTexture r2(b2.windowSize());

        r1.clear();
        r1.draw(b1);
        r1.display();

        r2.clear();
        r2.draw(b2);
        r2.display();

        BOOST_CHECK(checkImagesIdentical(
            r1.getTexture().copyToImage(),
            r2.getTexture().copyToImage()));
    }
}

BOOST_AUTO_TEST_CASE(TestFixedSeedInconsistency) {
    SpriteBuilder b1("rogue.txt");
    SpriteBuilder b2("rogue.txt");

    Vector2u s = b1.windowSize();
    RenderTexture rt1(s);
    RenderTexture rt2(s);

    rt1.clear();
    rt1.draw(b1);
    rt1.display();

    rt2.clear();
    rt2.draw(b2);
    rt2.display();

    BOOST_CHECK(!checkImagesIdentical(
        rt1.getTexture().copyToImage(),
        rt2.getTexture().copyToImage()));

    for (int i = 0; i < 5; ++i) {
        b1.randomize();
        b2.randomize();

        RenderTexture r1(b1.windowSize());
        RenderTexture r2(b2.windowSize());

        r1.clear();
        r1.draw(b1);
        r1.display();

        r2.clear();
        r2.draw(b2);
        r2.display();

        BOOST_CHECK(!checkImagesIdentical(
            r1.getTexture().copyToImage(),
            r2.getTexture().copyToImage()));
    }
}

BOOST_AUTO_TEST_CASE(TestSizewithRandomization) {
    SpriteBuilder builder("rogue.txt");
    Vector2u initialSize = builder.windowSize();

    for (int i = 0; i < 100; i++) {
        builder.randomize();
        BOOST_CHECK_EQUAL(builder.windowSize().x, initialSize.x);
        BOOST_CHECK_EQUAL(builder.windowSize().y, initialSize.y);
    }
}

BOOST_AUTO_TEST_CASE(TestBuilderIndependence) {
    SpriteBuilder b1("rogue.txt", 111);
    SpriteBuilder b2("rogue.txt", 222);

    BOOST_CHECK_EQUAL(b1.windowSize().x, b2.windowSize().x);
    BOOST_CHECK_EQUAL(b1.windowSize().y, b2.windowSize().y);
}

BOOST_AUTO_TEST_CASE(TestRandomizeChangesSprite) {
    SpriteBuilder b("rogue.txt", 555);
    Vector2u s = b.windowSize();

    RenderTexture rt(s);

    rt.clear();
    rt.draw(b);
    rt.display();
    Image state1 = rt.getTexture().copyToImage();

    b.randomize();

    rt.clear();
    rt.draw(b);
    rt.display();
    Image state2 = rt.getTexture().copyToImage();

    BOOST_CHECK(!checkImagesIdentical(state1, state2));
}

BOOST_AUTO_TEST_CASE(TestUniqueSeeds) {
    SpriteBuilder b1("rogue.txt", 111);
    SpriteBuilder b2("rogue.txt", 999);
    Vector2u s = b1.windowSize();

    RenderTexture rt1(s);
    RenderTexture rt2(s);

    rt1.clear();
    rt1.draw(b1);
    rt1.display();

    rt2.clear();
    rt2.draw(b2);
    rt2.display();

    BOOST_CHECK(!checkImagesIdentical(
        rt1.getTexture().copyToImage(),
        rt2.getTexture().copyToImage()));
}