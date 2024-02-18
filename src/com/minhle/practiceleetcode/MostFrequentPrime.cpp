#include "AllNecessaryHeaders.h"

class Solution {
public:
    const vector<int> dR = {1,0,-1,0,1,1,-1,-1};
    const vector<int> dC = {0,1,0,-1,1,-1,1,-1};
    int mostFrequentPrime(vector<vector<int>>& mat) {
        unordered_map<int, int> counter;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                string curr = to_string(mat[i][j]);
                for (int direction = 0; direction < 8; ++direction)
                {
                    int next_i = i + dR[direction];
                    int next_j = j + dC[direction];
                    bool in_bound = next_i >= 0 && next_i < m && next_j >= 0 && next_j < n;
                    if (in_bound)
                    {
                        curr += ('0' + mat[next_i][next_j]);
                        backtracking(mat, next_i, next_j, m, n, curr, counter, direction);
                        curr.pop_back();
                    }
                }
            }
        }
        if (counter.empty())
        {
            return -1;
        }
        vector<pair<int, int>> counter_pairs(counter.begin(), counter.end());
        sort(counter_pairs.begin(), counter_pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            if (p1.second == p2.second)
            {
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        });
        return counter_pairs.front().first;
    }
private:
    void backtracking(const vector<vector<int>> &mat, int r, int c, const int m, const int n,
                      string &curr, unordered_map<int, int> &counter, int direction)
    {
        int num = stoi(curr);
        if (num > 10 && (counter.find(num) != counter.end() || is_prime(num)))
        {
            ++counter[num];
        }
        int next_r = r + dR[direction];
        int next_c = c + dC[direction];
        bool in_bound = next_r >= 0 && next_r < m && next_c >= 0 && next_c < n;
        if (in_bound)
        {
            curr += ('0' + mat[next_r][next_c]);
            backtracking(mat, next_r, next_c, m, n, curr, counter, direction);
            curr.pop_back();
        }
    }

    bool is_prime(int num)
    {
        if (num <= 2)
        {
            return true;
        }
        for (int i = 2; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
