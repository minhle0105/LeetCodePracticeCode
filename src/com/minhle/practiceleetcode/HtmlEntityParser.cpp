#include "AllNecessaryHeaders.h"

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, char> parser;
        parser["&quot;"] = '"';
        parser["&apos;"] = '\'';
        parser["&amp;"] = '&';
        parser["&gt;"] = '>';
        parser["&lt;"] = '<';
        parser["&frasl;"] = '/';

        vector<int> open_positions;
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] == '&')
            {
                open_positions.push_back(i);
            }
        }
        unordered_map<int, pair<char, int>> replaced;

        for (int position : open_positions)
        {
            int end_position = position;
            while (end_position < text.size() && text[end_position] != ';')
            {
                ++end_position;
            }
            auto tag = text.substr(position, end_position - position + 1);
            if (parser.find(tag) != parser.end())
            {
                replaced[position] = {parser[tag], end_position};
            }
        }
        string html;
        for (int i = 0; i < text.size();)
        {
            if (replaced.find(i) == replaced.end())
            {
                html += text[i];
                ++i;
            }
            else
            {
                auto parsed_value = replaced[i];
                html += parsed_value.first;
                i = parsed_value.second + 1;
            }
        }
        return html;
    }
};

