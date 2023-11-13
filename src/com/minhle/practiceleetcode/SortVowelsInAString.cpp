#include <string>
#include <queue>
#include <functional>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string res(s.size(), '.');
        priority_queue<char, vector<char>, greater<char>> vowels;

        for (int i = 0; i < s.size(); ++i)
        {
            if (isVowel(s[i]))
            {
                vowels.push(s[i]);
            }
            else
            {
                res[i] = s[i];
            }
        }

        for (char &c : res)
        {
            if (c == '.')
            {
                c = vowels.top();
                vowels.pop();
            }
        }
        return res;
    }

    bool isVowel(char c)
    {
        return vowels.find(c) != vowels.end();
    }

private:
    const unordered_set<char> vowels = {'u', 'e', 'o', 'a', 'i', 'U', 'E', 'O', 'A', 'I'};
};
