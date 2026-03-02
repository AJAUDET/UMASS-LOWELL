// Copyright (c) 2026 AJ Audet

#include <sstream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SokobanTests
#include <boost/test/unit_test.hpp>

#include "Sokoban.hpp"

using SB::Direction;
using SB::Sokoban;

using sf::Color;
using sf::Event;
using sf::FloatRect;
using sf::RenderWindow;
using sf::Vector2u;
using sf::VideoMode;
using sf::Keyboard::Key;

using std::cerr;
using std::cout;
using std::exception;
using std::optional;
using std::string;
using std::stringstream;

static Sokoban makeGame(const string& lvlString) {
  stringstream ss(lvlString);
  Sokoban s;
  ss >> s;
  return s;
}

BOOST_AUTO_TEST_CASE(testMovement) {
  Sokoban s = makeGame(
      "5 5\n"
      "#####\n"
      "#...#\n"
      "#.@.#\n"
      "#...#\n"
      "#####");
  Vector2u start = s.playerLoc();
  s.movePlayer(Direction::Up);
  BOOST_CHECK_EQUAL(s.playerLoc().x, start.x);
  BOOST_CHECK_EQUAL(s.playerLoc().y, start.y);
}

BOOST_AUTO_TEST_CASE(testBox) {
  Sokoban s = makeGame(
      "5 5\n"
      "#####\n"
      "#...#\n"
      "#.@A#\n"
      "#...#\n"
      "#####");
  Vector2u start = s.playerLoc();
  s.movePlayer(Direction::Right);
  BOOST_CHECK_EQUAL(s.playerLoc().x, start.x);
  BOOST_CHECK_EQUAL(s.playerLoc().y, start.y);

  Sokoban s2 = makeGame(
      "5 5\n"
      "#####\n"
      "#..@#\n"
      "#..A#\n"
      "#...#\n"
      "#####");
  start = s2.playerLoc();
  s2.movePlayer(Direction::Down);
  BOOST_CHECK_EQUAL(s2.playerLoc().x, start.x);
  BOOST_CHECK_EQUAL(s2.playerLoc().y, start.y);
}

BOOST_AUTO_TEST_CASE(testOnOffScreen) {
  Sokoban s = makeGame(
      "2 2\n"
      "@.\n"
      "..\n");
  Vector2u start = s.playerLoc();
  s.movePlayer(Direction::Up);
  BOOST_CHECK_EQUAL(s.playerLoc().x, start.x);
  BOOST_CHECK_EQUAL(s.playerLoc().y, start.y);

  s.movePlayer(Direction::Left);
  BOOST_CHECK_EQUAL(s.playerLoc().x, start.x);
  BOOST_CHECK_EQUAL(s.playerLoc().y, start.y);
}

BOOST_AUTO_TEST_CASE(testLotsOfBoxes) {
  Sokoban s = makeGame(
      "3 5\n"
      "#####\n"
      "#@AA#\n"
      "#####\n");
  Vector2u start = s.playerLoc();
  BOOST_CHECK_EQUAL(s.playerLoc().x, start.x);
  BOOST_CHECK_EQUAL(s.playerLoc().y, start.y);
}

BOOST_AUTO_TEST_CASE(testLotsOfGoals) {
  Sokoban s = makeGame(
      "3 5\n"
      "#####\n"
      "#@aa#\n"
      "#####\n");
  BOOST_CHECK(s.isWon());
}

BOOST_AUTO_TEST_CASE(testMissingSymbol) {
  stringstream ss(
      "2 2\n"
      "..\n"
      "..\n");
  Sokoban s;
  ss >> s;
  BOOST_CHECK_EQUAL(s.playerLoc().x, 0);
  BOOST_CHECK_EQUAL(s.playerLoc().y, 0);
}
