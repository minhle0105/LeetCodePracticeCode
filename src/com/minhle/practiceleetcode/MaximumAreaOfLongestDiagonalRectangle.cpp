#include "AllNecessaryHeaders.h"

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        map<pair<int, int>, double> diagonals;
        double longest_diagonal = 0;
        for (const auto &dimension : dimensions)
        {
            double diagonal = sqrt(pow(dimension[0], 2) + pow(dimension[1], 2));
            diagonals[make_pair(dimension[0], dimension[1])] = diagonal;
            longest_diagonal = max(longest_diagonal, diagonal);
        }

        vector<pair<int, int>> qualified;
        for (const auto &pair : diagonals)
        {
            if (pair.second == longest_diagonal)
            {
                qualified.push_back(pair.first);
            }
        }
        sort(qualified.begin(), qualified.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.first * a.second  > b.first * b.second;
        });
        return qualified.front().first * qualified.front().second;
    }
};
