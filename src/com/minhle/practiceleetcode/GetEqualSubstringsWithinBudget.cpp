class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs;
        costs.reserve(s.size());
        for (int i = 0; i < s.size(); ++i)
        {
            costs.push_back(abs(s[i] - t[i]));
        }
        int res = 0;
        int current_cost = 0;
        int i = 0;
        int j = 0;
        while (j < costs.size())
        {
            current_cost += costs[j];
            while (i < j && current_cost > maxCost)
            {
                current_cost -= costs[i];
                ++i;
            }
            if (current_cost <= maxCost)
            {
                res = max(res, j - i + 1);
            }
            ++j;
        }
        return res;
    }
};
