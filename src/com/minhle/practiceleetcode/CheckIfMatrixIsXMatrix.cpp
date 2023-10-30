#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        size_t n = grid.size();
        vector<bool> visited_row(n, false);
        vector<vector<bool>> visited(n, visited_row);
        int leftCol = 0;
        int rightCol = n - 1;
        for (size_t r = 0; r < n; ++r)
        {
            if (grid.at(r).at(leftCol) == 0 || grid.at(r).at(rightCol) == 0)
            {
                return false;
            }   
            visited.at(r).at(leftCol) = true;
            visited.at(r).at(rightCol) = true;
            ++leftCol;
            --rightCol;
        }
        for (size_t r = 0; r < n; ++r)
        {
            for (size_t c = 0; c < n; ++c)
            {
                if (!visited.at(r).at(c))
                {
                    if (grid.at(r).at(c) != 0)
                    {
                        return false;
                    }                  
                }
            }
        }
        return true;
    }
};
