package com.minhle.practiceleetcode;

public class StrobogrammaticNumber {
    public boolean isStrobogrammatic(String num) {
        int left = 0;
        int right = num.length() - 1;
        while (left <= right) {
            boolean case1 = num.charAt(left) == '0' && num.charAt(right) == '0';
            boolean case2 = num.charAt(left) == '1' && num.charAt(right) == '1';
            boolean case3 = num.charAt(left) == '6' && num.charAt(right) == '9';
            boolean case4 = num.charAt(left) == '9' && num.charAt(right) == '6';
            boolean case5 = num.charAt(left) == '8' && num.charAt(right) == '8';
            if (case1 | case2 | case3 | case4 | case5) {
                left++;
                right--;
            }
            else {
                return false;
            }
        }
        return true;
    }
}
