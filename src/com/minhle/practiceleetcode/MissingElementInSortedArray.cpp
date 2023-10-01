#include <vector>

using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        vector<int> prefix_missing;
        prefix_missing.reserve(nums.size());
        prefix_missing.push_back(0);
        for (int i = 1; i < nums.size(); ++i)
        {
            prefix_missing.push_back(prefix_missing.back() + (nums.at(i) - nums.at(i - 1) - 1));
            if (prefix_missing.back() > k)
            {
                break;
            }
        }
        int left = 0;
        int right = prefix_missing.size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (prefix_missing.at(mid) < k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (prefix_missing.at(right) < k)
        {
            return nums.at(right) + (k - prefix_missing.at(right));
        }
        return nums.at(left) + (k - prefix_missing.at(left));
    }
};
