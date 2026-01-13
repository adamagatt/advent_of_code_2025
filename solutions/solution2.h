#ifndef __SOLUTION_2_H
#define __SOLUTION_2_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const std::unordered_map<int, std::unordered_set<int>> repetition_start_indices {
    {1, {}},
    {2, {1}},
    {3, {1}},
    {4, {1, 2}},
    {5, {1}},
    {6, {1, 2, 3}},
    {7, {1}},
    {8, {1, 2, 4}},
    {9, {1, 3}},
    {10, {1, 2, 5}}
};

auto parse_input(const std::string& text) -> std::vector<std::pair<long long, long long>>;

#endif