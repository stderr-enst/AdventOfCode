#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

#include "aoc24_1.h"

std::vector<int>
calculateDistances(const std::vector<std::pair<int,int>>& preparedList) {
    std::vector<int> distances = {};

    const bool listIsNotEmpty = preparedList.size() > 0;
    if(listIsNotEmpty)
        std::for_each(preparedList.begin(), preparedList.end(), [&](const std::pair<int,int>& pair){
            int left = std::get<0>(pair);
            int right = std::get<1>(pair);
            int distance = std::abs(left - right);
            distances.push_back(distance);
        });
    
    return distances;
}

std::pair<std::vector<int>, std::vector<int>>
readPairsFromFile(const std::filesystem::path& inputfile){
    std::vector<int> left = {};
    std::vector<int> right = {};
    constexpr int expectedNumbeOfLines = 1000;
    left.reserve(expectedNumbeOfLines);
    right.reserve(expectedNumbeOfLines);

    std::string line = {""};
    int num1 = 0;
    int num2 = 0;
    std::ifstream file(inputfile);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file");

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        if (!(iss >> num1 >> num2)) {
            throw std::runtime_error("Invalid input format");
        }
        left.push_back(num1);
        right.push_back(num2);
    }

    return std::make_pair(left, right);
}

int calculateSimilarityScore(const std::pair<std::vector<int>, std::vector<int>>& inputList) {
    const auto& left = std::get<0>(inputList);
    const auto& right = std::get<1>(inputList);

    std::vector<int> scores = {};
    std::for_each(left.begin(), left.end(), [&](int i){
        // NOLINTNEXTLINE
        int count = std::count_if(right.begin(), right.end(), [i](int j){ return i == j; });
        int localScore = i*count;
        scores.push_back(localScore);
    });

    auto sum = std::accumulate(scores.begin(), scores.end(), 0);

    return sum;
}