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


// Extra solution using backtracking. This solution does not pass all the test cases due to time-limit-exceeded.
// However, it is correct in terms of logic.


// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid.at(0).size();
//         if (obstacleGrid.at(0).at(0) == 1 || obstacleGrid.at(m - 1).at(n - 1) == 1)
//         {
//             return 0;
//         }

//         pair<int, int> current_cell = {0, 0};
//         vector<vector<pair<int, int>>> all_paths;
//         vector<pair<int, int>> current_path;
//         set<pair<int, int>> visited;
//         current_path.push_back(current_cell);
//         visited.insert(current_cell);
//         backtracking(obstacleGrid, current_cell, m, n, all_paths, current_path, visited);
//         return all_paths.size();
//     }

//     void backtracking(const vector<vector<int>> &grid, const pair<int, int> &current_cell, int m, int n, vector<vector<pair<int, int>>> &all_paths, vector<pair<int, int>> &current_path, set<pair<int, int>> &visited)
//     {
//         if (current_cell.first == m - 1 && current_cell.second == n - 1)
//         {
//             all_paths.push_back(current_path);
//             visited.erase(current_path.back());
//             current_path.pop_back();
//             return;
//         }
//         int row = current_cell.first;
//         int col = current_cell.second;
//         pair<int, int> next_right_cell = {row + 1, col};
//         pair<int, int> next_below_cell = {row, col + 1};
//         if (in_bound(next_right_cell, m, n) && visited.find(next_right_cell) == visited.end() && grid.at(row + 1).at(col) != 1)
//         {
//             visited.insert(next_right_cell);
//             current_path.push_back(next_right_cell);
//             backtracking(grid, next_right_cell, m, n, all_paths, current_path, visited);
//         }

//         if (in_bound(next_below_cell, m, n) && visited.find(next_below_cell) == visited.end() && grid.at(row).at(col + 1) != 1)
//         {
//             visited.insert(next_below_cell);
//             current_path.push_back(next_below_cell);
//             backtracking(grid, next_below_cell, m, n, all_paths, current_path, visited);
//         }
//         visited.erase(current_path.back());
//         current_path.pop_back();
//     }

//     bool in_bound(const pair<int, int> &cell, int m, int n)
//     {
//         return cell.first >= 0 && cell.first < m && cell.second >= 0 && cell.second < n;
//     }
// };
