package mawenshu.liner.test;

import mawenshu.liner.queue.LinkedQueue;

/**
 * @author 马文澍
 * @date 2021/1/19 12:59
 */
public class TestLinkedQueue {
    public static void main(String[] args) {
        LinkedQueue queue = new LinkedQueue();
        queue.add("mawneshu");
        queue.add("hello");
        queue.add("java");
        queue.add("data");queue.add("mawneshu");
        queue.add("hello");
        queue.add("java");
        queue.add("data");queue.add("mawneshu");
        queue.add("hello");
        queue.add("java");
        queue.add("data");
        queue.add("mawneshu");
        queue.add("hello");
        queue.add("java");
        queue.add("data");
        System.out.println("size = " + queue.size());
        for (int i = 0; i < 20; i++) {
            System.out.println("第" + (i + 1) + "个" + queue.poll());
        }
    }
}
