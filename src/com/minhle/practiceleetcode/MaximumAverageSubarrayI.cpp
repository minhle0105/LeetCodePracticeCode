#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum_first_k = 0;
        for (int i = 0; i < k; ++i)
        {
            sum_first_k += nums.at(i);
        }
        double res = sum_first_k / k;
        for (int i = 1; i + k <= nums.size(); ++i)
        {
            sum_first_k -= nums.at(i - 1);
            sum_first_k += nums.at(i + k - 1);
            res = max_(res, sum_first_k / k);
        }
        return res;
    }

    double max_(double a, double b)
    {
        return a > b ? a : b;
    }
};
