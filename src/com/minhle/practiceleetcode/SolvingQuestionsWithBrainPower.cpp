#include "AllNecessaryHeaders.h"

class Solution {
public:
    long long res;

    long long mostPoints(vector<vector<int>>& questions) {
        res = 0;
        vector<pair<long long, long long>> dp(questions.size(), {-1,-1});
        recursion(questions, dp, 0);
        return res;
    }

    pair<long long, long long> recursion(const vector<vector<int>> &questions, vector<pair<long long, long long>> &dp, int current_question)
    {
        if (current_question >= questions.size())
        {
            return {0, 0};
        }
        if (dp[current_question].first != -1)
        {
            return dp[current_question];
        }
        int point = questions[current_question][0];
        int next_question = current_question + questions[current_question][1] + 1;
        auto skipping_next = recursion(questions, dp, next_question);
        auto take_this = point + max(skipping_next.first, skipping_next.second);

        auto take_next = recursion(questions, dp, current_question + 1);
        auto skip_this = max(take_next.first, take_next.second);
        dp[current_question] = {take_this, skip_this};
        res = max(take_this, skip_this);
        return dp[current_question];
    }
};
