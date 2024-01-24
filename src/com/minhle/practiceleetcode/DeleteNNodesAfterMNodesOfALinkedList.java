package com.minhle.practiceleetcode;

public class DeleteNNodesAfterMNodesOfALinkedList {
    public ListNode deleteNodes(ListNode head, int m, int n) {
        int size = 0;
        ListNode curr = head;
        while (curr != null) {
            size++;
            curr = curr.next;
        }
        int total = m + n;
        int totalCount = size / total;
        return deleteNodes(head, m, n, totalCount, 0);
    }
    private ListNode deleteNodes(ListNode head, int m, int n, int totalCount, int count) {
        ListNode curr = head;
        int c = 0;
        if (count == totalCount) {
            while (c < m - 1 && curr != null) {
                curr = curr.next;
                c++;
            }
            if (curr == null) {
                return head;
            }

            ListNode removedPart = curr.next;
            c = 0;
            while (c < n - 1 && removedPart != null) {
                removedPart = removedPart.next;
                c++;
            }
            curr.next = null;
        }
        else {
            while (c < m - 1) {
                curr = curr.next;
                c++;
            }
            ListNode removedPart = curr.next;
            c = 0;
            while (c < n - 1) {
                removedPart = removedPart.next;
                c++;
            }
            curr.next = deleteNodes(removedPart.next, m, n, totalCount, count + 1);
        }
        return head;
    }
}
