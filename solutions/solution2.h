#ifndef __SOLUTION_2_H
#define __SOLUTION_2_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const std::unordered_map<int, std::unordered_set<int>> potential_repetitions {
    {1, {}},
    {2, {2}},
    {3, {3}},
    {4, {2, 4}},
    {5, {5}},
    {6, {2, 3, 6}},
    {7, {7}},
    {8, {2, 4, 8}},
    {9, {3, 9}},
    {10, {2, 5, 10}}
};

auto parse_input(const std::string& text) -> std::vector<std::pair<long long, long long>>;

auto count_digits(long long number) -> int;

auto calc_pow10(int exp) -> long long;

auto repeat(long long number, int repeat_count) -> long long;

auto within_range(long long number, long long lower_bound, long long upper_bound) -> bool;

#endif