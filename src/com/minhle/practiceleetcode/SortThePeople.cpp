#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> info;
        for (int i = 0; i < names.size(); ++i)
        {
            info.push_back({names[i], heights[i]});
        }
        sort(info.begin(), info.end(), [](const pair<string, int> &p1, const pair<string, int> &p2)
        {
            return p1.second > p2.second;
        });
        vector<string> res;
        for (const auto &pair : info)
        {
            res.push_back(pair.first);
        }
        return res;
    }
};
