package com.minhle.practiceleetcode;

public class MakeTheStringGreat {
    public String makeGood(String s) {
        boolean isGood = true;
        int a = -1;
        int b = -1;
        for (int i = 0; i < s.length() - 1; i++) {
            boolean sameChar = Character.toLowerCase(s.charAt(i)) == Character.toLowerCase(s.charAt(i + 1));
            boolean diffCase1 = Character.isUpperCase(s.charAt(i)) && Character.isLowerCase(s.charAt(i + 1));
            boolean diffCase2 = Character.isLowerCase(s.charAt(i)) && Character.isUpperCase(s.charAt(i + 1));
            if (sameChar && (diffCase1 || diffCase2)) {
                isGood = false;
                a = i;
                b = i + 1;
                break;
            }
        }
        if (isGood) {
            return s;
        }
        StringBuilder newS = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (i == a || i == b) {
                continue;
            }
            newS.append(s.charAt(i));
        }
        return makeGood(newS.toString());
    }
}
