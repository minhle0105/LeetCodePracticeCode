class Solution {
public:
    set<vector<int>> all_distributions;

    int distributeCandies(int n, int limit) {
        vector<int> curr(3, 0);
        backtracking(n, curr, 0, limit);
        return all_distributions.size();
    }

    void backtracking(int candies, vector<int> &curr, int pos, int limit)
    {
        if (candies == 0)
        {
            all_distributions.insert(curr);
            return;
        }
        for (int i = pos; i < 3; ++i)
        {
            for (int candy = 0; candy <= limit; ++candy)
            {
                curr[i] += candy;
                if (curr[i] > limit)
                {
                    curr[i] -= candy;
                    break;
                }
                backtracking(candies - candy, curr, i + 1, limit);
                curr[i] -= candy;
            }
        }
    }
};
