#ifndef AOC24_2_H
#define AOC24_2_H
#include <filesystem>
#include <vector>

using inputListType = std::vector<std::vector<int>>;

inputListType readFromFile(const std::filesystem::path& inputfile);

bool checkSorting(const std::vector<int>& row);
std::vector<int> calculateSafetyLevel(const std::vector<int>& row);

bool checkRow(const std::vector<int>& row);

bool checkRowWithDampener(const std::vector<int> &row);

#endif // AOC24_2_H