package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.Stack;

public class ReorderList {
    static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode (int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }
    public void reorderList(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        ListNode curr = head;
        int n = 0;
        while (curr != null) {
            stack.push(curr);
            curr = curr.next;
            n++;
        }
        int count = 0;
        curr = head;
        while (count < n/2) {
            ListNode temp = stack.pop();
            temp.next = curr.next;
            curr.next = temp;
            curr = curr.next.next;
            count++;
        }
        count = 0;
        curr = head;
        while (count <= n) {
            curr = curr.next;
            count++;
        }
        curr.next = null;
    }
}
