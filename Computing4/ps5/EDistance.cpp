// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// EDistance.cpp
#include "EDistance.hpp"

EDistance::EDistance(const std::string& s1, const std::string& s2)
: DNAStrand1_(s1), DNAStrand2_(s2), m_(s1.length()), n_(s2.length()) {
  opt_.assign(m_ + 1, std::vector<int>(n_ + 1, 0));
}

int EDistance::penalty(char a, char b) { return (a == b) ? 0 : 1; }

int EDistance::min3(int a, int b, int c) { return std::min({a, b, c}); }

int EDistance::optDistance() {
  for (int j = n_; j >= 0; --j) {
    opt_[m_][j] = 2 * (n_ - j);
  }

  for (int i = m_; i >= 0; --i) {
    opt_[i][n_] = 2 * (m_ - i);
  }

  for (int i = m_ - 1; i >= 0; --i) {
    for (int j = n_ - 1; j >= 0; --j) {
      int cost = opt_[i + 1][j + 1] + penalty(DNAStrand1_[i], DNAStrand2_[j]);
      int gapInStrand2 = opt_[i + 1][j] + 2;
      int gapInStrand1 = opt_[i][j + 1] + 2;

      opt_[i][j] = min3(cost, gapInStrand2, gapInStrand1);
    }
  }
  return opt_[0][0];
}

std::string EDistance::alignment() {
  std::stringstream strand;
  int i = 0;
  int j = 0;

  while (i < m_ || j < n_) {
    if (i < m_ && j < n_) {
      if (opt_[i][j] ==
          opt_[i + 1][j + 1] + penalty(DNAStrand1_[i], DNAStrand2_[j])) {
        strand << DNAStrand1_[i] << " " << DNAStrand2_[j] << " "
               << penalty(DNAStrand1_[i], DNAStrand2_[j]) << "\n";
        ++i;
        ++j;
      } else if (opt_[i][j] == opt_[i + 1][j] + 2) {
        strand << DNAStrand1_[i] << " " << "-" << " " << "2" << "\n";
        ++i;
      } else {
        strand << "-" << " " << DNAStrand2_[j] << " " << "2" << "\n";
        ++j;
      }
    } else if (i < m_) {
      strand << DNAStrand1_[i] << " " << "-" << " " << "2" << "\n";
      ++i;
    } else {
      strand << "-" << " " << DNAStrand2_[j] << " " << "2" << "\n";
      ++j;
    }
  }

  return strand.str();
}
