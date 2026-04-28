// Copyright 2026 AJ Audet
// RandWriter.hpp

#include <chrono>
#include <iostream>
#include <sstream>
#include "RandWriter.hpp"

RandWriter::RandWriter(const std::string& str, size_t k)
: k_(k), text_(str), rng_(std::chrono::system_clock::now().time_since_epoch().count()) {
  if (str.empty()) {
    throw std::invalid_argument("Text cannot be empty");
  }

  if (str.size() < k) {
    throw std::invalid_argument("Text must have length of at least k");
  }

  for (const auto& c : str) {
    char_set.insert(c);
  }

  size_t size = str.size();
  for (size_t i = 0; i < size; i++) {
    std::string kgram;
    for (size_t j = 0; j < k; j++) {
      kgram += str[(i + j) % size];
    }
    char next = str[(i + k) % size];
    kgram_[kgram][next]++;
  }
}

void RandWriter::validateKgram(const std::string& kgram) const {
  if (kgram.size() != k_) {
    throw std::invalid_argument("Length does not match");
  }
}

size_t RandWriter::orderK() const { return k_; }

int RandWriter::freq(const std::string& kgram) const {
  validateKgram(kgram);
  if (kgram_.find(kgram) == kgram_.end()) {
    return 0;
  }

  int total = 0;
  for (const auto& p : kgram_.at(kgram)) {
    total += p.second;
  }

  return total;
}

int RandWriter::freq(const std::string& kgram, char c) const {
  validateKgram(kgram);
  if (kgram_.find(kgram) == kgram_.end()) {
    return 0;
  }

  const auto& char_map = kgram_.at(kgram);
  if (char_map.find(c) == char_map.end()) {
    return 0;
  }

  return char_map.at(c);
}

char RandWriter::kRand(const std::string& kgram) {
  validateKgram(kgram);
  if (kgram_.find(kgram) == kgram_.end()) {
    throw std::invalid_argument("KGram not found");
  }

  const auto& char_freq = kgram_.at(kgram);
  std::vector<std::pair<char, int>> frequency;
  int cmul = 0;
  for (const auto& p : char_freq) {
    cmul += p.second;
    frequency.push_back({p.first, cmul});
  }

  std::uniform_int_distribution dist(0, cmul - 1);
  int rand_val = dist(rng_);

  for (const auto& p : frequency) {
    if (rand_val < p.second) {
      return p.first;
    }
  }

  return frequency.back().first;
}

std::string RandWriter::generate(const std::string& kgram, size_t l) {
  validateKgram(kgram);
  if (kgram_.find(kgram) == kgram_.end()) {
    throw std::invalid_argument("Starting kgram not found");
  }

  if (l < k_) {
    throw std::invalid_argument("Generated length must be at least k");
  }

  std::string result = kgram;
  std::string curr_kg = kgram;

  for (size_t i = k_; i < l; i++) {
    char next = kRand(curr_kg);
    result += next;

    if (k_ > 0) {
      curr_kg = curr_kg.substr(1) + next;
    }
  }

  return result;
}

std::ostream& operator<<(std::ostream& os, const RandWriter& a) {
  os << "Order: " << a.k_ << std::endl;
  os << "Alphabet: ";
  for (char c : a.char_set) {
    if (c == ' ') {
      os << "[space]";
    } else if (c == '\n') {
      os << "[newline]";
    } else {
      os << c;
    }
  }
  os << std::endl;

  os << "KGram freqencies:" << std::endl;
  for (const auto& p : a.kgram_) {
    os << " \"" << p.first << "\" ->";
    for (const auto& c : p.second) {
      os << "[" << c.first << ":" << c.second << "] ";
    }
    os << std::endl;
  }

  return os;
}
