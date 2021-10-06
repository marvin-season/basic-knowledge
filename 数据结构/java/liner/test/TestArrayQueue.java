package mawenshu.liner.test;

import mawenshu.liner.queue.ArrayQueue;

/**
 * @author 马文澍
 * @date 2021/1/15 20:01
 */
public class TestArrayQueue {
    public static void main(String[] args) {
        ArrayQueue queue = new ArrayQueue(2);
        test(queue);
        test(queue);
        test(queue);
    }
    private static void test(ArrayQueue queue){
        queue.add(1);
        queue.add(2);
        queue.add(3);
        queue.poll();
        System.out.println(queue.size());
        queue.poll();
        System.out.println(queue.size());
    }
}
