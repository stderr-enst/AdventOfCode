#include <algorithm>
#include <print>

#include "aoc24_2.h"

int main() {
  std::filesystem::path inputfile = "./input";
  if (!std::filesystem::exists(inputfile)) {
    std::println("Expecting file ./input next to binary.");
    const int objectivelyBestErrorCode = 193;
    return objectivelyBestErrorCode;
  }

  auto inputLists = readFromFile(inputfile);
  long safeReports =
      std::count_if(inputLists.cbegin(), inputLists.cend(),
                    [](const auto& row) { return checkRow(row); });

  std::println("Number of safe reports = {}", safeReports);

  long safeReportsWithDampener =
      std::count_if(inputLists.cbegin(), inputLists.cend(),
                    [](const auto& row) { return checkRowWithDampener(row); });

  std::println("Number of safe reports with dampener = {}",
               safeReportsWithDampener);

  return 0;
}
