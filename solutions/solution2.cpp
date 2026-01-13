#include "solutions.h"
#include "solution2.h"

#include "../utils/read.h"

#include <vector>
#include <ranges>

auto Solutions::solution2() -> Answers {
    auto ranges = parse_input(Utils::readAsSingleLine("inputs/input2.txt"));

    long long answerA = 0;
    long long answerB = 0;
    
    for (const auto& range : ranges) {

        for (long long check_num = range.first; check_num <= range.second; ++check_num) {
            std::string num_as_chars =  std::to_string(check_num);
            int num_digits = num_as_chars.size();

            bool any_repetitions = false;
            for (auto repetition_start_index : repetition_start_indices.at(num_digits)) {
                if (num_as_chars.starts_with(num_as_chars.substr(repetition_start_index))) {
                    any_repetitions = true;
                    if (repetition_start_index * 2 == num_digits) {
                        answerA += check_num;
                    }
                    break;
                }
            }
            if (any_repetitions) {
                answerB += check_num;
            }
        }
    }

    return {std::to_string(answerA), std::to_string(answerB)};
}

auto parse_input(const std::string& text) -> std::vector<std::pair<long long, long long>> {
    std::vector<std::pair<long long, long long>> ranges{};

    std::stringstream ss{text};

    long long range_start{}, range_end{};
    char _hyphen, _comma;

    while (true) {
        ss >> range_start >> _hyphen >> range_end;
        ranges.emplace_back(range_start, range_end);
        if (ss.peek() != ',') break;
        ss >> _comma;
    }
    
    return ranges;
}