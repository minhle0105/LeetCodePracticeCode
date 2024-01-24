#include <AllNecessaryHeaders.h>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> combination;
        backtracking(candidates, combination, 0, target, 0, res);
        return res;
    }
private:
    void backtracking(const vector<int> &candidates, vector<int> &combination,
                      int current_sum, int target, int pos,
                      vector<vector<int>> &res)
    {
        if (current_sum == target)
        {
            res.push_back(combination);
            return;
        }
        if (pos >= candidates.size() || current_sum > target)
        {
            return;
        }
        current_sum += candidates[pos];
        combination.push_back(candidates[pos]);
        backtracking(candidates, combination, current_sum, target, pos, res);
        combination.pop_back();
        current_sum -= candidates[pos];
        backtracking(candidates, combination, current_sum, target, pos + 1, res);
    }
};