#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> bfs;
        unordered_map<TreeNode*, TreeNode*> child_to_parent;
        bfs.push(root);
        child_to_parent[root] = nullptr;

        while (!bfs.empty())
        {
            auto curr = bfs.front();
            bfs.pop();

            if (curr->left != nullptr)
            {
                bfs.push(curr->left);
                child_to_parent[curr->left] = curr;
            }

            if (curr->right != nullptr)
            {
                bfs.push(curr->right);
                child_to_parent[curr->right] = curr;
            }
        }

        unordered_set<TreeNode*> os;
        os.insert(p);
        auto curr = p;
        while (child_to_parent[curr] != nullptr)
        {
            os.insert(child_to_parent[curr]);
            curr = child_to_parent[curr];
        }
        os.insert(root);
        curr = q;
        while (os.find(curr) == os.end())
        {
            curr = child_to_parent[curr];
        }
        return curr;
    }
};
