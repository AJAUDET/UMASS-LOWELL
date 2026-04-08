// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// main.cpp

#include <iostream>
#include <SFML/System.hpp>
#include "EDistance.hpp"

/**
 * Helper function to clean a string by removing trailing whitespace and line
 * endings.
 * @param str Reference to the string to clean
 */
void cleanString(std::string& str) {
  while (!str.empty() &&
         (str.back() == '\r' || str.back() == '\n' || str.back() == ' ')) {
    str.pop_back();
  }
}

int main() {
  std::string s1, s2;

  if (!std::getline(std::cin, s1)) {
    std::cerr << "Error: Could not read first DNA sequence from stdin"
              << std::endl;
    return 1;
  }

  if (!std::getline(std::cin, s2)) {
    std::cerr << "Error: Could not read second DNA sequence from stdin"
              << std::endl;
    return 1;
  }

  cleanString(s1);
  cleanString(s2);

  sf::Clock clock;

  try {
    EDistance ed(s1, s2);

    std::string alignment = ed.alignmentDP();
    int distance = ed.optDistance();


//  Uncomment the below statement to implement Hirschberg's algorithm.
//  Comment out line 44
    // std::string alignment = ed.alignment();
    // int distance = 0;
    // std::istringstream ss(alignment);
    // std::string line;

    // while (std::getline(ss, line)) {
    //   std::stringstream ls(line);
    //   char a, b;
    //   int cost;

    //   ls >> a >> b >> cost;
    //   distance += cost;
    // }

    sf::Time elapsed_time = clock.getElapsedTime();

    std::cout << alignment;

    std::cout << "Edit distance = " << distance << std::endl;

    std::cout << "Execution time is " << elapsed_time.asSeconds() << " seconds"
              << std::endl;

    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}
