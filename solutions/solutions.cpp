#include "solutions.h"

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <unordered_map>

const std::array<Solutions::Solution, 4> solutions {{
    Solutions::solution1,
    Solutions::solution2,
    Solutions::solution3,
    Solutions::solution4
}};

auto Solutions::selectSolution() -> Solution {
    int choice = 0;
    std::string toNewLine;
    while (choice < 1 || choice > static_cast<int>(solutions.size())) {
        std::cout << "Choose as solution (1-" << solutions.size() << "):" << std::endl;
        std::cin >> choice;
        std::cin.clear(); // Clear and ignore until newline in case of non-integral input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return solutions[choice - 1];
}