class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<string> num_strs;
        num_strs.reserve(nums.size());
        for (int num : nums)
        {
            num_strs.push_back(to_string(num));
        }   

        int n = num_strs[0].size();
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            unordered_map<int, long long> counter;
            for (const auto &num_str : num_strs)
            {
                ++counter[num_str[i] - '0'];
            }
            for (const auto &pair : counter)
            {
                long long c = pair.second;
                res += (c * (nums.size() - c));
            }
            
        }
        return res / 2;
    }
};
