package com.minhle.practiceleetcode;

import java.util.*;

public class LetterCombinationOfAPhoneNumber {
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return new ArrayList<>();
        }
        Map<Integer, String[]> map = new HashMap<>();
        map.put(2, new String[]{"a", "b", "c"});
        map.put(3, new String[]{"d", "e", "f"});
        map.put(4, new String[]{"g", "h", "i"});
        map.put(5, new String[]{"j", "k", "l"});
        map.put(6, new String[]{"m", "n", "o"});
        map.put(7, new String[]{"p", "q", "r", "s"});
        map.put(8, new String[]{"t", "u", "v"});
        map.put(9, new String[]{"w", "x", "y", "z"});
        List<String> res = new ArrayList<>();
        if (digits.length() == 1) {
            res.addAll(Arrays.asList(map.get(Integer.parseInt(String.valueOf(digits.charAt(0))))));
            return res;
        }
        if (digits.length() == 2) {
            for (int i = 0; i < digits.length() - 1; i++) {
                String[] a = map.get(Integer.parseInt(String.valueOf(digits.charAt(i))));
                for (int j = i + 1; j < digits.length(); j++) {
                    String[] b = map.get(Integer.parseInt(String.valueOf(digits.charAt(j))));
                    append(res, a, b);
                }
            }
            return res;
        }
        else if (digits.length() == 3) {
            for (int i = 0; i < digits.length() - 2; i++) {
                String[] a = map.get(Integer.parseInt(String.valueOf(digits.charAt(i))));
                for (int j = i + 1; j < digits.length() - 1; j++) {
                    String[] b = map.get(Integer.parseInt(String.valueOf(digits.charAt(j))));
                    for (int k = j + 1; k < digits.length(); k++) {
                        String[] c = map.get(Integer.parseInt(String.valueOf(digits.charAt(k))));
                        append(res, a, b, c);
                    }
                }
            }
            return res;
        }
        else {
            for (int i = 0; i < digits.length() - 3; i++) {
                String[] a = map.get(Integer.parseInt(String.valueOf(digits.charAt(i))));
                for (int j = i + 1; j < digits.length() - 2; j++) {
                    String[] b = map.get(Integer.parseInt(String.valueOf(digits.charAt(j))));
                    for (int k = j + 1; k < digits.length() - 1; k++) {
                        String[] c = map.get(Integer.parseInt(String.valueOf(digits.charAt(k))));
                        for (int l = k + 1; l < digits.length(); l++) {
                            String[] d = map.get(Integer.parseInt(String.valueOf(digits.charAt(l))));
                            append(res, a, b, c, d);
                        }
                    }
                }
            }
            return res;
        }

    }

    private void append(List<String> list, String[] a, String[] b) {
        for (String i : a) {
            for (String j : b) {
                list.add(i + j + "");
            }
        }
    }

    private void append(List<String> list, String[] a, String[] b, String[] c) {
        for (String i : a) {
            for (String j : b) {
                for (String k : c) {
                    list.add(i + j + k + "");
                }

            }
        }
    }

    private void append(List<String> list, String[] a, String[] b, String[] c, String[] d) {
        for (String i : a) {
            for (String j : b) {
                for (String k : c) {
                    for (String x : d) {
                        list.add(i + j + k + x + "");
                    }
                }

            }
        }
    }
}
