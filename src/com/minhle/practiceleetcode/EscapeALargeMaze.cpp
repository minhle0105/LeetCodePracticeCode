#include <vector>
#include <set>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.size() == 0)
        {
            return true;
        }
        set<pair<int, int>> visited;
        for (const auto &cell : blocked)
        {
            visited.insert({cell.front(), cell.back()});
        }

        // if either source or target is completely surrounded by blocked -> return false
        int source_row = source.front();
        int source_col = source.back();
        int target_row = target.front();
        int target_col = target.back();
        int bound = pow(10, 6);
        vector<pair<int, int>> surrounded_source_blocked;
        vector<pair<int, int>> surrounded_target_blocked;
        for (int i = 0; i < 4; ++i)
        {
            int next_source_row = source_row + dR[i];
            int next_source_col = source_col + dC[i];
            int next_target_row = target_row + dR[i];
            int next_target_col = target_col + dC[i];
            bool in_bound_1 = next_source_row >= 0 && next_source_row < bound && next_source_col >= 0 && next_source_col < bound;
            bool in_bound_2 = next_target_row >= 0 && next_target_row < bound && next_target_col >= 0 && next_target_col < bound;
            if (in_bound_1)
            {
                if (visited.find({next_source_row, next_source_col}) != visited.end())
                {
                    surrounded_source_blocked.push_back({next_source_row, next_source_col});
                }
            }
            if (in_bound_2)
            {
                if (visited.find({next_target_row, next_target_col}) != visited.end())
                {
                    surrounded_target_blocked.push_back({next_target_row, next_target_col});
                }
            }
            if (surrounded_source_blocked.size() == 4 || surrounded_target_blocked.size() == 4)
            {
                return false;
            }
        }

        // normal dfs
        stack<pair<int, int>> st;
        const int area_covered_by_blocked = blocked.size() * blocked.size();
        int area_covered_by_visited_cells = 1;

        st.push({source.front(), source.back()});
        pair<int, int> dst = {target.front(), target.back()};
        while (!st.empty())
        {
            auto curr = st.top();
            st.pop();
            int curr_row = curr.first;
            int curr_col = curr.second;
            for (int i = 0; i < 4; ++i)
            {
                int next_row = curr_row + dR[i];
                int next_col = curr_col + dC[i];
                // if we reach target
                if (next_row == dst.first && next_col == dst.second)
                {
                    return true;
                }
                // if area covered by visited cells is already greater than
                // area covered by blocked cells -> there is always a way between source and target
                if (area_covered_by_visited_cells > area_covered_by_blocked)
                {
                    return true;
                }
                bool in_bound = next_row >= 0 && next_row < bound && next_col >= 0 && next_col < bound;
                if (in_bound)
                {
                    if (visited.find({next_row, next_col}) == visited.end())
                    {
                        ++area_covered_by_visited_cells;
                        visited.insert({next_row, next_col});
                        st.push({next_row, next_col});
                    }
                }
            }
        }
        return false;
    }
private:
    vector<int> dR = {1, -1, 0, 0};
    vector<int> dC = {0, 0, 1, -1};
};
