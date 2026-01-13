#include "solutions.h"
#include "solution3.h"

#include "../utils/read.h"

#include <algorithm>

auto Solutions::solution3() -> Answers {

    auto batteries = Utils::readLines("inputs/input3.txt");

    long long answerA = 0;
    long long answerB = 0;

    for (const auto& battery : batteries) {
        answerA += max_joltage_with_n_digits(battery, 2);
        answerB += max_joltage_with_n_digits(battery, 12);
    }

    return {std::to_string(answerA), std::to_string(answerB)};
}

auto max_joltage_with_n_digits(const std::string& battery, int digits) -> long long {
    auto search_from_index = battery.begin() - 1;

    std::string selected_digits(digits, '0');
    for (int digit = 0; digit < digits; ++digit) {
        search_from_index = std::max_element(search_from_index+1, battery.end()-digits+digit+1);
        selected_digits[digit] = *search_from_index;
    }

    return std::stoll(selected_digits);
}