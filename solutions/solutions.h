#ifndef __SOLUTIONS_H
#define __SOLUTIONS_H

#include <functional>
#include <string>
#include <utility>

namespace Solutions {
    using Answers = std::pair<std::string, std::string>;
    using Solution = Solutions::Answers(*)();

    auto solution1() -> Answers;
    auto solution2() -> Answers;
    auto solution3() -> Answers;
    auto solution4() -> Answers;

    auto selectSolution() -> Solution;
}

#endif