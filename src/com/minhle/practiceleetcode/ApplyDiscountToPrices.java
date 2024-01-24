package com.minhle.practiceleetcode;

import java.text.DecimalFormat;

public class ApplyDiscountToPrices {
    public String discountPrices(String sentence, int discount) {
        String[] sentenceSplit = sentence.split(" ");
        double discountRate = ((double) discount) / 100;
        DecimalFormat f = new DecimalFormat("#0.00");
        for (int i = 0; i < sentenceSplit.length; i++) {
            String word = sentenceSplit[i];
            boolean wordStartsWithDollarSign = word.charAt(0) == '$';
            if (wordStartsWithDollarSign && word.length() > 1) {
                boolean isValidPrice = true;
                for (int j = 1; j < word.length(); j++) {
                    char c = word.charAt(j);
                    if (!Character.isDigit(c)) {
                        isValidPrice = false;
                        break;
                    }
                }
                if (isValidPrice) {
                    long originalPrice = Long.parseLong(word.substring(1));
                    double discountedPrice = (originalPrice - (discountRate * originalPrice));
                    sentenceSplit[i] = "$" + f.format(discountedPrice);
                }
            }
        }
        StringBuilder res = new StringBuilder();
        for (String word : sentenceSplit) {
            res.append(word).append(" ");
        }
        return res.toString().trim();
    }
}
