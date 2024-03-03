class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        int res = 0;
        for (const auto &pair : counter)
        {
            int a = pair.first;
            int b1 = a - k;
            int b2 = a + k;
            if (counter.find(b1) != counter.end())
            {
                res += (pair.second * counter[b1]);
            }
            if (counter.find(b2) != counter.end())
            {
                res += (pair.second * counter[b2]);
            }
        }
        return res / 2;
    }
};

