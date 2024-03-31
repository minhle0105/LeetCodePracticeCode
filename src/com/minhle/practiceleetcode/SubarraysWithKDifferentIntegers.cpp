class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l_far = 0;
        int l_near = 0;
        int r = 0;
        const int n = nums.size();

        int res = 0;

        unordered_map<int, int> counter;

        while (r < n)
        {
            ++counter[nums[r]];

            while (counter.size() > k)
            {
                --counter[nums[l_near]];
                if (counter[nums[l_near]] == 0)
                {
                    counter.erase(nums[l_near]);
                }
                ++l_near;
                l_far = l_near;
            }

            while (l_near < r && counter[nums[l_near]] > 1)
            {
                --counter[nums[l_near]];
                ++l_near;
            }

            if (counter.size() == k)
            {
                res += (l_near - l_far + 1);
            }
            ++r;
        }
        return res;
    }
};
