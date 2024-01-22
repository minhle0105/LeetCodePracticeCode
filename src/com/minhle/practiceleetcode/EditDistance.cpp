#include "AllNecessaryHeaders.h"

class Solution {
public:
    map<pair<int, int>, int> dp;
    int minDistance(string word1, string word2) {
        dp.clear();
        if (word1 == word2)
        {
            return 0;
        }
        if (word1.empty())
        {
            return word2.size();
        }
        if (word2.empty())
        {
            return word1.size();
        }
        return minDistance(word1, word2, 0, 0);
    }

    int minDistance(const string &word1, const string &word2, int i, int j)
    {
        if (dp.find({i, j}) != dp.end())
        {
            return dp[{i, j}];
        }
        if (i == word1.size() && j == word2.size())
        {
            dp[{i, j}] = 0;
            return 0;
        }
        if (i == word1.size())
        {
            dp[{i, j}] = word2.size() - j;
            return word2.size() - j;
        }
        if (j == word2.size()) {
            dp[{i, j}] = word1.size() - i;
            return word1.size() - i;
        }
        if (word1[i] == word2[j])
        {
            int res = minDistance(word1, word2, i + 1, j + 1);
            dp[{i, j}] = res;
            return res;
        }
        int case_insert = minDistance(word1, word2, i, j + 1);
        int case_delete = minDistance(word1, word2, i + 1, j);
        int case_replace = minDistance(word1, word2, i + 1, j + 1);
        int res = 1 + min(case_insert, min(case_delete, case_replace));
        dp[{i, j}] = res;
        return res;
    }
};
