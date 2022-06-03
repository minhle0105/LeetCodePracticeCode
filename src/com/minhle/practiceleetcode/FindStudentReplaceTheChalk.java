package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FindStudentReplaceTheChalk {
    public int chalkReplacer(int[] chalk, int k) {
        int totalChalksEachRound = 0;
        for (int i = 0; i < chalk.length; i++) {
            totalChalksEachRound += chalk[i];
            if (totalChalksEachRound >= k) return i < chalk.length - 1 ? i : 0;
        }
        int chalkForLastRound = k % totalChalksEachRound;
        for (int i = 0; i < chalk.length; i++) {
            chalkForLastRound -= chalk[i];
            if (chalkForLastRound < 0) return i;
        }
        return -1;
    }
}
