package com.minhle.practiceleetcode;

import java.util.*;

public class MergeKSortedList
{
    static class ListNode
    {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0)
        {
            return null;
        }
        if (lists.length == 1)
        {
            return lists[0];
        }
        ListNode res = mergeTwoList(lists[0], lists[1]);
        for (int i = 2; i < lists.length; ++i)
        {
            res = mergeTwoList(res, lists[i]);
        }
        return res;
    }

    private ListNode mergeTwoList(ListNode node1, ListNode node2)
    {
        ListNode curr1 = node1;
        ListNode curr2 = node2;
        ListNode res = new ListNode(-1);
        ListNode curr = res;
        while (curr1 != null && curr2 != null)
        {
            if (curr1.val < curr2.val)
            {
                ListNode next = new ListNode(curr1.val);
                curr.next = next;
                curr = curr.next;
                curr1 = curr1.next;
            }
            else
            {
                ListNode next = new ListNode(curr2.val);
                curr.next = next;
                curr = curr.next;
                curr2 = curr2.next;
            }
        }
        while (curr1 != null)
        {
            curr.next = new ListNode(curr1.val);
            curr = curr.next;
            curr1 = curr1.next;
        }
        while (curr2 != null)
        {
            curr.next = new ListNode(curr2.val);
            curr = curr.next;
            curr2 = curr2.next;
        }
        return res.next;
    }
}
