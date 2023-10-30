#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int, vector<int>, greater<int>> heap;
        traverse(root1, heap);
        traverse(root2, heap);
        vector<int> res;
        while (!heap.empty())
        {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
private:
    void traverse(TreeNode *root, priority_queue<int, vector<int>, greater<int>> &heap)
    {
        if (root == nullptr)
        {
            return;
        }
        traverse(root->left, heap);
        heap.push(root->val);
        traverse(root->right, heap);
    }
};
