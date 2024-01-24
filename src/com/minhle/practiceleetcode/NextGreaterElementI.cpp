#include <vector>
#include <unordered_map>
#include <utility>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int, int>> element_pos;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (nums2[j] == nums1[i])
                {
                    element_pos[nums2[j]] = {i, j};
                    break;
                }
            }
        }

        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i)
        {
            int num = nums1[i];
            int pos = element_pos[num].second;
            stack<int> st;
            for (int j = pos; j < nums2.size(); ++j)
            {
                while (!st.empty() && nums2[j] > st.top())
                {
                    int element = st.top();
                    if (element_pos.find(element) != element_pos.end())
                    {
                        res[element_pos[element].first] = nums2[j];
                    }
                    st.pop();
                }
                st.push(nums2[j]);
            }
        }
        return res;
    }
};
