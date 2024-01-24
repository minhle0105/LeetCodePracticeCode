package com.minhle.practiceleetcode;

import java.util.Arrays;

public class CheckIfTwoExpressionTreesAreEquivalent {
    public boolean checkEquivalence(Node root1, Node root2) {
        String val1 = evals(root1);
        String val2 = evals(root2);
        char[] vals1 = val1.toCharArray();
        char[] vals2 = val2.toCharArray();
        Arrays.sort(vals1);
        Arrays.sort(vals2);
        return Arrays.toString(vals1).equals(Arrays.toString(vals2));
    }

    private String evals(Node root) {
        if (root.val == '+') {
            return evals(root.left) + "" + evals(root.right);
        }
        else {
            return String.valueOf(root.val);
        }
    }
}
