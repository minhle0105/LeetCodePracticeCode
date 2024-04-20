class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dp_max_ranges;
    int mctFromLeafValues(vector<int>& arr) {
        int n = static_cast<int>(arr.size());

        dp.clear();
        dp_max_ranges.clear();
        dp.resize(n, vector<int>(n, -1));
        dp_max_ranges.resize(n, vector<int>(n, 0));

        return recursive(arr, 0, arr.size() - 1);
    }

    int recursive(const vector<int> &arr, int i, int j)
    {
        if (i == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        dp[i][j] = INT_MAX;
        for (int k = i; k < j; ++k)
        {
            int max_from_i_to_k = find_max(arr, i, k);
            int max_from_k_plus_1_to_j = find_max(arr, k + 1, j);

            dp[i][j] = min(dp[i][j], (max_from_i_to_k * max_from_k_plus_1_to_j) 
                                        + recursive(arr, i, k) 
                                        + recursive(arr, k + 1, j));
        }
        return dp[i][j];
    }

    int find_max(const vector<int> &arr, int start, int end)
    {
        if (dp_max_ranges[start][end] != 0)
        {
            return dp_max_ranges[start][end];
        }
        dp_max_ranges[start][end] = INT_MIN;
        for (int i = start; i <= end; ++i)
        {
            dp_max_ranges[start][end] = max(arr[i], dp_max_ranges[start][end]);
        }
        return dp_max_ranges[start][end];
    }
};
