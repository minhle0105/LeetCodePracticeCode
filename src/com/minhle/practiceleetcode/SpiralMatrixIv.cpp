class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> spiral(m, vector<int>(n, 0));
        vector<pair<int, int>> cells;
        int i = 0;
        int j = 0;
        int count = 0;
        while (count < m * n)
        {
            while (j < n && spiral[i][j] == 0)
            {
                cells.push_back({i, j});
                spiral[i][j] = -1;
                ++j;   
                ++count;
            }
            --j;
            ++i;
            while (i < m && spiral[i][j] == 0)
            {
                cells.push_back({i, j});
                spiral[i][j] = -1;
                ++i;
                ++count;
            }
            --i;
            --j;
            while (j >= 0 && spiral[i][j] == 0)
            {
                cells.push_back({i, j});
                spiral[i][j] = -1;
                --j;
                ++count;
            }
            ++j;
            --i;
            while (i >= 0 && spiral[i][j] == 0)
            {
                cells.push_back({i, j});
                spiral[i][j] = -1;
                --i;
                ++count;
            }
            ++i;
            ++j;
        }
        auto curr = head;
        int pos = 0;
        while (curr)
        {
            spiral[cells[pos].first][cells[pos].second] = curr->val;
            curr = curr->next;
            ++pos;
        }
        return spiral;
    }
};
