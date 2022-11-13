package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

public class ReverseWordsInAStringII {
    public static void reverseWords(char[] s) {
        for (int i = 0; i < s.length / 2; i++) {
            char temp = s[i];
            s[i] = s[s.length - i - 1];
            s[s.length - i - 1] = temp;
        }
        int i = 0;
        int j = i;
        while (i < s.length) {
            while (i < s.length && s[i] != ' ') {
                i++;
            }
            i--;
            int k = i;
            while (j < k) {
                char temp = s[j];
                s[j] = s[k];
                s[k] = temp;
                j++;
                k--;
            }
            i+=2;
            j = i;
        }
    }
}
