class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int total = skill.front() + skill.back();
        long long res = (skill.front() * skill.back());
        int i = 1;
        int j = skill.size() - 2;
        while (i < j)
        {
            if (skill[i] + skill[j] != total)
            {
                return -1;
            }
            res += skill[i++] * skill[j--];
        }

        return res;
    }
};
