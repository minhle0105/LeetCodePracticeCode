#include "AllNecessaryHeaders.h"

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> all_prefixes_1;

        // complexity O(arr1.size() * m), with m being the largest number in arr1
        for (int num : arr1)
        {
            string num_str = to_string(num);
            while (num_str.size() > 0)
            {
                all_prefixes_1.insert(num_str);
                num_str.pop_back();
            }
        }
        int res = 0;

        // complexity O(arr2.size() * n), with n being the largest number in arr2
        for (int num : arr2)
        {
            string num_str = to_string(num);
            while (num_str.size() > 0)
            {
                if (all_prefixes_1.find(num_str) != all_prefixes_1.end())
                {
                    res = max(res, static_cast<int>(num_str.size()));
                    break;
                }
                num_str.pop_back();
            }
        }
        return res;
    }
};
