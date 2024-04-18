class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> counter;
        for (int num : nums)
        {
            ++counter[num];
        }
        int res = 0;
        for (const auto &pair : counter)
        {
            int curr = pair.first;
            int target = curr + 1;
            if (counter.find(target) != counter.end())
            {
                res = max(res, counter[curr] + counter[target]);
            }
        }
        return res;
    }
};
