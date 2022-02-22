#pragma once

#include "class/game_board.hpp"
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include <random>


int	negamax(game_board &board, int lower_bound, int upper_bound, int depth);
int random_number(int lower_bound, int upper_bound);
