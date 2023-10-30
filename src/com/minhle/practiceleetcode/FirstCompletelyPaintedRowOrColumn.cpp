#include <cstdint>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int, int> row_map;
        map<int, int> col_map;
        size_t m = mat.size();
        size_t n = mat.at(0).size();
        for (size_t r = 0; r < m; ++r)
        {
            for (size_t c = 0; c < n; ++c)
            {
                row_map[mat.at(r).at(c)] = r;
                col_map[mat.at(r).at(c)] = c;
            }
        }
        map<int, int> painted_in_row;
        map<int, int> painted_in_col;
        for (size_t r = 0; r < m; ++r)
        {
            painted_in_row[r] = 0;
        }
        for (size_t c = 0; c < n; ++c)
        {
            painted_in_col[c] = 0;
        }
        for (size_t i = 0; i < arr.size(); ++i)
        {
            int pos = arr.at(i);
            int row_painted = row_map[pos];
            int col_painted = col_map[pos];
            ++painted_in_row[row_painted];
            if (painted_in_row[row_painted] == n)
            {
                return i;
            }
            ++painted_in_col[col_painted];
            if (painted_in_col[col_painted] == m)
            {
                return i;
            }
        }
        return 0;
    }
};
