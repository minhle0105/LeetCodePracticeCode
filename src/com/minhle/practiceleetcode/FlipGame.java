package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class FlipGame {
    public List<String> generatePossibleNextMoves(String currentState) {
        if (currentState.length() < 2) {
            return new ArrayList<>();
        }
        List<String> res = new ArrayList<>();
        for (int i = 0; i < currentState.length() - 1; i++) {
            if (currentState.charAt(i) == currentState.charAt(i + 1) && currentState.charAt(i) == '+') {
                String thisCase = currentState.substring(0, i) + "--" + currentState.substring(i + 2);
                res.add(thisCase);
            }
        }
        return res;
    }
}
