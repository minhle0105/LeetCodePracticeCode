#include "AllNecessaryHeaders.h"

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0)
        {
            return true;
        }
        queue<int> q;
        vector<bool> visited(arr.size(), false);
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            auto i = q.front();
            q.pop();

            int right_most = i + arr[i];
            int left_most = i - arr[i];
            if (right_most < arr.size())
            {
                if (arr[right_most] == 0)
                {
                    return true;
                }
                if (!visited[right_most])
                {
                    q.push(right_most);
                    visited[right_most] = true;
                }
            }
            if (left_most >= 0)
            {
                if (arr[left_most] == 0)
                {
                    return true;
                }
                if (!visited[left_most])
                {
                    q.push(left_most);
                    visited[left_most] = true;
                }
            }
        }
        return false;
    }
};
