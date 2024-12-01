#include <cstdlib>
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