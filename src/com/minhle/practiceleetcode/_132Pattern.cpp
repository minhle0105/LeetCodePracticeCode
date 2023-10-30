#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2)
        {
            return false;
        }
        stack<pair<int, int>> st;
        int current_min = min(nums.at(0), nums.at(1));
        for (int i = 1; i < nums.size(); ++i)
        {
            if (i == 1)
            {
                st.emplace(nums.at(i), current_min);
            }
            else
            {
                current_min = min(nums.at(i), current_min);
                while (!st.empty() && st.top().first < nums.at(i))
                {
                    st.pop();
                }
                if (!st.empty() && nums.at(i) < st.top().first && nums.at(i) > st.top().second)
                {
                    return true;
                }
                st.emplace(nums.at(i), current_min);
            }
        }
        return false;
    }
};
