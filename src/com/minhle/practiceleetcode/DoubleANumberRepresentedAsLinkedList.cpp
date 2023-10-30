#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> s1;
        auto curr = head;
        while (curr != nullptr)
        {
            s1.push(curr);
            curr = curr->next;
        }
        stack<ListNode*> s2;
        bool carry = false;
        while (!s1.empty())
        {
            auto top_node = s1.top();
            s1.pop();
            int next_num = top_node->val;
            if (!carry)
            {
                int next_num_x_2 = 2 * next_num;
                if (next_num_x_2 >= 10)
                {
                    carry = true;
                    next_num_x_2 %= 10;
                }
                top_node->val = next_num_x_2;
                s2.push(top_node);
            }
            else
            {
                int next_num_x_2 = (2 * next_num) + 1;
                if (next_num_x_2 < 10)
                {
                    carry = false;
                }
                else
                {
                    next_num_x_2 %= 10;
                }
                top_node->val = next_num_x_2;
                s2.push(top_node);
            }
        }
        auto *res = carry ? new ListNode(1) : new ListNode(-1);
        curr = res;
        while (!s2.empty())
        {
            curr->next = s2.top();
            s2.pop();
            curr = curr->next;
        }
        return carry ? res : res->next;
    }
};