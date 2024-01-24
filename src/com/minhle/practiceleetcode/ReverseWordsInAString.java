package com.minhle.practiceleetcode;

public class ReverseWordsInAString {
    public String reverseWords(String s) {
        String[] array = s.split("\\s+");
        StringBuilder res = new StringBuilder();
        for (int i = array.length - 1; i >= 0; i--) {
            res.append(array[i]).append(" ");
        }
        return res.toString().trim();
    }
}
