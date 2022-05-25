package com.minhle.practiceleetcode;

public class GoatLatin {
    public String toGoatLatin(String sentence) {
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            boolean wordStartsWithVowel = startsWithVowel(words[i]);
            if (wordStartsWithVowel) {
                words[i] = handleVowel(words[i]);
            } else {
                words[i] = handleConsonant(words[i]);
            }
            words[i] = handleGeneral(words[i], i + 1);
        }
        StringBuilder result = new StringBuilder("");
        for (String word : words) {
            result.append(word).append(" ");
        }
        return result.toString().trim();
    }

    private boolean startsWithVowel(String word) {
        return word.charAt(0) == 'u' |
                word.charAt(0) == 'e' |
                word.charAt(0) == 'o' |
                word.charAt(0) == 'a' |
                word.charAt(0) == 'i' |
                word.charAt(0) == 'U' |
                word.charAt(0) == 'E' |
                word.charAt(0) == 'O' |
                word.charAt(0) == 'A' |
                word.charAt(0) == 'I';
    }

    private String handleVowel(String word) {
        return word + "ma";
    }

    private String handleConsonant(String word) {
        StringBuilder result = new StringBuilder("");
        for (int i = 1; i < word.length(); i++) {
            result.append(word.charAt(i));
        }
        result.append(word.charAt(0));
        result.append("ma");
        return result.toString();
    }

    private String handleGeneral(String word, int index) {
        StringBuilder result = new StringBuilder(word);
        result.append("a".repeat(Math.max(0, index)));
        return result.toString();
    }
}
