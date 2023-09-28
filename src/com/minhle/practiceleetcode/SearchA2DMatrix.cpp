#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        while (top < bottom - 1)
        {
            int mid = (top + bottom) / 2;
            if (matrix.at(mid).at(0) == target)
            {
                return true;
            }
            if (matrix.at(mid).at(0) < target)
            {
                top = mid;
            }
            else
            {
                bottom = mid - 1;
            }
        }
        int row = matrix.at(bottom).at(0) <= target ? bottom : top;
        int left = 0;
        int right = matrix.at(row).size() - 1;
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (matrix.at(row).at(mid) == target)
            {
                return true;
            }
            if (matrix.at(row).at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }   
        return matrix.at(row).at(left) == target || matrix.at(row).at(right) == target;
    }
};
