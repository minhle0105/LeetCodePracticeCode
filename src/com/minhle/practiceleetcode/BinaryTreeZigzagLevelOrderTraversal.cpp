#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<vector<int>>{};
        }
        map<int, vector<TreeNode *>> levels_map;
        map<TreeNode *, int> node_level_map;

        bfs_to_construct_node_level_mapping(root, levels_map, node_level_map);

        vector<vector<int>> res;
        bool left_to_right = true;
        for (const auto &pair : levels_map)
        {
            vector<int> this_level;
            this_level.reserve(pair.second.size());
            for (auto &node : pair.second)
            {
                this_level.push_back(node->val);
            }
            if (left_to_right)
            {
                res.push_back(this_level);
            }
            else
            {
                reverse(this_level.begin(), this_level.end());
                res.push_back(this_level);
            }
            left_to_right = !left_to_right;
        }
        return res;
    }

    void bfs_to_construct_node_level_mapping(TreeNode *root, map<int, vector<TreeNode *>> &levels_map, map<TreeNode *, int> &node_level_map)
    {
        queue<TreeNode *> queue;
        set<TreeNode *> visited;

        queue.push(root);
        visited.insert(root);
        node_level_map[root] = 1;
        levels_map[1] = vector<TreeNode *>{};
        levels_map[1].push_back(root);

        while (!queue.empty())
        {
            auto this_node = queue.front();
            int next_level = node_level_map[this_node] + 1;
            queue.pop();
            if (this_node->left != nullptr)
            {
                if (visited.find(this_node->left) == visited.end())
                {
                    queue.push(this_node->left);
                    visited.insert(this_node->left);
                    node_level_map[this_node->left] = next_level;
                    if (levels_map.find(next_level) == levels_map.end())
                    {
                        levels_map[next_level] = vector<TreeNode *>{};
                    }
                    levels_map[next_level].push_back(this_node->left);
                }
            }
            if (this_node->right != nullptr)
            {
                if (visited.find(this_node->right) == visited.end())
                {
                    queue.push(this_node->right);
                    visited.insert(this_node->right);
                    node_level_map[this_node->right] = next_level;
                    if (levels_map.find(next_level) == levels_map.end())
                    {
                        levels_map[next_level] = vector<TreeNode *>{};
                    }
                    levels_map[next_level].push_back(this_node->right);
                }
            }
        }
    }
};
