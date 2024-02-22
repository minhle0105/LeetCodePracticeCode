class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> trust_counts;
        unordered_map<int, int> is_trusted_counts;

        for (const auto &pair : trust)
        {
            int a = pair.front();
            int b = pair.back();
            ++trust_counts[a];
            ++is_trusted_counts[b];
        }

        for (int i = 1; i <= n; ++i)
        {
            if (trust_counts.find(i) == trust_counts.end() && is_trusted_counts[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};
