package com.minhle.practiceleetcode;

import java.util.Arrays;

public class RearrangeWordsInSentence {

    static class MyString implements Comparable<MyString> {
        String s;
        int length;
        int index;

        public MyString(String s, int index) {
            this.s = s;
            this.index = index;
            this.length = s.length();
        }

        @Override
        public int compareTo(MyString o) {
            if (this.length == o.length) {
                return Integer.compare(this.index, o.index);
            }
            return Integer.compare(this.length, o.length);
        }
    }

    public String arrangeWords(String text) {
        String[] words = text.split(" ");
        MyString[] myStrings = new MyString[words.length];
        for (int i = 0; i < words.length; i++) {
            MyString myString = new MyString(words[i], i);
            myStrings[i] = myString;
        }
        Arrays.sort(myStrings);
        myStrings[0].s = myStrings[0].s.substring(0, 1).toUpperCase() + myStrings[0].s.substring(1);
        for (int i = 1; i < myStrings.length; i++) {
            myStrings[i].s = myStrings[i].s.toLowerCase();
        }
        StringBuilder result = new StringBuilder("");
        for (MyString myString : myStrings) {
            result.append(myString.s);
            result.append(" ");
        }
        return result.toString().trim();
    }
}
