#ifndef __SOLUTION_4_H
#define __SOLUTION_4_H

#include "../utils/read.h"

#include <array>

constexpr int ROWS = 136;
constexpr int COLS = 136;

constexpr std::array<std::pair<int, int>, 8> adjacent_offsets = {{
    { -1, -1 },
    { -1, 0 },
    { -1, 1 },
    { 0, -1 },
    { 0, 1 },
    { 1, -1 },
    { 1, 0 },
    { 1, 1 }
}};

auto count_removable(Utils::Grid<ROWS, COLS>& grid, int r, int c) -> int;

#endif