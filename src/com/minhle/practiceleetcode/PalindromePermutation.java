package com.minhle.practiceleetcode;

import java.util.HashSet;
import java.util.Set;

public class PalindromePermutation {
    public boolean canPermutePalindrome(String s) {
        Set<Character> set = new HashSet<>();
        for (char c : s.toCharArray()) {
            if (set.contains(c)) {
                set.remove(c);
            }
            else {
                set.add(c);
            }
        }
        return set.size() <= 1;
    }
}
