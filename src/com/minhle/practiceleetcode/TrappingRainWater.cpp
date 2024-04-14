class Solution {
public:
    int trap(vector<int>& height) {
        auto max_left = find_max_left(height);
        auto max_right = find_max_right(height);
        int res = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            res += max(0, min(max_left[i], max_right[i]) - height[i]);
        }
        return res;
    }
private:
    vector<int> find_max_right(const vector<int> &heights)
    {
        vector<int> max_right(heights.size(), 0);
        for (int i = heights.size() - 2; i >= 0; --i)
        {
            max_right[i] = max(max_right[i + 1], heights[i + 1]);
        }
        return max_right;
    }

    vector<int> find_max_left(const vector<int> &heights)
    {
        vector<int> max_left(heights.size(), 0);
        for (int i = 1; i < heights.size(); ++i)
        {
            max_left[i] = max(max_left[i - 1], heights[i - 1]);
        }
        return max_left;
    }
};
