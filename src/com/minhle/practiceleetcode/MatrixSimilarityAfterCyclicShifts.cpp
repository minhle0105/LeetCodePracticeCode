class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        auto temp = mat;
        k %= mat[0].size();
        vector<int> new_row;
        for (int i = 0; i < k; ++i)
        {
            for (int r = 0; r < mat.size(); ++r)
            {
                if (r % 2 == 0)
                {
                    new_row = mat[r];
                    new_row.push_back(mat[r][0]);
                    new_row.erase(new_row.begin());
                    mat[r] = new_row;
                }
                else
                {
                    new_row = {mat[r].back()};
                    for (int num : mat[r])
                    {
                        new_row.push_back(num);
                    }
                    new_row.pop_back();
                    mat[r] = new_row;
                }
                new_row.clear();
            }
        }
        return temp == mat;
    }
};
