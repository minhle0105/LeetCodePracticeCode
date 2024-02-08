#include "AllNecessaryHeaders.h"

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> counter;
        for (char c : s)
        {
            ++counter[c];
        }
        vector<pair<char, int>> freq;
        for (const auto &pair : counter)
        {
            double a = ceil(static_cast<double>(s.size()) / 2);
            if (pair.second > a)
            {
                return "";
            }
            freq.push_back(pair);
        }
        sort_(freq);
        vector<char> alternate;
        while (alternate.size() < s.size())
        {
            if (alternate.empty())
            {
                alternate.push_back(freq.front().first);
                --freq.front().second;
            }
            else
            {
                char prev = alternate.back();
                if (freq.front().first == prev)
                {
                    alternate.push_back(freq[1].first);
                    --freq[1].second;
                }
                else
                {
                    alternate.push_back(freq.front().first);
                    --freq.front().second;
                }
            }
            sort_(freq);
        }
        string res;
        for (char c : alternate)
        {
            res += c;
        }
        return res;
    }

    void sort_(vector<pair<char, int>> &freq)
    {
        sort(freq.begin(), freq.end(), [](const pair<char, int> &p1, const pair<char, int> &p2){
            return p1.second > p2.second;
        });
    }
};
