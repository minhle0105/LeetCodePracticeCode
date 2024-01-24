package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.*;

public class StudentAttendanceRecordI {
    public boolean checkRecord(String s) {
        Map<Character, List<Integer>> map = new HashMap<>();
        int countAbsent = 0;
        map.put('L', new ArrayList<>());
        map.put('P', new ArrayList<>());
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'A') {
                countAbsent++;
                if (countAbsent == 2) {
                    return false;
                }
            }
            else {
                map.get(s.charAt(i)).add(i);
            }
        }
        boolean lateForThreeConsecutiveDays = checkLateDays(map.get('L'));
        return !lateForThreeConsecutiveDays;
    }

    private boolean checkLateDays(List<Integer> days) {
        for (int i = 2; i < days.size(); i++) {
            if (days.get(i) - days.get(i - 2) == 2) {
                return true;
            }
        }
        return false;
    }

    @Test
    void test1() {
        String s = "PPALLP";
        Assertions.assertTrue(checkRecord(s));
    }

    @Test
    void test2() {
        String s = "PPALLL";
        Assertions.assertFalse(checkRecord(s));
    }
}
