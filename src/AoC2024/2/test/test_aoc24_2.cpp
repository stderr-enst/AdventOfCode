#include "aoc24_2.h"
#include "doctest/doctest.h"

TEST_CASE("Check row - Day 2") {
    const inputListType expectedList = {
        {7, 6, 4, 2, 1}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {1, 2, 7, 8, 9}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {9, 7, 6, 2, 1}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {1, 3, 2, 4, 5}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {8, 6, 4, 4, 1}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {1, 3, 6, 7, 9}  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    };

    CHECK(checkRow(expectedList.at(0)));
    CHECK_FALSE(checkRow(expectedList.at(1)));
    CHECK_FALSE(checkRow(expectedList.at(2)));
    CHECK_FALSE(checkRow(expectedList.at(3)));
    CHECK_FALSE(checkRow(expectedList.at(4)));
    CHECK(checkRow(expectedList.at(5)));
}

TEST_CASE("Check row with dampener- Day 2") {
    const inputListType expectedList = {
        {7, 6, 4, 2, 1}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {1, 2, 7, 8, 9}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {9, 7, 6, 2, 1}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {1, 3, 2, 4, 5}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {8, 6, 4, 4, 1}, // NOLINT(cppcoreguidelines-avoid-magic-numbers)
        {1, 3, 6, 7, 9}  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    };

    CHECK(checkRowWithDampener(expectedList.at(0)));
    CHECK_FALSE(checkRowWithDampener(expectedList.at(1)));
    CHECK_FALSE(checkRowWithDampener(expectedList.at(2)));
    CHECK(checkRowWithDampener(expectedList.at(3)));
    CHECK(checkRowWithDampener(expectedList.at(4)));
    CHECK(checkRowWithDampener(expectedList.at(5)));
}