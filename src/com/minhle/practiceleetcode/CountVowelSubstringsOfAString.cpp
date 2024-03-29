class Solution {
public:
    int countVowelSubstrings(string word) {
        int res = 0;
        int n = word.size();
        unordered_set<char> vowels;

        for (int i = 0; i < n - 4; ++i)
        {
            for (int j = i + 4; j < n; ++j)
            {
                bool consonant_not_found = true;
                vowels.clear();
                for (int k = i; k <= j; ++k)
                {
                    char c = word[k];
                    if (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i')
                    {
                        vowels.insert(c);
                    }
                    else
                    {
                        consonant_not_found = false;
                        break;
                    }
                }
                if (!consonant_not_found)
                {
                    break;
                }
                if (vowels.size() == 5)
                {
                    ++res;
                }  
            }
        }
        return res;
    }
};
