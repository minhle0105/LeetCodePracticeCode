class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> st;
        for (const auto &word : words)
        {
            if (st.empty())
            {
                st.push(word);
            }
            else
            {
                if (!is_anagram(word, st.top()))
                {
                    st.push(word);
                }
            }
        }
        vector<string> res(st.size(), "");
        int i = res.size() - 1;
        while (!st.empty())
        {
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }

        bool is_anagram(const string &w1, const string &w2)
        {
            auto counter1 = count_char(w1);
            auto counter2 = count_char(w2);
            for (const auto &pair : counter1)
            {
                if (counter2.find(pair.first) == counter2.end() || counter2[pair.first] != pair.second)
                {
                    return false;
                }
            }
            for (const auto &pair : counter2)
            {
                if (counter1.find(pair.first) == counter1.end() || counter1[pair.first] != pair.second)
                {
                    return false;
                }
            }

            return true;
        }

        unordered_map<char, int> count_char(const string &word)
        {
            unordered_map<char, int> counter;
            for (char c : word)
            {
                ++counter[c];
            }
            return counter;
        }
};
