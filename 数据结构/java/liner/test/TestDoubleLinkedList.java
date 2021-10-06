package mawenshu.liner.test;

import mawenshu.liner.linkedlist.DoubleLinkedList;

/**
 * @author 马文澍
 * @date 2021/1/19 13:16
 */
public class TestDoubleLinkedList {
    public static void main(String[] args) {
        DoubleLinkedList list = new DoubleLinkedList();
        System.out.println("isEmpty = " + list.isEmpty());
        list.add("222");
        list.add("333");
        System.out.println("isEmpty = " + list.isEmpty());

        System.out.println(list.get(0));
        System.out.println(list.get(1));
    }
}
