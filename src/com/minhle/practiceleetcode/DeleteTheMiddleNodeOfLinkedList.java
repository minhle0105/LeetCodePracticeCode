package com.minhle.practiceleetcode;

public class DeleteTheMiddleNodeOfLinkedList {
    public ListNode deleteMiddle(ListNode head) {
        ListNode slow = new ListNode(-1, head);
        ListNode fast = head;
        if (fast.next == null) {
            return null;
        }
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = slow.next.next;
        return head;
    }
}
