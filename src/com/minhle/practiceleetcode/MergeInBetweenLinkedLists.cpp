#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // traverse the two linked lists to save 5 important parts
        // 1. list2 head
        // 2. list2 tail
        // 3. list1 at (a - 1)
        // 4. list1 at (b)
        // 5. list1 after b
        // because merging will be done by 3->next = 1, 2->next = 5, and 4->next = null
        vector<ListNode*> nodes;
        nodes.push_back(list2);
        ListNode *curr = list2;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        nodes.push_back(curr);
        curr = list1;
        int i = 0;
        while (i != a - 1)
        {
            curr = curr->next;
            ++i;
        }
        nodes.push_back(curr);
        while (i != b)
        {
            curr = curr->next;
            ++i;
        }
        nodes.push_back(curr);
        curr = curr->next;
        nodes.push_back(curr);

        auto list2Head = nodes.front();
        auto list2Tail = nodes.at(1);
        auto list1BeforeA = nodes.at(2);
        auto list1AtB = nodes.at(3);
        auto list1AfterB = nodes.at(4);
        
        list1BeforeA->next = list2Head;
        list1AtB->next = nullptr;
        list2Tail->next = list1AfterB;
        
        return list1;
    }
};
