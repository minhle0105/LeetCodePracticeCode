#include "AllNecessaryHeaders.h"

class Leetcode84_Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // index-based
        vector<int> left_right(heights.size(), 0);
        vector<int> right_left(heights.size(), 0);

        stack<pair<int, int>> st1;
        stack<pair<int, int>> st2;

        for (int i = 0; i < heights.size(); ++i)
        {
            while (!st1.empty() && heights[i] < st1.top().first)
            {
                left_right[st1.top().second] = i;
                st1.pop();
            }
            st1.push({heights[i], i});
        }

        while (!st1.empty())
        {
            left_right[st1.top().second] = heights.size();
            st1.pop();
        }

        for (int i = heights.size() - 1; i >= 0; --i)
        {
            while (!st2.empty() && heights[i] < st2.top().first)
            {
                right_left[st2.top().second] = i;
                st2.pop();
            }
            st2.push({heights[i], i});
        }

        while (!st2.empty())
        {
            right_left[st2.top().second] = -1;
            st2.pop();
        }

        int res = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            int height = heights[i];
            int width = left_right[i] - right_left[i] - 1;
            res = max(res, height * width);
        }
        return res;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
            vector<vector<int>> dp(matrix.size(), vector<int>(matrix.front().size() , 0));
            for (int c = 0; c < matrix[0].size(); ++c)
            {
                if (matrix[0][c] == '1')
                {
                    ++dp[0][c];
                }
            }

            for (int r = 1; r < matrix.size(); ++r)
            {
                for (int c = 0; c < matrix[r].size(); ++c)
                {
                    if (matrix[r][c] == '0')
                    {
                        dp[r][c] = 0;
                    }
                    else
                    {
                        dp[r][c] = dp[r - 1][c] + 1;
                    }
                }
            }

            Leetcode84_Solution helper;
            int res = 0;
            for (auto &row : dp)
            {
                res = max(res, helper.largestRectangleArea(row));
            }
            return res;
    }
};