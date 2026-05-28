#ifndef __SOLUTION_5_H
#define __SOLUTION_5_H

#include <string>
#include <utility>
#include <vector>

using FreshRange = std::pair<long long, long long>;

using FreshRanges = std::vector<FreshRange>;

auto parseInput(const std::vector<std::string>& lines) -> std::pair<FreshRanges, std::vector<long long>>;

auto withinRange(const FreshRange& range, long long value) -> bool;

auto isFresh(const FreshRanges& ranges, long long value) -> bool;

auto rangeLength(const FreshRange& range) -> long long;

auto rangesOverlapOrAdjacent(const FreshRange& range1, const FreshRange& range2) -> bool;

auto anyOverlapsOrAdjacent(const FreshRanges& ranges) -> bool;

auto combineRanges(const FreshRange& range1, const FreshRange& range2) -> FreshRange;

auto combineOverlappingOrAdjacentRanges(FreshRanges& freshRanges) -> void;

#endif