#include <algorithm>
#include <cstdint>
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        int prev_vowel = 0;
        for (size_t i = 0; i < k; ++i)
        {
            if (isVowel(s[i]))
            {
                ++prev_vowel;
            }
        }
        res = max(res, prev_vowel);

        for (size_t i = 1; i + k <= s.length(); ++i)
        {
            char removed_char = s[i - 1];
            char added_char = s[i + k - 1];
            if (isVowel(removed_char))
            {
                --prev_vowel;
            }
            if (isVowel(added_char))
            {
                ++prev_vowel;
            }
            res = max(res, prev_vowel);
        }
        return res;
    }

    bool isVowel(char c)
    {
        return (c == 'u' ||
                c == 'e' ||
                c == 'o' ||
                c == 'a' ||
                c == 'i');
    }
};

