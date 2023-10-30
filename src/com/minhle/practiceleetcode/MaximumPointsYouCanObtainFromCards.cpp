#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size() - k;
        int smallest_sum = INT_MAX;
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        for (int point : cardPoints)
        {
            prefix_sum.push_back(prefix_sum.back() + point);
        }

        for (int i = 0; i + n <= cardPoints.size(); ++i)
        {
            int sum = prefix_sum.at(i + n) - prefix_sum.at(i);
            smallest_sum = min(smallest_sum, sum);
        }
        return prefix_sum.back() - smallest_sum;
    }
};