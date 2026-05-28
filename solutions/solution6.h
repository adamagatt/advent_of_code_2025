#ifndef __SOLUTION_6_H
#define __SOLUTION_6_H

constexpr int NUM_PROBLEMS = 1000;
constexpr int NUM_OPERANDS = 4;
constexpr int OPERATOR_LINE_IDX = 4;

auto tokenize(const std::vector<std::string>& input) -> std::vector<std::array<std::string, NUM_PROBLEMS>>;

#endif