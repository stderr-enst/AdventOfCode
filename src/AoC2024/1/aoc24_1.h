#ifndef AOC24_1_H
#define AOC24_1_H
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <filesystem>

template<typename T>
std::vector<std::pair<T,T>>
prepareListOfPairs(const std::pair<std::vector<T>, std::vector<T>>& inputLists) {
    auto left = std::get<0>(inputLists);
    auto right = std::get<1>(inputLists);
    const bool listIsEmpty = (left.size() == 0) or (right.size() == 0);
    const bool unequalLength = left.size() != right.size();
    if(listIsEmpty || unequalLength)
        return {};

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    std::vector<std::pair<T,T>> preparedList = {};
    for(unsigned int i = 0; i < left.size(); i++)
        preparedList.push_back(std::make_pair(left.at(i), right.at(i)));
    
    return preparedList;
}

std::vector<int>
calculateDistances(const std::vector<std::pair<int,int>>& preparedList);

inline int calculateTotalDistance(const std::vector<int>& distances) {
    return std::accumulate(distances.begin(), distances.end(), 0);
}

std::pair<std::vector<int>, std::vector<int>>
readPairsFromFile(const std::filesystem::path& inputfile);

#endif // AOC24_1_H