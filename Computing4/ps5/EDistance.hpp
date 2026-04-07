// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// EDistance.hpp
#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class EDistance {
 public:
   /**
    * Creates an EDistance object containing the data from two DNA strands
    * @param s1 A DNA strand that is stored as a string: e.g "AACTTGCC"
    * @param s2 A DNA strand that is stored as a string: e.g "AACTTGCC"
    */
    EDistance(const std::string& s1, const std::string& s2);

   /**
    * Identifies the penalty that comes when comparing / aligning two characters
    * @param a First character to compare
    * @param b Second character to compare
    * @return penalty cost (1 or 0)
    */
    static int penalty(char a, char b);

   /**
    * Returns the minimum value of 3 given integers
    * @return Minimum of a, b, and c
    */
    static int min3(int a, int b, int c);

    /**
    * Compute optimal distance between the two strings
    * @return optimal distance between two strings stored at opt_[0][0]
    */
    int optDistance();

   /**
    * Formats the desired string in the optimal allignment given by opt_
    * @return alligned DNA string
    */
    std::string alignmentDP();
    std::string alignment();
    void hirschberg(const std::string& a, int aStart, int aEnd, const std::string& b, int bStart,
                int bEnd, std::stringstream& out);
    std::vector<int> computeForward(const std::string& a, int aStart, int aEnd, const std::string& b,
                                int bStart, int bEnd);
    std::vector<int> computeBackward(const std::string& a, int aStart, int aEnd, const std::string& b,
                                 int bStart, int bEnd);

 private:
    std::string DNAStrand1_;
    std::string DNAStrand2_;
    int m_;
    int n_;
    std::vector<std::vector<int>> opt_;
};
