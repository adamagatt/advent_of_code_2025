#include "solutions.h"
#include "solution5.h"

#include <algorithm>
#include <numeric>
#include "../utils/read.h"

auto Solutions::solution5() -> Answers {

    auto [freshRanges, ingredients] = parseInput(Utils::readLines("inputs/input5.txt"));

    int answerA = std::ranges::count_if(ingredients, [&freshRanges](long long ingredient) {
        return isFresh(freshRanges, ingredient);
    });

    // Combine ranges that overlap to prevent double counting fresh indices
    while (anyOverlapsOrAdjacent(freshRanges)) {
        combineOverlappingOrAdjacentRanges(freshRanges);
    }
    std::printf("Done\n");

    long long answerB = std::transform_reduce(
        freshRanges.begin(), freshRanges.end(),
        0LL,
        std::plus<>(),
        rangeLength
    );
    for (const auto& freshRange : freshRanges) {
        printf("Length: %lld, Range: %lld-%lld\n", rangeLength(freshRange), freshRange.first, freshRange.second);
    }

    return {std::to_string(answerA), std::to_string(answerB)};
}

auto withinRange(const FreshRange& range, long long value) -> bool {
    return value >= range.first && value <= range.second; // Inclusive range check
}

auto isFresh(const FreshRanges& ranges, long long value) -> bool {
    return std::ranges::any_of(ranges, [&value](const FreshRange& range) {
        return withinRange(range, value);
    });
}

auto parseInput(const std::vector<std::string>& lines) -> std::pair<FreshRanges, std::vector<long long>> {
    FreshRanges freshRanges;
    freshRanges.reserve(186);

    std::vector<long long> ingredients;
    ingredients.reserve(1000);

    bool parseRanges = true;
    for (const auto& line : lines) {
        if (line.empty()) {  // Empty line indicates end of fresh ranges
            parseRanges = false;
            continue;
        } else if (parseRanges) { // Parse ranges for fresh ingredients
            auto delimiterPos = line.find('-');
            long long start = std::stoll(line.substr(0, delimiterPos));
            long long end = std::stoll(line.substr(delimiterPos + 1));
            freshRanges.emplace_back(start, end);
        } else { // Parse available ingredients
            ingredients.push_back(std::stoll(line));
        }
    }

    return {freshRanges, ingredients};
}

auto rangeLength(const FreshRange& range) -> long long {
    return range.second - range.first + 1; // Inclusive range length
}

auto rangesOverlapOrAdjacent(const FreshRange& range1, const FreshRange& range2) -> bool {
    return range1.first <= (range2.second + 1) && range2.first <= (range1.second + 1);
}

auto combineRanges(const FreshRange& range1, const FreshRange& range2) -> FreshRange {
    long long newStart = std::min(range1.first, range2.first);
    long long newEnd = std::max(range1.second, range2.second);
    return {newStart, newEnd};
}

auto anyOverlapsOrAdjacent(const FreshRanges& ranges) -> bool {
    // Check if any ranges overlap or are adjacent
    for (auto r1 = ranges.begin(); r1 != ranges.end(); ++r1) {
        for (auto r2 = std::next(r1); r2 != ranges.end(); ++r2) {
            if (rangesOverlapOrAdjacent(*r1, *r2)) {
                return true;
            }
        }
    }
    return false;
}

auto combineOverlappingOrAdjacentRanges(FreshRanges& freshRanges) -> void {
    for (auto rangeIdx = 0; rangeIdx < freshRanges.size(); ++rangeIdx) {
        for (auto otherRangeIdx = rangeIdx+1; otherRangeIdx < freshRanges.size(); ++otherRangeIdx) {
            if (rangesOverlapOrAdjacent(freshRanges[rangeIdx], freshRanges[otherRangeIdx])) {
                freshRanges[rangeIdx] = combineRanges(freshRanges[rangeIdx], freshRanges[otherRangeIdx]);

                // Remove other range from the list and adjust next index to check
                freshRanges.erase(freshRanges.begin()+otherRangeIdx);
                --otherRangeIdx;
            }
        }
    }
}