class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int> &e1, const vector<int> &e2){
            return e1.front() < e2.front();
        });

        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return attend(events, 0, k, dp);
    }

    int attend(const vector<vector<int>> &events, int curr, int k, vector<vector<int>> &dp)
    {
        if (k == 0 || curr == events.size())
        {
            return 0;
        }
        if (dp[curr][k] != -1)
        {
            return dp[curr][k];
        }
        int next = binary_search(events, curr, events[curr][1]);
        auto take_this = events[curr][2] + attend(events, next, k - 1, dp);
        auto skip_this = attend(events, curr + 1, k, dp);
        dp[curr][k] = max(take_this, skip_this);
        return dp[curr][k];
    }

    int binary_search(const vector<vector<int>> &events, int left, int target)
    {
        int right = events.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (events[mid][0] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (events[left][0] > target)
        {
            return left;
        }
        if (events[right][0] > target)
        {
            return right;
        }
        return events.size();
    }
};
