class Solution {
public:
    string interpret(string command) {
        string res;
        int i = 0;
        while (i < command.size())
        {
            if (command[i] == 'G')
            {
                res += 'G';
                ++i;
            }
            else if (command[i] == '(')
            {
                ++i;
            }
            else if (command[i] == 'a')
            {
                i += 3;
                res += "al";
            }
            else
            {
                res += 'o';
                ++i;
            }
        }
        return res;
    }
};
