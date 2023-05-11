#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int leftCol = 0;
        int rightCol = mat.at(0).size() - 1;
        for (const auto &row : mat)
        {
            sum += row.at(leftCol);
            if (leftCol != rightCol)
            {
                sum += row.at(rightCol);
            }
            ++leftCol;
            --rightCol;
        }
        return sum;
    }
};
