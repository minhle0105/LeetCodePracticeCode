class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = static_cast<int>(skills.size());
        int max_skill = *max_element(skills.begin(), skills.end());
        int max_index = max_element(skills.begin(), skills.end()) - skills.begin();

        if (k >= n)
        {
            return max_index;
        }
        
        int current_player = skills[0];
        int current_win = 0;

        for (int i = 1; i < n; ++i)
        {
            if (skills[i] < current_player)
            {
                ++current_win;
            }
            else
            {
                current_player = skills[i];
                current_win = 1;
            }
            if (current_win == k)
            {
                return find(skills.begin(), skills.end(), current_player) - skills.begin();
            }
        }

        return max_index;
        
    }
};
