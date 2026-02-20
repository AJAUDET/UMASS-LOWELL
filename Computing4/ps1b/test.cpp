// Copyright 2026 AJ Audet

#include <iostream>
#include <memory>
#include <string>

#include "SpriteSheet.hpp"
#include "SpriteBuilder.hpp"

#include <SFML/Graphics.hpp>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SpriteBuilderTests
#include <boost/test/included/unit_test.hpp>

using sb::TextureView;
using sb::SpriteSheet;
using sb::SpriteBuilder;

using sf::Image;
using sf::IntRect;
using sf::RenderStates;
using sf::RenderTexture;
using sf::RenderWindow;
using sf::Sprite;
using sf::Vector2i;
using sf::Vector2u;

using std::string;

// ostream operator for Vector2u so we can compare equality easily
namespace sf {
std::ostream& operator<<(std::ostream& os, const sf::Vector2u& v) {
    os << "<" << v.x << "," << v.y << ">";
    return os;
}
}

BOOST_AUTO_TEST_CASE(TestFixedSeed) {
    SpriteBuilder sprite1("rogue.txt", 555);
    SpriteBuilder sprite2("rogue.txt", 555);

    Vector2u size1 = sprite1.windowSize();
    RenderWindow window1(sf::VideoMode({size1.x * 16, size1.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state1;
    state1.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window1.clear(sf::Color::Transparent);
    window1.draw(sprite1, state1);
    window1.display();

    Vector2u size2 = sprite2.windowSize();
    RenderWindow window2(sf::VideoMode({size2.x * 16, size2.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state2;
    state2.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window2.clear(sf::Color::Transparent);
    window2.draw(sprite2, state2);
    window2.display();

    BOOST_CHECK_EQUAL(sprite1, sprite2);
    window1.close();
    window2.close();

    SpriteBuilder sprite3("rogue.txt", 432);
    SpriteBuilder sprite4("rogue.txt", 456);

    Vector2u size3 = sprite3.windowSize();
    RenderWindow window3(sf::VideoMode({size3.x * 16, size3.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state3;
    state3.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window3.clear(sf::Color::Transparent);
    window3.draw(sprite3, state3);
    window3.display();

    Vector2u size4 = sprite4.windowSize();
    RenderWindow window4(sf::VideoMode({size4.x * 16, size4.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state4;
    state4.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window4.clear(sf::Color::Transparent);
    window4.draw(sprite4, state4);
    window4.display();

    BOOST_CHECK_NE(sprite3, sprite4);
    window3.close();
    window4.close();
}

BOOST_AUTO_TEST_CASE(TestRandomSeed) {
    SpriteBuilder sprite1("rogue.txt");
    SpriteBuilder sprite2("rogue.txt");

    Vector2u size1 = sprite1.windowSize();
    RenderWindow window1(sf::VideoMode({size1.x * 16, size1.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state1;
    state1.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window1.clear(sf::Color::Transparent);
    window1.draw(sprite1, state1);
    window1.display();

    Vector2u size2 = sprite2.windowSize();
    RenderWindow window2(sf::VideoMode({size2.x * 16, size2.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state2;
    state2.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window2.clear(sf::Color::Transparent);
    window2.draw(sprite2, state2);
    window2.display();

    BOOST_CHECK_NE(sprite1, sprite2);
    window1.close();
    window2.close();
}

BOOST_AUTO_TEST_CASE(TestNoReroll) {
    SpriteBuilder sprite1("rogue.txt");
    SpriteBuilder sprite2("rogue.txt");
    
    sprite1.randomize();

    Vector2u size1 = sprite1.windowSize();
    RenderWindow window1(sf::VideoMode({size1.x * 16, size1.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state1;
    state1.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window1.clear(sf::Color::Transparent);
    window1.draw(sprite1, state1);
    window1.display();

    Vector2u size2 = sprite2.windowSize();
    RenderWindow window2(sf::VideoMode({size2.x * 16, size2.y * 16}),
        "SpriteBuilder Tests");
    RenderStates state2;
    state2.transform.scale(
        {static_cast<float>(16),
         static_cast<float>(16)});
    window2.clear(sf::Color::Transparent);
    window2.draw(sprite2, state2);
    window2.display();

    BOOST_CHECK_NE(sprite1, sprite2);
    window1.close();
    window2.close();

    sprite2.randomize();

    window1.clear(sf::Color::Transparent);
    window1.draw(sprite1, state1);
    window1.display();

    window2.clear(sf::Color::Transparent);
    window2.draw(sprite2, state2);
    window2.display();

    BOOST_CHECK_NE(sprite2, sprite1);
    window1.close();
    window2.close();
}
