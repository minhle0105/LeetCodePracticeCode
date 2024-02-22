class Solution {
public:
    int convertTime(string current, string correct) {
        int min_diff = get_minutes_diff(current, correct);
        vector<int> minutes = {60, 15, 5, 1};
        int res = 0;
        for (int minute : minutes)
        {
            while (min_diff >= minute)
            {
                min_diff -= minute;
                ++res;
            }
        }
        return res;
    }

    int get_minutes_diff(string &current, string &correct)
    {
        int hour_diff = stoi(correct.substr(0, 2)) - stoi(current.substr(0, 2));
        int min_diff = stoi(correct.substr(3)) - stoi(current.substr(3));
        return 60 * hour_diff + min_diff;
    }
};
