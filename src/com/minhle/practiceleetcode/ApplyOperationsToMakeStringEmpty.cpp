#include "AllNecessaryHeaders.h"

class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, vector<int>> char_pos;
        for (int i = 0; i < s.size(); ++i)
        {
            char_pos[s[i]].push_back(i);
        }
        int max_frequency = 0;
        for (auto &pair : char_pos)
        {
            reverse(pair.second.begin(), pair.second.end());
            max_frequency = max(max_frequency, static_cast<int>(pair.second.size()));
        }

        int count = 0;
        while (count < max_frequency - 1)
        {
            for (auto &pair : char_pos)
            {
                if (pair.second.empty())
                {
                    continue;
                }
                pair.second.pop_back();
            }
            ++count;
        }
        vector<int> remaining_positions;
        for (const auto &pair : char_pos)
        {
            if (pair.second.empty())
            {
                continue;
            }
            remaining_positions.push_back(pair.second.front());
        }
        sort(remaining_positions.begin(), remaining_positions.end());
        string res;
        for (int position : remaining_positions)
        {
            res += s[position];
        }
        return res;
    }
};

