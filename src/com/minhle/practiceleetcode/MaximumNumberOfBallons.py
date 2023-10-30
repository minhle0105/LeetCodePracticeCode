class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        char_count = dict()
        res = 0
        key_word = "balloon"
        for char in text:
            if key_word.count(char) != 0:
                if char in char_count:
                    char_count[char] = char_count[char] + 1
                else:
                    char_count[char] = 1
        if len(char_count) != 5:
            return 0
        keep_finding = True
        while keep_finding:
            for char in char_count.keys():
                if char == 'l' or char == 'o':
                    char_count[char] = char_count[char] - 2
                else:
                    char_count[char] = char_count[char] - 1
                if char_count[char] < 0:
                    keep_finding = False
                    break

            if not keep_finding:
                break
            else:
                res += 1
        return res

        
