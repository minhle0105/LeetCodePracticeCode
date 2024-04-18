class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> counter;
        for (int candy : candies)
        {
            ++counter[candy];
        }
        if (k == 0)
        {
            return counter.size();
        }
        int res = 0;
        int left = 0;
        int right = 0;
        while (right < candies.size())
        {
            --counter[candies[right]];
            if (counter[candies[right]] == 0)
            {
                counter.erase(candies[right]);
            }
            if (right - left + 1 == k)
            {
                res = max(res, static_cast<int>(counter.size()));
                ++counter[candies[left]];
                ++left;   
            }
            ++right;
        }
        return res;
    }
};
