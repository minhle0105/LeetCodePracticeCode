class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> counter;
        for (int i = 0; i < messages.size(); ++i)
        {
            counter[senders[i]] += count_words(messages[i]);
        }
        vector<pair<string, int>> counter_pairs(counter.begin(), counter.end());
        sort(counter_pairs.begin(), counter_pairs.end(), [](const pair<string, int> &p1, const pair<string, int> &p2){
            return p1.second == p2.second ? p1.first > p2.first : p1.second > p2.second;
        });
        return counter_pairs.front().first;
    }

    int count_words(const string &message)
    {
        int count = 0;
        for (int i = 0; i < message.size();)
        {
            int j = i;
            while (j < message.size() && message[j] != ' ')
            {
                ++j;
            }
            ++count;
            i = j + 1;
        }
        return count;
    }
};
