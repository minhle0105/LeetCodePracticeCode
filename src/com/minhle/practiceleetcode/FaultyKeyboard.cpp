class Solution {
public:
    string finalString(string s) {
        string res;
        for (char c : s)
        {
            if (c == 'i')
            {
                string temp = res;
                reverse(temp.begin(), temp.end());
                res.clear();
                res += temp;
            }
            else
            {
                res += c;
            }
        }
        return res;
    }
};
