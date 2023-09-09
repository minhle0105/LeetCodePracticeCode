#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mono_stack;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < res.size(); ++i)
        {
            if (mono_stack.empty())
            {
                res.at(i) = 0;
            }
            else
            {
                int this_temp = temperatures.at(i);
                while (!mono_stack.empty() && this_temp > mono_stack.top().first)
                {
                    res.at(mono_stack.top().second) = i - mono_stack.top().second;
                    mono_stack.pop();
                }
            }
            mono_stack.push({temperatures.at(i), i});
        }
        while (!mono_stack.empty())
        {
            int index = mono_stack.top().second;
            res.at(index) = 0;
            mono_stack.pop();
        }
        return res;
    }
};
