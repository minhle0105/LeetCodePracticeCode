#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> sameEndSubstringCount(string s, vector<vector<int>>& queries) {
        unordered_map<char, vector<int>> counter;
        vector<int> prefix_count;
        prefix_count.reserve(s.size());
        for (char c : s)
        {
            if (counter.find(c) != counter.end())
            {
                continue;
            }
            prefix_count.clear();
            prefix_count.push_back(0);
            for (int i = 0; i < s.size(); ++i)
            {
                prefix_count.push_back(prefix_count.back() + (s[i] == c ? 1 : 0));
            }
            counter[c] = prefix_count;
        }
        vector<int> res;
        res.reserve(queries.size());
        for (const auto &query : queries)
        {
            int start = query[0];
            int end = query[1];
            int count = 0;
            for (const auto &pair : counter)
            {
                count += get_sum(pair.second[end + 1] - pair.second[start]);
            }
            res.push_back(count);
        }
        return res;
    }

    int get_sum(int n)
    {
        return (n * (1 + n)) / 2;
    }
};
