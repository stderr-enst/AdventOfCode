#include "aoc24_1.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <filesystem>

#include "doctest/doctest.h"

TEST_CASE("Read input file") {
  std::filesystem::path inputfile = "./input";
  REQUIRE(std::filesystem::exists(inputfile));

  auto inputLists = readPairsFromFile(inputfile);
  CHECK(std::get<0>(inputLists).size() == 6);
  CHECK(std::get<1>(inputLists).size() == 6);

  std::vector<int> left = {3, 4, 2, 1, 3, 3};
  std::vector<int> right = {
      4, 3, 5, 3, 9, 3};  // NOLINT(cppcoreguidelines-avoid-magic-numbers)

  for (unsigned int i = 0; i < left.size(); i++) {
    CHECK(std::get<0>(inputLists).at(i) == left.at(i));
    CHECK(std::get<1>(inputLists).at(i) == right.at(i));
  }
}
