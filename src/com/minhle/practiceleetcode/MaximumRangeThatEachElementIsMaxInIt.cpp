#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> maximumLengthOfRanges(vector<int>& nums)
    {
        vector<int> position_of_next_smaller_element_on_the_right(nums.size(), nums.size());
        vector<int> position_of_next_smaller_element_on_the_left(nums.size(), -1);
        stack<pair<int, int>> mono_st;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (!mono_st.empty() && nums[i] > mono_st.top().second)
            {
                position_of_next_smaller_element_on_the_right[mono_st.top().first] = i;
                mono_st.pop();
            }
            mono_st.push({i, nums[i]});
        }
        while (!mono_st.empty())
        {
            mono_st.pop();
        }


        for (int i = nums.size() - 1; i >= 0; --i)
        {
            while (!mono_st.empty() && nums[i] > mono_st.top().second)
            {
                position_of_next_smaller_element_on_the_left[mono_st.top().first] = i;
                mono_st.pop();
            }
            mono_st.push({i, nums[i]});
        }
        while (!mono_st.empty())
        {
            mono_st.pop();
        }

        vector<int> res;
        res.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            res.push_back(position_of_next_smaller_element_on_the_right[i] - position_of_next_smaller_element_on_the_left[i] - 1);
        }
        return res;
    }
};
