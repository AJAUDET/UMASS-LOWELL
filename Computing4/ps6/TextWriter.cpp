// Copyright 2026 AJ Audet
// TextWriter.hpp

#include <iostream>
#include <string>
#include <sstream>
#include "RandWriter.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::string;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << "k L" << endl;
    cerr << "k: order of Markov Model" << endl;
    cerr << "L: length of generated text" << endl;
    return 1;
  }

  size_t k = std::stoul(argv[1]);
  size_t L = std::stoul(argv[2]);

  string text, line;
  while (std::getline(cin, line)) {
    text += line + "\n";
  }

  if (!text.empty() && text.back() == '\n') {
    text.pop_back();
  }

  try {
    RandWriter a(text, k);
    string seed = text.substr(0, k);
    string kgram = a.generate(seed, L);

    cout << kgram << endl;

    return 0;
  } catch (const exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
  }
}
