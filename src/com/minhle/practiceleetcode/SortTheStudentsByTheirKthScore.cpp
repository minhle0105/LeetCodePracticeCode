#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& scores, int k) {
        sort(scores.begin(), scores.end(), [k](const vector<int> &score1, const vector<int> &score2){
            return score1[k] > score2[k];
        });
        return scores;
    }
};
