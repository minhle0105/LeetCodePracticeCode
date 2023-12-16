#include "AllNecessaryHeaders.h"

struct Node
{
    bool isEndOfWord;
    vector<Node*> next;

    Node()
    {
        isEndOfWord = false;
        next.resize(26, nullptr);
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(const string &word) {
        auto curr = root;
        for (char c : word)
        {
            if (curr->next[c - 'a'] == nullptr)
            {
                curr->next[c - 'a'] = new Node();
            }
            curr = curr->next[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto &word : words)
        {
            trie.insert(word);
        }
        int pos = 0;
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            char_pos[ch] = pos;
            ++pos;
        }
        unordered_set<string> words_found;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                int curr_char_pos = char_pos[board[i][j]];
                if (trie.root->next[curr_char_pos] != nullptr)
                {
                    string current_word;
                    current_word += board[i][j];
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    visited[i][j] = true;
                    backtracking(board, words_found, current_word, trie.root->next[curr_char_pos], visited, i, j);
                }
            }
        }
        vector<string> answer;
        for (const auto &word : words_found)
        {
            answer.push_back(word);
        }
        return answer;
    }

private:
    Trie trie;
    unordered_map<char, int> char_pos;
    const vector<int> dR = {0, 0, 1, -1};
    const vector<int> dC = {1, -1, 0, 0};
    void backtracking(const vector<vector<char>> &board, unordered_set<string> &words_found,
                      string &current_word, Node* curr, vector<vector<bool>> &visited, int i, int j)
    {
        if (curr->isEndOfWord)
        {
            words_found.insert(current_word);
        }
        for (int k = 0; k < 4; ++k)
        {
            int next_i = i + dR[k];
            int next_j = j + dC[k];
            bool in_bound = next_i >= 0 && next_j >= 0 && next_i < board.size() && next_j < board[0].size();
            if (in_bound)
            {
                if (!visited[next_i][next_j])
                {
                    int next_char_pos = char_pos[board[next_i][next_j]];
                    if (curr->next[next_char_pos] != nullptr)
                    {
                        visited[next_i][next_j] = true;
                        current_word += board[next_i][next_j];
                        auto temp = curr;
                        curr = curr->next[next_char_pos];
                        backtracking(board, words_found, current_word, curr, visited, next_i, next_j);
                        curr = temp;
                        current_word.pop_back();
                        visited[next_i][next_j] = false;
                    }
                }
            }
        }
    }
};
