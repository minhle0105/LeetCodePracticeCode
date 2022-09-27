package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class PalindromePartitioning {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            List<String> list = new ArrayList<>();
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s.substring(i, j)) && i != j) {
                    list.add(s.substring(i, j));
                }
            }
            res.add(list);
        }
        return res;
    }

    private boolean isPalindrome(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
                return false;
            }
        }
        return true;
    }
    // Input: s = "aab"
    // Output: [["a","a","b"],["aa","b"]]
    //
    // Input: s = "a"
    // Output: [["a"]]
}
