#include <vector>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int res = 1;
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            res = max_(res, 1 - sum);
        }
        return res;
    }

    int max_(int a, int b)
    {
        return a > b ? a : b;
    }
};
