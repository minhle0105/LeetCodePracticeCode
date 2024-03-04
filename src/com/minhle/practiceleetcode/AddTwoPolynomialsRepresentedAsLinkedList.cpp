#include "AllNecessaryHeaders.h"

struct PolyNode {
    int coefficient, power;
    PolyNode *next;
    PolyNode(): coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
};


class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        auto curr1 = poly1;
        while (curr1)
        {
            int coefficient = curr1->coefficient;
            int power = curr1->power;
            m1[power] = coefficient;
            curr1 = curr1->next;
        }

        auto curr2 = poly2;
        while (curr2)
        {
            int coefficient = curr2->coefficient;
            int power = curr2->power;
            m2[power] = coefficient;
            curr2 = curr2->next;
        }

        unordered_map<int, int> m3;


        for (const auto &pair : m1)
        {
            int power = pair.first;
            int coefficient = pair.second;
            if (m2.find(power) == m2.end())
            {
                m3[power] = coefficient;
            }
            else
            {
                m3[power] = coefficient + m2[power];
                m2.erase(power);
            }
        }

        for (const auto &pair : m2)
        {
            int power = pair.first;
            int coefficient = pair.second;
            if (m1.find(power) == m1.end())
            {
                m3[power] = coefficient;
            }
            else
            {
                m3[power] = coefficient + m1[power];
            }
        }

        vector<pair<int, int>> m3_pairs(m3.begin(), m3.end());
        sort(m3_pairs.begin(), m3_pairs.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.first > p2.first;
        });
        PolyNode* res = new PolyNode();
        auto curr = res;
        for (auto &pair : m3_pairs)
        {
            if (pair.second == 0)
            {
                continue;
            }
            PolyNode* next = new PolyNode(pair.second, pair.first);
            curr->next = next;
            curr = curr->next;
        }
        return res->next;
    }
};
