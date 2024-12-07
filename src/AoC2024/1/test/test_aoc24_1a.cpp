#include "aoc24_1.h"
#include "doctest/doctest.h"

TEST_CASE("Prepare list of pairs - empty list") {
  std::vector<int> left = {};
  std::vector<int> right = {};

  auto inputLists = std::make_pair(left, right);
  auto preparedList = prepareListOfPairs(inputLists);

  CHECK(preparedList.size() == 0);
}

TEST_CASE("Prepare list of pairs - unequal list") {
  std::vector<int> left = {};
  std::vector<int> right = {1};

  auto inputLists = std::make_pair(left, right);
  auto preparedList = prepareListOfPairs(inputLists);

  CHECK(preparedList.size() == 0);
}

TEST_CASE("Prepare list of pairs - sorting") {
  std::vector<int> left = {3, 4, 2, 1, 3, 3};
  std::vector<int> right = {
      4, 3, 5, 3, 9, 3};  // NOLINT(cppcoreguidelines-avoid-magic-numbers)

  pairListType expectedList = {
      std::make_pair(1, 3), std::make_pair(2, 3), std::make_pair(3, 3),
      std::make_pair(3, 4), std::make_pair(3, 5),  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
      std::make_pair(4, 9)  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
  };

  auto inputLists = std::make_pair(left, right);
  auto preparedList = prepareListOfPairs(inputLists);

  for (unsigned int i = 0; i < expectedList.size(); i++)
    CHECK(expectedList.at(i) == preparedList.at(i));
}

TEST_CASE("Calculate distances - 0 case") {
  pairListType expectedList = {};

  auto distances = calculateDistances(expectedList);
  CHECK(distances.size() == 0);
}

TEST_CASE("Calculate distances - 1 case") {
  pairListType expectedList = {
      std::make_pair(1, 3),
  };

  auto distances = calculateDistances(expectedList);
  CHECK(distances.at(0) == 2);
}

TEST_CASE("Total distance") {
  const std::vector<int> distances = {
      2, 1, 0, 1, 2, 5};  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
  auto totaldist = calculateTotalDistance(distances);
  CHECK(totaldist == 11);  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
}

TEST_CASE("Calculate similarity score") {
  std::vector<int> left = {3, 4, 2, 1, 3, 3};
  std::vector<int> right = {
      4, 3, 5, 3, 9, 3};  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
  auto inputList = std::make_pair(left, right);

  auto similarity = calculateSimilarityScore(inputList);

  CHECK(similarity == 31);
}