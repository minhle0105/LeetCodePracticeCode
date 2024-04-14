class Solution {
public:
    int minKnightMoves(int x, int y) {
        x += 300;
        y += 300;
        vector<vector<int>> levels(700, vector<int>(700, -1));
        queue<pair<int, int>> q;
        q.push({300, 300});
        levels[300][300] = 0;
        int step = 0;
        
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            auto r = cell.first;
            auto c = cell.second;
            auto level = levels[r][c];
            if (r == x && c == y)
            {
                return level;
            }
            for (int i = 0; i < 8; ++i)
            {
                int next_r = r + dR[i];
                int next_c = c + dC[i];

                if (next_r >= 0 && next_c >= 0 && levels[next_r][next_c] == -1)
                {
                    levels[next_r][next_c] = level + 1;
                    q.push({next_r, next_c});
                }
            }
        }
        return 0;
    }

private:
    const vector<int> dR = {1, 2, 2, 1, -1, -2, -1, -2};
    const vector<int> dC = {2, 1, -1, -2, -2, -1, 2, 1};
};
