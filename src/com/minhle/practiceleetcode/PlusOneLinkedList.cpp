#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<int> s1;
        auto *curr = head;
        while (curr != nullptr)
        {
            s1.push(curr->val);
            curr = curr->next;
        }
        stack<int> s2;
        bool carry_one = s1.top() + 1 == 10;
        if (carry_one)
        {
            s2.push(0);
        }
        else
        {
            s2.push(s1.top() + 1);
        }
        s1.pop();
        while (!s1.empty())
        {
            int top_num = s1.top();
            if (!carry_one)
            {
                s2.push(top_num);
            }
            else
            {
                ++top_num;
                if (top_num == 10)
                {
                    s2.push(0);
                }
                else
                {
                    s2.push(top_num);
                    carry_one = false;
                }
            }
            s1.pop();
        }
        if (carry_one)
        {
            s2.push(1);
        }
        ListNode* res = new ListNode(-1);
        curr = res;
        while (!s2.empty())
        {
            curr->next = new ListNode(s2.top());
            s2.pop();
            curr = curr->next;
        }
        return res->next;
    }
};
