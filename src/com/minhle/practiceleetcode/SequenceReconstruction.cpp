#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        unordered_map<int, vector<int>> graph;
        unordered_set<int> sequence_set;
        vector<int> degrees(nums.size() + 1, 0);
        for (const auto &sequence : sequences)
        {
            for (int i = 0; i < sequence.size(); ++i)
            {
                sequence_set.insert(sequence[i]);
                if (i < sequence.size() - 1)
                {
                    graph[sequence[i]].push_back(sequence[i + 1]);
                    ++degrees.at(sequence[i + 1]);
                }
            }
        }
        // if there is a number in nums that do not exist in sequences --> false, since the
        // correct sequence can be shorter than nums
        if (nums.size() != sequence_set.size())
        {
            return false;
        }

        queue<int> q;
        for (int i = 1; i < degrees.size(); ++i)
        {
            if (degrees.at(i) == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            // whenever there is one more element in queue, it means therer are
            // more than one node at the same degrees --> can exist more than one path
            if (q.size() > 1)
            {
                return false;
            }
            int curr = q.front();
            q.pop();
            for (int neighbor : graph[curr])
            {
                --degrees.at(neighbor);
                if (degrees[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        return true;
    }
};

