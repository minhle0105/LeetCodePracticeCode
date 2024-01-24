#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
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
