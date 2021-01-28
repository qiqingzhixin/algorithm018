package com.liang.jksj;

import java.util.Deque;
import java.util.LinkedList;

public class 改写Deque的代码 {
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<>();
        System.out.println("===源程序===");
        deque.push("a");
        deque.push("b");
        deque.push("c");
        System.out.println(deque);
        System.out.println(deque.peek());
        System.out.println(deque);
        while (deque.size() > 0) {
            System.out.println(deque.pop());
        }
        System.out.println(deque);
        System.out.println("===addFirst改写===");
        deque.addFirst("a");
        deque.addFirst("b");
        deque.addFirst("c");
        System.out.println(deque);
        System.out.println(deque.peek());
        System.out.println(deque);
        while (deque.size() > 0) {
            System.out.println(deque.removeFirst());
        }

        System.out.println("===addLast改写===");
        deque.addLast("a");
        deque.addLast("b");
        deque.addLast("c");
        System.out.println(deque);
        System.out.println(deque.peekLast());
        System.out.println(deque);
        while (deque.size() > 0) {
            System.out.println(deque.removeLast());
        }


    }
}
