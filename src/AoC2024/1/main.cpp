#include "aoc24_1.h"
#include <iostream>

int main(){
    std::filesystem::path inputfile = "./input";
    if(! std::filesystem::exists(inputfile)){
        std::cout << "Expecting file ./input next to binary.\n";
        return 193; // NOLINT(cppcoreguidelines-avoid-magic-numbers)
    }

    auto inputLists = readPairsFromFile(inputfile);
    auto preparedLists = prepareListOfPairs(inputLists);
    auto distances = calculateDistances(preparedLists);
    auto totalDistance = calculateTotalDistance(distances);

    std::cout << "Total distance = " << totalDistance << '\n';

    auto similarity = calculateSimilarityScore(inputLists);

    std::cout << "Similarity score = " << similarity << '\n';

    return 0;
}
