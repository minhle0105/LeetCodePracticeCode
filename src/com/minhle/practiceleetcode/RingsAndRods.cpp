#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, vector<bool>> rods;
        for (int i = 0; i < 10; ++i)
        {
            rods[i] = vector<bool>(3, false);
        }
        for (int i = 0; i < rings.size() - 1; ++i)
        {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            if (color == 'R')
            {
                rods[rod][0] = true;
            }
            if (color == 'G')
            {
                rods[rod][1] = true;
            }
            if (color == 'B')
            {
                rods[rod][2] = true;
            }
        }
        int res = 0;
        for (const auto &pair : rods)
        {
            if (pair.second[0] && pair.second[1] && pair.second[2])
            {
                ++res;
            }
        }
        return res;
    }
};
