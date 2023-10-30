package com.minhle.practiceleetcode;

public class SwapNodesInPairs {
    public static ListNode swapPairs(ListNode head) {
        if (head == null) {
            return null;
        }
        if (head.next == null) {
            return head;
        }
        ListNode node1 = head;
        ListNode node2 = head.next;

        // recursively swap nodes
        node1.next = swapPairs(node2.next);
        node2.next = node1;
        return node2;
    }
}
