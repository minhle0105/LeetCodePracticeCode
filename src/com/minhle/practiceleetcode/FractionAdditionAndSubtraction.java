package com.minhle.practiceleetcode;


public class FractionAdditionAndSubtraction {

    public String fractionAddition(String expression) {
        int c = 0;
        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) == '/') c++;
        }
        if (c < 2) {
            return expression;
        }
        String currentEvals = "";
        int r = 0;
        while (r < expression.length()) {
            int l = r + 1;
            if (currentEvals.length() == 0) {
                StringBuilder firstFraction = new StringBuilder(expression.charAt(r) + "");
                while (l < expression.length() && (expression.charAt(l) != '+' && expression.charAt(l) != '-' )) {
                    firstFraction.append(expression.charAt(l));
                    l++;
                }
                char operator = expression.charAt(l);
                StringBuilder secondFraction = new StringBuilder();
                l++;
                while (l < expression.length() && (expression.charAt(l) != '+' && expression.charAt(l) != '-' )) {
                    secondFraction.append(expression.charAt(l));
                    l++;
                }
                currentEvals = evaluateFraction(firstFraction.toString(), secondFraction.toString(), operator);
            }
            else {
                String firstFraction = currentEvals;
                char operator = expression.charAt(r);
                StringBuilder secondFraction = new StringBuilder();
                while (l < expression.length() && (expression.charAt(l) != '+' && expression.charAt(l) != '-' )) {
                    secondFraction.append(expression.charAt(l));
                    l++;
                }
                currentEvals = evaluateFraction(firstFraction, secondFraction.toString(), operator);
            }
            r = l;

        }
        return currentEvals;
    }

    private String evaluateFraction(String fraction1, String fraction2, char operator) {
        String[] f1 = fraction1.split("/");
        String[] f2 = fraction2.split("/");
        int a = Integer.parseInt(f1[0]);
        int b = Integer.parseInt(f1[1]);
        int c = Integer.parseInt(f2[0]);
        int d = Integer.parseInt(f2[1]);
        int numerator;
        int denominator;
        if (b == d) {
            numerator = operator == '+' ? a + c : a - c;
            denominator = b;
        }
        else {
            denominator = b * d;
            numerator = operator == '+' ? (a * d) + (b * c) : (a * d) - (b * c);
        }
        if (numerator % denominator == 0) {
            return (numerator / denominator) + "/" + 1;
        }
        while (true) {
            boolean stillFinding = false;
            for (int i = 2; i < Math.min(Math.abs(denominator), Math.abs(numerator)); i++) {
                if (denominator % i == 0 & numerator % i == 0) {
                    stillFinding = true;
                    denominator /= i;
                    numerator /= i;
                }
            }
            if (!stillFinding) break;
        }
        return numerator + "/" + denominator;
    }
}
