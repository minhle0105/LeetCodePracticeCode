#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefix(nums.size(), 0);
        prefix.at(0) = ((nums.at(0) % k) + k) % k;
        for (int i = 1; i < nums.size(); ++i)
        {
            prefix.at(i) = (((prefix.at(i - 1) + nums.at(i)) % k) + k) % k; 
        }
        int res = 0;
        map<int, int> frequency;
        frequency[0] = 1;
        for (int sum : prefix)
        {
            if (frequency.find(sum) == frequency.end())
            {
                frequency[sum] = 0;
            }
            ++frequency[sum];
        }
        for (const auto &pair : frequency)
        {
            if (pair.second > 1)
            {
                res += (pair.second * (pair.second - 1)) / 2;
            }
        }
        return res;
    }
};
