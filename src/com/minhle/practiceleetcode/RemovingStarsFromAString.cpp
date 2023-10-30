#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        for (char c : s)
        {
            if (c == '*' && !stack.empty())
            {
                stack.pop();
            }
            else
            {
                stack.push(c);
            }
        }
        string res;
        while (!stack.empty())
        {
            res += stack.top();
            stack.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

