package com.minhle.practiceleetcode;

public class OddEvenLinkedList {
    public ListNode oddEvenList(ListNode head) {
        ListNode curr = head;

        boolean isOdd = true;

        ListNode odds = new ListNode();
        ListNode currOdds = odds;

        ListNode evens = new ListNode();
        ListNode currEvens = evens;

        while (curr != null) {
            if (isOdd) {
                currOdds.next = new ListNode(curr.val);
                currOdds = currOdds.next;
            }
            else {
                currEvens.next = new ListNode(curr.val);
                currEvens = currEvens.next;
            }
            curr = curr.next;
            isOdd = !isOdd;
        }

        odds = odds.next;
        evens = evens.next;
        currOdds.next = evens;

        return odds;
    }
}
