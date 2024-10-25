class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        for (int i = 1; i < folder.size(); ++i)
        {
            if (!is_prefix(res.back(), folder[i]))
            {
                res.push_back(folder[i]);
            }
        }
        return res;
    }

private:
    bool is_prefix(const string &a, const string &b)
    {
        if (a.size() >= b.size())
        {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] != b[j])
            {
                return false;
            }
            ++i;
            ++j;
        }
        return b[j] == '/';
    }
};
