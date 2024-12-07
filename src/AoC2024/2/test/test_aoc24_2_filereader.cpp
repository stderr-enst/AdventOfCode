#include "aoc24_2.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

TEST_CASE("Read input file - Day 2") {
  inputListType expectedList = {
      {7, 6, 4, 2, 1},  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
      {1, 2, 7, 8, 9},  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
      {9, 7, 6, 2, 1},  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
      {1, 3, 2, 4, 5},  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
      {8, 6, 4, 4, 1},  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
      {1, 3, 6, 7, 9}   // NOLINT(cppcoreguidelines-avoid-magic-numbers)
  };

  std::filesystem::path inputfile = "./input";

  REQUIRE(std::filesystem::exists(inputfile));
  auto inputList = readFromFile(inputfile);
  CHECK(inputList.size() == expectedList.size());

  for (unsigned int i = 0; i < inputList.size(); i++) {
    const auto& lineRead = inputList.at(i);
    const auto& lineExpected = expectedList.at(i);
    REQUIRE(lineRead.size() == lineExpected.size());
    for (unsigned int j = 0; j < lineRead.size(); j++) {
      CHECK(lineRead.at(j) == lineExpected.at(j));
    }
  }
}
