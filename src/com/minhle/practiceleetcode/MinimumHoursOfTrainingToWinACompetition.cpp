class Solution {
public:
    int minNumberOfHours(int initialEnergy,
                         int initialExperience, 
                         vector<int>& energy, 
                         vector<int>& experience) {
        int total_energy = 0;
        for (int e : energy)
        {
            total_energy += e;
        }
        int energy_needed = total_energy >= initialEnergy ? total_energy + 1 - initialEnergy : 0;
        int max_exp = experience[0];
        for (int exp : experience)
        {
            max_exp = max(max_exp, exp);
        }
        int exp_needed = find_energy_needed(experience, 0, max_exp + 1);
        exp_needed = exp_needed > initialExperience ? exp_needed - initialExperience : 0;
        return exp_needed + energy_needed;
    }
    
    int find_energy_needed(const vector<int> &energy, int left, int right)
    {
        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (can_fight_all(energy, mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return can_fight_all(energy, left) ? left : right;
    }

    bool can_fight_all(const vector<int> &energy, int initial)
    {
        for (int e : energy)
        {
            if (initial <= e)
            {
                return false;
            }
            initial += e;
        }
        return true;
    }


};
