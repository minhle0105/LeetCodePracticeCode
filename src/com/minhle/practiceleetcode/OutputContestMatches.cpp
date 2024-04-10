class Solution {
public:
    string findContestMatch(int n) {
        vector<string> curr;
        curr.reserve(n);
        for (int i = 1; i <= n; ++i)
        {
            curr.push_back(to_string(i));
        }
        recursion(curr);
        string res = "(";
        for (const string &pair : curr)
        {
            res += (pair + ",");
        }
        res.pop_back();
        res += ")";
        return res;
    }

    void recursion(vector<string> &curr)
    {
        if (curr.size() == 2)
        {
            return;
        }
        vector<string> temp;
        int i = 0;
        int j = curr.size() - 1;
        while (i < j)
        {
            temp.push_back("(" + curr[i] + "," + curr[j] + ")");
            ++i;
            --j;
        }
        curr = temp;
        recursion(curr);
    }
};
