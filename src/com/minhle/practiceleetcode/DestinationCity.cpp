#include "AllNecessaryHeaders.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> out_degrees;
        for (const auto &path : paths)
        {
            if (out_degrees.find(path.front()) == out_degrees.end())
            {
                out_degrees[path.front()] = 0;
            }
            if (out_degrees.find(path.back()) == out_degrees.end())
            {
                out_degrees[path.back()] = 0;
            }
            ++out_degrees[path.front()];
        }
        for (const auto &pair : out_degrees)
        {
            if (pair.second == 0)
            {
                return pair.first;
            }
        }
        return "";
    }
};
