#include <algorithm>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> all_subsets;
        vector<int> curr;
        backtracking(nums, all_subsets, curr, 0);

        vector<vector<int>> res;
        for (const auto &subset : all_subsets)
        {
            res.push_back(subset);
        }
        return res;
    }

    void backtracking(const vector<int> &nums, set<vector<int>> &all_subsets, vector<int> current_subset, int pos)
    {
        sort(current_subset.begin(), current_subset.end());
        all_subsets.insert(current_subset);

        if (pos == nums.size())
        {
            return;
        }
        for (int i = pos; i < nums.size(); ++i)
        {
            current_subset.push_back(nums[i]);
            backtracking(nums, all_subsets, current_subset, i + 1);
            current_subset.pop_back();
        }
    }
};
