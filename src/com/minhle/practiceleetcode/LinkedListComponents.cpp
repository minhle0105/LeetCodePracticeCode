#include <vector>
#include <unordered_set>

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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums)
        {
            s.insert(num);
        }
        int res = 0;
        auto curr = head;
        while (curr != nullptr)
        {
            if (s.find(curr->val) == s.end())
            {
                curr = curr->next;
                continue;
            }
            while (curr != nullptr && s.find(curr->val) != s.end())
            {
                curr = curr->next;
            }
            ++res;
        }
        return res;
    }
};