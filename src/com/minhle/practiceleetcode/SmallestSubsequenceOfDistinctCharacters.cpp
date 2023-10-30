#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, vector<int>> c_pos;
        unordered_set<char> current_chars;
        stack<char> stack_;

        for (int i = 0; i < s.size(); ++i)
        {
            if (c_pos.find(s.at(i)) == c_pos.end())
            {
                c_pos[s.at(i)] = vector<int>{};
            }
            c_pos[s.at(i)].push_back(i);
        }

        for (int i = 0; i < s.size(); ++i)
        {
            char c = s.at(i);
            if (stack_.empty())
            {
                stack_.push(c);
                current_chars.insert(c);
            }
            else
            {
                if (current_chars.find(c) == current_chars.end())
                {
                    while (!stack_.empty() && c < stack_.top())
                    {
                        char top_stack = stack_.top();
                        if (!binary_search(c_pos[top_stack], i))
                        {
                            break;
                        }
                        stack_.pop();
                        current_chars.erase(top_stack);
                    }
                    stack_.push(c);
                    current_chars.insert(c);
                }
            }
        }
        string res;
        while (!stack_.empty())
        {
            res += stack_.top();
            stack_.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
private:
    bool binary_search(const vector<int> &indexes, int index)
    {
        int left = 0;
        int right = indexes.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (indexes.at(mid) > index)
            {
                return true;
            }
            left = mid + 1;
        }
        return indexes.at(right) > index;
    }
};
