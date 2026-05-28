#include "solutions.h"
#include "solution6.h"

#include "../utils/read.h"

#include <functional>

auto Solutions::solution6() -> Answers {

    auto input = Utils::readLines("inputs/input6.txt");
    auto tokens = tokenize(input);

    long long answerA = 0;
    for (int problemIdx = 0; problemIdx < NUM_PROBLEMS; ++problemIdx) {
        auto op = tokens[NUM_OPERANDS][problemIdx] == "+"
            ? [](long long a, long long b) { return a + b; }
            : [](long long a, long long b) { return a * b; };
        
        long long value = std::stoll(tokens[0][problemIdx]);
        for (int operandIdx = 1; operandIdx < NUM_OPERANDS; ++operandIdx) {
            value = op(value, std::stoll(tokens[operandIdx][problemIdx]));
        }
        answerA += value;
    }

    std::array<size_t, NUM_PROBLEMS> operatorIndices;
    size_t operatorCount = 0;
    for (size_t i = 0; i < input[OPERATOR_LINE_IDX].size(); ++i) {
        if (input[OPERATOR_LINE_IDX][i] == '*' || input[OPERATOR_LINE_IDX][i] == '+') {
            operatorIndices[operatorCount++] = i;
        }
    }

    int answerB = -1;

    return {std::to_string(answerA), std::to_string(answerB)};
}

auto tokenize(const std::vector<std::string>& input) -> std::vector<std::array<std::string, NUM_PROBLEMS>> {
    std::vector<std::array<std::string, NUM_PROBLEMS>> output;

    for (const auto& line : input) {
        std::stringstream ss(line);
        std::array<std::string, NUM_PROBLEMS> tokens;
        for (int i = 0; i < NUM_PROBLEMS; ++i) {
            ss >> tokens[i];
        }
        output.push_back(tokens);
    }

    return output;
}