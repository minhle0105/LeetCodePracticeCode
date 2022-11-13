package com.minhle.practiceleetcode;

import java.util.ArrayList;
import java.util.List;

public class BinarySearchTreeIterator {
    static class BSTIterator {

        List<TreeNode> inorder;
        int index = 0;

        public BSTIterator(TreeNode root) {
            inorder = new ArrayList<>();
            traverse(root);
        }

        private void traverse(TreeNode root) {
            if (root == null) {
                return;
            }
            traverse(root.left);
            inorder.add(root);
            traverse(root.right);
        }

        public int next() {
            return inorder.get(index++).val;
        }

        public boolean hasNext() {
            return index < inorder.size();
        }
    }
}
