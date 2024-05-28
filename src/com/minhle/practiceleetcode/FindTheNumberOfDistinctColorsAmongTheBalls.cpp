class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors;
        unordered_map<int, int> balls;
        vector<int> res;
        res.reserve(queries.size());

        for (const auto &query : queries)
        {
            int ball = query[0];
            int color = query[1];
            if (balls.find(ball) == balls.end())
            {
                balls[ball] = color;
                ++colors[color];
            }
            else
            {
                int current_color = balls[ball];
                --colors[current_color];
                if (colors[current_color] == 0)
                {
                    colors.erase(current_color);
                }
                ++colors[color];
                balls[ball] = color;
            }
            res.push_back(colors.size());
        }
        return res;
    }
};
