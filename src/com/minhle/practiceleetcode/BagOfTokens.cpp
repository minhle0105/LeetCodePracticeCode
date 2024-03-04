class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.empty())
        {
            return 0;
        }
        sort(tokens.begin(), tokens.end());
        int score = 0;
        return recursion(tokens, score, power, 0, tokens.size() - 1);
    }

    int recursion(const vector<int> &tokens, int score, int power, int i, int j)
    {
        if (i >= j)
        {
            return power >= tokens[i] ? score + 1 : score;
        }
        if (power >= tokens[i])
        {
            return recursion(tokens, score + 1, power - tokens[i], i + 1, j);
        }
        auto play_face_down = score >= 1 ? recursion(tokens, score - 1, power + tokens[j], i, j - 1) : 0;
        auto skip_this = play_face_down == 0 ? 
                        max(recursion(tokens, score, power, i + 1, j), 
                            recursion(tokens, score, power, i, j - 1)) : 
                            play_face_down;
        return max(play_face_down, skip_this);
    }
};
