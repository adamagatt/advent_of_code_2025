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
        int range_start_digits = count_digits(range.first);
        int range_end_digits = count_digits(range.second);

        for (int num_digits = range_start_digits; num_digits <= range_end_digits; ++num_digits) {
            for (auto repetitions : potential_repetitions.at(num_digits)) {
                int subsequence_length = num_digits / repetitions;

                long long check_num_start = calc_pow10(subsequence_length-1);
                long long check_num_end = calc_pow10(subsequence_length);

                for (long long check_num = check_num_start; check_num < check_num_end; ++check_num) {
                    long long repeated_num = repeat(check_num, repetitions);
                    if (within_range(repeated_num, range.first, range.second)) {
                        answerB += repeated_num;
                        if (repetitions == 2) {
                            answerA += repeated_num;
                        }
                    }
                }
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

auto count_digits(long long number) -> int {
    int digits = 1;
    while (number >= 10) {
        digits++;
        number /= 10;
    }
    return digits;
}

auto calc_pow10(int exp) -> long long {
    long long result = 1;
    for(int i = 0; i < exp; ++i) {
        result *= 10;
    }
    return result;
}

auto repeat(long long number, int repeat_count) -> long long {
    long long result = number;
    
    int number_length = count_digits(number);
    long long multiplicand = calc_pow10(number_length);
    for (int i = 1; i < repeat_count; ++i) {
        result = result * multiplicand + number;
    }

    return result;
}

auto within_range(long long number, long long lower_bound, long long upper_bound) -> bool {
    return number >= lower_bound && number <= upper_bound;
}