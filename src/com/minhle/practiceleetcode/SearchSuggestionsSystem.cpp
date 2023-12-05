#include "AllNecessaryHeaders.h"

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res(searchWord.size(), vector<string>{});
        sort(products.begin(), products.end());
        string current;
        int pos = 0;
        for (char c : searchWord)
        {
            current += c;
            int first_index = binary_search(products, current);
            if (first_index != -1)
            {
                int current_index = first_index;
                while (res[pos].size() < 3 && current_index < products.size() && has_prefix(current, products[current_index]))
                {
                    res[pos].push_back(products[current_index]);
                    ++current_index;
                }
            }
            ++pos;
        }
        return res;
    }

    int binary_search(const vector<string> &products, const string &word)
    {
        int left = 0;
        int right = products.size() - 1;

        while (left < right - 1)
        {
            int mid = (left + right) / 2;
            if (has_prefix(word, products[mid]))
            {
                right = mid;
            }
            else if (word < products[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (has_prefix(word, products[left]))
        {
            return left;
        }
        if (has_prefix(word, products[right]))
        {

            return right;
        }
        return -1;
    }

    bool has_prefix(const string &prefix, const string &word)
    {
        if (word.size() == prefix.size() && prefix == word)
        {
            return true;
        }
        if (word.size() < prefix.size())
        {
            return false;
        }
        return prefix == word.substr(0, prefix.size());
    }
};
