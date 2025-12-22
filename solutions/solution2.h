#ifndef __SOLUTION_2_H
#define __SOLUTION_2_H

#include <string>
#include <utility>
#include <vector>

auto parse_input(const std::string& text) -> std::vector<std::pair<long long, long long>>;

auto count_digits(long long number) -> int;

auto calc_pow10(int exp) -> long long;

auto repeat(long long number, int pow10) -> long long;


auto within_range(long long number, long long lower_bound, long long upper_bound) -> bool;

#endif