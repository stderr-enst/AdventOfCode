#include "aoc24_2.h"

#include <algorithm>
#include <fstream>
#include <functional>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>

inputListType readFromFile(const std::filesystem::path& inputfile) {
  inputListType lines{};
  constexpr int expectedNumbeOfLines = 1000;
  lines.reserve(expectedNumbeOfLines);

  std::string line = {""};
  std::ifstream file(inputfile);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  }

  while (std::getline(file, line)) {
    std::vector<int> row{};
    std::istringstream iss(line);
    std::transform(std::istream_iterator<std::string>{iss},
                   std::istream_iterator<std::string>{},
                   std::inserter(row, std::end(row)),
                   [](auto& value) { return std::stoi(value); });
    lines.emplace_back(row);
  }

  return lines;
}

bool checkSorting(const std::vector<int>& row) {
  const bool isForwardSorted = std::ranges::is_sorted(row, std::ranges::less{});
  const bool isBackwardSorted =
      std::ranges::is_sorted(row, std::ranges::greater{});
  return isForwardSorted || isBackwardSorted;
}

std::vector<int> calculateSafetyLevel(const std::vector<int>& row) {
  std::vector<int> differences(row.size());

  std::adjacent_difference(row.cbegin(), row.cend(), differences.begin());
  differences.erase(
      differences.begin());  // first element contains original value

  std::for_each(differences.begin(), differences.end(),
                [](int& num) { num = std::abs(num); });

  return differences;
}

bool checkRow(const std::vector<int>& row) {
  auto differences = calculateSafetyLevel(row);

  const int min = *std::min_element(differences.begin(), differences.end());
  const int max = *std::max_element(differences.begin(), differences.end());
  const bool hasCorrectDifferences = (min >= 1) && (max <= 3);

  return checkSorting(row) && hasCorrectDifferences;
}

bool checkRowWithDampener(const std::vector<int>& row) {
  if (!checkRow(row)) {
    for (unsigned int i = 0; i < row.size(); i++) {
      std::vector<int> rowCopy = row;
      auto it = std::next(rowCopy.begin(), i);
      rowCopy.erase(it);
      if (checkRow(rowCopy)) {
        return true;
      }
    }
  } else {
    return true;
  }
  return false;
}