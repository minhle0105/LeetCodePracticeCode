package com.minhle.practiceleetcode;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class MaximumTwinSumOfALinkedList {
    public int pairSum(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        Queue<ListNode> queue = new LinkedList<>();
        ListNode curr = head;
        while (curr != null) {
            stack.push(curr);
            queue.add(curr);
            curr = curr.next;
        }
        int res = Integer.MIN_VALUE;
        while (!stack.isEmpty()) {
            res = Math.max(res, stack.pop().val + queue.remove().val);
        }
        return res;
    }
}
