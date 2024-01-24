#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> counter;
        for (char jewel : jewels)
        {
            ++counter[jewel];
        }
        int res = 0;
        for (char stone : stones)
        {
            if (counter.find(stone) == counter.end())
            {
                continue;
            }
            res += counter[stone];
        }
        return res;
    }
};
