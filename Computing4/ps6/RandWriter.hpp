// Copyright 2026 AJ Audet
// RandWriter.hpp

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <ostream>
#include <random>
#include <stdexcept>

class RandWriter {
 public:
  // Create a Markov model of order k from given text
  // Assume that text has length at least k.
  RandWriter(const std::string& str, size_t k);

  size_t orderK() const;  // Order k of Markov model

  // Number of occurences of kgram in text
  // Throw an exception if kgram is not length k
  int freq(const std::string& kgram) const;

  // Number of times that character c follows kgram
  // if order=0, return num of times that char c appears
  // (throw an exception if kgram is not of length k)
  int freq(const std::string& kgram, char c) const;

  // Random character following given kgram
  // (throw an exception if kgram is not of length k)
  // (throw an exception if no such kgram)
  char kRand(const std::string& kgram);

  // Generate a string of length L characters by simulating a trajectory
  // through the corresponding Markov chain. The first k characters of
  // the newly generated string should be the argument kgram.
  // Throw an exception if kgram is not of length k.
  // Assume that L is at least k
  std::string generate(const std::string& kgram, size_t l);

  friend std::ostream& operator<<(std::ostream& os, const RandWriter& a);

 private:
  size_t k_;
  std::string text_;
  std::minstd_rand0 rng_;
  std::map<std::string, std::map<char, int>> kgram_;
  std::set<char> char_set;

  /**
   * validateKgram: helper function that takes in a kgram and validates if the length of the kgram is not equal to the order of the model
   * @param kgram: kgram we are using as the base for the Markov Model
   */
  void validateKgram(const std::string& kgram) const;
};
