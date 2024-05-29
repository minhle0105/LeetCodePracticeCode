class Solution {
public:
    string compressedString(string word) {
        string res;
        string curr;
        int i = 0;
        while (i < word.size())
        {
            if (curr.empty())
            {
                curr += word[i];
                ++i;
            }
            else
            {
                if (curr.size() == 9)
                {
                    res += to_string(curr.size());
                    res += curr[0];
                    curr.clear();
                }
                else
                {
                    if (curr.back() == word[i])
                    {
                        curr += word[i];
                        ++i;
                    }
                    else
                    {
                        res += to_string(curr.size());
                        res += curr[0];
                        curr.clear();
                    }
                }
            }
        }
        if (!curr.empty())
        {
            res += to_string(curr.size());
            res += curr[0];
        }
        return res;
    }
};
