class Solution {
public:
    int largestInteger(int num) {
        string num_str = to_string(num);
        priority_queue<int> odds;
        priority_queue<int> evens;
        for (char c : num_str)
        {
            if ((c - '0') % 2 == 0)
            {
                evens.push(c - '0');
            }
            else
            {
                odds.push(c - '0');
            }
        }
        for (char &c : num_str)
        {
            if ((c - '0') % 2 == 0)
            {
                c = '0' + evens.top();
                evens.pop();
            }
            else
            {
                c = '0' + odds.top();
                odds.pop();
            }
        }
        return stoi(num_str);
    }
};
