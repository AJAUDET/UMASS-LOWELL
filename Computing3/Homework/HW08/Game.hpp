#pragma once

#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;

bool checkForWin(int guess, int answer);
void play(Player &player1, Player &player2);