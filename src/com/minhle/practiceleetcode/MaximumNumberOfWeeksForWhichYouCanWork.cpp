class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long total_milestones = 0;
        int max_milestone = 0;
        for (int milestone : milestones)
        {
            total_milestones += milestone;
            max_milestone = max(max_milestone, milestone);
        }

        long long remaining_milestone = total_milestones - max_milestone;

        return max_milestone > remaining_milestone + 1 ? 2 * remaining_milestone + 1 : total_milestones;
    }
};
