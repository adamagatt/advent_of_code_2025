#ifndef __SOLUTION_1_H
#define __SOLUTION_1_H

#include <string>

constexpr int DIAL_INIT_VALUE = 50;

auto command_to_numeric(const std::string& command) -> int;

auto dial_add(int lhs, int rhs) -> int;

auto is_zero(int value) -> bool;

auto zero_crossings(int lhs, int rhs) -> int;

#endif