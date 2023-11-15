#include <iterator>
#include <AllNecessaryHeaders.h>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> combination;
        set<vector<int>> sorted_combinations;
        backtracking(candidates, combination, 0, target, res, sorted_combinations);
        return res;
    }
private:
    void backtracking(const vector<int> &candidates, vector<int> &combination,
                      int current_sum, int target,
                      vector<vector<int>> &res, set<vector<int>> &sorted_combinations)
    {
        if (current_sum == target)
        {
            if (combination_is_unique(combination, sorted_combinations))
            {
                res.push_back(combination);
            }
            return;
        }
        if (current_sum > target)
        {
            return;
        }
        for (int i = 0; i < candidates.size(); ++i)
        {
            current_sum += candidates[i];
            combination.push_back(candidates[i]);
            backtracking(candidates, combination, current_sum, target, res, sorted_combinations);
            combination.pop_back();
            current_sum -= candidates[i];
        }
    }

    bool combination_is_unique(const vector<int> &combination, set<vector<int>> &sorted_combinations)
    {
        vector<int> copy;
        std::copy(combination.begin(), combination.end(), back_inserter(copy));
        sort(copy.begin(), copy.end());
        if (sorted_combinations.find(copy) == sorted_combinations.end())
        {
            sorted_combinations.insert(copy);
            return true;
        }
        return false;
    }
};
