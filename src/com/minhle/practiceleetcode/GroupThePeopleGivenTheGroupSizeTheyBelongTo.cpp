#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < groupSizes.size(); ++i)
        {
            groups[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (const auto &pair : groups)
        {
            auto size = pair.first;
            auto members = pair.second;
            if (members.size() == size)
            {
                res.push_back(members);
            }
            else
            {
                int current = 0;
                while (current < members.size())
                {
                    vector<int> subgroups;
                    while (subgroups.size() < size)
                    {
                        subgroups.push_back(members[current]);
                        ++current;
                    }
                    res.push_back(subgroups);
                }
            }
        }
        return res;
    }
};
