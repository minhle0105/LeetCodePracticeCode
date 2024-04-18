class Solution {
public:
    struct Transaction
    {
        int time;
        int amount;
        string location;        

        Transaction(int t, int a, string l) : time(t), amount(a), location(l) {};
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<Transaction>> transaction_details;
        vector<string> res;
        for (const auto &transaction : transactions)
        {
            auto details = process_transaction(transaction);
            auto name = details[0];
            auto time = details[1];
            auto amount = details[2];
            auto location = details[3];
            transaction_details[name].push_back(Transaction{stoi(time), stoi(amount), location});        
        }

        for (auto &pair : transaction_details)
        {
            sort(pair.second.begin(), pair.second.end(), [](const Transaction &t1, const Transaction &t2){
                return t1.time < t2.time;
            });
        }

        for (const auto &pair : transaction_details)
        {
            int i = 0;
            unordered_set<int> seen;

            for (int i = 0; i < pair.second.size(); ++i)
            {
                if (pair.second[i].amount > 1000)
                {
                    seen.insert(i);
                }
                int j = i + 1;
                while (j < pair.second.size() && pair.second[j].time - pair.second[i].time <= 60)
                {
                    if (pair.second[j].location != pair.second[i].location)
                    {
                        seen.insert(j);
                        seen.insert(i);
                    }
                    ++j;
                }
            }
            for (int pos : seen)
            {
                res.push_back(decode_transaction(pair.second[pos], pair.first));
            }
        }
        return res;
    }

    string decode_transaction(const Transaction &t, const string &name)
    {
        return name + "," + to_string(t.time) + "," + to_string(t.amount) + "," + t.location;
    }

    vector<string> process_transaction(const string &transaction)
    {
        vector<string> res;
        string curr;
        int i = 0;
        while (i < transaction.size())
        {
            if (transaction[i] == ',')
            {
                res.push_back(curr);
                curr = "";
            }
            else
            {
                curr += transaction[i];
            }
            ++i;
        }
        res.push_back(curr);
        return res;
    }
};
