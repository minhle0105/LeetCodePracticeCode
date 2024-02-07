#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<pair<int, string>> count_domains;
        count_domains.reserve(cpdomains.size());
        for (const auto &cpdomain : cpdomains)
        {
            count_domains.push_back(preprocess(cpdomain));
        }
        unordered_map<string, int> counter;
        for (const auto &pair : count_domains)
        {
            auto all_domains = get_all_domains(pair.second);
            for (const auto &domain : all_domains)
            {
                counter[domain] += pair.first;
            }
        }
        vector<string> res;
        for (const auto &pair : counter)
        {
            res.push_back(construct_domain_count(pair));
        }
        return res;
    }

    string construct_domain_count(const pair<string, int> &domain_count)
    {
        return to_string(domain_count.second) + " " + domain_count.first;
    }

    vector<string> get_all_domains(const string &domain)
    {
        vector<string> res;
        res.push_back(domain);
        for (int i = 0; i < domain.size(); ++i)
        {
            if (domain[i] == '.')
            {
                res.push_back(domain.substr(i + 1));
            }
        }
        return res;
    }

    pair<int, string> preprocess(const string &cpdomain)
    {
        int split_position = -1;
        string count;
        for (int i = 0; i < cpdomain.size(); ++i)
        {
            if (cpdomain[i] == ' ')
            {
                split_position = i;
                break;
            }
            count += cpdomain[i];
        }
        return {stoi(count), cpdomain.substr(split_position + 1)};
    }
};
