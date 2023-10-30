#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> current_combination;
        current_combination.reserve(n);
        backtrack(n, k, 1, current_combination);
        return res;
    }
    void backtrack(int n, int k, int curr, vector<int> &current_combination)
    {
        if (current_combination.size() == k)
        {
            res.push_back(current_combination);
            return;
        }
        for (int i = curr; i <= n; ++i)
        {
            current_combination.push_back(i);
            backtrack(n, k, i + 1, current_combination);
            current_combination.pop_back();
        }
    }
};
