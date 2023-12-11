#include "AllNecessaryHeaders.h"

class WordDictionary {
public:
    WordDictionary() {
    }

    void addWord(string word) {
        dictionary.insert(word);
    }

    bool search(string word) {
        for (char ch : word)
        {
            if (ch == '.')
            {
                return backtracking(word, 0);
            }
        }
        return dictionary.find(word) != dictionary.end();
    }
private:
    unordered_set<string> dictionary;
    bool backtracking(string &word, int i)
    {
        if (i ==  word.size())
        {
            return dictionary.find(word) != dictionary.end();
        }
        if (word[i] != '.')
        {
            return backtracking(word, i + 1);
        }
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            word[i] = ch;
            if (backtracking(word, i + 1))
            {
                return true;
            }
            word[i] = '.';
        }
        return false;
    }
};
