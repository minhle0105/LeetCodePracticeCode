package com.minhle.practiceleetcode;

import java.util.*;

public class AddTwoNumbersII {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> queue1 = new Stack<>();
        Stack<Integer> queue2 = new Stack<>();
        ListNode curr1 = l1;
        ListNode curr2 = l2;
        while (curr1 != null) {
            queue1.push(curr1.val);
            curr1 = curr1.next;
        }
        while (curr2 != null) {
            queue2.push(curr2.val);
            curr2 = curr2.next;
        }
        LinkedList<Integer> result = new LinkedList<>();
        boolean hasCarry = false;
        while (!queue1.isEmpty() && !queue2.isEmpty()) {
            int a = queue1.pop();
            int b = queue2.pop();
            int sum = a + b;
            if (hasCarry) {
                if (sum + 1 >= 10) {
                    result.addFirst((sum + 1) % 10);
                    hasCarry = true;
                }
                else {
                    result.addFirst(sum + 1);
                    hasCarry = false;
                }
            }
            else {
                if (sum >= 10) {
                    result.addFirst(sum % 10);
                    hasCarry = true;
                }
                else {
                    result.addFirst(sum);
                    hasCarry = false;
                }
            }
        }
        if (!queue1.isEmpty()) {
            while (!queue1.isEmpty()) {
                if (hasCarry) {
                    if (queue1.peek() + 1 >= 10) {
                        result.addFirst((queue1.pop() + 1) % 10);
                        hasCarry = true;
                    }
                    else {
                        result.addFirst(queue1.pop() + 1);
                        hasCarry = false;
                    }
                }
                else {
                    if (queue1.peek() >= 10) {
                        result.addFirst(queue1.pop() % 10);
                        hasCarry = true;
                    }
                    else {
                        result.addFirst(queue1.pop());
                        hasCarry = false;
                    }
                }
            }
        }
        else if (!queue2.isEmpty()) {
            while (!queue2.isEmpty()) {
                if (hasCarry) {
                    if (queue2.peek() + 1 >= 10) {
                        result.addFirst((queue2.pop() + 1) % 10);
                        hasCarry = true;
                    }
                    else {
                        result.addFirst(queue2.pop() + 1);
                        hasCarry = false;
                    }
                }
                else {
                    if (queue2.peek() >= 10) {
                        result.addFirst(queue2.pop() % 10);
                        hasCarry = true;
                    }
                    else {
                        result.addFirst(queue2.pop());
                        hasCarry = false;
                    }
                }
            }
        }
        if (hasCarry) {
            result.addFirst(1);
        }
        if (result.get(0) >= 10) {
            int unitDigit = result.get(0) % 10;
            int tenthDigit = result.get(0) / 10;
            result.removeFirst();
            result.addFirst(unitDigit);
            result.addFirst(tenthDigit);
        }
        ListNode sum = new ListNode(result.get(0));
        ListNode curr = sum;
        for (int i = 1; i < result.size(); i++) {
            curr.next = new ListNode(result.get(i));
            curr = curr.next;
        }
        return sum;
    }
}
