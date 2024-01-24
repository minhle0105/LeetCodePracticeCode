#include "AllNecessaryHeaders.h"

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> char_pos;
        for (int i = 0; i < s.size(); ++i)
        {
            char_pos[s[i]].push_back(i);
        }
        int res = -1;
        for (const auto &pair : char_pos)
        {
            if (pair.second.size() > 1)
            {
                res = max(res, pair.second.back() - pair.second.front() - 1);
            }
        }
        return res;
    }
};
