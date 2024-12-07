#include <print>

#include "aoc24_1.h"

int main() {
  std::filesystem::path inputfile = "./input";
  if (!std::filesystem::exists(inputfile)) {
    std::println("Expecting file ./input next to binary.");
    const int objectivelyBestErrorCode = 193;
    return objectivelyBestErrorCode;
  }

  auto inputLists = readPairsFromFile(inputfile);
  auto preparedLists = prepareListOfPairs(inputLists);
  auto distances = calculateDistances(preparedLists);
  auto totalDistance = calculateTotalDistance(distances);

  std::println("Total distance = {}", totalDistance);

  auto similarity = calculateSimilarityScore(inputLists);

  std::println("Similarity score = {}", similarity);

  return 0;
}
