#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int i = 0; i < arr.size(); ++i)
        {
            prefix_sum.push_back(prefix_sum.back() + arr.at(i));
        }
        int res = 0;
        for (int i = 0; i < prefix_sum.size() - 1; ++i)
        {
            for (int j = i + 1; j < prefix_sum.size(); j += 2)
            {
                int sum_i_plus_1_to_j = prefix_sum.at(j) - prefix_sum.at(i);
                res += sum_i_plus_1_to_j;
            }
        }
        return res;
    }
};
