#include "AllNecessaryHeaders.h"

class StringIterator {
public:
    StringIterator(string compressedString) {
        word = decompress(compressedString);
    }

    char next() {
        return hasNext() ? word[pos++] : ' ';
    }

    bool hasNext() {
        return pos < word.size();
    }
private:
    string word;
    int pos = 0;
    bool is_digit(char c)
    {
        return '0' <= c && c <= '9';
    }

    string decompress(const string &compressedString)
    {
        string res;
        int left = 0;
        while (left < compressedString.size())
        {
            char c = compressedString[left];
            string num;
            int right = left + 1;
            while (right < compressedString.size() && is_digit(compressedString[right]))
            {
                num += string{compressedString[right]};
                ++right;
            }
            res += string(stoi(num), c);
            left = right;
        }
        return res;
    }
};
