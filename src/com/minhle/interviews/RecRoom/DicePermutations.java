package com.minhle.interviews.RecRoom;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class DicePermutations {
    private List<int[]> getDicePermutations(int n) {
        List<int[]> permutations = new ArrayList<>();
        generatePermutations(permutations, new ArrayList<>(), n);
        return permutations;
    }

    private void generatePermutations(List<int[]> permutations, List<Integer> currentPerm, int n) {
        if (currentPerm.size() == n) {
            int[] perm = new int[n];
            for (int i = 0; i < currentPerm.size(); i++) {
                perm[i] = currentPerm.get(i);
            }
            permutations.add(perm);
            return;
        }
        for (int i = 1; i <= 6; i++) {
            currentPerm.add(i);
            generatePermutations(permutations, currentPerm, n);
            currentPerm.remove(currentPerm.size() - 1);
        }
    }
}
