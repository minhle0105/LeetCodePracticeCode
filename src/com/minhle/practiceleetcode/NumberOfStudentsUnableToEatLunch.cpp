#include <vector>
#include <utility>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        pair<int, int> student_count;
        pair<int, int> sandwich_count;
        stack<int> st;
        queue<int> q;
        for (int student : students)
        {
            if (student == 0)
            {
                ++student_count.first;
            }
            else
            {
                ++student_count.second;
            }
            q.push(student);
        }

        for (int i = sandwiches.size() - 1; i >= 0; --i)
        {
            int sandwich = sandwiches[i];
            if (sandwich == 0)
            {
                ++sandwich_count.first;
            }
            else
            {
                ++sandwich_count.second;
            }
            st.push(sandwich);
        }

        while (!st.empty())
        {
            if (st.top() == q.front())
            {
                if (q.front() == 0)
                {
                    --student_count.first;
                    --sandwich_count.first;
                }
                else
                {
                    --student_count.second;
                    --sandwich_count.second;
                }
                q.pop();
                st.pop();
            }
            else
            {
                if (student_count.first == 0)
                {
                    return student_count.second;
                }
                if (student_count.second == 0)
                {
                    return student_count.first;
                }
                q.push(q.front());
                q.pop();
            }
        }
        return 0;
    }
};

