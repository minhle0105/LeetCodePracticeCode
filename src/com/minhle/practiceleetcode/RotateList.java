package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

public class RotateList {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode curr = head;
        if (curr == null) return null;
        if (curr.next == null) return curr;
        int n = 0;
        while (curr != null) {
            n++;
            curr = curr.next;
        }
        return rotate(head, k % n, 0, n);
    }

    private ListNode rotate(ListNode head, int k, int count, int n) {
        if (k == count) return head;
        ListNode newHead = head;
        ListNode newTail = new ListNode(-1, newHead);
        int i = 0;
        while (i < n - 1) {
            newHead = newHead.next;
            newTail = newTail.next;
            i++;
        }
        newHead.next = head;
        newTail.next = null;
        return rotate(newHead, k, count + 1, n);
    }
}
