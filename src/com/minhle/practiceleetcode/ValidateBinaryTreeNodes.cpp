#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int source = findRoot(n, leftChild, rightChild);
        // a source node means a node which doesn't have any other node pointing to it
        // so if source = -1 it means there is a cycle in this tree
        return source != -1 ? dfs(n, source, leftChild, rightChild) : false;
    }
private:
    int findRoot(int n, const vector<int> &leftChild, const vector<int> &rightChild)
    {
        vector<int> remainingNodes(n, 0);
        for (int i = 0; i < leftChild.size(); ++i)
        {
            int left = leftChild.at(i);
            int right = rightChild.at(i);
            if (left != -1)
            {
                remainingNodes.at(left) = -1;
            }
            if (right != -1)
            {
                remainingNodes.at(right) = -1;
            }
        }
        for (int i = 0; i < remainingNodes.size(); ++i)
        {
            if (remainingNodes.at(i) != -1)
            {
                return i;
            }
        }
        return -1;
    }

    bool dfs(int n, int start, const vector<int> &left, const vector<int> &right)
    {
        stack<int> st;
        set<int> visited;
        st.push(start);
        visited.insert(start);
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            int leftChild = left.at(curr);
            int rightChild = right.at(curr);
            if (leftChild != -1)
            {
                // if we see a child which is already visited, this means
                // we have the case of a node with 2 parents --> false
                if (visited.find(leftChild) != visited.end())
                {
                    return false;
                }
                st.push(leftChild);
                visited.insert(leftChild);
            }
            if (rightChild != -1)
            {
                // if we see a child which is already visited, this means
                // we have the case of a node with 2 parents --> false
                if (visited.find(rightChild) != visited.end())
                {
                    return false;
                }
                st.push(rightChild);
                visited.insert(rightChild);
            }
        }
        return visited.size() == n;
    }
};