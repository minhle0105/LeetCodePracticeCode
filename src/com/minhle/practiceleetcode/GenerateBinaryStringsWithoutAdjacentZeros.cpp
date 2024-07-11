class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> res;
        string curr;
        recursion(n, curr, res);
        return res;
    }

    void recursion(const int n, string &curr, vector<string> &res)
    {
        if (curr.size() == n)
        {
            res.push_back(curr);
            return;
        }
        if (curr.empty())
        {
            curr += "0";
            recursion(n, curr, res);
            curr.pop_back();
            curr += "1";
            recursion(n, curr, res);
            curr.pop_back();
        }
        else
        {
            if (curr.back() == '0')
            {
                curr += "1";
                recursion(n, curr, res);
                curr.pop_back();
            }
            else
            {
                curr += "0";
                recursion(n, curr, res);
                curr.pop_back();
                curr += "1";
                recursion(n, curr, res);
                curr.pop_back();
            }
        }
    }
};
