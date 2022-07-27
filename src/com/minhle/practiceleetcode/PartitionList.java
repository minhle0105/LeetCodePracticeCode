package com.minhle.practiceleetcode;

public class PartitionList {
    public ListNode partition(ListNode head, int x) {
        ListNode newHead = new ListNode();
        ListNode curr1 = newHead;
        ListNode curr2 = head;
        while (curr2 != null) {
            if (curr2.val < x) {
                curr1.next = new ListNode(curr2.val);
                curr1 = curr1.next;
            }
            curr2 = curr2.next;
        }
        curr2 = head;
        while (curr2 != null) {
            if (!(curr2.val < x)) {
                curr1.next = new ListNode(curr2.val);
                curr1 = curr1.next;
            }
            curr2 = curr2.next;
        }
        return newHead.next;
    }
}
