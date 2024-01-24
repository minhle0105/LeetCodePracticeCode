package com.minhle.practiceleetcode;

import org.junit.jupiter.api.Test;

import java.util.HashSet;
import java.util.Set;

public class InsertIntoASortedCircularLinkedList {

    static class Node {
        public int val;
        public Node next;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, Node _next) {
            val = _val;
            next = _next;
        }
    };

    public Node insert(Node head, int insertVal) {
        if (head == null) {
            head = new Node(insertVal);
            head.next = head;
        }
        else {
            Node minNode = getMinNode(head);
            if (insertVal > minNode.val) {
                Node curr = minNode;
                while (curr.next.val < insertVal && curr.next != minNode) {
                    curr = curr.next;
                }
                Node currNext = curr.next;
                Node newNode = new Node(insertVal);
                curr.next = newNode;
                newNode.next = currNext;
            }
            else {
                Node newNode = new Node(insertVal);
                Node curr = minNode;
                while (curr.next != minNode) {
                    curr = curr.next;
                }
                newNode.next = minNode;
                curr.next = newNode;
            }

        }
        return head;
    }

    private Node getMinNode(Node head) {
        Node minNode = head;
        Node curr = head;
        Set<Node> visited = new HashSet<>();
        while (curr != null && !visited.contains(curr)) {
            if (curr.val < minNode.val) {
                minNode = curr;
            }
            visited.add(curr);
            curr = curr.next;

        }
        return minNode;
    }

    @Test
    void test1() {
        Node one = new Node(1);
        Node three = new Node(3);
        Node five = new Node(5);
        one.next = three;
        three.next = five;
        five.next = one;
        int insertVal = 4;
        insert(one, insertVal);
    }

    @Test
    void test2() {
        Node one = new Node(1);
        one.next = one;
        insert(one, 2);
    }

    @Test
    void test3() {
        Node three = new Node(3);
        Node five = new Node(5);
        Node one = new Node(1);
        one.next = three;
        three.next = five;
        five.next = one;
        int insertVal = 0;
        insert(one, insertVal);
    }
}
