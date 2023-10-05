#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> st;
        auto *curr = head;
        int n = 0;
        while (curr != nullptr)
        {
            ++n;
            curr = curr->next;
        }
        vector<int> res(n, 0);
        curr = head;
        int i = 0;
        while (curr != nullptr)
        {
            while (!st.empty() && curr->val > st.top().first)
            {
                res.at(st.top().second) = (curr->val);
                st.pop();
            }
            st.push({curr->val, i});
            ++i;
            curr = curr->next;
        }
        return res;
    }
};
