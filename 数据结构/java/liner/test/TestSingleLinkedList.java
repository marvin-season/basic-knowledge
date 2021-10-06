package mawenshu.liner.test;

import mawenshu.liner.List;
import mawenshu.liner.linkedlist.SingleLinkedList;

/**
 * @author 马文澍
 * @date 2021/1/13 16:54
 */
public class TestSingleLinkedList {
    public static void main(String[] args) {
        SingleLinkedList list = new SingleLinkedList();
        list.add("123");
        list.add("234");
        list.add("345");
        list.add("345");
        list.add("456");
        list.add("789");
        list.add(1, "567");

        System.out.println(list);
        list.reverse2();
        System.out.println("===============");
        System.out.println("反");
        System.out.println(list);

        System.out.println(list.get(3));

        System.out.println("删除了下标为1的元素 = " + list.removeByIndex(1));
        System.out.println(list);
        System.out.println(list.remove("345"));
        System.out.println(list);

        list.replaceByIndex(0, "234");
        System.out.println(list);
        list.replace("234", "345");
        System.out.println(list);
    }
}
