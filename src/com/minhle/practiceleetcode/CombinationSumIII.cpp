#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        backtracking(res, k, n, current, 1, 0);
        return res;
    }

    void backtracking(vector<vector<int>> &res, int k, int n, vector<int> &current, int next_index, int current_sum)
    {
        if (current.size() == k && current_sum == n)
        {
            res.push_back(current);
            return;
        }

        for (int i = next_index; i <= 9; ++i)
        {
            current.push_back(i);
            current_sum += i;
            backtracking(res, k, n, current, i + 1, current_sum);
            current_sum -= i;
            current.pop_back();
        }
    }
};
