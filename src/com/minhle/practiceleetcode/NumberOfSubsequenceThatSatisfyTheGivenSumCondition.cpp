#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        unsigned long long res = 0;
        const long mod = static_cast<long>(pow(10, 9)) + 7;

        vector<long long> powers(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            powers.at(i) = (powers.at(i - 1) * 2) % mod;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = i;
            int right = nums.size() - 1;
            while (left < right - 1)
            {
                int mid = (left + right) / 2;
                if (nums.at(i) + nums.at(mid) <= target)
                {
                    left = mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
            if (nums.at(right) + nums.at(i) <= target)
            {
                res += powers.at(right - i);
            }
            else if (nums.at(left) + nums.at(i) <= target)
            {
                res += powers.at(left - i);
            }
            else
            {
                res += 0;
            }
        }
        return res % mod;
    }
};
