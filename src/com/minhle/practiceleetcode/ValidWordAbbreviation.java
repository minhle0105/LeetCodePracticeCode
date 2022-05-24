package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class ValidWordAbbreviation {
    public boolean validWordAbbreviation(String word, String abbr) {
        char[] chars = abbr.toCharArray();
        char[] wordToChar = word.toCharArray();
        int nonDigitChars = 0;
        List<Integer> numbers = new ArrayList<>();
        int wordPointer = 0;
        int abbrPointer1 = 0;
        int abbrPointer2 = 0;
        int sumLength = 0;
        while (abbrPointer1 < chars.length) {
            // nếu là số
            if (Character.isDigit(chars[abbrPointer1])) {
                abbrPointer2 = abbrPointer1 + 1;
                StringBuilder number = new StringBuilder(String.valueOf(chars[abbrPointer1]));
                // bắt đầu tách số ấy ra
                while (abbrPointer2 < chars.length && Character.isDigit(chars[abbrPointer2])) {
                    number.append(chars[abbrPointer2]);
                    abbrPointer2++;
                }
                // nếu số ấy là leading zero -> false
                if (number.toString().charAt(0) == '0') {
                    return false;
                }
                // đẩy pointer lên vị trí vừa đếm xong
                abbrPointer1 = abbrPointer2;
                // thêm số vào mảng, và cộng lấy tổng độ dài đã bị thay thế
                numbers.add(Integer.parseInt(number.toString()));
                sumLength += Integer.parseInt(number.toString());
                // đẩy wordPointer lên vị trí tương ứng
                wordPointer += Integer.parseInt(number.toString());
            }
            else {
                // nếu phần chữ cái ở từ gốc và từ thay thế là khác nhau -> false
                if (wordPointer < word.length() && wordToChar[wordPointer] != chars[abbrPointer1]) {
                    return false;
                }
                // nếu không đẩy 2 cái pointer lên tiếp
                wordPointer++;
                abbrPointer1 ++;
                nonDigitChars++;
            }
        }
        // nếu không có kí tự nào bị thay thế -> so sánh thuần 2 từ gốc
        if (numbers.size() == 0) return word.equals(abbr);
        // tổng những chữ bị thay thế cộng tổng không bị thay thế mà bằng độ dài từ gốc -> true, else false
        return sumLength + nonDigitChars == word.length();
    }


    @Test
    void test1() {
        String word = "substitution";
        String abbr1 = "s010n";
        String abbr2 = "s55n";
        Assertions.assertFalse(validWordAbbreviation(word, abbr1) && validWordAbbreviation(word, abbr2));
    }

    @Test
    void test2() {
        String word = "substitution";
        String abbr = "s10n";
        Assertions.assertTrue(validWordAbbreviation(word, abbr));
    }

    @Test
    void test3() {
        String word = "internationalization";
        String abbr = "i12iz4n";
        Assertions.assertTrue(validWordAbbreviation(word, abbr));
    }

    @Test
    void test4() {
        String word = "substitution";
        String abbr = "s55n";
        Assertions.assertFalse(validWordAbbreviation(word, abbr));
    }
}
