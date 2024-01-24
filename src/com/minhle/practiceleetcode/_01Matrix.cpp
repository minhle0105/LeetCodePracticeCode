#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> queue;
        set<pair<int, int>> visited;

        int nRows = mat.size();
        int nCols = mat.at(0).size();

        vector<vector<int>> res(nRows, vector<int>(nCols, 0));

        const int dR[4] = {1, -1, 0, 0};
        const int dC[4] = {0, 0, 1, -1};

        for (int r = 0; r < nRows; ++r)
        {
            for (int c = 0; c < nCols; ++c)
            {
                if (mat.at(r).at(c) == 0)
                {
                    queue.push({r, c, 0});
                    visited.insert({r, c});
                }
                res.at(r).at(c) = mat.at(r).at(c);
            }
        }

        while (!queue.empty())
        {
            vector<int> this_cell = queue.front();
            queue.pop();
            int this_row = this_cell.at(0);
            int this_col = this_cell.at(1);
            int this_level = this_cell.at(2);

            for (int i = 0; i < 4; ++i)
            {
                int next_row = this_row + dR[i];
                int next_col = this_col + dC[i];
                bool in_bound = next_row >= 0 && next_col >= 0 && next_row < nRows && next_col < nCols;
                if (in_bound)
                {
                    if (visited.find({next_row, next_col}) == visited.end())
                    {
                        visited.insert({next_row, next_col});
                        queue.push({next_row, next_col, this_level + 1});
                        res.at(next_row).at(next_col) = this_level + 1;
                    }
                }
            }
        }
        return res;
    }
};
