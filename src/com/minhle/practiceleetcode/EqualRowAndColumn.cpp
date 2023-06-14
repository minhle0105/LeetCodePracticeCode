#include <vector>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> map;
        for (const auto &row : grid)
        {
            string encoded_row = encode(row);
            if (map.find(encoded_row) == map.end())
            {
                map[encoded_row] = 0;
            }
            map[encoded_row] = map[encoded_row] + 1;
        }  
        int res = 0;      
        for (size_t c = 0; c < grid.size(); ++c)
        {
            vector<int> this_col;
            for (size_t r = 0; r < grid.size(); ++r)
            {
                this_col.push_back(grid.at(r).at(c));
            }
            string encoded_col = encode(this_col);
            if (map.find(encoded_col) != map.end())
            {
                res += map[encoded_col];
            }
        }
        return res;
    }

    string encode(const vector<int> &nums)
    {
        string encoded_row;
        for (auto num : nums)
        {
            encoded_row += to_string(num) + ",";
        }
        encoded_row.pop_back();
        return encoded_row;
    }
};
