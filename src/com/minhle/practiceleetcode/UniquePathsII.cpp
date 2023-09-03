#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();

        if (obstacleGrid.at(m - 1).at(n - 1) == 1 || obstacleGrid.at(0).at(0) == 1)
        {
            return 0;
        }
        vector<int> dp_row(n, 0);
        vector<vector<int>> dp(m, dp_row);

        dp.at(0).at(0) = 1;
        for (int i = 1; i < n; ++i)
        {
            dp.at(0).at(i) = obstacleGrid.at(0).at(i) == 1 ? 0 : dp.at(0).at(i - 1);
        }

        for (int i = 1; i < m; ++i)
        {
            dp.at(i).at(0) = obstacleGrid.at(i).at(0) == 1 ? 0 : dp.at(i - 1).at(0);
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid.at(i).at(j) == 0)
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i).at(j - 1); 
                }
                else
                {
                    dp.at(i).at(j) = 0;
                }
            }
        }
        return dp.at(m - 1).at(n - 1);
    }
};
