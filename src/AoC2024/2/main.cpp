#include <algorithm>
#include <iostream>

#include "aoc24_2.h"

int main() {
  std::filesystem::path inputfile = "./input";
  if (!std::filesystem::exists(inputfile)) {
    std::cout << "Expecting file ./input next to binary.\n";
    return 193;  // NOLINT(cppcoreguidelines-avoid-magic-numbers)
  }

  auto inputLists = readFromFile(inputfile);
  long safeReports =
      std::count_if(inputLists.cbegin(), inputLists.cend(),
                    [](const auto& row) { return checkRow(row); });

  std::cout << "Number of safe reports = " << safeReports << '\n';

  long safeReportsWithDampener =
      std::count_if(inputLists.cbegin(), inputLists.cend(),
                    [](const auto& row) { return checkRowWithDampener(row); });

  std::cout << "Number of safe reports with dampener = "
            << safeReportsWithDampener << '\n';

  return 0;
}
