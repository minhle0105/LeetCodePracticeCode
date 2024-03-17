class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        for (const auto &pair : counter)
        {
            int num = pair.first;
            int diff = k - num;
            if (counter.find(diff) != counter.end())
            {
                res += min(counter[diff], pair.second);
            }
        }
        return res / 2;
    }
};
