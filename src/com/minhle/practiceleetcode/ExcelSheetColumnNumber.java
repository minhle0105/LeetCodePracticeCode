package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.Map;

public class ExcelSheetColumnNumber {
    public static int titleToNumber(String columnTitle) {
        Map<Character, Integer> map = new HashMap<>();
        int code = 1;
        for (int i = 65; i < 65 + 26; i++) {
            map.put((char) i, code);
            code++;
        }
        int totalCode = 0;
        int pow = 0;
        for (int i = columnTitle.length() - 1; i >= 0; i--) {
            totalCode += Math.pow(26, pow) * map.get(columnTitle.charAt(i));
            pow++;
        }
        return totalCode;
    }
}
