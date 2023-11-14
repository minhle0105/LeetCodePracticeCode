#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int last_element = nums.size();
        int ind = 0;
        int new_size = nums.size() * 2;
        while (nums.size() < new_size)
        {
            nums.push_back(nums[ind]);
            ++ind;
        }
        vector<int> nextGreaterPos(nums.size(), -1);

        stack<pair<int, int>> st;
        int max_num = pow(-10, 9) - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (!st.empty() && nums[i] > st.top().second)
            {
                nextGreaterPos[st.top().first] = i;
                st.pop();
            }
            st.push({i, nums[i]});
            max_num = max(max_num, nums[i]);
        }
        vector<int> res(last_element, -1);
        for (int i = 0; i < last_element; ++i)
        {
            if (nums[i] == max_num)
            {
                continue;
            }
            else
            {
                res[i] = nums[nextGreaterPos[i]];
            }
        }
        return res;
    }
};

