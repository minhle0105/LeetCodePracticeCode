#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> counter;
        vector<string> res;
        res.reserve(names.size());
        for (const auto &name : names)
        {
            if (counter.find(name) != counter.end())
            {
                int next_num = counter[name];
                while (counter.find(name + "(" + to_string(next_num) + ")") != counter.end())
                {
                    ++counter[name];
                    ++next_num;
                }
                res.push_back(name + "(" + to_string(next_num) + ")");
            }
            else
            {
                res.push_back(name);
            }
            ++counter[res.back()];
        }
        return res;
    }
};
