#include "solutions.h"
#include "solution2.h"

#include "../utils/read.h"

#include <vector>
#include <ranges>

auto Solutions::solution2() -> Answers {
    auto ranges = parse_input(Utils::readAsSingleLine("inputs/input2.txt"));

    long long answerA = std::ranges::fold_left(
        ranges | std::views::transform([](const auto& range) { // For each range
            int half_fewest_digits = count_digits(range.first) / 2;
            int half_most_digits = count_digits(range.second) / 2;

            return std::views::iota(half_fewest_digits, half_most_digits+1) // For all potential numbers of digits in the range
                    | std::views::transform([&range](int num_digits) {
                        long long pow10 = calc_pow10(num_digits);
                        return std::views::iota(calc_pow10(num_digits-1), pow10) // For all numbers with that number of digits
                                | std::views::transform([pow10](long long check_num){return repeat(check_num, pow10);})
                                | std::views::filter([&range](long long check_num){return within_range(check_num, range.first, range.second);});
                    });
        })
        | std::views::join // Flatten lists of numbers within number of digits
        | std::views::join, // Flatten lists of numbers of digits
        0,
        std::plus<long long>{}
    );

    int answerB = 0;

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

auto repeat(long long number, int pow10) -> long long {
    return number * pow10 + number;
}

auto within_range(long long number, long long lower_bound, long long upper_bound) -> bool {
    return number >= lower_bound && number <= upper_bound;
}