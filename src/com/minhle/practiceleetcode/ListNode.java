package com.minhle.practiceleetcode;

public class ListNode {
    int val;
    ListNode next;

    public ListNode() {
    }

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    public boolean compareTo(ListNode o) {
        if (o == null) {
            return false;
        }
        if (this.val != o.val) {
            return false;
        }
        ListNode cur1 = this;
        ListNode cur2 = o;
        while (cur1.next != null && cur2.next != null) {
            if (cur1.val != cur2.val) {
                return false;
            }
            cur1 = cur1.next;
            cur2 = cur2.next;
        }
        return !((cur1.next == null && cur2.next != null) | (cur1.next != null && cur2.next == null));
    }
}
