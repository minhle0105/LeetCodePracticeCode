#include "AllNecessaryHeaders.h"

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> pos;

        for (int i = 0; i < s.size(); ++i)
        {
            if (pos.find(s[i]) == pos.end())
            {
                pos[s[i]] = {i, -1};
            }
            else
            {
                pos[s[i]].second = i;
            }
        }

        int res = 0;
        unordered_set<char> unique_chars;
        for (const auto &pair : pos)
        {
            if (pair.second.second != -1)
            {
                char first_char = s[pair.second.first];
                char last_char = s[pair.second.second];
                unique_chars.clear();
                for (int i = pair.second.first + 1; i < pair.second.second; ++i)
                {
                    unique_chars.insert(s[i]);
                }
                res += unique_chars.size();
            }
        }
        return res;
    }
};
