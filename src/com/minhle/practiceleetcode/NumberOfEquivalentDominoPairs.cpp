class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> counter;
        for (const auto &domino : dominoes)
        {
            int a = domino[0];
            int b = domino[1];
            ++counter[{min(a,b), max(a,b)}];
        }
        int res = 0;
        for (const auto &pair : counter)
        {
            if (pair.second >= 2)
            {
                int n = pair.second;
                res += ((n * (n - 1)) / 2);
            }
        }
        return res;

    }
};
