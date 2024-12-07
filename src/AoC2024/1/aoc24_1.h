#ifndef AOC24_1_H
#define AOC24_1_H
#include <filesystem>
#include <numeric>
#include <vector>

using inputListType = std::pair<std::vector<int>, std::vector<int>>;
using pairListType = std::vector<std::pair<int, int>>;

pairListType prepareListOfPairs(const inputListType& inputLists);

std::vector<int> calculateDistances(const pairListType& preparedList);

inline int calculateTotalDistance(const std::vector<int>& distances) {
  return std::accumulate(distances.begin(), distances.end(), 0);
}

inputListType readPairsFromFile(const std::filesystem::path& inputfile);

int calculateSimilarityScore(const inputListType& inputList);

#endif  // AOC24_1_H