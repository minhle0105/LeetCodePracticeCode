class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> counter;
        int res = 0;

        for (int num : nums)
        {
            ++counter[num];
            if (counter[num] == 2)
            {
                res ^= num;
            }
        }
        return res;
    }
};
