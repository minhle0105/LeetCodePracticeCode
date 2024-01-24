#include <vector>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row_zero(1, poured);
        return champagneTower(query_row, query_glass, 0, row_zero);
    }
    double champagneTower(int query_row, int query_glass, int current_row, vector<double> &glasses)
    {
        if (query_row == current_row)
        {
            return glasses.at(query_glass) > 1 ? 1 : glasses.at(query_glass);
        }
        vector<double> next_row(glasses.size() + 1, 0);
        for (int i = 0; i < glasses.size(); ++i)
        {
            if (glasses.at(i) > 1)
            {
                double over_flow_part = (glasses.at(i) - 1) / 2;
                next_row.at(i) += over_flow_part;
                next_row.at(i + 1) += over_flow_part;
            }
        }
        return champagneTower(query_row, query_glass, current_row + 1, next_row);
    }
};
