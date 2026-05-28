#include "solutions.h"
#include "solution4.h"

auto Solutions::solution4() -> Answers {

    auto grid = Utils::readGrid<ROWS, COLS>("inputs/input4.txt");

    int answerA = 0;
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (grid[r][c] == '@' && count_removable(grid, r, c) < 4) {
                ++answerA;
            }
        }
    }

    int answerB = 0;
    // Loop endlessly as we will break out when no more can be removed
    while (true) {
        int removed = 0;
        // Count removable in the current step and mark them for removal
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == '@' && count_removable(grid, r, c) < 4) {
                    grid[r][c] = 'X';
                    ++removed;
                }
            }
        }

        // Clean-up pass for rolls marked for removal
        for (auto& row : grid) {
            std::ranges::transform(row, row.begin(), [](char c){ return c == 'X' ? '.' : c;});
        }

        // If no more can be removed then there are no more passes to make
        if (removed == 0) {
            break;
        }
        answerB += removed;
    }

    return {std::to_string(answerA), std::to_string(answerB)};
}

auto count_removable(Utils::Grid<ROWS, COLS>& grid, int r, int c) -> int {
    int count = 0;

    for (const auto& [dr, dc] : adjacent_offsets) {
        int check_row = r + dr;
        int check_col = c + dc;
        if (check_row >= 0 && check_row < ROWS && check_col >= 0 && check_col < COLS) {
            char symbol = grid[check_row][check_col];
            if (symbol == '@' || symbol == 'X') { // 'X' are marked for removal but not yet removed in this step
                ++count;
            }
        }
    }

    return count;
}