#include <set>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int xKing = king[0];
        int yKing = king[1];
        set<pair<int, int>> queen_positions;
        for (vector<int> queen : queens)
        {
            queen_positions.insert({queen[0], queen[1]});
        }
        vector<vector<int>> res;
        for (int x = xKing + 1; x < 8; ++x)
        {
            if (queen_positions.count({x, yKing}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(x);
                this_res.push_back(yKing);
                res.push_back(this_res);
                break;
            }
        }
        for (int x = xKing - 1; x >= 0; --x)
        {
            if (queen_positions.count({x, yKing}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(x);
                this_res.push_back(yKing);
                res.push_back(this_res);
                break;
            }
        }
        for (int y = yKing + 1; y < 8; ++y)
        {
            if (queen_positions.count({xKing, y}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(xKing);
                this_res.push_back(y);
                res.push_back(this_res);
                break;
            }
        }
        for (int y = yKing - 1; y >= 0; --y)
        {
            if (queen_positions.count({xKing, y}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(xKing);
                this_res.push_back(y);
                res.push_back(this_res);
                break;
            }
        }
        int x = xKing + 1;
        int y = yKing + 1;
        while (x < 8 && y < 8)
        {
            if (queen_positions.count({x, y}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(x);
                this_res.push_back(y);
                res.push_back(this_res);
                break;
            }
            ++x;
            ++y;
        }
        x = xKing - 1;
        y = yKing - 1;
        while (x >= 0 && y >= 0)
        {
            if (queen_positions.count({x, y}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(x);
                this_res.push_back(y);
                res.push_back(this_res);
                break;
            }
            --x;
            --y;
        }
        x = xKing + 1;
        y = yKing - 1;
        while (x < 8 && y >= 0)
        {
            if (queen_positions.count({x, y}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(x);
                this_res.push_back(y);
                res.push_back(this_res);
                break;
            }
            ++x;
            --y;
        }
        x = xKing - 1;
        y = yKing + 1;
        while (x >= 0 && y < 8)
        {
            if (queen_positions.count({x, y}) == 1)
            {
                vector<int> this_res;
                this_res.push_back(x);
                this_res.push_back(y);
                res.push_back(this_res);
                break;
            }
            --x;
            ++y;
        }
        return res;
    }
};

