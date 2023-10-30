#include <stdlib.h>
#include <unordered_map>

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
    Solution(ListNode* head) {
        auto curr = head;
        n = 0;
        while (curr != nullptr)
        {
            map_[n] = curr;
            ++n;
            curr = curr->next;
        }
    }

    int getRandom() {
        return map_[get_random_index(n)]->val;
    }
private:
    int get_random_index(int n)
    {
        return rand() % n;
    }
    unordered_map<int, ListNode*> map_;
    int n;
};