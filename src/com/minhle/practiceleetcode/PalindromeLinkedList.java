package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class PalindromeLinkedList {
    public boolean isPalindrome(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        Queue<Integer> queue = new LinkedList<>();
        ListNode curr = head;
        while (curr != null) {
            stack.push(curr.val);
            queue.add(curr.val);
            curr = curr.next;
        }
        while (!stack.isEmpty()) {
            if (!stack.pop().equals(queue.remove())) {
                return false;
            }
        }
        return true;
    }
}
