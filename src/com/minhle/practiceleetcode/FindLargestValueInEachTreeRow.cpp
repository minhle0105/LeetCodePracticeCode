#include <vector>
#include <queue>
#include <map>
#include <set>

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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        unordered_map<TreeNode*, int> map;
        queue<TreeNode*> queue;
        set<TreeNode*> visited;
        queue.push(root);
        visited.insert(root);
        map[root] = 1;
        while (!queue.empty())
        {
            auto top = queue.front();
            queue.pop();
            if (top->left != nullptr && visited.find(top->left) == visited.end())
            {
                visited.insert(top->left);
                queue.push(top->left);
                map[top->left] = map[top] + 1;
            }
            if (top->right != nullptr && visited.find(top->right) == visited.end())
            {
                visited.insert(top->right);
                queue.push(top->right);
                map[top->right] = map[top] + 1;
            }
        }
        unordered_map<int, vector<int>> levels;
        for (const auto &pair : map)
        {
            if (levels.find(pair.second) == levels.end())
            {
                vector<int> nums;
                levels[pair.second] = nums;
            }
            levels[pair.second].push_back(pair.first->val);
        }
        vector<int> res(levels.size());
        for (const auto &pair : levels)
        {
            int level = pair.first;
            int max_at_this_level = find_max(pair.second);
            res.at(level - 1) = max_at_this_level;
        }
        return res;   
    }

    int find_max(const vector<int> &nums)
    {
        int res = INT_MIN;
        for (auto num : nums)
        {
            res = max_(num, res);
        }
        return res;
    }

    int max_(int a, int b)
    {
        return a > b ? a : b;
    }

};
