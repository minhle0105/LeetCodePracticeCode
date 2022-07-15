package com.minhle.practiceleetcode;

import java.util.HashMap;
import java.util.Map;

public class FractionToRecurringDecimals {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        StringBuilder res = new StringBuilder("");
        if ((numerator < 0 & denominator > 0) | (numerator > 0 & denominator < 0)) {
            res.append("-");
        }
        long divisor = Math.abs((long) numerator);
        long dividend = Math.abs((long) denominator);
        res.append(divisor / dividend);
        long remainder = divisor % dividend;
        if (remainder == 0) {
            return res.toString();
        }
        res.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (remainder != 0) {
            if (map.containsKey(remainder)) {
                res.insert(map.get(remainder), "(");
                res.append(")");
                break;
            }
            else {
                map.put(remainder, res.length());
                remainder *= 10;
                res.append(remainder / dividend);
                remainder %= dividend;
            }
        }
        return res.toString();
    }
}
