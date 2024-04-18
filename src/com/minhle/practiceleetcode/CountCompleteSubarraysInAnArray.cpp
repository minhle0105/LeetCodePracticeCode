class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        int k = counter.size();
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            counter.clear();
            for (int j = i; j < nums.size(); ++j)
            {
                ++counter[nums[j]];
                if (counter.size() == k)
                {
                    ++res;
                }
                if (counter.size() > k)
                {
                    break;
                }
            }
        }
        return res;
    }
};
