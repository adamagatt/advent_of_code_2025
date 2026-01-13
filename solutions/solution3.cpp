#include "solutions.h"
#include "solution3.h"

#include "../utils/read.h"

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
    auto search_from_index = battery.begin();

    std::string selected_digits(digits, '0');
    for (int digit = 0; digit < digits; ++digit) {
        auto last_allowed_position_for_digit = battery.end() - digits + digit + 1;
        search_from_index = std::max_element(search_from_index, last_allowed_position_for_digit);
        selected_digits[digit] = *search_from_index;
        search_from_index++;
    }

    return std::stoll(selected_digits);
}