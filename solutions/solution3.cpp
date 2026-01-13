#include "solutions.h"

#include "../utils/read.h"

auto Solutions::solution3() -> Answers {

    auto batteries = Utils::readLines("inputs/input3.txt");

    int answerA = 0;
    int answerB = 0;


    for (const auto& battery : batteries) {
        auto first_digit_index = std::max_element(battery.begin(), battery.end()-1);
        auto second_digit_index = std::max_element(first_digit_index+1, battery.end());

        int joltage = Utils::parseIntChar(*first_digit_index) * 10 + Utils::parseIntChar(*second_digit_index);
        answerA += joltage;
    }

    return {std::to_string(answerA), std::to_string(answerB)};
}