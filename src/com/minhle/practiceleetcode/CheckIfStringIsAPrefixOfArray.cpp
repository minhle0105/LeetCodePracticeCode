class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string curr;
        for (string word : words)
        {
            curr += word;
        }
        int i = words.size() - 1;
        while (i >= 0)
        {
            if (s == curr)
            {
                return true;
            }
            int count = 0;
            while (count < words[i].size())
            {
                curr.pop_back();
                ++count;
            }
            --i;
        }
        return false;
    }
};
