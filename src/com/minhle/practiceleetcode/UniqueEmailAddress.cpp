#include "AllNecessaryHeaders.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        vector<pair<string, string>> processed_emails;
        for (const auto &email : emails)
        {
            auto processed = split_email(email);
            processed_emails.push_back({processed.first, processed.second});
        }
        unordered_set<string> unique_emails;
        for (const auto &email : processed_emails)
        {
            unique_emails.insert(processed_local_name(email.first) + "@" + email.second);
        }
        return unique_emails.size();
    }
private:
    pair<string, string> split_email(const string &email)
    {
        string local_name;
        string host_name;
        int pivot = -1;
        for (int i = 0; i < email.size(); ++i)
        {
            if (email[i] == '@')
            {
                pivot = i;
                break;
            }
        }
        return {email.substr(0, pivot), email.substr(pivot + 1, email.size() - pivot - 1)};
    }

    string processed_local_name(const string &local_name)
    {
        string res;
        for (char c : local_name)
        {
            if (c == '+')
            {
                break;
            }
            if (c == '.')
            {
                continue;
            }
            res += c;
        }
        return res;
    }
};
