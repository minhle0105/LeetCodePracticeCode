#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char letter : letters)
        {
            if (letter > target)
            {
                return letter;
            }
        }
        return letters.at(0);
    }
};
