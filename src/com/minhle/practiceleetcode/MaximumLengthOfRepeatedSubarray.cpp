#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int nRows = nums2.size() + 1;
        int nCols = nums1.size() + 1;
        vector<int> one_row(nCols, 0);
        vector<vector<int>> dp(nRows, one_row);
        int res = 0;
        for (int i = nums1.size() - 1; i >= 0; --i)
        {
            for (int j = nums2.size() - 1; j >= 0; --j)
            {
                if (nums1.at(i) == nums2.at(j))
                {
                    dp.at(j).at(i) = dp.at(j + 1).at(i + 1) + 1;
                    res = max(res, dp.at(j).at(i));
                }
            }
        }
        return res;
    }
};