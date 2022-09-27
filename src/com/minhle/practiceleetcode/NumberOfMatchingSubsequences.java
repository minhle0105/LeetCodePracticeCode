package com.minhle.practiceleetcode;

public class NumberOfMatchingSubsequences {
    public int numMatchingSubseq(String s, String[] words) {
        int count = 0;
        for (String word : words) {
            int firstPointer = 0;
            int secondPointer = 0;
            while (firstPointer < s.length() && secondPointer < word.length()) {
                if (word.charAt(secondPointer) == s.charAt(firstPointer)) {
                    secondPointer++;
                }
                firstPointer++;
            }
            if (secondPointer == word.length()) {
                count++;
            }
        }
        return count;
    }
}
