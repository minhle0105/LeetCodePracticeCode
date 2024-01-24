#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int, int> id_values;
        for (const auto &row : nums2)
        {
            id_values[row.front()] = row.back();
        }
        vector<vector<int>> res;
        for (const auto &row : nums1)
        {
            if (id_values.find(row.front()) == id_values.end())
            {
                res.push_back(row);
            }
            else
            {
                res.push_back({row.front(), row.back() + id_values[row.front()]});
                id_values.erase(row.front());
            }
        }

        for (const auto &pair : id_values)
        {
            res.push_back({pair.first, pair.second});
        }

        sort(res.begin(), res.end(), [](const vector<int> &pair1, const vector<int> &pair2) {
            return pair1.front() < pair2.front();
        });

        return res;
    }
};
