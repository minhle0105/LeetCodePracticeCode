class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res;

        unordered_set<int> seen;

        for (const auto &row : grid)
        {
            for (int num : row)
            {
                if (seen.find(num) != seen.end())
                {
                    res.push_back(num);
                }
                else
                {
                    seen.insert(num);
                }
            }
        }

        for (int i = 1; i <= n*n; ++i)
        {
            if (seen.find(i) == seen.end())
            {
                res.push_back(i);
                break;
            }
        }

        return res;
    }
};
