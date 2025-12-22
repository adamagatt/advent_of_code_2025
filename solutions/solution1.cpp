#include "solutions.h"
#include "solution1.h"

#include "../utils/read.h"

#include <algorithm>
#include <functional>
#include <numeric>
#include <ranges>

auto Solutions::solution1() -> Answers {

    auto turns = Utils::readLines("inputs/input1.txt")
                          | std::views::transform(command_to_numeric)
                          | std::ranges::to<std::vector>();

    auto running_sum = std::vector<int>(turns.size());
    std::inclusive_scan(turns.begin(), turns.end(), running_sum.begin(), dial_add, DIAL_INIT_VALUE);

    int answerA = std::ranges::count_if(running_sum, is_zero);

    
    // First turn is already present in first running_sum value so when we need to compare the nth element
    // in the running sum to the (n+1)th element in the turns
    auto total_zero_crossings = std::views::zip_transform(zero_crossings, running_sum, turns | std::views::drop(1));
        
    int answerB = std::ranges::fold_left(total_zero_crossings, 0, std::plus{});

    return {std::to_string(answerA), std::to_string(answerB)};
}

auto command_to_numeric(const std::string& command) -> int {
    return command.starts_with('R')
        ?  std::stoi(command.substr(1))
        : -std::stoi(command.substr(1));
}

auto dial_add(int lhs, int rhs) -> int {
    int result = (lhs + rhs) % 100;
    return (result < 0)
        ? result + 100
        : result;
}

auto is_zero(int value) -> bool {
    return value == 0;
}

auto zero_crossings(int lhs, int rhs) -> int {
    // Special case most required for when the dial starts at 0 and
    // is turned left. In the main logic below this will register an
    // extra erroneous crossing from its starting point.
    if (lhs == 0) {
        return std::abs(rhs) / 100;
    }

    return (rhs > 0)
        ? (lhs + rhs) / 100
        : (100-lhs-rhs) / 100;
}