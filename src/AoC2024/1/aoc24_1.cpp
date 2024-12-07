#include "aoc24_1.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

pairListType prepareListOfPairs(const inputListType& inputLists) {
    auto left = std::get<0>(inputLists);
    auto right = std::get<1>(inputLists);
    const bool listIsEmpty = (left.size() == 0) or (right.size() == 0);
    const bool unequalLength = left.size() != right.size();
    if(listIsEmpty || unequalLength)
        return {};

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    pairListType preparedList = {};
    for(unsigned int i = 0; i < left.size(); i++)
        preparedList.emplace_back(left.at(i), right.at(i));

    return preparedList;
}

std::vector<int> calculateDistances(const pairListType& preparedList) {
    std::vector<int> distances = {};
    constexpr int expectedNumbeOfLines = 1000;
    distances.reserve(expectedNumbeOfLines);

    const bool listIsNotEmpty = preparedList.size() > 0;
    if(listIsNotEmpty) {
        auto calcSingleDistance = [&](const std::pair<int,int>& pair){
            int left = std::get<0>(pair);
            int right = std::get<1>(pair);
            int distance = std::abs(left - right);
            distances.emplace_back(distance);
        };
        std::for_each(preparedList.begin(), preparedList.end(), calcSingleDistance);
    }

    return distances;
}

inputListType readPairsFromFile(const std::filesystem::path& inputfile){
    std::vector<int> left{};
    std::vector<int> right{};
    constexpr int expectedNumbeOfLines = 1000;
    left.reserve(expectedNumbeOfLines);
    right.reserve(expectedNumbeOfLines);

    std::string line = {""};
    std::ifstream file(inputfile);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1 = 0;
        int num2 = 0;
        if (!(iss >> num1 >> num2)) {
            throw std::runtime_error("Invalid input format");
        }
        left.emplace_back(num1);
        right.emplace_back(num2);
    }

    return std::make_pair(left, right);
}

int calculateSimilarityScore(const inputListType& inputList) {
    const auto& left = std::get<0>(inputList);
    const auto& right = std::get<1>(inputList);

    std::vector<int> scores = {};
    std::for_each(left.begin(), left.end(), [&](int i){
        // NOLINTNEXTLINE
        int count = std::count_if(right.begin(), right.end(), [i](int j){ return i == j; });
        int localScore = i*count;
        scores.emplace_back(localScore);
    });

    auto sum = std::accumulate(scores.begin(), scores.end(), 0);

    return sum;
}