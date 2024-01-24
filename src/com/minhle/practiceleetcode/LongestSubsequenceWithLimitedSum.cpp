#include <vector>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int num : nums)
        {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
        vector<int> res;
        for (int query : queries)
        {
            res.push_back(binary_search(prefix_sum, query));
        }
        return res;
    }

    int binary_search(const vector<int> &nums, int target)
    {
        int left = 0; 
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums.at(mid) == target)
            {
                return mid;
            }
            else if (nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};
