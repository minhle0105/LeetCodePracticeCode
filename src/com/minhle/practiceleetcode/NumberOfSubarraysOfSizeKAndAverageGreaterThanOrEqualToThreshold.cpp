#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int num : arr)
        {
            prefix_sum.push_back(prefix_sum.back() + num);
        }
        for (int i = 0; i + k <= arr.size(); ++i)
        {
            int sum = prefix_sum.at(i + k) - prefix_sum.at(i);
            if ((sum / k) >= threshold)
            {
                ++res;
            }
        }
        return res;
    }
};
