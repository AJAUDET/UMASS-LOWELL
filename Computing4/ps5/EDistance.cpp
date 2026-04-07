// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// EDistance.cpp

#include <climits>
#include "EDistance.hpp"

EDistance::EDistance(const std::string& s1, const std::string& s2)
    : DNAStrand1_(s1), DNAStrand2_(s2), m_(s1.length()), n_(s2.length()) {
}

int EDistance::penalty(char a, char b) { return (a == b) ? 0 : 1; }

int EDistance::min3(int a, int b, int c) { return std::min({a, b, c}); }

int EDistance::optDistance() {
    opt_.assign(m_ + 1, std::vector<int>(n_ + 1, 0));
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

std::string EDistance::alignmentDP() {
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

std::vector<int> EDistance::computeForward(const std::string& a, int aStart, int aEnd,
                                           const std::string& b, int bStart, int bEnd) {
    int n = bEnd - bStart;
    std::vector<int> prev(n + 1), curr(n + 1);

    for (int j = 0; j <= n; ++j) prev[j] = 2 * j;

    for (int i = aStart; i < aEnd; ++i) {
        curr[0] = 2 * (i - aStart + 1);
        for (int j = 1; j <= n; ++j) {
            int match = prev[j - 1] + penalty(a[i], b[bStart + j - 1]);
            int del = prev[j] + 2;
            int ins = curr[j - 1] + 2;
            curr[j] = min3(match, del, ins);
        }
        std::swap(prev, curr);
    }

    return prev;
}

std::vector<int> EDistance::computeBackward(const std::string& a, int aStart, int aEnd,
                                            const std::string& b, int bStart, int bEnd) {
    int n = bEnd - bStart;
    std::vector<int> prev(n + 1), curr(n + 1);

    for (int j = 0; j <= n; ++j) prev[j] = 2 * (n - j);

    for (int i = aEnd - 1; i >= aStart; --i) {
        curr[n] = 2 * (aEnd - i);
        for (int j = n - 1; j >= 0; --j) {
            int match = prev[j + 1] + penalty(a[i], b[bStart + j]);
            int del = prev[j] + 2;
            int ins = curr[j + 1] + 2;
            curr[j] = min3(match, del, ins);
        }
        std::swap(prev, curr);
    }

    return prev;
}

void EDistance::hirschberg(const std::string& a, int aStart, int aEnd, const std::string& b,
                           int bStart, int bEnd, std::stringstream& out) {
    int m = aEnd - aStart;
    int n = bEnd - bStart;

    if (m == 0) {
        for (int j = bStart; j < bEnd; ++j) out << "- " << b[j] << " 2\n";
        return;
    }

    if (n == 0) {
        for (int i = aStart; i < aEnd; ++i) out << a[i] << " - 2\n";
        return;
    }

    if (m <= 10 || n <= 10) {
        std::string aSub = a.substr(aStart, m);
        std::string bSub = b.substr(bStart, n);
        EDistance small(aSub, bSub);
        small.optDistance();
        out << small.alignmentDP();
        return;
    }

    int mid = aStart + m / 2;

    std::vector<int> L = computeForward(a, aStart, mid, b, bStart, bEnd);
    std::vector<int> R = computeBackward(a, mid, aEnd, b, bStart, bEnd);

    int k = 0;
    int best = INT_MAX;
    for (int j = 0; j <= n; ++j) {
        int sum = L[j] + R[j];
        if (sum < best) {
            best = sum;
            k = j;
        }
    }

    hirschberg(a, aStart, mid, b, bStart, bStart + k, out);
    hirschberg(a, mid, aEnd, b, bStart + k, bEnd, out);
}

std::string EDistance::alignment() {
    std::stringstream out;
    hirschberg(DNAStrand1_, 0, m_, DNAStrand2_, 0, n_, out);
    return out.str();
}
