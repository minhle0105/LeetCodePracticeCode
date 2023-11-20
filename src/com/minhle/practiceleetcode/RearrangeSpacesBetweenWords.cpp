#include "AllNecessaryHeaders.h"

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        int nChars = 0;
        int left = 0;
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] != ' ')
            {
                left = i;
                break;
            }
        }

        while (left < text.size())
        {
            string word;
            int right = left;
            while (right < text.size() && text[right] != ' ')
            {
                word += text[right];
                ++right;
            }
            nChars += word.size();
            words.push_back(word);
            cout << word << endl;
            while (right < text.size() && text[right] == ' ')
            {
                ++right;
            }
            left = right;
        }
        int nSpaces = text.size() - nChars;
        if (words.size() == 1)
        {
            return words.front() + build_empty_string(nSpaces);
        }
        int nSpacesBetweenEachWord = nSpaces / (words.size() - 1);
        string spacesBetweenEachWord = build_empty_string(nSpacesBetweenEachWord);
        int nSpacesAtTheEnd = nSpaces % (words.size() - 1);
        string spacesAtTheEnd = build_empty_string(nSpacesAtTheEnd);
        string res;
        for (int i = 0; i < words.size(); ++i)
        {
            res += words[i];
            if (i < words.size() - 1)
            {
                res += spacesBetweenEachWord;
            }
        }
        res += spacesAtTheEnd;
        return res;
    }

    string build_empty_string(int nSpaces)
    {
        string res;
        for (int i = 0; i < nSpaces; ++i)
        {
            res += " ";
        }
        return res;
    }
};
